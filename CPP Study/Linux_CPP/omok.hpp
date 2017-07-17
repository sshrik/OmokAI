
// Declare constants.
#define BLACK 1
#define WHITE 2
#define EMPTY 3
#define BLOCK 0

#define MAX_PAN 19

#define EAST	2
#define WEST	3
#define SOUTH	5
#define NORTH	7
// We can use it like EAST * SOUTH or just SOUTH.


// ●○★☆□■△▲▽▼→←↑↓◁◀▷▶┼┌┐┘└┬┤├┴ 
// αβγδεθω
// ┠╋╋┿╊╉╈╇╆╅╄╃╀┾┽┺╂┼

// Declare class.
class Location;
class Square
{
public:
	virtual void PrintSquare() = 0;
	virtual int GetSquareType() = 0;
};
class GameBoard;
class Player;
class GameManager;

// Declare Functions.
int getch();
