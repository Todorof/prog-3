#include <iostream>
#include <vector>
using namespace std;

class UnionFindBySize {
    vector<int> parent;
    vector<int> size;
public:
    UnionFindBySize(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        while (x != parent[x])
            x = parent[x];
        return x;
    }
    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        if (size[ra] < size[rb]) {
            parent[ra] = rb;
            size[rb] += size[ra];
        } else {
            parent[rb] = ra;
            size[ra] += size[rb];
        }
    }
};

class UnionFindByHeight {
    vector<int> parent;
    vector<int> height;
public:
    UnionFindByHeight(int n) {
        parent.resize(n);
        height.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        while (x != parent[x])
            x = parent[x];
        return x;
    }
    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        if (height[ra] < height[rb]) {
            parent[ra] = rb;
        } else if (height[ra] > height[rb]) {
            parent[rb] = ra;
        } else {
            parent[rb] = ra;
            height[ra]++;
        }
    }
};

class UnionFindByRankPC {
    vector<int> parent;
    vector<int> rank;
public:
    UnionFindByRankPC(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        if (rank[ra] < rank[rb]) {
            parent[ra] = rb;
        } else if (rank[ra] > rank[rb]) {
            parent[rb] = ra;
        } else {
            parent[rb] = ra;
            rank[ra]++;
        }
    }
};

int main() {
    cout << "Union-Find by Size"<<endl;
    UnionFindBySize ufSize(6);
    ufSize.unite(0, 1);
    ufSize.unite(2, 3);
    ufSize.unite(1, 2);
    cout << "0 i 3 se povrzani? "<< (ufSize.find(0) == ufSize.find(3)) <<endl;

    cout << "Union-Find by Height"<<endl;
    UnionFindByHeight ufHeight(6);
    ufHeight.unite(0, 1);
    ufHeight.unite(2, 3);
    ufHeight.unite(3, 4);
    ufHeight.unite(1, 4);
    cout << "0 i 4 se povrzani? "<< (ufHeight.find(0) == ufHeight.find(4)) <<endl;

    cout << "Union-Find by Rank + Path Compression"<<endl;
    UnionFindByRankPC ufRankPC(6);
    ufRankPC.unite(0, 1);
    ufRankPC.unite(1, 2);
    ufRankPC.unite(3, 4);
    ufRankPC.unite(2, 4);
    cout << "0 i 4 se povrzani? "<< (ufRankPC.find(0) == ufRankPC.find(4));

    return 0;
}
