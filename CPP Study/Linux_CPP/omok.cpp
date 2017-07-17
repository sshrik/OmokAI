#include<vector>
#include<iostream>
#include <stdio.h>
#include <termio.h>
#include "omok.hpp"

using namespace std;

class Location {
private:
	// Member Variable which have x, y coordinate information.
	int x, y;
public:
	Location() {
		// Default Initializer, init with (0, 0).
		this -> x = 0;
		this -> y = 0;
	}

	Location(int x, int y) {
		// Initialize with input value (x, y).
		this -> x = x;
		this -> y = y;
	}

	int GetX()	{ return x; }

	int GetY()	{   return y;   }

	void SetXY(int x, int y)    {
		this->x = x;
		this->y = y;
	}

	void SetX(int x) {   
        if(x >= 0 && x < MAX_PAN)
        {
            this -> x = x;
        }
        else
        {
            this -> x = 0;
        }
    }

	void SetY(int y) {    
        if(y >= 0 && y < MAX_PAN)
        {
            this -> y = y;
        }
        else
        {
            this -> y = 0;
        }
    }
	int move(int direction, Location border)	{
		// move loctaion with given direction.
		if(direction == EAST)	{
			// x + 1, if x is larger then border.GetX(), return -1. else, return 0.
			if(this -> x + 1 >= border.GetX())	{
				return -1;
			}
			else {
				this -> x = this -> x + 1;
				return 0;
			}
		}
		else if(direction == WEST) {
			// x - 1, if x is lower then 0, return -1. else, return 0.
			if(this -> x - 1 < 0)	{
				return -1;
			}
			else {
				this -> x = this -> x - 1;
				return 0;
			}
		}
		else if(direction == SOUTH) {
			// y + 1, if x is larger then border.GetY(), return -1. else, return 0.
			if(this -> y + 1 >= border.GetY())	{
				return -1;
			}
			else {
				this -> y = this -> y + 1;
				return 0;
			}
		}
		else if(direction == NORTH) {
			// y - 1, if x is lower then 0, return -1. else, return 0.
			if(this -> y - 1 < 0)	{
				return -1;
			}
			else {
				this -> y = this -> y - 1;
				return 0;
			}
		}
		else if(direction == EAST * SOUTH) {
			// x + 1, if x is larger then border.GetX(), return -1. else, return 0.
			// y + 1, if x is larger then border.GetY(), return -1. else, return 0.
			if(this->move(EAST, border) + this->move(SOUTH, border)	< 0)	{
				// Recursive call of move.
				return -1;
			}
			else {
				return 0;
			}
		}
		else if(direction == EAST * NORTH) {
			// x + 1, if x is larger then border.GetX(), return -1. else, return 0.
			// y - 1, if x is lower then 0, return -1. else, return 0.
			if(this->move(EAST, border) + this->move(NORTH, border)	< 0)	{
				// Recursive call of move.
				return -1;
			}
			else {
				return 0;
			}
		}
		else if(direction == WEST * SOUTH) {
			// x - 1, if x is lower then 0, return -1. else, return 0.
			// y + 1, if x is larger then border.GetY(), return -1. else, return 0.
			if(this->move(WEST, border) + this->move(SOUTH, border)	< 0)	{
				// Recursive call of move.
				return -1;
			}
			else {
				return 0;
			}
		}
		else if(direction == WEST * NORTH) {
			// x - 1, if x is lower then 0, return -1. else, return 0.
			// y - 1, if x is lower then 0, return -1. else, return 0.
			if(this->move(WEST, border) + this->move(NORTH, border)	< 0)	{
				// Recursive call of move.
				return -1;
			}
			else {
				return 0;
			}
		}
		else {
			// -2 mean error of return.
			return -2;
		}
	}
};

class BlackStone:public Square
{
public:
	virtual void PrintSquare()	{
		// Print Black Stone. This is Unicode( UTF-8 ), so print " ", too.
		cout << "○ ";
	}
	virtual int GetSquareType()	{
		return BLACK;
	}
};

class WhiteStone:public Square
{
public:
	virtual void PrintSquare()	{
		// Print White Stone. This is Unicode( UTF-8 ), so print " ", too.
		cout << "● ";
	}
	virtual int GetSquareType()	{
		return WHITE;
	}
};

class EmptyStone:public Square
{
public:
	virtual void PrintSquare()	{
		// Print Empty Stone. This is Unicode( UTF-8 ), so print " ", too.
		cout << "╋ ";
	}
	virtual int GetSquareType()	{
		return EMPTY;
	}
};

class BlockStone:public Square
{
public:
	virtual void PrintSquare()	{
		// Print Block Stone. This is Unicode( UTF-8 ), so print " ", too.
		cout << "■ ";
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
		// Default GameBoard Constructor. Initialize with default value (MAX_PAN, MAX_PAN).
		// And set Cursor defaul ( 0, 0 ). Cursor is not pointer variable, so not need to have "new" keyword.
		this -> border.SetX(MAX_PAN);
		this -> border.SetY(MAX_PAN);
		this -> cursor = Location(0,0);
	}
	GameBoard(int _width, int _height)	{
		// Initialize with expected value (_width, _height)
		// And set Cursor defaul ( 0, 0 ). Cursor is not pointer variable, so not need to have "new" keyword.
		this -> border.SetX(_width);
		this -> border.SetY(_height);
		this -> cursor = Location(0,0);
	}

	int MoveCursor(int direction, int color) {
		// Move Cursor with give color and direction.
		// And Move Cursor with given direction.
		return this->cursor.move(direction, this -> border);
    }

	int WhosWin() {
        int i, j;
        for(i = 0; i < MAX_PAN; i++) {
            for(j = 0; j < MAX_PAN; j++) {
				// Check wins...
            }
        }
    }
    
	bool SetStone(int color) {
		// Set Stone at now cursor, with given color.
        if(this -> board[cursor.GetX()][cursor.GetY()]->GetSquareType() == EMPTY)  {
			// If GetSquareType is EMPTY, set Stone with given color and return true.
			delete board[cursor.GetX()][cursor.GetY()];
			// Delete First for unlock memory.
			if(color == BLACK)	{
				// Set Stone with given Color.
				this -> board[cursor.GetX()][cursor.GetY()] = new BlackStone;
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

    void AddHistory(Location where) {
		// For extenstion, Add History will be needed to get back to past time.

    }

	Location GetCursor() {	return this -> cursor; }
    
private:
	Location cursor;
	Location border;
	vector<Location> actionHistory;
	vector<Square*> stoneHistory;
	Square* board[MAX_PAN][MAX_PAN];
};

class Player {
public:
	Location MakeDecision(GameBoard Board) {
		Board.SetStone(this->GetPlayerType());
	}
	Location MoveCursor(GameBoard Board) {
		// Moving cursor around. If input is "wasd" or arrows, move.
		// if input is space or enter, do MakeDecision();	
	}
	virtual int GetPlayerType() = 0;
    
};

class BlackPlayer:Player {
public:
	virtual int GetPlayerType() {
		return BLACK;
	}
};

class WhitePlayer:Player
{
public:
	virtual int GetPlayerType() {
		return WHITE;
	}
};

class GameManager
{
public:
	void GameStart() {

	}

	Player* WhosTurn() {

	}
	
	Player* WhosWin() {

	}
	
	bool IsFinished() {

	}
	
	Location GetPlayerDicision(Player* p) {

	}
	
	void PrintBoard() {
		// print board with each square information.
	}
	
private:
	Player* black_player;
	Player* white_player;
	Player* now_turn;
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