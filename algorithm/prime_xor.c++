#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define LL long long
#define M 1000000007
using namespace std;

vector<int> prime;  // cache all prime numbers
void makePrime(){
    vector<int> nums(8200, 0);
    nums[0] = 1;
    nums[1] = 1;
    for(int i = 2; i * i < 8200; ++i)
    {
        if(!nums[i])
            for(int j = i + i; j < 8200; j += i)
                nums[j] = 1;
    }
    for(int i = 2; i < 8200; ++i)
        if(!nums[i])
            prime.push_back(i);
}

int main() {
    int q;
    cin >> q;
    makePrime();

    while(q--)
    {
        int n;
        cin >> n;

        vector<LL> count(1005, 0);
        vector<vector<LL>> dp(1005, vector<LL>(8200, 0));

        int temp;
        for(int i = 0; i < n; ++i)
        {
            cin >> temp;
            ++count[temp-3500];
        }

        dp[0][3500] = (count[0] + 1) >> 1;
        dp[0][0] = (count[0] + 2) >> 1;

        for(int i = 1; i < 1005; ++i)
        {
            for(int j = 0; j < 8200; ++j)
            {
                dp[i][j] = (dp[i-1][j] * ((count[i]+2)>>1) +
                            dp[i-1][j^(i+3500)]*((count[i]+1)>>1)) % M;
            }
        }

        LL ans = 0;
        for(int p : prime){
            (ans += dp[1004][p]) %= M;
        }
        cout << ans % M << endl;

    }
    return 0;
}
