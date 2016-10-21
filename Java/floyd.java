import java.util.*;

public class floyd {

  	public static int[][] shortestpath(int[][] adj, int[][] path) {

    	int n = adj.length;
    	int[][] ans = new int[n][n];
    
    	// Implement algorithm on a copy matrix so that the adjacency isn't
    	// destroyed.
    	copy(ans, adj);

    	// Compute successively better paths through vertex k.
    	for (int k=0; k<n;k++) {

      		// Do so between each possible pair of points.
      		for (int i=0; i<n; i++) {
        		for (int j=0; j<n;j++) {
        		
        
          			if (ans[i][k]+ans[k][j] < ans[i][j]) {
          				ans[i][j] = ans[i][k]+ans[k][j];
          				path[i][j] = path[k][j];
          			}
          		}
      		}
    	}
    
    	// Return the shortest path matrix.
    	return ans;
  	}

  	// Copies the contents of array b into array a. Assumes that both a and
  	// b are 2D arrays of identical dimensions.
  	public static void copy(int[][] a, int[][] b) {

    	for (int i=0;i<a.length;i++)
      		for (int j=0;j<a[0].length;j++)
        		a[i][j] = b[i][j];
  	}

  	// Returns the smaller of a and b.
  	public static int min(int a, int b) {
    	if (a < b) 
      		return a;
    	else       
      		return b;
  	}

  	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

    
    	// Tests out algorithm with graph shown in class.
    	int[][] m = new int[5][5];
    	m[0][0] = 0; m[0][1] = 3; m[0][2] = 8; m[0][3] = 10000; m[0][4] = -4;
    	m[1][0] = 10000; m[1][1] = 0; m[1][2] = 10000; m[1][3] = 1;
    	m[1][4]=7;
    	m[2][0] = 10000; m[2][1] = 4; m[2][2] = 0; m[2][3] = 10000; 
    	m[2][4] = 10000;
    	m[3][0] = 2; m[3][1] = 10000; m[3][2] = -5; m[3][3] = 0; 
    	m[3][4] = 10000;
    	m[4][0] = 10000; m[4][1] = 10000; m[4][2] = 10000; m[4][3] = 6;
    	m[4][4] =0;


    	int[][] shortpath;
    	int[][] path = new int[5][5];
    
    	// Initialize with the previous vertex for each edge. -1 indicates
    	// no such vertex.
    	for (int i=0; i<5; i++)
    		for (int j=0; j<5; j++)
    			if (m[i][j] == 10000)
    				path[i][j] = -1;
    			else
    				path[i][j] = i;
    		
    	// This means that we don't have to go anywhere to go from i to i.
    	for (int i=0; i<5; i++)
    		path[i][i] = i;
    	
    	
    	shortpath = shortestpath(m, path);

		// Prints out shortest distances.
    	for (int i=0; i<5;i++) {
      		for (int j=0; j<5;j++)
        		System.out.print(shortpath[i][j]+" ");
      		System.out.println();
    	}
    
    	System.out.println("From where to where do you want to find the shortest path?(0 to 4)");
    	int start = stdin.nextInt();
    	int end = stdin.nextInt();
    
    	// The path will always end at end.
    	String myPath = end + "";
    
    	// Loop through each previous vertex until you get back to start.
    	while (path[start][end] != start) {
    		myPath = path[start][end] + " -> " + myPath;
    		end = path[start][end];
    	}
    	
    	// Just add start to our string and print.
    	myPath = start + " -> " + myPath;
    	System.out.println("Here's the path "+myPath);
 
  	}
}