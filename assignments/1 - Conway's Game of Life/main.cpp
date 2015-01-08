#include <chrono>
#include <cstdlib>
#include <thread>
#include "Board.h"
#include "Cell.h"

int main()
{
    std::chrono::milliseconds restTime(500);

    Board board(22, 80); // = Board(22, 80);
    //board.SetBlinkerBoard(22, 80, 40, 11);
    board.SetGliderGun(22, 80, 5, 20);
    while(true)
    {
        board.PrintBoard();
        board.Tick();
        std::this_thread::sleep_for(restTime);
        system("clear");

    }
    return 0;
}