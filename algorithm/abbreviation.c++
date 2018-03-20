#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool CanBeAbbreviated(const string& a, const string& b){
    const int a_size = a.size(), b_size = b.size();
    vector<vector<bool>> can_abbre(a_size + 1, vector<bool>(b_size + 1, false));
    can_abbre[0][0] = true;
    for (int i = 1; i <= a_size && islower(a[i-1]); ++i)
    	can_abbre[i][0] = true;
    for (int i = 1; i <= a_size; ++i)
    {
        for (int j = 1; j <= b_size; ++j)
        {
            if (islower(a[i-1]) && can_abbre[i-1][j])
            	can_abbre[i][j] = true;
            if (can_abbre[i-1][j-1] && (toupper(a[i-1]) == b[j-1] || a[i-1] == b[j-1]))
            	can_abbre[i][j] = true;
        }
    }
    return can_abbre[a_size][b_size];
}

int main() {
    string temp;
    getline(cin, temp);
    int q = stoi(temp);
    for (int i = 0; i < q; ++i) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        cout << (CanBeAbbreviated(a,b) ? "YES" : "NO") << endl;
    }
    return 0;
}
