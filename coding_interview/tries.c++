#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Contacts {
    private:
        vector<string> names;

    public:
        Contacts ():
            names() {}

        void add (string name) {
            names.push_back(name);
        }

        void find (string name) {
            size_t found = -1;
            int count = 0;
            for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
                found = (*it).find(name);
                if (found < (*it).length())
                    count++;
            }
            cout << count << endl;
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int test_num = 0;
    cin >> test_num;
    Contacts c;
    for (int i = 0; i < test_num; ++i) {
        string instr, str;
        cin >> instr >> str;
        if (instr == "add")
            c.add(str);
        else if (instr == "find")
            c.find(str);
    }
    return 0;
}

/*
*   Use Tries data structure
*/

/*
#include <string>       // compare
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Node {
private:
    int count;
	bool isFullWord;
	map<char, Node*> m;

public:
	Node ():
        count(0), m() {}

	void add (string name) {
        Node* curr = this;
        curr->count++;

		for (char &c : name) {
            if (!(curr->hasChild(c))) {
                // if there is no node with c, then make a new node
                Node* next = new Node;
                curr->m.insert(pair<char, Node*>(c, next));
                curr = next;
            } else {
                curr = curr->hasChild(c);
            }

            curr->count++;
		}
	}

    Node* hasChild(char& c) {
        auto it = this->m.find(c);
        if (it != this->m.end())
            return it->second;
        return nullptr;
    }

	void find(string partial) {
        Node* curr = this;
        for (char& c : partial) {
            curr = curr->hasChild(c);

            if (!curr) {
                // if there is no child print 0
                cout << "0" << endl;
                return;
            }
        }
        // else print count
        cout << curr->count << endl;
        return;
	}
};

int main() {
    int cases = 0;
    cin >> cases;
    Node *root = new Node;
    while (cases--) {
        string instruction, name;
        cin >> instruction >> name;
        if (instruction.compare("add") == 0)
            root->add(name);
        else if (instruction.compare("find") == 0)
            root->find(name);
    }
    delete root;
    return 0;
}
*/
