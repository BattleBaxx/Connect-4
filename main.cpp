#include <iostream>
#include <vector>
#include <algorithm> 
// #include "Game.h"
#include "game.cpp"
#define ROW 4

using namespace std;

// Game class


int main()
{
    
    Game game;
    
    game.initialize();
    game.printBoard();
    // int compMove = game.getCompMove();
    game.start();

    // cout << "Did Win value: " << game.didWin() << endl;

    // game.printBoard();
    // cout << game.didWin() << " " <<  game.isTie() << endl;

    return 0;
}

    // game.makeMove(5, true);
    // game.makeMove(4, false);
    // game.makeMove(4, true);
    // game.makeMove(3, false);
    // game.makeMove(3, false);
    // game.makeMove(3, true);
    // game.makeMove(2, false);
    // game.makeMove(2, false);
    // game.makeMove(2, false);
    // game.makeMove(2, true);

    // game.makeMove(2, true);
    // game.makeMove(3, true);
    // game.makeMove(4, true);
    // game.makeMove(5, true);
    
    // game.makeMove(2, true);
    // game.makeMove(2, true);
    // game.makeMove(2, true);
    // game.makeMove(2, true);

    // game.makeMove(2, true);
    // game.makeMove(3, false);
    // game.makeMove(3, true);
    // game.makeMove(4, false);
    // game.makeMove(4, false);     
    // game.makeMove(4, true);
    // game.makeMove(5, false);
    // game.makeMove(5, false);
    // game.makeMove(5, false);
    // game.makeMove(5, true);


    // game.makeMove(0, false);
    // game.makeMove(0, true);
    // game.makeMove(0, false);
    // game.makeMove(0, true);
    // game.makeMove(0, false);
    // game.makeMove(0, true);
    // game.makeMove(0, false);
    // game.makeMove(0, true);
    // game.makeMove(0, false);
    // game.makeMove(0, true);


    // int play = game.didWin();
    // cout << play << " won." << endl;
    // game.printBoard();
    
    //game.start();

    // for(int i = ROW-1; i>=2; i--)
    // {
    //     for(int j = 0; j<ROW; j++)
    //     {
    //         if(j == ROW-1)
    //             game.board[i][j] = -1;
    //         else
    //             game.board[i][j] = 1;
    //     }

    // }

    //game.board[1][3] = -1;