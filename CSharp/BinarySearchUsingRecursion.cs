using System;

 /* Recursive implementation of Binary Search*/
namespace BinarySearch
{
  internal static class Program
  {
    private static void Main()
    {
      //      Console.WriteLine("Please enter the number of element in array");
      //      var n = int.Parse(Console.ReadLine() ?? throw new InvalidOperationException());
      //      //int[] arr = {6, 7, 3, 8, 2, 9, 1};
      //      var arr = new int[n];
      //      Console.WriteLine("Please enter the element of array");
      //      for (var i = 0; i < n; i++)
      //      {
      //        arr[i] = int.Parse(Console.ReadLine() ?? throw new InvalidOperationException());
      //      }
      //
      //      Console.WriteLine("Sorted Array is :: ");
      int[] arr = {2, 3, 4, 10, 40};
      int n = arr.Length;
      int x = 10;
      var t = binarySearch(arr, 0, n - 1, x);
      Console.WriteLine(t);
    }

    private static int binarySearch(int[] arr, int l, int r, int x)
    {
      if (r >= l)
      {
        int mid = l + (r - 1) / 2;
        if (arr[mid] == x)
        {
          return mid;
        }

        if (arr[mid] > x)
        {
          return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
      }

      return -1;
    }
  }
}
