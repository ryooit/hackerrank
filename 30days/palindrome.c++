#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    //Write your code here
    private:
        stack<int> _stack;
        queue<int> _queue;
    public:
        Solution () = default;
        
        void pushCharacter(char s) {
            _stack.push(s);    
        }
        void enqueueCharacter(char s) {
            _queue.push(s);
        }
        const char popCharacter() {
            const char ret_val = _stack.top();
            _stack.pop();
            return ret_val;
        }
        const char dequeueCharacter() {
            const char ret_val = _queue.front();
            _queue.pop();
            return ret_val;
        }

};
