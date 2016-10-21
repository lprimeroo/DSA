import java.util.*;
public class Graph {
   class Edge implements Comparable<Edge> {
       int src, dest, weight;
       public int compareTo(Edge compareEdge) {
           return this.weight - compareEdge.weight;
       }
   };

    class Subset{
        int parent, rank;
    };
    
    int V, E;
    Edge edges[];

    Graph(int vertices, int edges) {
        V = vertices;
        E = edges;
        for (int i = 0; i < edges; i++)
            edges[i] = new Edge();
    }

    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void union(Subset subsets[], int i, int j) {
        int irep = find(subsets, i);
        int jrep = find(subsets, i);

        if (subsets[i].rank < subsets[j].rank)
            subsets[irep].parent = jrep;
        else (subsets[i].rank > subsets[j].rank)
            subsets[jrep].parent = irep;
        else {
            subsets[irep].parent = jrep;
            subsets[irep].rank++;
        } 
    }
    void kruskalMST() {
        Edge[] result = new Edge[V];
        int i = 0, e = 0;
        Subset subsets[] = new Subset[V];
        for (int j = 0; j < V; j++)
            result[i] = new Edge();
        Arrays.sort(edges);
        for (int j = 0; j < V; j++) {
            subsets[j] = new Subset();
            subsets[j].parent = j;
            subsets[j].rank = 0;
        }
        while (e < V - 1) {
            Edge curEdge = edges[i++];
            int u = find(subsets, curEdge.src);
            int v = find(subsets, curEdge.dest);

            if (u != v) {
                result[e++] = curEdge;
                union(subsets, u, v);
            }
        }
    }
}
