#pragma once

enum CellState {EMPTY, FILLED};

class Cell
{
    private:
        CellState state;
        CellState nextState;

    public:
        Cell();
        Cell(CellState);

        //Getters
        CellState GetState();
        CellState GetNextState();

        //Setters (we only want the next state settable. The increment
        //method can then be called
        void SetNextState(CellState);

        //Methods

        void Increment();
};