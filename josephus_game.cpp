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

int n, k;

vi arr(2e5 + 1, 0);

void update(int idx, int value) {
    for(;idx <= n; idx += idx & (- idx)) {
        arr[idx] += value;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx; idx -= idx & (-idx)) {
        sum += arr[idx];
    }
    return sum;
}

int rangeSum(int l, int h) {
    return query(h) - query(l - 1);
}

int binarySearch(int l, int h, int target) {
    int temp = l;
    while (l < h) {
        int mid = (l + h) / 2;
        int got = rangeSum(temp, mid);
        if (got >= target) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return h;
}

void program() {
    cin >> n >> k;
    int size = n;
    int tempk = k;
    k = k % size;
    for (int i = 1; i <= n; i++) {
        update(i, 1);
    }
    
    int cur = 1;

    vi res;



    for (int i = 1; i <= n; i++) {
        int available = rangeSum(cur, n);
        int needIndex;
        if (available >= (k + 1)) {
            needIndex = binarySearch(cur, n, k + 1);
        } else {
            int newK = k + 1 - available;
            needIndex = binarySearch(1, cur - 1, newK);
        }
        update(needIndex, -1);
        res.push_back(needIndex);
        cur = needIndex + 1;
        if (cur == n + 1) cur = 1;
        size--;
        if (size == 0) continue;
        k = tempk % size;
    }
    
    for (int i : res) cout << i << " ";
    cout << endl;
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