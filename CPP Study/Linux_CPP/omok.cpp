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

class BlackStone:public Square
{
public:
	virtual void PrintSquare()	{
		cout << "●";
	}
	virtual int GetSquareType()	{
		return BLACK;
	}
};

class WhiteStone:public Square
{
public:
	virtual void PrintSquare()	{
		cout << "○";
	}
	virtual int GetSquareType()	{
		return WHITE;
	}
};

class EmptyStone:public Square
{
public:
	virtual void PrintSquare()	{
		cout << "┼";
	}
	virtual int GetSquareType()	{
		return EMPTY;
	}
};

class BlockStone:public Square
{
public:
	virtual void PrintSquare()	{
		cout << "■";
	}
	virtual int GetSquareType()	{
		return BLOCK;
	}
};

class GameBoard
{
public:
	// Constructor with widht and height.
	GameBoard()	{
		this -> width = MAX_PAN;
		this -> height = MAX_PAN;
	}
	GameBoard(int width, int height)	{
		this -> width = width;
		this -> height = height;
	}

	void MoveCursor(Location where, int direction, int color)
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
				// Check wins...
            }
        }
    }
    
	bool SetStone(int color)
    {	
        if(this -> board[cursor.GetX()][cursor.GetY()]->GetSquareType() == EMPTY)  {
			// If GetSquareType is EMPTY, set Stone with given color and return true.

			delete board[cursor.GetX()][cursor.GetY()];
			// Delete First for unlock memory.

			if(color == BLACK)	{
				// Set Stone with given Color.
				this -> board[cursor.GetX()][cursor.GetY()] = new BlakcStone;
			}
			else if(color == WHITE)	{
				// Set Stone with given Color.
				this -> board[cursor.GetX()][cursor.GetY()] = new WhiteStone;
			}
			return true;
        }
		else{
			// There is Blocked or early stones are set.
			return false;
		}
    }

    void AddHistory(Location where)
    {
		// For extenstion, Add History will be needed to get back to past time.

    }

	Location GetCursor() {	return this -> cursor; }
    
private:
	Location cursor;
	vector<Location> actionHistory;
	vector<Square> stoneHistory;
	int width, height;
	Square* board[MAX_PAN][MAX_PAN];
};

class Player
{
public:
	Location MakeDecision(GameBoard Board)
	{
		Board.SetStone(this->GetPlayerType());
	}
	Location MoveCursor(GameBoard Board)
    {
		
	}
	virtual int GetPlayerType() = 0;
    
};

class BlackPlayer:Player
{
public:
	virtual int GetPlayerType()
	{
		return BLACK;
	}
};

class WhitePlayer:Player
{
public:
	virtual int GetPlayerType()
	{
		return WHITE;
	}
};

class GameManager
{
public:
	void GameStart()
	{

	}

	Player WhosTurn()
	{

	}
	
	Player WhosWin()
	{

	}
	
	bool IsFinished()
	{

	}
	
	Location GetPlayerDicision(Player p)
	{

	}
	
	void PrintBoard()
	{

	}
	
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