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


        int boardHeight;
        int boardWidth;
        int frame;

        bool boardInit;

        int SumNeighborCells(int, int);
    public:
        Board();
        Board(int, int);
        ~Board();

        void GenerateEmptyBoard();
        void PopulateBoard(const std::vector<Cord>&, int, int);
        void SetBlinkerBoard(int, int);
        void SetGlider(int, int);
        void SetGliderGun(int, int);
        void Tick();
        void PrintBoard();

};