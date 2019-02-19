//CSCI 301
//PROJECT 1
//SUDOKU CHECKER
//Hissamuddin Shaikh
//This program reads in a Sudoku solution from a file, and check whether or not the solution is valid,
//by searching for duplicate numbers in the rows, columns and 3x3 sub-grids, and outputing the 9x9 matrix,
//along with a statement about whether its correct or not.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void openSudoku(ifstream&, string);
//Pre-Condition: Takes in the object, through which the data in the file will be accessed.
//               Takes in the name of the file to be opened.
//Post-Condition: Opens the file.
bool CheckRow(int[9][9],int,int);
//Pre-Condition: Takes in the name of the 2-Dimensional Array, along with 2 integers containing the parameters
//               for the Row and the Column to run the loops.
//Post-Condition: Outputs true or false, as to if the integer being tested is unique or not in the Row.
bool CheckColumn(int[9][9],int,int);
//Pre-Condition: Takes in the name of the 2-Dimensional Array, along with 2 integers containing the parameters
//               for the Row and the Column to run the loops.
//Post-Condition: Outputs true or false, as to if the integer being tested is unique or not in the Column.
bool CheckRegion(int[9][9],int,int);
//Pre-Condition: Takes in the name of the 2-Dimensional Array, along with 2 integers containing the parameters
//               for the Row and the Column to run the loops.
//Post-Condition: Outputs true or false, as to if the integer being tested is unique or not in the 3x3 sub-grid.
void printMatrix(int[9][9]);
//Pre-Condition: Takes in the 2-Dimensional Array.
//Post-Condition: Prints out the 2-Dimensional array, so it can be viewed by the User.
int main()
{
    /*Opening the File*/
    ifstream File;
    string FileName;
    int I, J, Row = 9, Col = 9;
    int Puzzle[9][9];
    cout << endl;
    cout << " |Sudoku Checker|" << endl;
    cout << endl;
    cout << " Enter the Name of the Input File: ";
    getline (cin, FileName);
    cout << endl;
    openSudoku(File, FileName);
    /*Reading in the Matrix*/
    for(I = 0; I < Row; I++) {
        for(J = 0; J < Col; J++)
            {
                File >> Puzzle[I][J];
            }
    }
    /*Checking each row, column and 3x3 box in the Matrix*/
    for(I = 0; I < Row; I++) {
        for(J = 0; J < Col; J++)
            {
                if (!(CheckRow(Puzzle, I, J) && CheckColumn(Puzzle, I, J) && CheckRegion(Puzzle, I, J)))
                {
                    printMatrix(Puzzle);
                    cout << endl;
                    cout << " " << FileName << " is NOT a Sudoku solution." << endl;
                    return -1;
                }
            }
    }
    //Output result for Sudoku solution being true
    printMatrix(Puzzle);
    cout << endl;
    cout << " " << FileName << " is a Sudoku solution. Kudos!"<< endl;

    return 0;
}
void openSudoku(ifstream &File, string FileName)
{
    File.open(FileName.c_str());
}
bool CheckRow(int Puzzle[9][9],int Row,int Column)
{
    for (int j = 0; j<9; j++)
    {
        if (j==Column)
            continue;
        else if (Puzzle[Row][Column] == Puzzle[Row][j]) {
            return false;
        }
    }
        return true;
}
bool CheckColumn(int Puzzle[9][9],int Row,int Column)
{
    for (int i = 0; i<9; i++)
    {
        if (i==Row)
            continue;
        else if (Puzzle[Row][Column] == Puzzle[i][Column]) {
            return false;
        }
    }
        return true;
}
bool CheckRegion(int Puzzle[9][9],int Row,int Column)
{
    int row_start = (Row / 3) * 3;
    int col_start = (Column / 3) * 3;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++) {
                if (row_start+i==Row && col_start+j==Column)
                    continue;
                else if (Puzzle[row_start+i][col_start+j]== Puzzle[Row][Column]){
                        return false;
                }
        }
    }
    return true;
}
void printMatrix(int Puzzle [9][9]){
        int I, J, Row = 9, Col = 9;
        for(I = 0; I < Row; I++) {
            for(J = 0; J < Col; J++)
            {
                cout << "  ";
                cout << Puzzle[I][J] << " ";
            }
            cout << endl;
    }
}
