#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int test = 0;
    int temp = 0;
    double medianL, medianX, medianU;
    vector<int> numbers;
    cin >> test;
    for (int i = 0; i < test; ++i) {
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    
    int index = numbers.size() >> 1;
    
    if (numbers.size() % 2 == 0) {
        medianX = (double)((numbers[index-1] + numbers[index]) >> 1);
        index = index >> 1;
        if (index % 2 == 0) {
            medianL = numbers[index];
            medianU = numbers[3*index+1];   
        }
        else {
            medianL = (double) ((numbers[index-1] + numbers[index]) >> 1);
            medianU = (double) ((numbers[3*index-1] + numbers[3*index]) >> 1);
        }
    }
    else {
        medianX = numbers[index];
        index = index >> 1;
        medianL = (double)((numbers[index-1] + numbers[index]) >> 1);
        medianU = (double)((numbers[3*index] + numbers[3*index+1]) >> 1);
    }
        
    
    cout << medianL << endl;
    cout << medianX << endl;
    cout << medianU << endl;
    return 0;
}
