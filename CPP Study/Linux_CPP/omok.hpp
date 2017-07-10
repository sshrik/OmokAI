#include<vector>
#include<iostream>

#define BLACK 1
#define WHITE 2
#define EMPTY 3
#define BLOCK 0

using namespace std;

int getch();

// ●○★☆□■△▲▽▼→←↑↓◁◀▷▶┼┌┐┘└┬┤├┴ 
// αβγδεθω

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
