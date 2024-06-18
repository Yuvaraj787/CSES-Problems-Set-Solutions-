/*
A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example 1
Input:
5

Output:
4 2 5 3 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    } 

    for (int i = 2; i <= n; i += 2) {
        arr.push_back(i);
    }


    for (int i = 1; i <= n; i += 2) {
        arr.push_back(i);
    }



    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}