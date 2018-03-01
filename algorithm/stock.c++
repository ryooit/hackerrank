#include <vector>
#include <iostream>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> price(n);
        for(int i = 0; i < n; ++i)
            cin >> price[i];

        long sum = 0, local_max = 0;
        for(int i = n-1; i > -1; --i)
        {
            if(price[i] >= local_max)
                local_max = price[i];
            sum += local_max - price[i];
        }
        cout << sum << endl;
    }
    return 0;
}
