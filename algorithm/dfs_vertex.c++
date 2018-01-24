using namespace std;

long long vertices = 0;

void dfs(long long s, bool visited[], vector<long long> adj[]) {
    visited[s] = true;
    ++vertices;
    for(long long i = 0; i < adj[s].size(); ++i) {
        if(visited[adj[s][i]] == false) {
            dfs(adj[s][i], visited, adj);
        }
    }
}

void initialize(bool visited[], long long n) {
    for(long long i = 0; i < n+1; ++i)
        visited[i]=false;
}

int main() {
    long long astro, lines;
    cin >> astro >> lines;

    vector<long long> adj[astro];
    bool visited[astro];
    long long compound = 0;

    for (long long i = 0; i < lines; ++i) {
        // input pairs of astro
        long long a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // initialize all elem in visited array with false
    initialize(visited, astro);

    long long depth = 0, result = 0, sum = 0;
    for (long long i = 0; i < astro; ++i) {
        if (visited[i] == false) {
            vertices = 0;
            dfs(i, visited, adj);
            result += sum * vertices;
            sum += vertices;
        }
    }
    cout << result << endl;
    return 0;
}
