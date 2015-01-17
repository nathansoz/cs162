#include "Board.h"

Cord::Cord(int heightFromTop, int widthFromleft)
{
    x = heightFromTop;
    y = widthFromleft;
}

Board::Board() {};

Board::Board(int height, int width)
{

    boardHeight = height + (MARGIN * 2);
    boardWidth = width + (MARGIN * 2);


    boardInit = false;
    GenerateEmptyBoard();
    boardInit = true;
}

Board::~Board()
{
    if(boardInit)
    {
        for (int i = 0; i < boardHeight; i++)
        {
            delete[] boardWorld[i];
        }

        delete[] boardWorld;
    }
}

void Board::PrintBoard()
{
    for(int i = MARGIN; i < boardHeight - MARGIN; i++)
    {
        for(int j = MARGIN; j  < boardWidth - MARGIN; j++)
        {
            if(boardWorld[i][j].GetState() == CellState::FILLED)
            {
                std::cout << "X" << " ";
            }
            else
            {
                std::cout << "." << " ";
            }
        }

        std::cout << std::endl;
    }

}

int Board::SumNeighborCells(int height, int width)
{
    int fillTotal = 0;

    for(int i = (height - 1); i <= (height + 1); i++)
    {
        for(int j = (width -1); j <= (width + 1); j++)
        {
            if(i < 0 || i >= boardHeight || j < 0 || j >= boardWidth || (i == height && j == width))
                continue;
            else
            {
                if(boardWorld[i][j].GetState() == CellState:: FILLED)
                {
                    fillTotal++;
                }
            }
        }

    }

    return fillTotal;
}

void Board::Tick()
{
    std::cout << std::endl;
    for(int i = 0; i < boardHeight; i++)
    {
        for(int j = 0; j < boardWidth; j++)
        {
            int nearCells = SumNeighborCells(i, j);
            if(boardWorld[i][j].GetState() == CellState::EMPTY)
            {
                if(nearCells == 3)
                {
                    boardWorld[i][j].SetNextState(CellState::FILLED);
                }
                else
                {
                    boardWorld[i][j].SetNextState(CellState::EMPTY);
                }
            }
            else
            {
                if(nearCells <= 1)
                {
                    boardWorld[i][j].SetNextState(CellState::EMPTY);
                }
                else if(nearCells > 3)
                {
                    boardWorld[i][j].SetNextState(CellState::EMPTY);
                }
            }

        }
    }
    for(int i = 0; i < boardHeight; i++)
    {
        for(int j = 0; j < boardWidth; j++)
        {
            boardWorld[i][j].Increment();
        }
    }
}


void Board::GenerateEmptyBoard()
{

    if(boardInit)
    {
        for (int i = 0; i < boardHeight; i++)
        {
            delete[] boardWorld[i];
        }

        delete[] boardWorld;
    }

    boardWorld = new Cell* [boardHeight];
    for(int i = 0; i < boardHeight; i++)
    {
        boardWorld[i] = new Cell[boardWidth];
    }

    for(int i = 0; i < boardHeight; i++)
    {
        for(int j = 0; j < boardWidth; j++)
        {

            boardWorld[i][j].SetNextState(CellState::EMPTY);
            boardWorld[i][j].Increment();
        }
    }

}

void Board::PopulateBoard(std::vector<Cord> const & cords, int fromTop, int fromleft)
{
    for(int i = 0; i < cords.size(); i++)
    {
        int x = cords[i].x + MARGIN + fromTop;
        int y = cords[i].y + MARGIN + fromleft;

        boardWorld[x][y].SetNextState(CellState::FILLED);
        boardWorld[x][y].Increment();
    }
}

void Board::SetBlinkerBoard(int fromTop, int fromLeft)
{

    GenerateEmptyBoard();

    boardWorld[fromTop + MARGIN][fromLeft + MARGIN - 1].SetNextState(FILLED);
    boardWorld[fromTop + MARGIN][fromLeft + MARGIN].SetNextState(FILLED);
    boardWorld[fromTop + MARGIN][fromLeft + MARGIN + 1].SetNextState(FILLED);

    boardWorld[fromTop + MARGIN][fromLeft + MARGIN - 1].Increment();
    boardWorld[fromTop + MARGIN][fromLeft + MARGIN].Increment();
    boardWorld[fromTop + MARGIN][fromLeft + MARGIN + 1].Increment();

}

void Board::SetGlider(int fromTopEdge, int fromLeftEdge)
{
    GenerateEmptyBoard();
    
    const std::vector<Cord> glider {Cord(0, 1), Cord(1, 2), Cord(2, 0), Cord(2, 1), Cord(2, 2)};

    PopulateBoard(glider, fromTopEdge, fromLeftEdge);
}

void Board::SetGliderGun(int fromTopEdge, int fromLeftEdge)
{
    GenerateEmptyBoard();

    const std::vector<Cord> glider {Cord(0,24), Cord(1,22), Cord(1,24), Cord(2,12), Cord(2,13),Cord(2,20),Cord(2,21),
                              Cord(2,34),Cord(2,35),Cord(3,11),Cord(3,15),Cord(3,20),Cord(3,21),Cord(3,34), Cord(3,35),
                              Cord(4,0),Cord(4,1),Cord(4,10),Cord(4,16),Cord(4,20),Cord(4,21),Cord(5,0),Cord(5,1),
                              Cord(5,10),Cord(5,14),Cord(5,16),Cord(5,17),Cord(5,22),Cord(5,24),Cord(6,10),Cord(6,16),
                              Cord(6,24),Cord(7,11),Cord(7,15),Cord(8,12),Cord(8,13)};

    PopulateBoard(glider, fromTopEdge, fromLeftEdge);
}




