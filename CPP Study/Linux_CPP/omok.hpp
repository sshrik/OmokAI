
// Declare constants.
#define BLACK 1
#define WHITE 2
#define EMPTY 3
#define BLOCK 0

#define MAX_PAN 19

// ●○★☆□■△▲▽▼→←↑↓◁◀▷▶┼┌┐┘└┬┤├┴ 
// αβγδεθω

// Declare class.
class Location;
class Square
{
public:
	void PrintSquare();
	int GetSquareType();
};
class GameBoard;
class Player;
class GameManager;

// Declare Functions.
int getch();
