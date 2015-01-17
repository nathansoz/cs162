#include <chrono>
#include <cstdlib>
#include <thread>
#include <unistd.h>
#include "Board.h"
#include "Cell.h"

void GameLoop(Board &board)
{
    system("clear");
    board.PrintBoard();
    bool exit = false;
    do
    {
        char choice;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "(n)ext iteration / (s)pecify frames to advance, / e(x)it: ";
        std::cin >> choice;
        switch(choice)
        {
            case 'n':
                board.Tick();
                system("clear");
                board.PrintBoard();
                break;
            case 's':
            {
                int frames = 1;
                std::cout << "Enter the number of frames you would like to advance: ";
                std::cin >> frames;
                for (int x = 0; x < frames; x++)
                {
                    board.Tick();
                    system("clear");
                    board.PrintBoard();
                    usleep(100000);
                }
                break;
            }
            case 'x':
                exit = true;
                break;
            default:
                std::cout << "Invalid selection. Please try again." << std::endl;
                break;
        }
    } while(!exit);
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
                int topOffset = -1;
                int leftOffset = -1;

                while((topOffset < 0 || topOffset > 80) || (leftOffset < 0 || leftOffset > 79))
                {
                    std::cin.ignore(1000, '\n');

                    std::cout << "Offset from top of board (0 - 21): ";
                    std::cin >> topOffset;
                    std::cout << "Offset from left of board (0 - 79): ";
                    std::cin >> leftOffset;


                }
                board.SetBlinkerBoard(topOffset, leftOffset);
                GameLoop(board);
                break;
            }
            case 2:
            {
                int topOffset = -1;
                int leftOffset = -1;

                while((topOffset < 0 || topOffset > 80) || (leftOffset < 0 || leftOffset > 79))
                {
                    std::cin.ignore(1000, '\n');

                    std::cout << "Offset from top of board (0 - 21): ";
                    std::cin >> topOffset;
                    std::cout << "Offset from left of board (0 - 79): ";
                    std::cin >> leftOffset;


                }
                board.SetGlider(topOffset, leftOffset);
                GameLoop(board);
                break;
            }
            case 3:
            {
                int topOffset = -1;
                int leftOffset = -1;

                while ((topOffset < 0 || topOffset > 80) || (leftOffset < 0 || leftOffset > 79))
                {
                    std::cin.ignore(1000, '\n');

                    std::cout << "Offset from top of board (0 - 21): ";
                    std::cin >> topOffset;
                    std::cout << "Offset from left of board (0 - 79): ";
                    std::cin >> leftOffset;


                }
                board.SetGliderGun(topOffset, leftOffset);
                GameLoop(board);
                break;
            }
            case 4:
                exit(0);
            default:
                break;
        }

    } while (true);

    return 0;
}