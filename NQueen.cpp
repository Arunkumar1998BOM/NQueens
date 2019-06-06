//
// Created by ak47a on 06-06-2019.
//

//now we shall first include the header file
#include "NQueen.h"
#include <iostream>

using namespace std;
using std::cout;
//first define the constructor functionality

Queens::Queens(int _no_of_Queens):no_of_queens(_no_of_Queens) {

    //what ever you perform here, will executed upon the creation of the object of this particular class
    // we shall resize the chess board
    //resize the rows
    chess_table.resize(static_cast<unsigned long long int>(no_of_queens));
    for (auto &p :chess_table) {
        //resize the columns
        p.resize(static_cast<unsigned long long int>(no_of_queens));

    }
}

//this function is to solve the queens problem
void Queens::solve() {

    if(set_queens(0)){
        //all the number of queens were able to be positioned appropriately
        //we can now print the queens

        print_queens();

    }
    else
    {
        cout<<"There is no valid solution";

    }
}

//This function is to set the queens
bool Queens::set_queens(int col_index) {

    //This is our exit condition
    if(col_index==no_of_queens){
        //we are done with placing all the queens
        //code highway exit
        return true;
    }
    //we shall start traversing through all the rows and see, which row would be the appropriate place to sit for the queen
    //if we strike upon a right place, then we shall traverse down to the next column and the next queen
    //if we are unable to find a right place, we shall backtrack

    for (int rowIndex=0;rowIndex<no_of_queens;++rowIndex){

        if(is_place_valid(rowIndex,col_index)){
            //The place turned out to be valid for the queen
            //Now we shall place a queen at this location by making this slot 1
            chess_table[rowIndex][col_index]=1;

            //now we shall check for the other queen
            if(set_queens(col_index+1)){
                //code highway exit
                return true;
            }

            //if we still havent hit the exit highway, it means , that we have run out of all the options (rows) in this case
            //let us backtrack and make any changes in the previous case, hopefully, doin that would open a ton of options for us

            chess_table[rowIndex][col_index]=0;
        }

    }

    //we have traversed through all the possible options that turned up, but nothing worked, so is no way to the solution of the problem
    return false;
}


//This function is to check if the given place is valid or no
bool Queens::is_place_valid(int row_index, int col_index) {

    //There cannot be another queen in the same row (they would attack each other )
    for (int q=0;q<col_index;q++){
        if(chess_table[row_index][q]==1)
            return false;
    }

    //if there is a queen in the diagonal (from top left to bottom right)
    for (int i=row_index,j=col_index;i>=0 && j>=0;i--,j--){
        if(chess_table[i][j]==1)
            return false;
    }

    for (int i=row_index,j=col_index;i<no_of_queens && j>=0;i++,j--){
        if(chess_table[i][j]==1)
            return false;
    }


    return true;
}

//This function is to print the chess table

void Queens::print_queens() {
    //if there is a queen, the table position contains a 1 else 0

    for (int m=0;m<no_of_queens;m++){
        for(int n=0;n<no_of_queens;n++){
            if(chess_table[m][n]==1){
                cout<<" * ";

            }
            else{
                cout<<" - ";
            }


        }
        cout<<"\n";
    }


}