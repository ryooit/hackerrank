#include <vector>
#include <iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<int> types(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> types[i];
    }

    vector<long long> ways(n+1);
    ways[0] = 1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = types[i]; j <= n; ++j)
        {
            ways[j] += ways[j - types[i]];
        }
    }

    cout << ways[n];

    return 0;
}
