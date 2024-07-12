#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, q;
vector<ll> arr;


void buildTree(ll tree[], ll index, ll l, ll h) {
    if (l == h) {
        tree[index] = arr[l];
        return;
    }
    ll mid = (l + h) / 2;
    ll li = 2 * index + 1;
    ll ri = li + 1;
    buildTree(tree, li, l, mid);
    buildTree(tree, ri, mid + 1, h);

    tree[index] = tree[li] + tree[ri];
}

ll handleSumQuery(ll tree[], ll update_range_tree[], ll set_range_tree[], ll index, ll l, ll h, ll givenL, ll givenH) {
    
    ll mid = (l + h) / 2;
    ll li = 2 * index + 1;
    ll ri = li + 1;

    
    if (update_range_tree[index] > 0) {
        
        tree[index] += ((h - l + 1) * update_range_tree[index]);
        if (l != h) {
            
            if (set_range_tree[li] > 0) {
                set_range_tree[li] += update_range_tree[index];
            } else {
                update_range_tree[li] += update_range_tree[index];
            }

            if (set_range_tree[ri] > 0) {
                set_range_tree[ri] += update_range_tree[index];
            } else {
                update_range_tree[ri] += update_range_tree[index];
            }
        }

        update_range_tree[index] = 0;
    }

     if (set_range_tree[index] > 0) {
        tree[index] = (h - l + 1) * set_range_tree[index];
        if (l != h) {
            set_range_tree[li] = set_range_tree[index];
            set_range_tree[ri] = set_range_tree[index];
            update_range_tree[li] = 0;
            update_range_tree[ri] = 0;
        }
        set_range_tree[index] = 0;
    }

    if (l >= givenL && h <= givenH ) {
        return tree[index];
    }

    if (l > givenH || h < givenL) return 0;


    return handleSumQuery(tree, update_range_tree, set_range_tree, li, l, mid, givenL, givenH) + handleSumQuery(tree, update_range_tree, set_range_tree,  ri, mid + 1, h, givenL, givenH);
    
}



void updateRange(ll tree[], ll update_range_tree[], ll set_range_tree[], ll index, ll l, ll h, ll givenL, ll givenH, ll x) {
    
    ll li = 2 * index + 1;
    ll ri = li + 1;
    ll mid = (l + h) / 2;

    // cout << "here with " << l << " and " << h << endl;


    if (update_range_tree[index] > 0) {

        // cout << "here there is a previous update of " << update_range_tree[index] << " found" << endl; 
        // cout << "so tree is increased by " << (h - l + 1) * update_range_tree[index] << endl;
        
        tree[index] += ((h - l + 1) * update_range_tree[index]);
        if (l != h) {
            if (set_range_tree[li] > 0) {
                set_range_tree[li] += update_range_tree[index];
            } else {
                update_range_tree[li] += update_range_tree[index];
            }

            if (set_range_tree[ri] > 0) {
                set_range_tree[ri] += update_range_tree[index];
            } else {
                update_range_tree[ri] += update_range_tree[index];
            }
        }

        update_range_tree[index] = 0;
    }

     if (set_range_tree[index] > 0) {
        tree[index] = (h - l + 1) * set_range_tree[index];
        if (l != h) {
            set_range_tree[li] = set_range_tree[index];
            set_range_tree[ri] = set_range_tree[index];
            update_range_tree[li] = 0;
            update_range_tree[ri] = 0;
        }
        set_range_tree[index] = 0;
    }
    
    if (l >= givenL && h <= givenH) {
        tree[index] += (x * (h - l + 1));
         if (l != h) {
            if (set_range_tree[li] > 0) {
                set_range_tree[li] += x;
            } else {
                update_range_tree[li] += x;
            }

            if (set_range_tree[ri] > 0) {
                set_range_tree[ri] += x;
            } else {
                update_range_tree[ri] += x;
            }
        }
        return;
    }

    if (l > givenH || h < givenL) return;


    updateRange(tree, update_range_tree, set_range_tree, li, l, mid, givenL, givenH, x);
    updateRange(tree, update_range_tree, set_range_tree, ri, mid + 1, h, givenL, givenH, x);
    tree[index] = tree[li] + tree[ri];
}

