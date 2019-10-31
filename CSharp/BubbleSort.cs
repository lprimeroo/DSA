using System;

namespace ImplementingBubbleSortAlgo
{
  internal static class Program
  {
    private static void Main()
    {
      Console.WriteLine("Please enter the number of element in array");
      var n = int.Parse(Console.ReadLine() ?? throw new InvalidOperationException());

      //int[] arr = {6, 7, 3, 8, 2, 9, 1};
      var arr = new int[n];
      Console.WriteLine("Please enter the element of array");
      for (var i = 0; i <n; i++)
      {
        arr[i] = int.Parse(Console.ReadLine() ?? throw new InvalidOperationException());
      }
      Console.WriteLine("Sorted Array is :: ");
      BubbleSort(arr);
    }

    private static void BubbleSort(int[] arr)
    {
      for (var i = 0; i < arr.Length; i++)
      {
        for (var j = i; j < arr.Length; j++)
        {
          if (arr[j] < arr[i])
          {
            var temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
          }
        }
      }

      foreach (var variable in arr)
      {
        Console.WriteLine(variable);
      }
    }
  }
}
