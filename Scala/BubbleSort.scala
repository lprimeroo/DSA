object BubbleSort {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    val array = new Array[Int](n)
    for (i <- 0 until n) {
      array(i) = sc.nextInt()
    }

    bubbleSort(array)

    println(array.deep.mkString(" "))
  }

  def bubbleSort(array: Array[Int]): Unit = {
    var numSwap = -1
    for (i <- array.length - 1 until 0 by -1) {
      if (numSwap == 0)
        return
      numSwap = 0
      for (j <- 0 until i) {
        if (array(j) > array(j + 1)) {
          numSwap += 1
          swap(array, j, j + 1)
        }
      }
    }
  }

  def swap(array: Array[Int], index1: Int, index2: Int): Unit = {
    val temp = array(index1)
    array(index1) = array(index2)
    array(index2) = temp
  }
}

// Example Input
// 3
// 3 2 1

// Example Output
// 1 2 3