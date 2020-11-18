#include <iostream>
#include <vector>
#include <algorithm> 
#include "game.cpp"
#define ROW 4

using namespace std;


int main()
{
    
    Game game;
    game.initialize();
    game.printBoard();
    game.start();

    return 0;
}
