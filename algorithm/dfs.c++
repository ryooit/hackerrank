#include <vector>
#include <iostream>

using namespace std;

void dfs(int s, bool visited[], vector<int> adj[]) {
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i) {
        if(visited[adj[s][i]] == false)
            dfs(adj[s][i], visited, adj);
    }
}

void intialize(bool visited[], int n) {
    for(int i = 0; i < n+1; ++i)
        visited[i]=false;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int cities, roads;
        long cost_lib, cost_road;
        cin >> cities >> roads >> cost_lib >> cost_road;

        vector<int> adj[cities+1];
        bool visited[cities+1];
        long count = 0;

        for (int j = 0; j < roads; ++j) {
            int src, des;
            cin >> src >> des;
            adj[des].push_back(src);
            adj[src].push_back(des);
        }

        if(cost_road >= cost_lib)
            cout << cities * cost_lib << endl;

        else {
            intialize(visited, cities);
            for(int j = 1; j <= cities; ++j) {
                if(visited[j] == false) {
                    dfs(j, visited, adj);
                    ++count;
                 }
            }
            cout << cost_road * (cities - count) + cost_lib * count <<endl;
        }
    }
    return 0;
}
