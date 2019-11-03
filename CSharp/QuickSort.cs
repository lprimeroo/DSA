using System;
/*
 *  Quick Sort : Quick sort is Divide and Conquer algorithm.
 *  It picks an element as pivot and partitions the given array around the piked pivot.
 *
 */
namespace ConsoleApp169
{
  internal static class Program
  {
    public static void Main()
    {
      var arr = new int[] { 2, 5, -4, 11, 0, 18, 22, 67, 51, 6 };
      foreach (var variable in arr)
      {
        Console.WriteLine(variable);
      }

      Console.WriteLine(" Sorted Array ");

      Quick_Sort(arr, 0, arr.Length - 1);
      foreach (var variable in arr)
      {
        Console.WriteLine(variable);
      }
    }

    private static void Quick_Sort(int[] arr, int i, int arrLength)
    {
      while (true)
      {
        if (i < arrLength)
        {
          var pivot = Partition(arr, i, arrLength);

          if (pivot > 1)
          {
            Quick_Sort(arr, i, pivot - 1);
          }

          if (pivot + 1 < arrLength)
          {
            i = pivot + 1;
            continue;
          }
        }

        break;
      }
    }

    private static int Partition(int[] arr, int i, int arrLength)
    {
      var pivot = arr[i];
      while (true)
      {
        while (arr[i] < pivot)
        {
          i++;
        }

        while (arr[arrLength] > pivot)
        {
          arrLength--;
        }

        if (i < arrLength)
        {
          if (arr[i] == arr[arrLength]) return arrLength;
          var temp = arr[i];
          arr[i] = arr[arrLength];
          arr[arrLength] = temp;
        }
        else
        {
          return arrLength;
        }
      }
    }
  }
}
