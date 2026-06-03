#include <iostream>

using namespace std;

int sudoku[9][9] = {0};

bool is_valid(int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (sudoku[i][col] == num || sudoku[row][i] == num) {
            return false;
        }
    }

    int rowPrefix = 3 * (row / 3), colPrefix = 3 * (col / 3);
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (sudoku[rowPrefix + i][colPrefix + j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

int solve(int i = 0, int j = 0) {
    if (i == 9) {
        return 1;
    }
    if (j == 9) {
        return solve(i + 1, 0);
    }
    
    if (sudoku[i][j] != 0) {
        return solve(i, j + 1);
    }
    
    int count = 0;
    for (int k = 1; k <= 9; ++k) {
        if (is_valid(i, j, k)) {
            sudoku[i][j] = k;
            count += solve(i, j + 1);
            sudoku[i][j] = 0; // backtrack
        }
    }
            
    return count;
}

int main() {

    int n; cin >> n;
    for (int k = 0; k < n; ++k) {
        int i, j, value;
        cin >> i >> j >> value;
        sudoku[i - 1][j - 1] = value;
    }
    
    cout << solve() << "\n";
}