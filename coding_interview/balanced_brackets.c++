#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_balanced(string expression) {
    stack<char> s;

    for (int i = 0; i < expression.size(); ++i) {
        if (s.size() == 0) {
            if (expression[i] == '}' || expression[i] == ')' || expression[i] == ']')
                return false;
            else
                s.push(expression[i]);
        }
        else {
            if (expression[i] == '}' || expression[i] == ')' || expression[i] == ']') {
                char top_char = s.top();
                s.pop();
                switch (top_char) {
                    case '{':
                        if (expression[i] != '}')
                            return false;
                        break;
                    case '(':
                        if (expression[i] != ')')
                            return false;
                        break;
                    case '[':
                        if (expression[i] != ']')
                            return false;
                        break;
                }
            }
            else
                s.push(expression[i]);
        }
    }
    if (s.size() == 0)
        return true;
    else
        return false;
}
/* Optimized version */
/*
bool is_balanced(string expression) {
  stack<char> s;
  for (char c : expression) {
    if      (c == '{') s.push('}');
    else if (c == '[') s.push(']');
    else if (c == '(') s.push(')');
    else {
      if (s.empty() || c != s.top())
        return false;
      s.pop();
    }
  }
  return s.empty();
}
*/
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
