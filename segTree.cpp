#include <bits/stdc++.h>
using namespace std;
class SegTree {
   private:
    int size;
    vector<int> arr;

   public:
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        arr.assign(2 * size, 0);
    }

    void build(vector<int>& a, int v, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) arr[v] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * v + 1, lx, m);
        build(a, 2 * v + 2, m, rx);
        arr[v] = arr[2 * v + 1] + arr[2 * v + 2];
    }

    void build(vector<int>& a) { build(a, 0, 0, size); }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            arr[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        arr[x] = arr[x * 2 + 1] + arr[x * 2 + 2];
    }

    void set(int i, int v) { set(i, v, 0, 0, size); }

    int sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return arr[x];
        int m = (lx + rx) / 2;
        int s1 = sum(l, r, 2 * x + 1, lx, m);
        int s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int sum(int l, int r) { return sum(l, r, 0, 0, size); }
};
int main() {
    vector<int> v = {1, 2, 3, 4, 2, 3, 5, 0};
    SegTree st(v.size());
    st.build(v);
    cout << st.sum(0, 2) << " ";
    st.set(1, 10);
    cout << st.sum(0, 2) << " ";
    return 0;
}