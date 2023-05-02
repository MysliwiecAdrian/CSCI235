//Adrian Mysliwiec
//4/15/23
//SudokuSolver.hpp
//Project 6: Solving Sudoku!

#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
namespace Sudoku
{ 
  struct Location
  {
    int row;
    int col;
  };
}

class SudokuSolver
{
  public:
 
    //Default constructor
    SudokuSolver();

    /**
    Parameterized constructor. 
    @param      : The name of the input file (a string)
    @post       : The private members are set to the values of the corresponding parameters.
    */
    SudokuSolver(std::string input_file);

    //helper function that solves the the entire puzzle
    bool solve();
    
    /**
    @return     : true if the puzzle is solvable, false otherwise
    */
    bool isPuzzleSolvable();

    /**
    @post      : updates solvable to true
    */
    void setSolvable();

    /**
    @return     : the 2D pointer array representing the puzzle
    */
    int** getPuzzleNumbers();

    /**
    @param      : the 2D pointer array representing the puzzle
    @post       : sets the 2D pointer array representing the puzzle
    */
    void setPuzzleNumbers(int** puzzle);

    /**
    @return    : returns a Location object with the coordinates of the first 0 
                 found in the 2D pointer array
    @post     : updates the row and col variables to the indices at which the
                first 0 is found. If there are no empty squares the Location 
                object should have row and col values of -1.
    */
    Sudoku::Location returnNextEmpty();

    /**
    @param      : the value to be checked (an int)
    @param      : the location of the value to be checked (a Location object)
    @return     : true if the value is legal at the given location, false otherwise
    */
    bool checkLegalValue(int value, Sudoku::Location location);

    /**
    @post      : prints the board where 0s are empty squares and the other numbers
                 are the values of the squares
    */
    void display();

  private:
  //Add your private members here
    int** sudoku;
    bool solvable;




};

#endif
