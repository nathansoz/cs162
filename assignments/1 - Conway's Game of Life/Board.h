#pragma once

//stdlib functions here
#include <iostream>
#include <vector>

//external libraries here
#include "Cell.h"


const int MARGIN = 10;

struct Cord
{
    Cord(int, int);
    int x;
    int y;
};

class Board
{
    private:
        Cell** boardWorld;

        long boardHeight;
        long boardWidth;

        bool boardInit;

        int SumNeighborCells(int, int);
    public:
        Board();
        Board(int, int);
        ~Board();

        void GenerateEmptyBoard(int, int);
        void PopulateBoard(const std::vector<Cord>&, int, int);
        void SetBlinkerBoard(int, int, int, int);
        void SetGliderGun(int, int,int, int);
        void Tick();
        void PrintBoard();

};