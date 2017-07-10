#include<vector>

#define BLACK 1
#define WHITE 2
#define EMPTY 3
#define BLOCK 0

class Square
{
public:
	void PrintSquare();
	int GetSquareType();
}

class BlackStone:Square
{
	int GetSquareType()	{
		return BLACK;
	}
}

class WhiteStone:Square
{
	int GetSquareType()	{
		return WHITE;
	}
}

class EmptyStone:Square
{
	int GetSquareType()	{
		return EMPTY;
	}
}

class BlockStone:Square
{
	int GetSquareType()	{
		return BLOCK;
	}
}

class Player
{
public:
	Location MakeDecision(GameBoard Board);
	Location MoveCursor(Location where);
	int GetPlayerType();
}

class BlackPlayer:Player
{
	int GetPlayerType()	{
		return BLACK;
	}
}

class WhitePlayer:Player
{
	int GetPlayerType()	{
		return WHITE;
	}
}

class Location
{
private:
	int x, y;
public:
	int GetX();
	int GetY();
	void SetXY(int x, int y);
	void SetX(int x);
	void SetY(int y);
}

class GameManager
{
public:
	void GameStart();
	Player WhosTurn();
	Player WhosWin();
	boolean IsFinished();
	Location GetPlayerDicision(Player p);
	void PrintBoard();
private:
	Player m_a, m_b;
	GameBoard board;
}

class GameBoard
{
public:
	boolean MoveCursor(Location Where);
	Player WhosWin();
	boolean SetStone(Location where);
private:
	Location cursor;
	vector<Location> actionHistory;
	int width, height;
	Square board[19][19];
}
