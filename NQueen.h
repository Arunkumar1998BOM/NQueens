//
// Created by ak47a on 06-06-2019.
//

#ifndef UNTITLED5_NQUEENS_H
#define UNTITLED5_NQUEENS_H

#include <vector>

using std::vector;

class Queens{
    vector<vector<int>> chess_table;
    int no_of_queens=10;
public:

    //here wwe shall define the constructor
    Queens(int _no_of_Queens);
    void solve();

private:
    //this function helps to set the queen
    bool set_queens(int col_index);
    //this function is to check if the queen is placed in a valid place of no
    bool is_place_valid(int row_index, int col_index);

    //now we need one function to just print the queens
    void print_queens();
};

#endif //UNTITLED5_NQUEENS_H