void setRange(ll tree[], ll set_range_tree[], ll update_range_tree[], ll index, ll l, ll h, ll givenL, ll givenH, ll x) {
      
    ll mid = (l + h) / 2;
    ll li = 2 * index + 1;
    ll ri = li + 1;

    
    if (update_range_tree[index] > 0) {
        
        tree[index] += ((h - l + 1) * update_range_tree[index]);
        if (l != h) {
            if (set_range_tree[li] > 0) {
                set_range_tree[li] += update_range_tree[index];
            } else {
                update_range_tree[li] += update_range_tree[index];
            }

            if (set_range_tree[ri] > 0) {
                set_range_tree[ri] += update_range_tree[index];
            } else {
                update_range_tree[ri] += update_range_tree[index];
            }
        }

        update_range_tree[index] = 0;
    }

     if (set_range_tree[index] > 0) {
        tree[index] = (h - l + 1) * set_range_tree[index];
        if (l != h) {
            set_range_tree[li] = set_range_tree[index];
            set_range_tree[ri] = set_range_tree[index];
            update_range_tree[li] = 0;
            update_range_tree[ri] = 0;
        }
        set_range_tree[index] = 0;
    }

    if (l >= givenL && h <= givenH) {
        tree[index] = (h - l + 1) * x;
        if (l != h) {
            update_range_tree[li] = 0;
            update_range_tree[ri] = 0;
            set_range_tree[li] = x;
            set_range_tree[ri] = x;
        }
        return;
    }

    if (l > givenH || h < givenL) return;

    setRange(tree, set_range_tree, update_range_tree, li, l, mid, givenL, givenH, x);
    setRange(tree, set_range_tree, update_range_tree, ri, mid + 1, h, givenL, givenH, x);

    tree[index] = tree[li] + tree[ri];
}



