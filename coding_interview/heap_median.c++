#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>   // greater
#include <queue>        // priority_queue
using namespace std;

class Heap {
    private:
        vector<int> _inputs;
        vector<double> _medians;
        priority_queue<int> _max_pq;
        priority_queue<int, vector<int>, greater<int>> _min_pq;
    public:
        Heap(const vector<int>& inputs) :
            _inputs(inputs), _medians(inputs.size()), _max_pq(), _min_pq() {}

        ~Heap() = default;

        void add_num (int num) {
            if (_max_pq.size() == 0 || num < _max_pq.top())
                _max_pq.push(num);
            else
                _min_pq.push(num);
        }

        void rebalance () {
            int cond = _max_pq.size() - _min_pq.size();
            int top = 0;
            if (cond > 1) {
                // move top elem from _max_pq to min_pq
                top = _max_pq.top();
                _min_pq.push(top);
                _max_pq.pop();
            }
            else if (cond < -1) {
                // move top elem from _min_pq to max_pq
                top = _min_pq.top();
                _max_pq.push(top);
                _min_pq.pop();
            }
        }

        double median () {
            int cond = _max_pq.size() - _min_pq.size();
            if (cond == 0)
                return ((double)_max_pq.top() + _min_pq.top()) / 2;
            else if (cond > 0)
                return (double)_max_pq.top();
            else
                return (double)_min_pq.top();
        }

        void eval() {
            for (int i = 0; i < _inputs.size(); ++i) {
                int input = _inputs[i];
                add_num (input);
                rebalance();
                _medians[i] = median();
            }
        }

        void print() {
            for (auto elem : _medians)
                printf("%.1f\n", elem);
        }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<double> medians(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    Heap heap(a);
    heap.eval();
    heap.print();
    return 0;
}
