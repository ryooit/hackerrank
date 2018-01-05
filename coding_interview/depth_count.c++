#include <limits>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int find_depth (vector< vector<int> >& grid, const int& i, const int& j){
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return 0;
    if (grid[i][j] == 0)
        return 0;
    else {
        int depth = grid[i][j]--;

        for (int ii = -1; ii < 2; ++ii) {
            for (int jj = -1; jj < 2; ++jj) {
                if (ii == 0 && jj == 0)
                    continue;
                else
                    depth += find_depth(grid, i + ii, j +jj);
            }
        }
        return depth;
    }
}

int get_biggest_region(vector< vector<int> >& grid) {
    int ret_val = INT_MIN;
    for (int i = 0; i < grid.size(); ++i) {
        vector<int> row = grid[i];
        for (int j = 0; j < row.size(); ++j) {
            if (row[j] != 1)
                continue;
            else {
                int temp = find_depth(grid, i, j);
                ret_val = ret_val > temp ? ret_val : temp;
            }
        }
    }
    return ret_val;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
