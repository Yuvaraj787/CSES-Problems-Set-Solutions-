#include <bits/stdc++.h>
using namespace std;
vector<int> prices;
int n, q;

void buildLeftTree(int tree[], int low, int high, int index) {
    if (low == high) {
        tree[index] = prices[low] - low;
        return;
    }
    int mid = (low + high) / 2;
    int li = index * 2 + 1;
    int ri = li + 1;
    buildLeftTree(tree, low, mid, li);
    buildLeftTree(tree, mid + 1, high, ri);
    tree[index] = min(tree[li], tree[ri]);
} 

void buildRightTree(int tree[], int low, int high, int index) {
    if (low == high) {
        tree[index] = prices[low] + low;
        return;
    }
    int mid = (low + high) / 2;
    int li = index * 2 + 1;
    int ri = li + 1;
    buildRightTree(tree, low, mid, li);
    buildRightTree(tree, mid + 1, high, ri);
    tree[index] = min(tree[li], tree[ri]);
} 

void update(int tree[], int low, int high, int index, int targetIndex, int new_price) {
    if (low == high) {
        tree[index] -= prices[low];
        tree[index] += new_price;
        return;
    }
    int mid = (low + high) / 2;
    int li = 2 * index + 1;
    int ri = li + 1;
    if (targetIndex >= low && targetIndex <= mid) {
        update(tree, low, mid, li, targetIndex, new_price);
    } else {
        update(tree, mid + 1, high, ri, targetIndex, new_price);
    }
    tree[index] = min(tree[li], tree[ri]);
}

int handleQuery(int tree[], int low, int high, int index, int givenL, int givenH) {
    if (low >= givenL && high <= givenH) return tree[index];

    if (low > givenH || high < givenL) return 1e9;

    int mid = (low + high) / 2;
    int li = 2 * index + 1;
    int ri = li + 1;
    int left = handleQuery(tree, low, mid, li, givenL, givenH);
    int right = handleQuery(tree, mid + 1, high, ri, givenL, givenH);
    return min(left, right);
}



int main() {
    cin >> n >> q;

    prices.resize(n);
    
    for (int &i: prices) {
        cin >> i;
    }

    int leftTree[n * 4];
    int rightTree[n * 4];

    buildLeftTree(leftTree, 0, n -1, 0);
    
    buildRightTree(rightTree, 0, n -1, 0);


    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        int building;

        if (type == 1) {
            int new_price;
            cin >> building >> new_price;
            update(leftTree, 0, n - 1, 0, building - 1, new_price);
            update(rightTree, 0, n - 1, 0, building - 1, new_price);
            prices[building - 1] =  new_price;           
        } else {
            cin >> building;
            building--;
            int leftResult = handleQuery(leftTree, 0, n - 1, 0, 0, building);
            int rightResult = handleQuery(rightTree, 0, n - 1, 0, building + 1, n - 1);
            int mini = min(leftResult + building, rightResult - building);
            cout << mini << endl;
        }

    }
    return 0;
}

