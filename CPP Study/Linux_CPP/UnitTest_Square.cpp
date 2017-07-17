#include"omok.cpp"
#include<iostream>
#include<cstdlib>
#include<ctime>
// #include<time.h>

using namespace std;

int main()  {
    Square* board[MAX_PAN][MAX_PAN];
    int type = 0;
    srand((unsigned int)time(NULL));

    for(int i = 0; i < MAX_PAN; i++)    {
        for(int j = 0; j < MAX_PAN; j++)    {
            type = rand() % 4;
            cout << "Board has been declared... ";
            if(type == BLOCK)   {
                cout << "BLOCK in (" << i << ", " << j << ")" << endl;
                board[i][j] = new BlockStone;
            }
            else if(type == BLACK)   {
                cout << "BLACK in (" << i << ", " << j << ")" << endl;
                board[i][j] = new BlackStone;
            }
            else if(type == WHITE)   {
                cout << "WHITE in (" << i << ", " << j << ")" << endl;
                board[i][j] = new WhiteStone;
            }
            else {
                cout << "EMPTY in (" << i << ", " << j << ")" << endl;
                board[i][j] = new EmptyStone;
            }
        }
    }

    for(int i = 0; i < MAX_PAN; i++)    {
        for(int j = 0; j < MAX_PAN; j++)    {
            board[i][j] -> PrintSquare();
            cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < MAX_PAN; i++)    {
        for(int j = 0; j < MAX_PAN; j++)    {
            delete board[i][j];
        }
    }
    
}