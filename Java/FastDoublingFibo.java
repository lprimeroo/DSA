import java.util.*;

class FastDoublingFibo 
{
	private static HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();

	private static int fib(int n) {
		if (n <= 2) 
			return (1);

		int ans = 0;
		if (hm.get(n) != null) {
			ans = hm.get(n);
			return (ans);
		}

		int half = n/2;
		int a = fib(half + 1);
		int b = fib(half);
		if (n % 2 == 1)
			ans = a*a + b*b;
		else
			ans = 2*a*b - b*b;
		hm.put(n, ans);
		return (ans);
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

        System.out.print("Enter n(0 to exit): ");
        int n = sc.nextInt();

        while (n != 0) {
        	int ans = fib(n);
        	System.out.println(ans);
        	System.out.print("Enter n(0 to exit): ");
        	n = sc.nextInt();
        }
        
	}
}