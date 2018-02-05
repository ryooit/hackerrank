#include <iostream> // istream, ostream
#include <sstream>  // stringstream
#include <string>
#include <vector>

using namespace std;
vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main() {
  string s = "3:00";
  vector<string> tokens = split(s, ':');
  for(auto& token : tokens)
  {
    cout << token << endl;
  }
  return 0;
}
