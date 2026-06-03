sudoku = [[0 for _ in range(9)] for _ in range(9)]

def is_valid(row, col, num):
 
    for i in range(9):
        if sudoku[i][col] == num or  sudoku[row][i] == num:
            return False

    rowPrefix, colPrefix = 3* (row // 3), 3* (col // 3)
    for i in range(3):
        for j in range(3):
            if sudoku[rowPrefix + i][colPrefix + j] == num:
                return False
        return True
    
def solve(i=0, j=0):    
    if i == 9:
        return 1
    if j == 9:
        return solve(i + 1, 0)
    
    if sudoku[i][j] != 0:
        return solve(i, j + 1)
    
    count = 0
    for k in range(1, 10):
        if is_valid(i, j, k):
            sudoku[i][j] = k
            count += solve(i, j + 1)
            sudoku[i][j] = 0
            
    return count
        
                
def main():
    n = int(input())

    for _ in range(n):
        i, j, value = map(int, input().split())
        sudoku [i-1][j-1] = value
    
    print(solve())

if __name__ == "__main__":
    main()