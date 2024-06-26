#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    ll sumDeadLines = 0;
    vector<int> durations;

    int duration, deadLine;

    for (int i = 0; i < n; i++) {
        cin >> duration >> deadLine;
        sumDeadLines += deadLine;
        durations.push_back(duration);
    }

    sort(durations.begin(), durations.end());

    ll timer = 0;

    ll sumFinishingTimes = 0;

    for (int i : durations) {
        timer += i;
        sumFinishingTimes += timer;
    }

    cout << sumDeadLines - sumFinishingTimes << endl;

    return 0;
}