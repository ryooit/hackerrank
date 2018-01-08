#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int greatest (int a, int b) {
    if (a == 0)
        return b;
    return greatest (b % a, a);
}

int least (int a, int b) {
    return a * (b / greatest(a, b));
}

int factors (int a) {
    int count = 0;
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0)
            ++count;
        else
            continue;
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a_num, b_num, temp;
    cin >> a_num >> b_num;
    vector<int> a(a_num);
    vector<int> b(b_num);
    for (int i = 0; i < a_num; ++i) {
        cin >> temp;
        a[i] = temp;
    }
    for (int i = 0; i < b_num; ++i) {
        cin >> temp;
        b[i] = temp;
    }

    sort (a.begin(), a.end());
    sort (b.begin(), b.end());

    int gcd, lcm;
    lcm = a[0];
    for (auto& elem : a) {
        lcm = least (lcm, elem);
    }

    gcd = b[0];
    for (auto& elem : b) {
        gcd = greatest (gcd, elem);
    }

    if (gcd % lcm != 0)
        cout << 0 << endl;
    else {
        int count = 0;
        for(int i = lcm, j = 2; i <= gcd; i = lcm * j, ++j){
            if(gcd % i == 0)
                ++count;
        }
        cout << count << endl;
    }

    return 0;
}
