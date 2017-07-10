#include"omok.hpp"
#include<iostream>
#include <stdio.h>
#include <termio.h>

using namespace std;

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

Location Player::MakeDecision(GameBoard Board)
{
    return Location(0, 0);
}

Location Player::MoveCursor(Location where)
{
    return Location(0, 0);
}

void GameManager::GameStart()   
{

}

Player GameManager::WhosTurn()
{
    return Player();
}

Player GameManager::WhosWin()
{

}

bool GameManager::IsFinished()
{
    return true;
}

Location GameManager::GetPlayerDicision(Player p)
{
    return Location(0, 0);
}

void GameManager::PrintBoard()
{

}

bool GameBoard::MoveCursor(Location Where)  
{
    return true;
}

int GameBoard::WhosWin()  
{
    return BLACK;
}

bool GameBoard::SetStone(Location where)  
{
    return true;
}

int main() {
    cout << "Hello World!";

    return 0;
}