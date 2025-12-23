#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(nullptr) {}
    void buildExample() {
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
    }
    void preorder(Node* n) {
        if (!n) return;
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
    void postorder(Node* n) {
        if (!n) return;
        postorder(n->left);
        postorder(n->right);
        cout << n->data << " ";
    }
    void preorderIterative() {
        if (!root) return;
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* cur = st.top(); st.pop();
            cout << cur->data << " ";
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
    }
    void inorderIterative() {
        stack<Node*> st;
        Node* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            cout << cur->data << " ";
            cur = cur->right;
        }
    }
    void postorderIterative() {
        if (!root) return;
        stack<Node*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            Node* cur = st1.top(); st1.pop();
            st2.push(cur);
            if (cur->left) st1.push(cur->left);
            if (cur->right) st1.push(cur->right);
        }
        while (!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
    }
    void bfs() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            cout << cur->data << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    bool find(Node* n, int x) {
        if (!n) return false;
        if (n->data == x) return true;
        return find(n->left, x) || find(n->right, x);
    }
    int sum(Node* n) {
        if (!n) return 0;
        return n->data + sum(n->left) + sum(n->right);
    }
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}
    Node* insert(Node* n, int x) {
        if (!n) return new Node(x);
        if (x < n->data)
            n->left = insert(n->left, x);
        else
            n->right = insert(n->right, x);
        return n;
    }
    void insert(int x) {
        root = insert(root, x);
    }
    bool find(Node* n, int x) {
        if (!n) return false;
        if (n->data == x) return true;
        if (x < n->data) return find(n->left, x);
        return find(n->right, x);
    }
    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
};

int main() {
    cout<<"Binarno drvo:: "<<endl;
    BinaryTree bt;
    bt.buildExample();
    cout<<"Rekurzivno:"<<endl;
    cout<<"Preorder: ";
    bt.preorder(bt.root);
    cout<<endl<<"Inorder: ";
    bt.inorder(bt.root);
    cout<<endl<<"Postorder: ";
    bt.postorder(bt.root);
    cout<<endl<<"Iterativno:"<<endl;
    cout<<"Preorder: ";
    bt.preorderIterative();
    cout<<endl<<"Inorder: ";
    bt.inorderIterative();
    cout<<endl<<"Postorder: ";
    bt.postorderIterative();
    cout<<endl;
    cout<<"BFS: ";
    bt.bfs();
    cout<<endl;
    cout<<"Najdi 5: " << bt.find(bt.root, 5)<<endl;
    cout << "Najdi 10: " << bt.find(bt.root, 10)<<endl;
    cout << "Suma na elementi: " << bt.sum(bt.root)<<endl<<endl;


    cout << "Binary Search Tree:: "<<endl;
    BST bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);

    cout << "Inorder (sortirano): ";
    bst.inorder(bst.root);
    cout<<endl;
    cout << "Najdi 6: " << bst.find(bst.root, 6)<<endl;
    cout << "Najdi 7: " << bst.find(bst.root, 7);

    return 0;
}
