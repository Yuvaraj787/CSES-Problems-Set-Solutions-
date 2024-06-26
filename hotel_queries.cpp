#include <bits/stdc++.h>
using namespace std;

void buildTree(int tree[], vector<int>& freeRooms, int index, int l, int h) {
    if (l == h) {
        tree[index] = freeRooms[l];
        return;
    }
    
    int li = 2 * index + 1;
    int ri = li + 1;
    int mid = (l + h) / 2;

    buildTree(tree, freeRooms, li, l, mid);
    buildTree(tree, freeRooms, ri, mid + 1, h);

    tree[index] = max(tree[li], tree[ri]);
}


void pointUpdate(int tree[], int index, int l, int h, int target, int reduction) {
    if (l == h && l == target) {
        tree[index] -= reduction;
        return;
    }
    
    int li = 2 * index + 1;
    int ri = li + 1;
    int mid = (l + h) / 2;

    if (target >= l && target <= mid) {
        pointUpdate(tree, li, l, mid, target, reduction);
    } else {
        pointUpdate(tree, ri, mid + 1, h, target, reduction);
    }

    tree[index] = max(tree[li], tree[ri]);
}

int handleQuery(int tree[], int index, int l, int h, int givenL, int givenH) {
    if (givenL <= l && h <= givenH) {
        return tree[index];
    }

    if (givenH < l || givenL > h) return -1;

    int li = 2 * index + 1;
    int ri = li + 1;

    int mid = (l + h) / 2;

    int leftResult = handleQuery(tree, li, l, mid, givenL, givenH);
    int rightResult = handleQuery(tree, ri, mid + 1, h, givenL, givenH);

    return max(leftResult, rightResult);
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> freeRooms(n);

    int tree[n * 4];

    for (int& i : freeRooms) {
        cin >> i;
    }

    buildTree(tree, freeRooms, 0, 0, n - 1);

    for (int i  = 0; i < q; i++) {
        int req;
        cin >> req;
        int start = 0;
        int end = n - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (handleQuery(tree, 0, 0, n - 1, start, mid) >= req) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        if (freeRooms[end] < req) {
            cout << 0 << " ";
        } else {
            cout << end + 1 << " ";
            freeRooms[end] -= req;
            pointUpdate(tree, 0, 0, n - 1, end, req);
        }

    }

    return 0;
}