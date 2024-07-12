#include <bits/stdc++.h>
using namespace std;


using tp = chrono::high_resolution_clock::time_point;

using ll = long long;
using pii = pair<int,int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;

int mod = 1e9 + 7;

void printCurrentTime() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int hour = now->tm_hour % 12;
    hour = hour ? hour : 12; // handle midnight case
    cout << "Last Run Time reporting : ";
    cout << hour << ':'
              << (now->tm_min < 10 ? "0" : "") << now->tm_min
              << (now->tm_hour >= 12 ? " PM" : " AM") << endl << endl;
}

void printRuntime(tp start, tp end) {
    cout << endl;
    chrono::duration<double> duration = end - start;

    cout << fixed << setprecision(6);
    cout << "Runtime: " << duration.count() << " seconds" << endl;
}

struct Node {
    Node * childs[26];
    int prefixCount = 0;
    int endCount = 0;

    void makeItEnd() {
        endCount++;
    }
    Node * getChild(char a) {
        return childs[a - 'a'];
    }
    bool isPresent(char a) {
        return childs[a - 'a'] != nullptr;
    }
    void increaseThePrefixCount() {
        prefixCount++;
    }
    void makeAChild(char a, Node * node) {
        childs[a - 'a'] = node;
    }
};

class Trie {
    public:
    Node * root;

    Trie() {
        root = new Node();
    }

    void insertWord(string& word) {
        Node * temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!temp->isPresent(word[i])) {
                temp->makeAChild(word[i], new Node());
            }
            temp = temp->getChild(word[i]);
            temp->increaseThePrefixCount();
        }
        temp->makeItEnd();
    }

    int countString(string& word) {
        Node * temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!temp->isPresent(word[i])) {
                return 0;
            }
            temp = temp->getChild(word[i]);
        }
        return temp->endCount;
    }

    int prefixCount(string& word) {
        Node * temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!temp->isPresent(word[i])) {
                return 0;
            }
            temp = temp->getChild(word[i]);
        }
        return temp->prefixCount;
    }
};

void program() {
    int n, q;
    cin >> n >> q;
    Trie t1;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        t1.insertWord(word);
    }
    for (int i = 0; i < q; i++) {
        int type;
        string word;
        cin >> type >> word;
        if (type == 1) {
            int countEnd = t1.countString(word);
            if (countEnd == 0) {
                cout << "NOT PRESENT" << endl;
            } else {
                cout << "PRESENT" << endl;
                cout << countEnd << endl;
            }
        } else if (type == 2) {
            int prefixCount = t1.prefixCount(word);
            if (prefixCount == 0) {
                cout << "NOT PRESENT" << endl;
            } else {
                cout << "PRESENT" << endl;
                cout << prefixCount << endl;
            }
        }
    }
}

int main() {    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    printCurrentTime();
    auto start = chrono::high_resolution_clock::now();

    program();

    auto end = chrono::high_resolution_clock::now();
    printRuntime(start, end);
    return 0;
}