#include <iostream>
#include <vector>

using namespace std;

/* xor with same number twice results itself */
void test_xor () {
  cout << "<--------<start test>--------->" << endl;
  cout << "1 ^ 1 = " << (1 ^ 1) << endl;     // 0
  cout << "1 ^ 0 = " << (1 ^ 0) << endl;     // 1
  cout << "0 ^ 1 = " << (0 ^ 1) << endl;     // 1
  cout << "0 ^ 0 = " << (0 ^ 0) << endl;     // 0
  cout << "2 ^ 2 = " << (2 ^ 2) << endl;     // 10 ^ 10 = 00 => 0
  cout << "2 ^ 1 = " << (2 ^ 1) << endl;     // 10 ^ 01 = 11 => 3
  cout << "2 ^ 0 = " << (2 ^ 0) << endl;     // 10 ^ 00 = 10 => 2
  cout << "<---------<end test>--------->" << endl;
}

void print (vector<int> numbers){
  cout << "numbers: ";
  for (auto elem : numbers)
    cout << elem << " ";
  cout << endl;
}

/* Find one duplicate number in 1 to n */
void find_dup (vector<int> numbers) {
  int result = numbers[0];          // save xor result of all elements
  int n = numbers.size() - 1;       // n = size - 1;

  /* Get the xor result of all elements in vector */
  for (auto it = begin(numbers)+1; it != end(numbers); ++it)
    result ^= *it;

  /* Get the xor result of 0 to n */
  for (int i = 0; i <= n; ++i)
    result ^= i;

  cout << "Duplicate numbers: " << result << endl;
}

int main()
{
  vector<int> numbers = {1, 2, 2, 3, 4, 5};
  test_xor ();
  print(numbers);
  find_dup (numbers);
  return 0;
}
