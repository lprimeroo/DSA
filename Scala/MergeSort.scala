object MergeSort {

  def main(args: Array[String]) {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    val arr = new Array[Int](n)
    for (arr_i <- 0 until n) {
      arr(arr_i) = sc.nextInt()
    }

    mergeSort(arr)()
    println(arr.deep.mkString(" "))
  }

  def mergeSort(arr: Array[Int])(start: Int = 0, end: Int = arr.length): Unit = {
    if (start < end - 1) {
      val mid = (end + start) / 2
      mergeSort(arr)(start, mid)
      mergeSort(arr)(mid, end)
      merge(arr, start, mid, end)
    }
  }

  def merge(arr: Array[Int], start: Int, mid: Int, end: Int): Unit = {
    val aux = arr.slice(start, end)

    var i = start
    var j = mid
    var k = start

    while (i < mid && j < end) {
      if (aux(j - start) < aux(i - start)) {
        arr(k) = aux(j - start)
        j += 1
      }
      else {
        arr(k) = aux(i - start)
        i += 1
      }
      k += 1
    }

    while (i < mid) {
      arr(k) = aux(i - start)
      i += 1
      k += 1
    }

    while (j < end) {
      arr(k) = aux(j - start)
      j += 1
      k += 1
    }
  }
}


// Sample input
// 9
// 9 4 3 7 1 2 8 5 6

// Sample output
// 1 2 3 4 5 6 7 8 9 