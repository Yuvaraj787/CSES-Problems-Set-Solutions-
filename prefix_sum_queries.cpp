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

const int m_size = 2 * 1e5 + 1;
ll tree[4 * m_size];
ll pTree[4 * m_size];


void printRuntime(tp start, tp end) {
    cout << endl;
    chrono::duration<double> duration = end - start;

    cout << fixed << setprecision(6);
    cout << "Runtime: " << duration.count() << " seconds" << endl;
}
vector<int> arr;

void buildTree(int index, int l, int h) {
    if (l == h) {
        tree[index] = arr[l];
        pTree[index] = arr[l];
        return;
    }
    int mid = (l + h) / 2;
    int li =  2 * index + 1;
    int ri = li + 1;
    buildTree(li, l, mid);
    buildTree(ri, mid + 1, h);
    tree[index] = tree[li] + tree[ri];
    pTree[index] = max(pTree[li], tree[li] + pTree[ri]);
}

void pointUpdate(int index,  int l, int h, int pos, int target) {
    if (l == h) {
        tree[index] = target;
        pTree[index] = target;
        return;
    }
    int mid = (l + h) / 2;
    int li = 2 * index + 1;
    int ri = li + 1;

    if (l <= pos && pos <= mid) {
        pointUpdate(li,  l, mid, pos, target);
    } else {
        pointUpdate(ri,  mid + 1, h, pos, target);
    }

    tree[index] = tree[li] + tree[ri];
    pTree[index] = max(pTree[li], tree[li] + pTree[ri]);
}

pair<ll,ll> maxiSumQuery(int index, int l, int h, int givenL, int givenH) {
    
    if (l >= givenL && h <= givenH) {
        return {tree[index], pTree[index]};
    }

    if (givenH < l || givenL > h) {
        return {0, 0};
    }

    int mid = (l + h) / 2;
    int li = 2 * index + 1;
    int ri = li + 1;

    pair<ll,ll> left = maxiSumQuery(li, l, mid, givenL, givenH);
    pair<ll,ll> right = maxiSumQuery(ri, mid + 1, h, givenL, givenH);

    pair<ll,ll> res = {left.first + right.first, max(left.second, left.first + right.second)};
    
    // cout << "Total sum " << l << " <-> " << h << " is " << res.first << endl;
    // cout << "Prefix sum " << l << " <-> " << h << " is " << res.second << endl << endl;

    return res;
}

void program() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int& i : arr) cin >> i;

    buildTree(0, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, k;
            cin >> u >> k;
            pointUpdate(0, 0, n - 1, u - 1, k);
        } else {
            int a, b;
            cin >> a >> b;
            // cout << maxiSumQuery(0, 0, n - 1, a - 1, b - 1).first << endl;
            cout << max(1ll * 0, maxiSumQuery(0, 0, n - 1, a - 1, b - 1).second) << endl;
        } 
    }

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // printCurrentTime();
    auto start = chrono::high_resolution_clock::now();

    program();

    auto end = chrono::high_resolution_clock::now();
    // printRuntime(start, end);
    return 0;
}