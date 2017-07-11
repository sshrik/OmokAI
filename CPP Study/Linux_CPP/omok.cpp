#include<vector>
#include<iostream>
#include <stdio.h>
#include <termio.h>

#include"omok.hpp"

using namespace std;

class Location
{
private:
	int x, y;
public:
	Location() 
	{
		this -> x = 0;
		this -> y = 0;
	}

	Location(int x, int y)
	{
		this -> x = x;
		this -> y = y;
	}

	int GetX()	{ return x; }

	int GetY()	{   return y;   }

	void SetXY(int x, int y)    
    {
		this->x = x;
		this->y = y;
	}

	void SetX(int x)    
    {   
        if(x >= 0 && x < MAX_PAN)
        {
            this -> x = x;
        }
        else
        {
            this -> x = 0;
        }
    }

	void SetY(int y)	
    {    
        if(y >= 0 && y < MAX_PAN)
        {
            this -> y = y;
        }
        else
        {
            this -> y = 0;
        }
    }
};

class BlackStone:Square
{
public:
	void PrintSquare()	{
		cout << "●";
	}
	int GetSquareType()	{
		return BLACK;
	}
};

class WhiteStone:Square
{
public:
	void PrintSquare()	{
		cout << "○";
	}
	int GetSquareType()	{
		return WHITE;
	}
};

class EmptyStone:Square
{
public:
	void PrintSquare()	{
		cout << "┼";
	}
	int GetSquareType()	{
		return EMPTY;
	}
};

class BlockStone:Square
{
public:
	void PrintSquare()	{
		cout << "■";
	}
	int GetSquareType()	{
		return BLOCK;
	}
};

class GameBoard
{
public:
	void MoveCursor(Location where)
    {
        this -> cursor = where;
        // Copy Constructor is default instered.
    }

	int WhosWin()
    {
        int i, j;
        for(i = 0; i < MAX_PAN; i++)
        {
            for(j = 0; j < MAX_PAN; j++)
            {

            }
        }
    }
    
	bool SetStone(Location where, int color)
    {
        if(board[where.GetX()][where.GetY()].GetSquareType() == BLACK)  {

        }
    }

    void AddHistory(Location where)
    {

    }
    
private:
	Location cursor;
	vector<Location> actionHistory;
	vector<int> stoneHistory;
	int width, height;
	Square board[MAX_PAN][MAX_PAN];
};

class Player
{
public:
	Location MakeDecision(GameBoard Board)
    {

    }
    
	Location MoveCursor(Location where)
    {

    }
    
	int GetPlayerType()
    {

    }
    
};

class BlackPlayer:Player
{
	int GetPlayerType()	{
		return BLACK;
	}
};

class WhitePlayer:Player
{
	int GetPlayerType()	{
		return WHITE;
	}
};

class GameManager
{
public:
	void GameStart();
	Player WhosTurn();
	Player WhosWin();
	bool IsFinished();
	Location GetPlayerDicision(Player p);
	void PrintBoard();
private:
	Player m_a, m_b;
	GameBoard board;
};


int getch(){
    int ch;
    struct termios buf, save;
    tcgetattr(0,&save);

    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}