#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<5> bs1("10100");
    bitset<5> bs2("10101");
    cout << (bs1 & bs2).count() << endl;
    return 0;
}