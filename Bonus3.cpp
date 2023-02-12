#include <iostream>
#include <cstdlib>


using namespace std;


class Game{
    public:
        Game();
        ~Game();
        void ClearBoard();
        void putMark(char k, int i, int j);
        bool getWinner();
        void DisplayBoard();
        void putMarkforComputer(char k);
      
        
    private:
        char board[3][3];
};


Game::Game(){
    board[3][3] = ' ';
}


Game::~Game(){
    
}


void Game::ClearBoard(){
    for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j] = ' ';
            }
    }
}


void Game::putMark(char k, int i, int j){
    i--;
    j--;
    if(board[i][j] == ' '){
    	board[i][j] = k;
    	return;
	}
	else{
		cout << "the place has been taken. " << endl;
		
	}
    
        
}

void Game::putMarkforComputer(char k){
	int i = rand() % 3 + 1;
	int j = rand() % 3 + 1;
	
	if(board[i][j] == ' '){
		board[i][j] = k;
		return;
	}
	else{
		Game::putMarkforComputer(k);
	}
	
}


bool Game::getWinner(){
    int x, y;
    
    //check colums
    for(x=0;x<3;x++){
        
        if(board[0][x] == board[1][x] && board[0][x] == board[2][x] && board[0][x] != ' '){
            cout << board[0][x] << " has won!" << endl;
            return 1;
        }
    }
    //check rows
    for(y=0;y<3;y++){
        if(board[y][0] == board[y][1] && board[y][0] == board[y][2] && board[y][0] != ' '){
            cout << board[y][0] << " has won!" << endl;
            return 1;
        }
    }
    
    //check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board [2][2] && board[1][1] != ' '){
        cout << board[0][0] << " has won!" << endl;
        return 1;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != ' '){
        cout << board[0][2] << " has won!" << endl;
        return 1;
    }
    
    return 0;
}


void Game::DisplayBoard(){
    cout << "-------------" << endl;
    cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    cout << "-------------" << endl;
    cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
    cout << "-------------" << endl;
}




int main() {
    Game game;
    int row, col, moveNum=0;
    
    game.ClearBoard();
    game.DisplayBoard();
    
    
    while(game.getWinner() != true && moveNum < 9){
        cout << "Enter player 1 row: ";
        cin >> row;
        cout << "Enter player 1 column: ";
        cin >> col;
        
        
        game.putMark('X', row, col);
        game.DisplayBoard();
        game.getWinner();
        moveNum++;
        
        if(game.getWinner() == true || moveNum == 9){
            break;
        }
        
        cout << "Computer moves..." << endl;
        
        
        game.putMarkforComputer('O');
        game.DisplayBoard();
        game.getWinner();
        moveNum++;
        
        if(moveNum == 10){
            break;
        }
        
    }
    

    else if(moveNum == 9){
        cout << "It is a draw" << endl;
    }
    
    return 0;
}