int main() {
    cin >> n >> q;
    arr.resize(n);
    
    ll tree[n * 4];
    ll range_update[n * 4];
    ll range_set[n * 4];

    memset(range_update, 0, n * 4 * sizeof(long long)); 
    memset(range_set, 0, n * 4 * sizeof(long long)); 


    for (ll& i : arr) {
        cin >> i;
    }

    buildTree(tree, 0, 0, n - 1);


    for (ll i = 0; i < q; i++) {
        ll t, a, b, x;
        cin >> t >> a >> b;
        a--; b--;
        if (t == 3) {
            cout << handleSumQuery(tree, range_update, range_set, 0, 0, n - 1, a, b) << endl;
        } else if (t == 1) {
            cin >> x;
            updateRange(tree, range_update, range_set, 0, 0, n - 1, a, b, x);
        } else {
            cin >> x;
            setRange(tree, range_set, range_update, 0, 0, n - 1, a, b, x);
        }
    }

    // updateRange(tree, range_update, range_set, 0, 0, n - 1, 0, 5, 2);

    // cout << handleSumQuery(tree, range_update, range_set, 0, 0, n - 1, 1, 3) << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll n, q;
// vector<ll> arr;

// void buildTree(vector<ll>& tree, ll index, ll l, ll h) {
//     if (l == h) {
//         tree[index] = arr[l];
//         return;
//     }
//     ll mid = (l + h) / 2;
//     ll li = 2 * index + 1;
//     ll ri = li + 1;
//     buildTree(tree, li, l, mid);
//     buildTree(tree, ri, mid + 1, h);
//     tree[index] = tree[li] + tree[ri];
// }

// void propagate(vector<ll>& tree, vector<ll>& update_range_tree, vector<ll>& set_range_tree, ll index, ll l, ll h) {
//     ll li = 2 * index + 1;
//     ll ri = li + 1;

//     if (set_range_tree[index] != LLONG_MIN) {
//         tree[index] = (h - l + 1) * set_range_tree[index];
//         if (l != h) {
//             set_range_tree[li] = set_range_tree[index];
//             set_range_tree[ri] = set_range_tree[index];
//             update_range_tree[li] = 0;
//             update_range_tree[ri] = 0;
//         }
//         set_range_tree[index] = LLONG_MIN;
//     }

//     if (update_range_tree[index] != 0) {
//         tree[index] += (h - l + 1) * update_range_tree[index];
//         if (l != h) {
//             if (set_range_tree[li] != LLONG_MIN) {
//                 set_range_tree[li] += update_range_tree[index];
//             } else {
//                 update_range_tree[li] += update_range_tree[index];
//             }
//             if (set_range_tree[ri] != LLONG_MIN) {
//                 set_range_tree[ri] += update_range_tree[index];
//             } else {
//                 update_range_tree[ri] += update_range_tree[index];
//             }
//         }
//         update_range_tree[index] = 0;
//     }
// }

// ll handleSumQuery(vector<ll>& tree, vector<ll>& update_range_tree, vector<ll>& set_range_tree, ll index, ll l, ll h, ll givenL, ll givenH) {
//     propagate(tree, update_range_tree, set_range_tree, index, l, h);

//     if (l > givenH || h < givenL) return 0;
//     if (l >= givenL && h <= givenH) return tree[index];

//     ll mid = (l + h) / 2;
//     ll li = 2 * index + 1;
//     ll ri = li + 1;
//     return handleSumQuery(tree, update_range_tree, set_range_tree, li, l, mid, givenL, givenH) +
//            handleSumQuery(tree, update_range_tree, set_range_tree, ri, mid + 1, h, givenL, givenH);
// }

// void updateRange(vector<ll>& tree, vector<ll>& update_range_tree, vector<ll>& set_range_tree, ll index, ll l, ll h, ll givenL, ll givenH, ll x) {
//     propagate(tree, update_range_tree, set_range_tree, index, l, h);

//     if (l > givenH || h < givenL) return;
//     if (l >= givenL && h <= givenH) {
//         update_range_tree[index] += x;
//         propagate(tree, update_range_tree, set_range_tree, index, l, h);
//         return;
//     }

//     ll mid = (l + h) / 2;
//     ll li = 2 * index + 1;
//     ll ri = li + 1;
//     updateRange(tree, update_range_tree, set_range_tree, li, l, mid, givenL, givenH, x);
//     updateRange(tree, update_range_tree, set_range_tree, ri, mid + 1, h, givenL, givenH, x);
//     tree[index] = tree[li] + tree[ri];
// }

// void setRange(vector<ll>& tree, vector<ll>& set_range_tree, vector<ll>& update_range_tree, ll index, ll l, ll h, ll givenL, ll givenH, ll x) {
//     propagate(tree, update_range_tree, set_range_tree, index, l, h);

//     if (l > givenH || h < givenL) return;
//     if (l >= givenL && h <= givenH) {
//         set_range_tree[index] = x;
//         propagate(tree, update_range_tree, set_range_tree, index, l, h);
//         return;
//     }

//     ll mid = (l + h) / 2;
//     ll li = 2 * index + 1;
//     ll ri = li + 1;
//     setRange(tree, set_range_tree, update_range_tree, li, l, mid, givenL, givenH, x);
//     setRange(tree, set_range_tree, update_range_tree, ri, mid + 1, h, givenL, givenH, x);
//     tree[index] = tree[li] + tree[ri];
// }

// int main() {
//     cin >> n >> q;
//     arr.resize(n);
    
//     vector<ll> tree(n * 4, 0);
//     vector<ll> range_update(n * 4, 0);
//     vector<ll> range_set(n * 4, LLONG_MIN);

//     for (ll& i : arr) {
//         cin >> i;
//     }

//     buildTree(tree, 0, 0, n - 1);

//     for (ll i = 0; i < q; i++) {
//         ll t, a, b, x;
//         cin >> t >> a >> b;
//         a--; b--;
//         if (t == 3) {
//             cout << handleSumQuery(tree, range_update, range_set, 0, 0, n - 1, a, b) << endl;
//         } else if (t == 1) {
//             cin >> x;
//             updateRange(tree, range_update, range_set, 0, 0, n - 1, a, b, x);
//         } else if (t == 2) {
//             cin >> x;
//             setRange(tree, range_set, range_update, 0, 0, n - 1, a, b, x);
//         }
//     }

//     return 0;
// }
