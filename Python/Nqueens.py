import sys

solutions = []

def place(positions,col):
	if positions is None:
		return True
	current_row = len(positions)
	if col in  positions:
		return False
	#diagonal
	d = 1
	for prev_row in range(current_row-1,-1,-1):
		if positions[prev_row] == col - d :
			return False
		d += 1
	#off-diagonal
	d = 1
	for prev_row in range(current_row-1,-1,-1):
		if positions[prev_row] == col + d:
			return False
		d += 1
	
	return True

def solve_nqueens(positions,row,max_queens):
	global solutions

	if(row == max_queens):
		solutions.append(positions)
		return True
	
	for col in range(0,max_queens):
		if place(positions,col) :
			Y = positions[:]
			Y.append(col)
			solve_nqueens(Y,row+1,max_queens)
		else:
			continue

	return False



if __name__ == '__main__':
	X = []
	queens = int(sys.argv[1])
	solve_nqueens(X,0,queens);
	print (solutions)