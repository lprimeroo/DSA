public class Knapsack0_1 {
	
	public static void main(String []args) {
		int [] val = {60, 100, 120};
		int [] wt = {10, 20, 30};
		int W = 50;
		int n = val.length;
		
		System.out.println(knapsack(W, wt, val, n));
	}
	
	private static int knapsack(int W, int [] wt, int [] val, int n) {
		if (W == 0 || n == 0) {
			return 0;
		} else if (wt[n-1] > W) {					
			return knapsack(W, wt, val, n-1);
		} else {
			return Math.max(val[n-1] + knapsack(W - wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
		}
	}
	
}