#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int current_player;
char current_marker;
char draw_board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void board(){
   cout << draw_board[0][0] << " | " << draw_board[0][1] << " | " << draw_board[0][2] << endl;
   cout << "----------" << endl;
   cout << draw_board[1][0] << " | " << draw_board[1][1] << " | " << draw_board[1][2] << endl;
   cout << "----------" << endl;
   cout << draw_board[2][0] << " | " << draw_board[2][1] << " | " << draw_board[2][2]  << endl;
}

bool placemarker(int slot){
    int row, col;
    if ((slot % 3) == 0){
        row = (slot/3 - 1);
        col = 2;
    }
    else {
        row = slot/3;
        col = (slot % 3) - 1;
    }
    if(draw_board[row][col] != 'X' && draw_board[row][col] != 'O'){
        draw_board[row][col] = current_marker;
        return true;
    }
    else{
        return false;
    }
}

int checkwinner(){
    for(int i = 0; i < 3; i++){
        if (draw_board[i][0] == draw_board[i][1] && draw_board[i][1] == draw_board[i][2]){
            return current_player;
        } 
        if (draw_board[0][i] == draw_board[1][i] && draw_board[1][i] == draw_board[2][i]){
            return current_player;
        }
    }

    if (draw_board[0][0] == draw_board[1][1] && draw_board[1][1] == draw_board[2][2]){
        return current_player;
    }
    if (draw_board[0][2] == draw_board[1][1] && draw_board[1][1] == draw_board[2][0]){
        return current_player;
    }
    return 0;
}

void place_comp_marker(){
    int comp_position;
    again :
        srand(time(0));
        comp_position = rand() % 9 + 1;
        cout << comp_position << endl;

        if (!placemarker(comp_position)){
            goto again;
        }
}

void swap(){
    if (current_marker == 'X'){
        current_marker = 'O';
    }
    else if (current_marker == 'O'){
        current_marker = 'X';
    }
    if (current_player == 1){
        current_player = 2;
    }
    else {
        current_player = 1;
    }
}