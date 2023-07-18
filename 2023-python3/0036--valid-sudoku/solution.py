"""
Category: Arrays & Hashing
Idea:     Check every row, then column then sub-box with a new set that checks
          that if the value is a digit, it isn't already in the set. If it
          passes all the checks, then it's a valid sudoku.
Runtime:  O(N^2) where N is the length/height of the sudoku
"""

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):    
            row_values = set()
            for j in range(9):
                if board[i][j] in row_values:
                    return False
                elif board[i][j] != '.':
                    row_values.add(board[i][j])
            
        for j in range(9):
            col_values = set()
            for i in range(9):
                if board[i][j] in col_values:
                    return False
                elif board[i][j] != '.':
                    col_values.add(board[i][j])
        
        for x in range(0, 9, 3):
            for y in range(0, 9, 3):
                subbox_values = set()
                for i in range(x, x + 3):
                    for j in range(y, y + 3):
                        if board[i][j] in subbox_values:
                            return False
                        elif board[i][j] != '.':
                            subbox_values.add(board[i][j])

        return True

