//File Name: GameState.h
//
//Author: Michael Johnson
//Collaborators: Roland Cortes, Brittany Hale, Mayra Flores
//Date: 9/15/2020
// Assignment Number: 6
// CS 2308 Fall 2020
//


#include "GameState.h"
#include "MoveStack.h"

using namespace std;

bool GameState::checkLastPlayerWin() {
    char targetSymbol = this->getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += this->boardState[i][j] == targetSymbol;
            sumVertical += this->boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += this->boardState[i][i] == targetSymbol;
        sumDiagonal2 += this->boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}

// constructor for the board, sets the board to blank under scores.

GameState::GameState()
{
 for ( int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            {
            boardState[i][j] = '_';
            }
    }

}

// getCurrentPlayer gets the player during for the game loop and determines how
// to assign an 'x' or 'o' in addMove.

int GameState::getCurrentPlayer()
{
    return ( moveStack.getSize() % 2);
}

// addMove as the move to the board by inputting the two int variables as the
// location.

int GameState::addMove(Move move)
{
    char current_player;


    if (getCurrentPlayer() == 0)
    {
        current_player = 'x';
        if(boardState[move.x][move.y] == '_')
                boardState[move.x][move.y] = current_player;

        else
            return -1;
    }
    else
    {
        current_player = 'o';
        if(boardState[move.x][move.y] == '_')
                boardState[move.x][move.y] = current_player;

        else
            return -1;
    }

    displayBoardState(cout);
    moveStack.push(move);

    if (moveStack.getSize() == 9)
        return 0;

    else
    return 1;
}

// undoLast undoes the move of the last player.

bool GameState::undoLast()
{
    if(moveStack.isEmpty() == false)
        {
            Move stack_array = moveStack.top();
            boardState[stack_array.x][stack_array.y] = '_';
            moveStack.pop();
            displayBoardState(cout);
            return true;
       }
    else
        {
        return false;
        }
}

// displayBoardState display the board and is called after every
// successful move.

void GameState::displayBoardState(std::ostream& out)
{
    for ( int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            {
            out << boardState[i][j];
            }
        out << endl;
    }
}
