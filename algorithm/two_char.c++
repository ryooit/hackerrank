#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool is_valid(const string& str){
    // constraint: same consecutive characters
    for (int i = 0; i < str.size() - 1; ++i) {
        if (str[i] == str[i+1])
            return false;
    }
    return true;
}

void eval(const string& str, const set<char>& unique) {
    int max_size = 0;
    // iterate through all posibile combinations
    for (auto& x : unique){
        for (auto& y : unique){
            // get two distinct values x, y in set
            if (x == y)
                continue;

            string cand = ""; // candidate string

            // filtering the string by containg x and y
            for(int k = 0 ; k < str.size(); ++k){
                if (str[k] == x || str[k] == y)
                     cand = cand + str[k];
            }

            // if it is valid, compute max size
            if(is_valid(cand)) {
                int size = cand.size();
                max_size = size > max_size ? size : max_size;
            }
        }
    }
    cout << max_size;
}

int main(){
    int len = 0;      // length of input string
    string str = "";  // input string
    char temp;        // temporary input character
    set<char> unique; // contain unique character

    // read input and set "str" and "unique"
    cin >> len;
    for (int i = 0; i < len; ++i) {
        cin >> temp;
        unique.insert(temp);
        str.push_back(temp);
    }

    eval(str, unique);

    return 0;
}
