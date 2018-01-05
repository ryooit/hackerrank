#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long make_change(vector<int> coins, int money) {
    vector<long long> combinations(money + 1);
    combinations[0] = 1; // base case
    for (auto& coin : coins) {
        for (int i = 1; i < combinations.size(); ++i) {
            if (i >= coin)
                combinations[i] += combinations[i - coin];
        }
    }
    return combinations[money];
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
