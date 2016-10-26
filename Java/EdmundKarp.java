import java.util.*;
import java.io.*;

public class Main {
	private static final int MAX_V = 40; // enough for sample graph in Figure 4.24/4.25/4.26
	private static final int INF = 1000000000;

	// we need these global variables
	private static int[][] res = new int[MAX_V][]; // define MAX_V appropriately
	private static int mf, f, s, t;
	private static Vector < Integer > p = new Vector < Integer > ();

	private static void augment(int v, int minEdge) { // traverse the BFS spanning tree as in print_path (section 4.3)
		if (v == s) { f = minEdge; return; } // reach the source, record minEdge in a global variable `f'
		else if (p.get(v) != -1) { augment(p.get(v), Math.min(minEdge, res[p.get(v)][v])); // recursive call
			res[p.get(v)][v] -= f; res[v][p.get(v)] += f; } // alter residual capacities
	}

	public static void main(String[] args) throws Exception {
		int V, k, vertex, weight;

		Scanner sc = new Scanner(System.in);

		V = sc.nextInt();
		s = sc.nextInt();
		t = sc.nextInt();

		for (int i = 0; i < V; i++) {
			res[i] = new int[MAX_V];
			k = sc.nextInt();
			for (int j = 0; j < k; j++) {
				vertex = sc.nextInt();
				weight = sc.nextInt();
				res[i][vertex] = weight;
			}
		}

		mf = 0;
		while (true) { // run O(VE^2) Edmonds Karp to solve the Max Flow problem
			f = 0;

			// run BFS, please examine parts of the BFS code that is different than in Section 4.3
			Queue < Integer > q = new LinkedList < Integer > ();
			Vector < Integer > dist = new Vector < Integer > ();
			dist.addAll(Collections.nCopies(V, INF)); // #define INF 2000000000
			q.offer(s);
			dist.set(s, 0);
			p.clear();
			p.addAll(Collections.nCopies(V, -1)); // (we have to record the BFS spanning tree)
			while (!q.isEmpty()) {                // (we need the shortest path from s to t!)
				int u = q.poll();
				if (u == t) break; // immediately stop BFS if we already reach sink t
				for (int v = 0; v < MAX_V; v++) // note: enumerating neighbors with AdjMatrix is `slow'
					if (res[u][v] > 0 && dist.get(v) == INF) { // res[u][v] can change!
						dist.set(v, dist.get(u) + 1);
						q.offer(v);
						p.set(v, u); // parent of vertex v is vertex u
					}
			}

			augment(t, INF); // find the min edge weight `f' along this path, if any
			if (f == 0) break; // if we cannot send any more flow (`f' = 0), terminate the loop
			mf += f; // we can still send a flow, increase the max flow!
		}

		System.out.printf("%d\n", mf); // this is the max flow value of this flow graph
	}
}
