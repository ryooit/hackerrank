#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    private:
        list<int> *adjacent;
        list<int> leaves;
        vector<int> deg;
        vector<vector<int>> count;
        int _size;

    public:
        Graph(int size):
            _size(size), deg(size, 0), count(size, vector<int>(2))
            {
                adjacent = new list<int>[size];
                for(int i = 0; i < _size; ++i)
                {
                    count[i][0] = 1;
                    count[i][1] = 1;
                }
            }

        void add_edge(int u, int v) {
            adjacent[u].push_back(v);
            adjacent[v].push_back(u);
            ++deg[u];
            ++deg[v];
        }

        void getLeaves(){
            for(int i = 0; i < _size; ++i)
            {
                if(deg[i] == 1)
                    leaves.push_back(i);
            }
        }

        void solve(){
            getLeaves();
            int root = 0;
            while(1)
            {
                int leaf = leaves.front();
                leaves.pop_front();
                count[leaf][0] = count[leaf][1] - count[leaf][0];

                if(deg[leaf] == 0)
                {
                    root = leaf;
                    break;
                }
                else
                {
                    int parent = adjacent[leaf].back();
                    adjacent[leaf].pop_back();

                    adjacent[parent].remove(leaf);
                    deg[parent]--;
                    if(deg[parent] == 1)
                        leaves.push_back(parent);

                    count[parent][1] *=
                        count[leaf][1] + count[leaf][0];
                    count[parent][0] *= count[leaf][0];
                }
            }
            int total = 2 * count[root][0];
            total = total % (1000000000 + 7);
            cout << total;
        }
};

int main() {
    int n;
    cin >> n;
    Graph graph(n);
    while(cin)
    {
        int u, v;               // input nodes
        cin >> u >> v;
        --u, --v;               // node id with decrementing by 1
        graph.add_edge(u, v);   // add edges to graph

        string str;             // temp str
        getline(cin, str);      // skip empty line
    }
    graph.solve();
    return 0;
}
