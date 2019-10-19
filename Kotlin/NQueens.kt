class NQueens(N: Int) {
    var sol: Board
    private var numSol: Int = 0

    inner class Board(var length: Int) {
        var solution: Array<IntArray>

        init {
            solution = Array(length) { IntArray(length) }
            for (i in 0 until length) {
                for (j in 0 until length) {
                    solution[i][j] = 0
                }
            }
        }

        private fun canPlaceRow(row: Int, column: Int): Boolean {
            for (i in 0 until column) {
                if (solution[row][i] == 1) {
                    return false
                }
            }
            return true
        }

        private fun canPlaceColumn(row: Int, column: Int): Boolean {
            for (i in 0 until row) {
                if (solution[i][column] == 1) {
                    return false
                }
            }
            return true
        }

        private fun canPlaceDiagonal(row: Int, column: Int): Boolean {
            run {
                var i = row
                var j = column
                while (i >= 0 && j >= 0) {
                    if (solution[i][j] == 1) {
                        return false
                    }
                    i--
                    j--
                }
            }
            var i = row
            var j = column
            while (i < length && j >= 0) {
                if (solution[i][j] == 1) {
                    return false
                }
                i++
                j--
            }
            return true
        }

        fun canPlaceRowColumn(row: Int, column: Int): Boolean {
            return canPlaceRow(row, column) && canPlaceDiagonal(row, column) &&
                    canPlaceColumn(row, column)
        }

        fun printSol() {
            for (i in 0 until length) {
                for (j in 0 until length) {
                    System.out.print(" " + solution[i][j])
                }
                System.out.println()
            }
            System.out.println()
        }
    }

    init {
        sol = Board(N)
        numSol = 0
    }

    fun solve(N: Int) {
        placeQueens(0, N)
        System.out.print("A total of $numSol solutions.\n")
    }

    private fun placeQueens(queen: Int, N: Int): Boolean {
        if (queen == N) {
            sol.printSol()
            ++numSol
            return false
        }
        for (row in 0 until N) {
            if (sol.canPlaceRowColumn(row, queen)) {
                sol.solution[row][queen] = 1
                if (placeQueens(queen + 1, N)) {
                    return true
                }
                sol.solution[row][queen] = 0
            }
        }
        return false
    }

    companion object {
        fun main(args: Array<String>) {
            System.out.print("Enter the length of side of chessboard:\n")
            val N = Integer.parseInt(System.console().readLine())
            val q = NQueens(N)
            q.solve(N)
        }
    }
}
