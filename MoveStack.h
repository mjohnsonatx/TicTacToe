//File Name: MoveStack..h
//
//Author: Michael Johnson
//Collaborators: Roland Cortes, Brittany Hale, Mayra Flores
//Date: 9/15/2020
// Assignment Number: 6
// CS 2308 Fall 2020
//

#ifndef LAB6_PART1_STACK_H
#define LAB6_PART1_STACK_H
#include <cassert>

using namespace std;

struct Move{
    Move(): x(0), y(0){}
    Move(int x, int y): x(x), y(y){}
    int x;
    int y;
};

class MoveStack{

    private:
        static const int MAX_SIZE = 9;
        int list_front;
        Move stack_array[MAX_SIZE];
        int turn_counter = 0;

    public:

// Constructor for MoveStack, start array at -1;
MoveStack()
{
    list_front = -1;
}

// getSize determines the size of the stack.

int getSize()
{
    return (list_front+1);
}

//moveTop returns the top of the array.

Move top()
{
    return stack_array[list_front];
}

//push adds an iteration of the struct variable to the array.

void push(Move move)
{
    if (list_front == MAX_SIZE)
        cout << "ERROR: Stack is FULL!" << endl;
    else
        {
         list_front++;
         stack_array[list_front] = move;
        }
}

//pop removes the top iteration of the array variable.

void pop()
{
    assert(!isEmpty());

    list_front--;
}

// isFull is used to determine if the stack is full.

bool isFull()
{
    return (list_front == MAX_SIZE -1 );
}

// isEmpty determines if the stack is empty.
bool isEmpty()
{
    return (list_front == -1);
}
};

#endif //LAB6_PART1_STACK_H
