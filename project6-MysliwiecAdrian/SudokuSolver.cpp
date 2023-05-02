//Adrian Mysliwiec
//4/15/23
//SudokuSolver.cpp
//Project 6: Solving Sudoku!

#include "SudokuSolver.hpp"

//Default constructor
SudokuSolver::SudokuSolver(){
    sudoku = new int*[9];
    for(int i = 0; i < 9; i++){
        sudoku[i] = new int[9];
        for(int j = 0; j < 9; j++){
            sudoku[i][j] = 0;
        }
    }
    solvable = false;
}

/**
    Parameterized constructor. 
    @param      : The name of the input file (a string)
    @post       : The private members are set to the values of the corresponding parameters. 
*/
SudokuSolver::SudokuSolver(std::string input_file){
    sudoku = new int*[9];
    for(int i = 0; i < 9; ++i){
        sudoku[i] = new int[9];
    }

    std::ifstream file(input_file);
    std::string temp;
    int num;
    int i = 0;
    while(std::getline(file, temp)){
        std::stringstream ss(temp);
        for(int j = 0; j < 9; j++){
            std::getline(ss, temp, ',');
            num = std::stoi(temp);
            sudoku[i][j] = num;
        }
        i++;
    }
    solvable = solve();
}

//helper function that solves the the entire puzzle
bool SudokuSolver::solve(){
    int row, col;
    Sudoku::Location location = returnNextEmpty();
    row = location.row;
    col = location.col;
    if(row == -1 && col == -1){
        return true;
    }
    for(int i = 1; i <= 9; i++){
        if(checkLegalValue(i, location)){
            sudoku[row][col] = i;
            if(solve()){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

/**
    @return     : true if the puzzle is solvable, false otherwise
*/
bool SudokuSolver::isPuzzleSolvable(){
    return solvable;
}


/**
    @post      : updates solvable to true
*/
void SudokuSolver::setSolvable(){
    solvable = true;
}

/**
    @return     : the 2D pointer array representing the puzzle
*/
int** SudokuSolver::getPuzzleNumbers(){
    return sudoku;
}

/**
    @param      : the 2D pointer array representing the puzzle
    @post       : sets the 2D pointer array representing the puzzle
*/
void SudokuSolver::setPuzzleNumbers(int** puzzle){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            sudoku[i][j] = puzzle[i][j];
        }
    }
}

/**
    @return    : returns a Location object with the coordinates of the first 0 
                 found in the 2D pointer array
    @post     : updates the row and col variables to the indices at which the
                first 0 is found. If there are no empty squares the Location 
                object should have row and col values of -1.
*/
Sudoku::Location SudokuSolver::returnNextEmpty(){
    Sudoku::Location location;
    location.row = -1;
    location.col = -1;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(sudoku[i][j] == 0){
                location.row = i;
                location.col = j;
                return location;
            }
        }
    }
    return location;
}

/**
    @param      : the value to be checked (an int)
    @param      : the location of the value to be checked (a Location object)
    @return     : true if the value is legal at the given location, false otherwise
*/
bool SudokuSolver::checkLegalValue(int value, Sudoku::Location location){
    for(int i = 0; i < 9; i++){
        if(sudoku[location.row][i] == value)
            return false;
    }
    for(int j = 0; j < 9; j++){
        if(sudoku[j][location.col] == value)
            return false;
    }
    int row = location.row - location.row % 3;
    int col = location.col - location.col % 3;
    for(int i = row; i < row + 3; i++){
        for(int j = col; j < col + 3; j++){
            if(sudoku[i][j] == value)
                return false;
        }
    }
    return true;
}

/**
    @post      : prints the board where 0s are empty squares and the other numbers
                 are the values of the squares
*/
void SudokuSolver::display(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (sudoku[i][j] == 0){
                std::cout << "X ";
            }
            else{
                std::cout << sudoku[i][j] << " ";
            }
            if (j % 3 == 2 && j != 9 - 1){
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i % 3 == 2 && i != 9 - 1){
            std::cout << "- - - - - - - - - - - -" << std::endl;
        }
    }
}
