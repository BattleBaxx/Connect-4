#include <iostream>
#include <vector>
#include <algorithm> 

#define ROW 4

using namespace std;


class Game
{
public:
    int board[ROW][ROW];
    char player;
    char cpu;
    char playerColor;
//public:
    Game();
    void initialize();
    void printBoard();
    string getColor(char);
    void makeMove(int, bool);
    void removeMove(int);
    void start();
    int didWin();
    bool isTie();
    int getCompMove();
    int minimax(int, bool);
};
