cmake_minimum_required(VERSION 2.8.4)
project(cs162)

find_package(Boost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES main.cpp)

set(LAB_1_2_FILES
    labs/lab1/f.h
    labs/lab1/g.h
    labs/lab1/f.cpp
    labs/lab1/g.cpp
    labs/lab1/lab1-2.cpp
)

set(LAB_3_FILES
    "labs/lab3/fileSort.cpp"
)

set(assignment_1_FILES
    "assignments/1 - Conway's Game of Life/main.cpp"
    "assignments/1 - Conway's Game of Life/Cell.cpp"
    "assignments/1 - Conway's Game of Life/Cell.h"
    "assignments/1 - Conway's Game of Life/Board.cpp"
    "assignments/1 - Conway's Game of Life/Board.h"
)

set(assignment_2_FILES
    "assignments/2 - Grocery List/Item.cpp"
    "assignments/2 - Grocery List/List.cpp"
    "assignments/2 - Grocery List/main.cpp"
    "assignments/2 - Grocery List/Item.h"
    "assignments/2 - Grocery List/List.h"
)

set(assignment_3_FILES
    "assignments/3 - Inheritance/Dice.cpp"
    "assignments/3 - Inheritance/Dice.h"
    "assignments/3 - Inheritance/SozLibs/Stats.h"
    "assignments/3 - Inheritance/SozLibs/Stats.cpp"
    "assignments/3 - Inheritance/Character.cpp"
    "assignments/3 - Inheritance/Character.h"
    "assignments/3 - Inheritance/Barbarian.cpp"
    "assignments/3 - Inheritance/Barbarian.h"
    "assignments/3 - Inheritance/ReptilePeople.cpp"
    "assignments/3 - Inheritance/ReptilePeople.h"
    "assignments/3 - Inheritance/BlueMen.h"
    "assignments/3 - Inheritance/BlueMen.cpp"
    "assignments/3 - Inheritance/Goblin.cpp"
    "assignments/3 - Inheritance/Goblin.h"
    "assignments/3 - Inheritance/Shadow.cpp"
    "assignments/3 - Inheritance/Shadow.h"
    "assignments/3 - Inheritance/TestDriver.cpp"
)

set(assignment_4_FILES
    "assignments/4 - Containers/SozLibs/Dice.cpp"
    "assignments/4 - Containers/SozLibs/Dice.h"
    "assignments/4 - Containers/GameChars/Character.cpp"
    "assignments/4 - Containers/GameChars/Character.h"
    "assignments/4 - Containers/GameChars/Barbarian.cpp"
    "assignments/4 - Containers/GameChars/Barbarian.h"
    "assignments/4 - Containers/GameChars/ReptilePeople.cpp"
    "assignments/4 - Containers/GameChars/ReptilePeople.h"
    "assignments/4 - Containers/GameChars/BlueMen.h"
    "assignments/4 - Containers/GameChars/BlueMen.cpp"
    "assignments/4 - Containers/GameChars/Goblin.cpp"
    "assignments/4 - Containers/GameChars/Goblin.h"
    "assignments/4 - Containers/GameChars/Shadow.cpp"
    "assignments/4 - Containers/GameChars/Shadow.h"

    "assignments/4 - Containers/main.cpp"

)

set(lab_4_FILES
    "labs/lab4/Dice.cpp"
    "labs/lab4/Dice.h"
    "labs/lab4/LoadedDice.cpp"
    "labs/lab4/LoadedDice.h"
    "labs/lab4/SozLibs/Stats.h"
    "labs/lab4/SozLibs/Stats.cpp"
    "labs/lab4/main.cpp"
)

set(lab_5_FILES
    "labs/lab5/FileFilter.cpp"
    "labs/lab5/FileFilter.h"
    "labs/lab5/CopyFileFilter.h"
    "labs/lab5/CopyFileFilter.cpp"
    "labs/lab5/EncryptFileFilter.cpp"
    "labs/lab5/EncryptFileFilter.h"
    "labs/lab5/UpcaseFileFilter.h"
    "labs/lab5/UpcaseFileFilter.cpp"
    "labs/lab5/GroupEncryptFileFilter.h"
    "labs/lab5/GroupEncryptFileFilter.cpp"
    "labs/lab5/main.cpp"
)

set(lab_6_sort_FILES
    "labs/lab6/sort.cpp"
)
set(lab_6_search_FILES
    "labs/lab6/search.cpp"
)
set(lab_6_binarySearch_FILES
    "labs/lab6/binarySearch.cpp"
)

set(lab_7_generate_FILES
    "labs/lab7/generate.cpp"
)

set(lab_7_search_FILES
    "labs/lab7/search.cpp"
)

set(lab_7_sort_FILES
    "labs/lab7/sort.cpp"
)

set(lab_7_binarySearch_FILES
    "labs/lab7/binarySearch.cpp"
)

set(lab_8_FILES
    "labs/lab8/Maze.h"
    "labs/lab8/Maze.cpp"
    "labs/lab8/gameLoop.cpp"
)

set(lab_9_FILES
    "labs/lab9/SozLibs/Dice.cpp"
    "labs/lab9/SozLibs/Dice.h"
    "labs/lab9/Node.h"
    "labs/lab9/Stack.h"
    "labs/lab9/Queue.h"
    "labs/lab9/LinkedList.h"
    "labs/lab9/DLinkedList.h"
    "labs/lab9/TestDriver.cpp"

)

set(lab_10_FILES
    "labs/lab10/main.cpp"
)

add_executable(lab1-1 labs/lab1/lab1-1.cpp)
add_executable(lab1-2 ${LAB_1_2_FILES})
add_executable(lab3 ${LAB_3_FILES})
add_executable(assignment-1 ${assignment_1_FILES})
add_executable(assignment-2 ${assignment_2_FILES})
add_executable(lab4 ${lab_4_FILES})
add_executable(lab5 ${lab_5_FILES})
add_executable(assignment-3 ${assignment_3_FILES})
add_executable(lab6-sort ${lab_6_sort_FILES})
add_executable(lab6-search ${lab_6_search_FILES})
add_executable(lab6-binarySearch ${lab_6_binarySearch_FILES})
add_executable(lab7-generate ${lab_7_generate_FILES})
add_executable(lab7-search ${lab_7_search_FILES})
add_executable(lab7-sort ${lab_7_sort_FILES})
add_executable(lab7-binarySearch ${lab_7_binarySearch_FILES})
add_executable(assignment4 ${assignment_4_FILES})
add_executable(lab8 ${lab_8_FILES})
add_executable(lab9 ${lab_9_FILES})
add_executable(lab10 ${lab_10_FILES})