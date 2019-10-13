#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

#define pp pair<int, int>
#define mp make_pair<int, int>

using namespace std;

const int NMAX = 41 * 41;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int px, py;
int fx, fy;

int start;
int finish;

int n;
int m;
int nodes;

char a[40][40];

vector<int> adj[NMAX];

int get_node(int x, int y)
{
    return x * m + y + 1;
}

vector<int> get_neigh(int x, int y)
{

    vector<int> neigh;
    for (int k = 0; k < 4; ++k)
    {
        int posx = x + dx[k];
        int posy = y + dy[k];
        if (posx >= 0 && posy >= 0 && posx < n && posy < m && a[posx][posy] != '%')
        {
            neigh.push_back(get_node(posx, posy));
        }
    }
    return neigh;
}

pp get_pos(int node)
{
    return {(node - 1) / m, (node - 1) % m};
}

void construct_graph()
{
    nodes = n * m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] != '%')
                adj[get_node(i, j)] = get_neigh(i, j);
}

void print_graph()
{

    for (int i = 1; i <= nodes; i++)
    {
        cout << i << ":  ";
        for (int v : adj[i])
            cout << v << ' ';
        cout << '\n';
    }
}

void print_path(int start, int finish, int *pi)
{
    stack<int> ss;
    while (finish != 0)
    {
        ss.push(finish);
        finish = pi[finish];
    }
    cout << ss.size() - 1 << '\n';
    ;
    while (!ss.empty())
    {
        int w = ss.top();
        ss.pop();
        pp p = get_pos(w);
        cout << p.first << " " << p.second << '\n';
    }
}

int h(int node1, int node2)
{

    int node1x, node1y, node2x, node2y;
    pp p1 = get_pos(node1);
    pp p2 = get_pos(node2);
    node1x = p1.first;
    node2x = p1.second;
    node2x = p2.first;
    node2y = p2.second;

    int distance = abs(node1x - node2x) + abs(node1y - node2y);
    return distance;
}

int astar_pacman(int start, int finish, int nodes)
{
    //print_graph();
    int *pi = new int[nodes + 1];
    vector<int> d(nodes + 1, (1 << 30));
    vector<bool> s(nodes + 1, false);
    vector<int> p(nodes + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    d[start] = 0;
    q.push(make_pair(d[start], start));

    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (s[u] == true)
        {
            continue;
        }
        s[u] = true;
        for (auto node : adj[u])
        {
            if (d[u] + 1 < d[node]) {
                d[node] = d[u] + 1;
                pi[node] = u;
                q.push({d[node] + h(node, finish), node});
            }
        }
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (d[i] == (1 << 30))
        {
            d[i] = -1;
        }
    }

    print_path(start, finish, pi);

    return 0;
}

int main()
{
    cin >> px >> py;

    cin >> fx >> fy;
    cin >> n >> m;

    start = get_node(px, py);
    finish = get_node(fx, fy);

    string str;

    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        for (int j = 0; j < m && j < str.size(); j++)
        {
            a[i][j] = str[j];
        }
    }
    construct_graph();
    astar_pacman(start, finish, nodes);

    return 0;
}