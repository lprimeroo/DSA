//sathvikrijo
#include <bits/stdc++.h>

using namespace std;

void bellmanFord(vector< vector<int> > &connect, int V, int E) {
  vector<int> distance(V+1);

  cout << "Enter the source vertex: ";
  int source;
  cin >> source;

  //initially all nodes costs are marked as inifinity except the souce node
  for(int itr=1; itr<=V; itr++) {
    distance[itr] = INT_MAX;
  }
  distance[source] = 0;

  //relaxation
  for(int relaxTimes=0; relaxTimes<V-1; relaxTimes++) {
    for(int selected=0; selected<E; selected++) {
      if( distance[connect[selected][0]] + connect[selected][2] < distance[connect[selected][1]] )
        distance[connect[selected][1]] = distance[connect[selected][0]] + connect[selected][2];
    }
  }

  //print all shortest paths from source to all other nodes
  for(int itr=1; itr<=V; itr++)
    cout << source << " --> " << itr << "\tcost=" << distance[itr] << endl;
}

int main() {
  int V, E, u, v, w;
  cout << "Number of vertices ranges from 1 to ";
  cin >> V;
  cout << "Number of edges: ";
  cin >> E;

  vector< vector<int> > connect(E);

  cout<<"Enter the edges (vertice1, vertice2, cost):\n";
  
  //enter vertices as integers
  for(int noE=0; noE<E; noE++) {
    cin >> u >> v >> w;
    connect[noE].push_back(u);
    connect[noE].push_back(v);
    connect[noE].push_back(w);
  }

  bellmanFord(connect, V, E);
}
