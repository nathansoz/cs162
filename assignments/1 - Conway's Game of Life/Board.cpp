#include "Board.h"

Board::Board() {};

Board::Board(int height, int width)
{
    boardHeight = height + (MARGIN * 2);
    boardWidth = width + (MARGIN * 2);

    GenerateEmptyBoard(height, width);
}

void Board::PrintBoard()
{
    for(long i = MARGIN; i < boardHeight - MARGIN; i++)
    {
        for(long j = MARGIN; j  < boardWidth - MARGIN; j++)
        {
            if(boardWorld[i][j].GetState() == CellState::FILLED)
            {
                std::cout << "X" << " ";
            }
            else
            {
                std::cout << "0" << " ";
            }
        }

        std::cout << std::endl;
    }

}

int Board::SumNeighborCells(int height, int width)
{
    int fillTotal = 0;

    if(((height - 1) >= 0 && (height + 1) < (boardHeight - 1)) && ((width - 1) >= 0 && (width + 1) < (boardWidth - 1)))
    {
        if(boardWorld[height - 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
    } //top row consideration
    else if(((height - 1) < 0) && ((width - 1) >= 0 && (width + 1) < (boardWidth - 1)))
    {
        if(boardWorld[height][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
    } //bottom row consideration
    else if(((height + 1) >= (boardHeight - 1)) && ((width - 1) >= 0 && (width + 1) < (boardWidth - 1)))
    {
        if(boardWorld[height - 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
    } //left row consideration
    else if(((height - 1) >= 0 && (height + 1) < (boardHeight - 1)) && ((width - 1) < 0))
    {
        if(boardWorld[height - 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }

    } //right row consideration
    else if(((height - 1) >= 0 && (height + 1) < (boardHeight - 1)) && ((width + 1) >= (boardWidth - 1)))
    {
        if(boardWorld[height - 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width].GetState() == CellState::FILLED) { fillTotal++; }
    }
    else if(height == 0 && width == 0)
    {
        if(boardWorld[height][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
    }
    else if(height == 0 && width == (boardWidth - 1))
    {
        if(boardWorld[height][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height + 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
    }
    else if(height == (boardHeight - 1) && width == 0)
    {
        if(boardWorld[height][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width + 1].GetState() == CellState::FILLED) { fillTotal++; }
    }
    else if(height == (boardHeight - 1) && width == (boardWidth - 1))
    {
        if(boardWorld[height][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width].GetState() == CellState::FILLED) { fillTotal++; }
        if(boardWorld[height - 1][width - 1].GetState() == CellState::FILLED) { fillTotal++; }
    }

    return fillTotal;
}

void Board::Tick()
{
    std::cout << std::endl;
    for(long i = 0; i < boardHeight; i++)
    {
        for(long j = 0; j < boardWidth; j++)
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
    for(long i = 0; i < boardHeight; i++)
    {
        for(long j = 0; j < boardWidth; j++)
        {
            boardWorld[i][j].Increment();
        }
    }
}

//Static board Generation methods

void Board::GenerateEmptyBoard(int height, int width)
{
    long heightWithMargin = height + (MARGIN * 2);
    long widthWithMargin = width + (MARGIN *2);

    boardWorld = new Cell* [heightWithMargin];
    for(int i = 0; i < heightWithMargin; i++)
    {
        boardWorld[i] = new Cell[widthWithMargin];
    }

    for(long i = 0; i < heightWithMargin; i++)
    {
        for(long j = 0; j < widthWithMargin; j++)
        {

            boardWorld[i][j].SetNextState(CellState::EMPTY);
            boardWorld[i][j].Increment();
        }
    }

}

void Board::SetBlinkerBoard(int height, int width, int xCenterOffset, int yCenterOffset)
{
    GenerateEmptyBoard(height, width);

    boardWorld[yCenterOffset + MARGIN][xCenterOffset + MARGIN - 1].SetNextState(FILLED);
    boardWorld[yCenterOffset + MARGIN][xCenterOffset + MARGIN].SetNextState(FILLED);
    boardWorld[yCenterOffset + MARGIN][xCenterOffset + MARGIN + 1].SetNextState(FILLED);

    boardWorld[yCenterOffset + MARGIN][xCenterOffset + MARGIN - 1].Increment();
    boardWorld[yCenterOffset + MARGIN][xCenterOffset + MARGIN].Increment();
    boardWorld[yCenterOffset + MARGIN][xCenterOffset + MARGIN + 1].Increment();

}



