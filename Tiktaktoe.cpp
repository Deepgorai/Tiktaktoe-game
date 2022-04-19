#include "Tiktak.h"

using namespace std;

int main()
{
    int your_position;
    char marker;
    int win;
    cout << "Player 1. Which symbol you want" << endl;
    cin >> marker;
    current_marker = marker;
    current_player = 1;
    board();
    cout << "\n\n";


    for(int i = 0; i < 4; i++){
        
        cout << "Player1 Enter the position you want to put the marker" << endl;    
        cin >> your_position;
        
        if (!placemarker(your_position)){
            cout << "Try again" << endl;
            i--;
            continue;
        }

        board();
        cout << "\n\n";
        swap();
        place_comp_marker();
        swap();
        board();
        cout << "\n";
        win = checkwinner();
        if (win == 1){
            cout << "player 1 is winner" << endl;
            break;
        }
        if (win == 2){
            cout << "player 2 is winner" << endl;
            break;
        }
    }
    if (win == 0){
        cout << "The match is a Tie" << endl;
    }
    return 0;
}