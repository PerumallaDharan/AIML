from constraint import *
import random

def solve_8_queens_csp():
    problem = Problem()
    cols = range(8)
    rows = range(8)
    problem.addVariables(cols, rows)
    for col1 in cols:
        for col2 in cols:
            if col1 < col2:
                problem.addConstraint(lambda row1, row2, col1=col1, col2=col2:
                                      row1 != row2 and row1 + col1 != row2 + col2 and row1 - col1 != row2 - col2,
                                      (col1, col2))

    solutions = problem.getSolutions()
    if len(solutions) > 0:
        print("Solution:")
        solution = random.choice(solutions)
        board = [[0 for _ in range(8)] for _ in range(8)]
        for col, row in solution.items():
            board[row][col] = 1
        for row in board:
            print(" ".join(map(str, row)))
    else:
        print("No solution exists.")

if __name__ == "__main__":
    solve_8_queens_csp()