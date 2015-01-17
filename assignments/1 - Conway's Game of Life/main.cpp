#include <chrono>
#include <cstdlib>
#include <thread>
#include "Board.h"
#include "Cell.h"

void GameLoop(Board &board)
{
    system("clear");
    board.PrintBoard();
}

int main()
{
    //generate one board object that can be used the whole time
    Board board(22, 80);

    std::cout << "Welcome to Conway's Game of Life!" << std::endl;
    do
    {
        int userInput = -1;

        std::cout << "Please make a selection from the menu below" << std::endl;
        std::cout << "1) Simple ocilator" << std::endl;
        std::cout << "2) Glider" << std::endl;
        std::cout << "3) Glider gun" << std::endl;
        std::cout << "4) Exit" << std::endl << std::endl;
        std::cout << "Choice: ";
        std::cin >> userInput;





        switch(userInput)
        {
            case 1:
            {
                board.SetBlinkerBoard(15, 10);
                GameLoop(board);
                exit(0);
                break;
            }
            case 2:
            {
                board.SetGlider(15, 10);
                GameLoop(board);
                exit(0);
                break;
            }
            case 3:
                break;
            case 4:
                exit(0);
            default:
                break;
        }

        break;
    } while (true);

    return 0;
}