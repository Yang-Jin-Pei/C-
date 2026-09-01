#include<iostream>
#include<vector>
using namespace std;

void recur(vector<int>& a, int m, int n) {
    if (m == n) {
        for (int x : a){cout << x << ' ';};
        cout << endl;
        return;
    }
    else {
        for (int i = m; i <= n; ++i) {
            swap(a[m],a[i]);
        recur(a,m + 1,n);
        swap(a[m],a[i]);
        }
    }
}
int main() {
    vector<int> a = {1,2,3};
    recur(a,0,2);
    return 0;
}