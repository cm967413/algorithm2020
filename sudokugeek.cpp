#include <bits/stdc++.h> 
using namespace std; 
#define empty_cell 0 
#define N 9  
int row_storage[9][10]={0};
int col_storage[9][10]={0};
bool find_empty_cell(int grid[N][N], 
                            int& row, int& col); 
bool islegal(int grid[N][N], int row, 
            int col, int num); 
  
bool sudoku(int grid[N][N]) 
{ 
    int row, col; 
    if (!find_empty_cell(grid, row, col)) 
        return true; 
    for (int num = 1; num <= 9; num++) { 
        if (islegal(grid, row, col, num)) { 
            grid[row][col] = num;
            row_storage[row][num]++;
            col_storage[col][num]++; 
            if (sudoku(grid)) 
                return true; 
            grid[row][col] = empty_cell; 
            row_storage[row][num]--;
            col_storage[col][num]--; 
        } 
    } 
    return false; 
} 
bool find_empty_cell(int grid[N][N], 
                            int& row, int& col) 
{ 
    for (row = 0; row < N; row++) 
        for (col = 0; col < N; col++) 
            if (grid[row][col] == empty_cell) 
                return true; 
    return false; 
} 
bool same_num_in_row(int row_storage[9][10], int row, int num) 
{ 
    if(row_storage[row][num]==1)
    return true;
    else
    {
        return false;
    }
    
} 
bool same_num_in_column(int col_storage[9][10], int col, int num) 
{ 
    if(col_storage[col][num]==1)
    return true;
    else
    {
        return false;
    }
    
} 
bool same_num_in_box(int grid[N][N], int boxStartRow, 
               int boxStartCol, int num) 
{ 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if (grid[row + boxStartRow] 
                    [col + boxStartCol] 
                == num) 
                return true; 
    return false; 
} 
bool islegal(int grid[N][N], int row, 
            int col, int num) 
{ 
    return !same_num_in_row(row_storage, row, num) 
           && !same_num_in_column(col_storage, col, num) 
           && !same_num_in_box(grid, row - row % 3, 
                         col - col % 3, num) 
           && grid[row][col] == empty_cell; 
} 
void printGrid(int grid[N][N]) 
{ 
    for (int row = 0; row < N; row++) { 
        for (int col = 0; col < N; col++) 
            cout << grid[row][col] << " "; 
        cout << endl; 
    } 
} 
int main() 
{ 
    int grid[N][N];
    for(int row = 0; row < N;row++)
        for(int column = 0; column < N; column++)
        {
            cin >> grid[row][column];
            if(grid[row][column]!=0)
            {
                row_storage[row][grid[row][column]]++;
                col_storage[column][grid[row][column]]++;
            }
        }
    if (sudoku(grid) == true) 
        printGrid(grid); 
    else
    cout << "NO\n";
    return 0; 
}