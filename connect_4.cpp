#include <iostream>
#include <vector>
#include<algorithm> 

#define ROW 4

using namespace std;

// Game class
class Game
{
public:
    int board[ROW][ROW];
    char player;
    char cpu;
//public:
    Game(char);
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

// Contructor sets char of player
Game :: Game(char player_1)
{
    for(auto &rows : board)
        for(auto &val : rows)
            val = 0;
    this->player = player_1;
    this->cpu = 'c';
}


// Function for returns color
string Game :: getColor(char color)
{
    switch (color)
    {
        case 'r': return "\u001b[31m";
        case 'g': return "\u001b[32;1m";
        case 'y': return "\u001b[33;1m";
        case 'b': return "\u001b[34;1m";
        case 'm': return "\u001b[35;1m";
        case 'c': return "\u001b[36;1m";
        default: return "\u001b[0m";
    }
}

// Prints the board
void Game :: printBoard()
{
    cout << "| ";
    for (int i = 0; i < ROW; i++)
        cout << i << " | ";

    cout << endl << " ";
    for (int i = 0; i < ROW; i++)
        cout << " |  ";
    cout << endl;

    cout << " ";
    for (int i = 0; i < ROW; i++)
        cout << " v  ";
    cout << endl;

    for(auto &rows : board)
    {
        cout << "| ";
        for(auto &val : rows)
        {
            if(val == 1)
                cout << getColor('y') << player << getColor('n') << " | ";
            else if(val == -1)
                cout << getColor('g') << cpu << getColor('n') << " | ";
            else
                cout << getColor('c') << "." << getColor('n') << " | ";
        }
        cout << endl << "-----------------------------------------" << endl;
    }


}

// Registers the move made by the players
void Game :: makeMove(int col, bool player)
{
    for (int i = ROW-1; i >= 0; i--)
    {
        if(board[i][col] == 0)
        {
            if(player)
                board[i][col] = 1;
            else
                board[i][col] = -1;
            break;
        } 
    }

}

// Removes the move made by the players
void Game :: removeMove(int col)
{
    for (int i = 0; i < ROW; i++)
    {
        if(board[i][col] != 0)
        {
           board[i][col] = 0;
           break;
        } 
    }

}

// Check of anyone won and if won returns the winning player char
int Game :: didWin()
{
    bool flag = true;
    int won = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < ROW; j++)
        {

            if (board[i][j] != 0)
            {
                flag = true;
                int val = board[i][j];

                // loop for 12:00
                for (int k = 1; k < 4; k++)
                {
                    if(i - 3 >= 0)
                    {
                        if(board[i-k][j] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                    
                }

                if(flag)
                {
                    won = board[i][j];
                    break;
                }
                
                flag = true;
                
                // loop for 6:00
                for (int k = 1; k < 4; k++)
                {
                    if(i + 3 <= ROW - 1 )
                    {
                        if(board[i+k][j] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }

                if(flag)
                {
                    won = board[i][j];
                    break;
                }

                flag = true;    
                
                // loop for 3:00 
                for (int k = 1; k < 4; k++)
                {
                    if(j + 3 <= ROW - 1 )
                    {
                        if(board[i][j+k] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }
                
                if(flag)
                {
                    won = board[i][j];
                    break;
                }

                flag = true;

                // loop for 9:00
                for (int k = 1; k < 4; k++)
                {
                    if(j - 3 >= 0)
                    {
                        if(board[i][j-k] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }

                if(flag)
                {
                    won = board[i][j];
                    break;
                }

                flag = true;

                // loop for 1:30
                for (int k = 1; k < 4; k++)
                {
                    if(j + 3 <= ROW - 1  && i - 3 >= 0)
                    {
                        if(board[i-k][j+k] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }

                if(flag)
                {
                    won = board[i][j];
                    break;
                }

                flag = true;

                // loop for 5:30
                for (int k = 1; k < 4; k++)
                {
                    if(j + 3 <= ROW - 1  && i + 3 >= ROW - 1 )
                    {
                        if(board[i+k][j+k] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }

                if(flag)
                {
                    won = board[i][j];
                    break;
                }

                flag = true;

                // loop for 7:30
                for (int k = 1; k < 4; k++)
                {
                    if(j + 3 >= 0 && i + 3 <= ROW - 1 )
                    {
                        if(board[i+k][j-k] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }

                if(flag)
                {
                    won = board[i][j];
                    break;
                }

                flag = true;

                // loop for 10:30
                for (int k = 1; k < 4; k++)
                {
                    if(j + 3 >= 0 && i + 3 >= 0)
                    {
                        if(board[i-k][j-k] != val)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }

                if(flag)
                {
                    won = board[i][j];
                    break;
                }
            }

            if(won != 0)
                return won;
            
        }
        
    }

    return won;
    
}

// Returns if the present board is a tied 
bool Game :: isTie()
{
    for(auto &rows : board)
        for(auto &val : rows)
            if(val == 0)
                return false;

    // the board is filled, nobody won => tie
    if(didWin() == 0)
        return true;
    else //the board is filled, somebody won
        return false;
}

int Game  :: minimax(int depth, bool player)
{
    int won = didWin();
    
    cout << "Calling minimax at depth: " << depth << endl;
    if(isTie() || won != 0 )
    {
        cout << "BASE CONDITION" << endl;
        return -won;
    }
    // Maximizing player
    if(player)
    {
        int presentScore = 0, bestScore = -9999999;
        for (int i = 0; i < ROW; i++)
        {
            // Checking if the position is free
            if(board[0][i] == 0)
            {
                makeMove(i, true);
                presentScore = minimax(depth+1, false);
                removeMove(i);
                bestScore = max(presentScore, bestScore);
            }
        }

        cout << "Returning bestscore: " << bestScore << endl;
        return bestScore;
    }

    // Minimizing player
    else
    {
        int presentScore = 0, bestScore = 9999999;
        for (int i = 0; i < ROW; i++)
        {
            // Checking if the position is free
            if(board[0][i] == 0)
            {
                makeMove(i, false);
                presentScore = minimax(depth+1, true);
                removeMove(i);
                bestScore = min(presentScore, bestScore);
            }
        }
        cout << "Returning bestscore: " << bestScore << endl;
        return bestScore;
    }
    
}

int Game :: getCompMove()
{
    int bestScore = -99999999;
    int bestMove = 0;
    int presentScore;
    for (int i = 0; i < ROW; i++)
    {
        // Checking if the position is free
        if(board[0][i] == 0)
        {
            makeMove(i, false);
            presentScore = minimax(0, false);
            cout << "RETURNED OUT OF MINIMAX" << endl;
            removeMove(i);
            if(presentScore == 1)
            {
                cout << "PRESENT SCORE 1" << endl;
                cout << "Best score: " << bestScore << endl;
            }
            if(presentScore >= bestScore)
            {
                bestMove = i;
                bestScore = presentScore;
            }
        }
        
    }
    cout << "Returning bestMove value : " << bestMove << endl;
    return bestMove;

    return 1;
}



// Skeleton of the Game
void Game :: start()
{
    int playerMove, compMove, won = 0;
    
    while (won == 0 & !isTie())
    {
        cout << "Please enter the move you are about to play: ";
        cin >> playerMove;
        makeMove(playerMove, true);
        printBoard();
        compMove = getCompMove();
        makeMove(compMove,false);
        printBoard();
        //system("clear");
        won = didWin();
    }
    
    if(won == 1)
        cout << "The human won." << endl;
    else if (won == -1)
        cout << "What did you think you would win with a computer.." << endl;
    else
        cout << "Well the game is a tie." << endl;
     
    
    
}

int main()
{
    char player;
    cout << "Choose your character PLAYER: ";
    cin >> player;

    Game game(player);
    
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

    // for(int i = 2; i<ROW; i++)
    // {
    //     for(int j = 0; j<ROW; j++)
    //     {
    //         if(j == ROW-1)
    //             game.board[i][j] = 1;
    //         else
    //             game.board[i][j] = -1;
    //     }

    // }

    game.start();

    //game.printBoard();
    //cout << game.didWin() << " " <<  game.isTie() << endl;

    return 0;
}

