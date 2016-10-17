public class NQueens {
	public class Board {
		public int[][] solution;
		public int length;
		public Board(int N) {
			solution = new int[N][N];
			length = N;
			for (int i = 0; i < length; i++) {
				for (int j = 0; j < length; j++) {
					solution[i][j] = 0;
				}
			}
		}
		private boolean canPlaceRow(int row, int column) {
			for (int i = 0; i < column; i++) {
				if (solution[row][i] == 1) {
					return false;
				}
		  	}
			return true;
		}
		private boolean canPlaceColumn(int row, int column) {
			for (int i = 0; i < row; i++) {
				if (solution[i][column] == 1) {
					return false;
				}
		  	}
		  	return true;
		}
		private boolean canPlaceDiagonal(int row, int column) {
			for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
				if (solution[i][j] == 1) {
					return false;
				}
		  	}
			for (int i = row, j = column; i < length && j >= 0; i++, j--) {
				if (solution[i][j] == 1) {
					return false;
				}
		  	}
			return true;
		}
		public boolean canPlaceRowColumn(int row, int column) {
		  return (canPlaceRow(row, column) && canPlaceDiagonal(row, column) &&
				  canPlaceColumn(row, column));
		}
		public void printSol() {
			for (int i = 0; i < length; i++) {
				for (int j = 0; j < length; j++) {
					System.out.print(" " + solution[i][j]);
				}
				System.out.println();
			}
			System.out.println();
		}
	}
	public Board sol;
	private int numSol;
	public NQueens(int N) {
		sol = new Board(N);
		numSol = 0;
	}
	public void solve(int N) {
		placeQueens(0, N);
		System.out.print("A total of " + numSol + " solutions.\n");
	}
	private boolean placeQueens(int queen, int N) {
		if (queen == N) {
			sol.printSol();
			++numSol;
			return false;
		}
		for (int row = 0; row < N; row++) {
			if (sol.canPlaceRowColumn(row, queen)) {
				sol.solution[row][queen] = 1;
				if (placeQueens(queen + 1, N)) {
					return true;
				}
				sol.solution[row][queen] = 0;
			}
		}
		return false;
	}
	public static void main(String[] args) {
		System.out.print("Enter the length of side of chessboard:\n");
		int N = Integer.parseInt(System.console().readLine());
		NQueens q = new NQueens(N);
		q.solve(N);
	}
}
