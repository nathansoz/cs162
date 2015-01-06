#include <stdio.h>
#include "Cell.h"

Cell::Cell() {};

Cell::Cell(CellState initState)
{
    state = initState;
}

CellState Cell::GetNextState()
{
    return nextState;
}

CellState Cell::GetState()
{
    return state;
}

void Cell::Increment()
{
    state = nextState;
}

void Cell::SetNextState(CellState setState)
{
    nextState = setState;
}