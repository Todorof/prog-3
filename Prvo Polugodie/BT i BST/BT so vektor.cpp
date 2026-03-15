#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insertNode(vector<int>& tree, int val) {
    tree.push_back(val);
}
int treeSum(const vector<int>& tree) {
    int s = 0;
    for (int x : tree) s += x;
    return s;
}
bool contains(const vector<int>& tree, int val) {
    for (int x : tree)
        if (x == val) return true;
    return false;
}
void bfs(const vector<int>& tree) {
    for (int x : tree)
        cout << x << " ";
    cout << endl;
}
void preorderRec(const vector<int>& tree, int i = 0) {
    if (i >= tree.size()) return;
    cout << tree[i] << " ";
    preorderRec(tree, 2 * i + 1);
    preorderRec(tree, 2 * i + 2);
}
void inorderRec(const vector<int>& tree, int i = 0) {
    if (i >= tree.size()) return;
    inorderRec(tree, 2 * i + 1);
    cout << tree[i] << " ";
    inorderRec(tree, 2 * i + 2);
}
void postorderRec(const vector<int>& tree, int i = 0) {
    if (i >= tree.size()) return;
    postorderRec(tree, 2 * i + 1);
    postorderRec(tree, 2 * i + 2);
    cout << tree[i] << " ";
}
void preorderIter(const vector<int>& tree) {
    if (tree.empty()) return;
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int i = st.top(); st.pop();
        cout << tree[i] << " ";
        if (2 * i + 2 < tree.size()) st.push(2 * i + 2);
        if (2 * i + 1 < tree.size()) st.push(2 * i + 1);
    }
    cout << endl;
}
void inorderIter(const vector<int>& tree) {
    stack<int> st;
    int i = 0;
    while (!st.empty() || i < tree.size()) {
        while (i < tree.size()) {
            st.push(i);
            i = 2 * i + 1;
        }
        i = st.top(); st.pop();
        cout << tree[i] << " ";
        i = 2 * i + 2;
    }
    cout << endl;
}
void postorderIter(const vector<int>& tree) {
    if (tree.empty()) return;
    stack<int> st;
    int i = 0;
    int last = -1;
    while (!st.empty() || i < tree.size()) {
        if (i < tree.size()) {
            st.push(i);
            i = 2 * i + 1;
        } else {
            int top = st.top();
            int right = 2 * top + 2;
            if (right < tree.size() && last != right) {
                i = right;
            } else {
                cout << tree[top] << " ";
                last = top;
                st.pop();
            }
        }
    }
    cout << endl;
}
int main() {
    vector<int> tree;
    for (int i = 1; i < 32; i++)
        insertNode(tree, i);

    cout << "Suma: " << treeSum(tree) << endl;
    cout << "Najdi 27: " << contains(tree, 27) << endl;

    cout << "BFS: ";
    bfs(tree);
    cout<<endl;

    cout<<"DFS:: "<<endl;
    cout<<"Rekurzivno: "<<endl;
    cout<<"Preorder: ";
    preorderRec(tree);
    cout << endl;
    cout << "Inorder: ";
    inorderRec(tree);
    cout << endl;
    cout << "Postorder: ";
    postorderRec(tree);
    cout << endl;
    cout<<"Iterativno: "<<endl;
    cout << "Preorder: ";
    preorderIter(tree);
    cout << "Inorder: ";
    inorderIter(tree);
    cout << "Postorder: ";
    postorderIter(tree);

    return 0;
}
