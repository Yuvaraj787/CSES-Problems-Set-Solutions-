#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> movies;

    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies.push_back({b, a});
    }

    sort(movies.begin(), movies.end());

    int curTime = 0;

    int countOfMovies = 0;

    for (auto &i : movies) {
        if (curTime <= i.second) {
            countOfMovies++;
            curTime = i.first;
        }
    }

    cout << countOfMovies << endl;

    return 0;
}