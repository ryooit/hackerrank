#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

void find (unordered_multimap<int, int>& costs, int& money) {
    int temp_1 = 0, temp_2 = 0, balance = 0;
    for (auto& elem : costs) {
        if (elem.first >= money)
            continue;
        else {
            temp_1 = elem.second;
            balance = money - elem.first;
            auto got = costs.find(balance);
            if (got == costs.end() || temp_1 == got->second)
                continue;
            else {
                temp_2 = got->second;
                break;
            }
        }
    }
    if (temp_1 < temp_2)
        cout << temp_1 << " " << temp_2 << endl;
    else
        cout << temp_2 << " " << temp_1 << endl;
}

int main () {
    int t = 0;
    cin >> t;
    while (t--) {
        int money = 0, n = 0, temp = 0;
        cin >> money >> n;
        unordered_multimap<int, int> costs;

        for (int i = 1; i <= n ; ++i) {
            cin >> temp;
            costs.insert(make_pair<int&, int&>(temp, i));
        }
        find (costs, money);
    }
    return 0;
}
