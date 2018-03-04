#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solve(vector<int> col, int min_elem){
    int sum = 0;
    for(int i = 0; i < col.size(); ++i)
    {
        col[i] = col[i] - min_elem;
        sum += col[i] / 5;
        sum += (col[i] % 5) / 2;
        sum += ((col[i] % 5) % 2);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> col(n);
        for(int i = 0; i < n; ++i)
            cin >> col[i];

        int min_elem = *min_element(col.begin(), col.end());
        int min_op = INT_MAX;
        // min, min-1, min-2, min-3
        for(int i = 0; i < 4; ++i)
        {
            int cur_op = solve(col, min_elem-i);
            min_op = min_op < cur_op ? min_op : cur_op;
        }
        cout << min_op << endl;
    }
    return 0;
}
