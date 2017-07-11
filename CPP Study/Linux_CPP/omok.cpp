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

	int GetX()	{
		return x;
	}

	int GetY()	{
		return y;
	}

	void SetXY(int x, int y)	{
		this->x = x;
		this->y = y;
	}

	void SetX(int x)	{
		this->x = x;
	}

	void SetY(int y)	{
		this->y = y;
	}
};

class Square
{
public:
	void PrintSquare();
	int GetSquareType();
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
	bool MoveCursor(Location Where);
	int WhosWin();
	bool SetStone(Location where);
private:
	Location cursor;
	vector<Location> actionHistory;
	vector<int> stoneHistory;
	int width, height;
	Square board[19][19];
};

class Player
{
public:
	Location MakeDecision(GameBoard Board);
	Location MoveCursor(Location where);
	int GetPlayerType();
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