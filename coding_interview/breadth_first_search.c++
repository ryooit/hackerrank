#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    private:
        list<int> *adjacent;
        int size;

    public:
        Graph(int n) {
            size = n;
            adjacent = new list<int>[size];
        }

        void add_edge(int u, int v) {
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {
            vector<int> distance(size, -1);
            bool *visited = new bool[size];
            for (int i = 0; i < size; ++i)
                visited[i] = false;

            list<int> queue;
            visited[start] = true;
            distance[start] = 0;
            queue.push_back(start);

            while (!queue.empty()) {
                start = queue.front();
                queue.pop_front();

                for (auto& elem : adjacent[start]) {
                    if (!visited[elem]) {
                        visited[elem] = true;
                        queue.push_back(elem);
                        distance[elem] = distance[start] + 6;
                    }
                }
            }
            return distance;
        }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
