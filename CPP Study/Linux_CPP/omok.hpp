
// Declare constants.
#define BLACK 1
#define WHITE 2
#define EMPTY 3
#define BLOCK 0


// ●○★☆□■△▲▽▼→←↑↓◁◀▷▶┼┌┐┘└┬┤├┴ 
// αβγδεθω

// Declare class.
class Location;
class Square;
class BlackStone:Square;
class WhiteStone:Square;
class EmptyStone:Square;
class BlockStone:Square;
class GameBoard;
class Player;
class BlackPlayer:Player;
class WhitePlayer:Player;
class GameManager;

// Declare Functions.
int getch();
