public class LinearSearch{  
    public static void main(String a[]) {    
        int[] a1= {50, 40, 20, 30, 70, 60};    
        int x = 70;   
        int result = linearSearch(a1, x);
        if(result == -1)
            System.out.println("Element is not present in the array.");
        else
            System.out.println(x+" is present in the array at index: "+ result);    
    } 

    public static int linearSearch(int[] arr, int key) {    
        for(int i=0;i<arr.length;i++) {    
            if(arr[i] == key) {    
                return i;    
            }    
        }    
        return -1;    
    }       
}