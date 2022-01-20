#include <bits/stdc++.h>
using namespace std;
class Dsu {
   private:
    // parent vector
    vector<int> parent;

    // size vector
    vector<int> size;

   public:
    // constructor
    Dsu(int n) {
        // resizing and intilizing parent vector
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;

        // resizing and intilizing size vector
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) size[i] = 1;
    }

    // find fuction with path compression
    int find(int u) {
        return parent[u] = (parent[u] == u) ? u : find(parent[u]);
    }

    // union by size
    void merge(int u, int v) {
        int a = find(u);
        int b = find(v);
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};
int main() {
    int size = 4;
    Dsu d(size);
    d.merge(1, 2);
    d.merge(2, 3);
    d.merge(1, 3);
    cout << d.find(1) << " ";
    cout << d.find(2) << " ";
    cout << d.find(3) << " ";
    cout << d.find(4) << " ";
}