#include "Board.h"
#include "Cell.h"

int main()
{
    Board *board = new Board(22, 80);
    board->SetBlinkerBoard(22, 80, 40, 11);
    board->PrintBoard();
    board->Tick();
    board->PrintBoard();
    board->Tick();
    board->PrintBoard();
    delete board;
    return 0;
}