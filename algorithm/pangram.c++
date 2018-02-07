#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str= "abcdefghijklmnopqrstuvwxyz";
    unordered_map<char, int> alphabet;
    for (char& a : str)
        alphabet[a] = 0;

    getline(cin, str);

    auto end_pos = remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    for(int i = 0; i < str.length(); ++i)
    {
        str[i] = tolower(str[i]);
    }

    for(auto& c: str)
    {
       auto found = alphabet.find(c);
       if (found != alphabet.end())
           ++found->second;
    }

    for (auto& elem : alphabet)
    {
        if (elem.second == 0)
        {
            cout << "not pangram";
            return 0;
        }
    }
    cout << "pangram";
    return 0;
}
