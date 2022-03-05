//File Name: main.cpp
//
//Author: Michael Johnson
//Collaborators: Roland Cortes, Brittany Hale, Mayra Flores
//Date: 9/15/2020
// Assignment Number: 6
// CS 2308 Fall 2020
//


#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>

#include "MoveStack.h"
#include "GameState.h"

using namespace std;

int main ( )
{
    bool gameWon = false, winGame = false, b = false;
    MoveStack stack_array;
    Move played_move;
    GameState myGame;
    int current_player = 0;
    int turn_counter = 0;
    string play;
    int x = 0, y = 0, k = 0;

    myGame.displayBoardState(cout);

    while (!gameWon)
     {

    current_player = myGame.getCurrentPlayer();

    cout << "Player " << current_player << " make a turn." << endl;
    cin >> play;

    if (play == "move")

        {
            cin >> x >> y;
            played_move.x = x;
            played_move.y = y;

            k = myGame.addMove(played_move);

            if ( k == -1)
                  cout << "Incorrect move. Please try again." << endl;

            else if ( k == 0)
             {
                gameWon = true;
                cout << "It's a draw!" << endl;
             }

        }
    else if (play == "undo")
                {
                 b = myGame.undoLast();
                    if(b == false)
                        cout << "No moves to undo." << endl;
                }

    winGame = myGame.checkLastPlayerWin();
        if (winGame == true)
            {
                cout << "Player " << current_player << " won!" << endl;
                gameWon = true;
            }
    }

return 0;
}

