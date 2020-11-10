#include <iostream>
#include <vector>
#include<algorithm> 

using namespace std;

// Game class
class Game
{
    int board[10][10];
    char player;
    char cpu;
public:
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
    for(auto &row : board)
        for(auto &val : row)
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
    for (int i = 0; i < 10; i++)
        cout << i << " | ";

    cout << endl << " ";
    for (int i = 0; i < 10; i++)
        cout << " |  ";
    cout << endl;

    cout << " ";
    for (int i = 0; i < 10; i++)
        cout << " v  ";
    cout << endl;

    for(auto &row : board)
    {
        cout << "| ";
        for(auto &val : row)
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
    for (int i = 9; i > 0; i--)
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
    for (int i = 0; i < 10; i++)
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

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
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
                    if(i + 3 <= 9)
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
                    if(j + 3 <= 9)
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
                    if(j + 3 <= 9 && i - 3 >= 0)
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
                    if(j + 3 <= 9 && i + 3 >= 9)
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
                    if(j + 3 >= 0 && i + 3 <= 9)
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
    for(auto &row : board)
        for(auto &val : row)
            if(val == 0)
                return false;
    return true;
}

int Game  :: minimax(int depth, bool player)
{
    int won = didWin();
    
    if(won != 0 || isTie())
        return won;
    // Maximizing player
    if(player)
    {
        int presentScore, bestScore = -9999999;
        for (int i = 0; i < 10; i++)
        {
            // Checking if the position is free
            if(board[0][i] == 0)
            {
                makeMove(i, false);
                presentScore = minimax(depth+1, false);
                removeMove(i);
                bestScore = max(presentScore, bestScore);
            }
        }
        return bestScore;
    }

    // Minimizing player
    else
    {
        int presentScore, bestScore = 9999999;
        for (int i = 0; i < 10; i++)
        {
            // Checking if the position is free
            if(board[0][i] == 0)
            {
                makeMove(i, true);
                presentScore = minimax(depth+1, true);
                removeMove(i);
                bestScore = min(presentScore, bestScore);
            }
        }
        return bestScore;
    }
    
}

int Game :: getCompMove()
{
    int bestScore = -99999999;
    int bestMove = 0;
    int presentScore;
    for (int i = 0; i < 10; i++)
    {
        // Checking if the position is free
        if(board[0][i] == 0)
        {
            makeMove(i, false);
            presentScore = minimax(0, false);
            removeMove(i);
            if(presentScore > bestScore)
            {
                bestMove = i;
                bestScore = presentScore;
            }
        }
        
    }
    return bestMove;

    return 1;
}



// Skeleton of the Game
void Game :: start()
{
    int playerMove, compMove, won = 0;
    
    while (won == 0 && !isTie())
    {
        cout << "Please enter the move you are about to play: ";
        cin >> playerMove;
        makeMove(playerMove, true);
        printBoard();
        compMove = getCompMove();
        makeMove(compMove,false);
        system("clear");
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
    
    game.start();

    return 0;
}

