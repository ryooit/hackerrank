#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
void printFrequencies(const string &str)
{
    // declaring map of <string, int> type, each word
    // is mapped to its frequency
    unordered_map<string, int> wordFreq;

    // breaking input into word using string stream
    stringstream ss(str);  // Used for breaking words
    string word; // To store individual words
    while (ss >> word)
        wordFreq[word]++;

    // now iterating over word, freq pair and printing
    // them in <, > format
    unordered_map<string, int>:: iterator p;
    for (p = wordFreq.begin(); p != wordFreq.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")\n";
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> count;
    for (auto elem : magazine) {
        ++count[elem];
    }

    for (auto elem: ransom) {
        unordered_map<string, int>::iterator got = count.find(elem);
        if (got != count.end()) {
            if (got->second != 0) {
                --count[elem];
                continue;
            }
            else
                return false;
        }
        else
            return false;
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
