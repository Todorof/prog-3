#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root;

    BST() { root =NULL; }
    Node* insert(Node* node, int v) {
        if (!node) return new Node(v);
        if (v < node->val) node->left = insert(node->left, v);
        else node->right = insert(node->right, v);
        return node;
    }

    void insert(int v) {
        root = insert(root, v);
    }

    bool find(Node* node, int v) {
        if (!node) return false;
        if (node->val == v) return true;
        if (v < node->val) return find(node->left, v);
        return find(node->right, v);
    }

    bool find(int v) {
        return find(root, v);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

    void preorder_iter() {
        if (!root) return;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* n = st.top(); st.pop();
            cout << n->val << " ";
            if (n->right) st.push(n->right);
            if (n->left)  st.push(n->left);
        }
    }

    void inorder_iter() {
        stack<Node*> st;
        Node* curr = root;
        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            cout << curr->val << " ";
            curr = curr->right;
        }
    }

    void postorder_iter() {
        if (!root) return;
        stack<Node*> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            Node* n = st1.top(); st1.pop();
            st2.push(n);
            if (n->left) st1.push(n->left);
            if (n->right) st1.push(n->right);
        }
        while (!st2.empty()) {
            cout << st2.top()->val << " ";
            st2.pop();
        }
    }

    void bfs() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* n = q.front(); q.pop();
            cout << n->val << " ";
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
    }

    int sum(Node* node) {
        if (!node) return 0;
        return node->val + sum(node->left) + sum(node->right);
    }

    int sum() {
        return sum(root);
    }
};

int main() {
    BST t;
    t.insert(8);
    t.insert(3);
    t.insert(10);
    t.insert(1);
    t.insert(6);
    t.insert(14);
    
    cout << "Rekurzivno inorder: ";
    t.inorder(t.root); cout << endl;
    
    cout << "Iterativno inorder: ";
    t.inorder_iter(); cout << endl;
    
    cout << "BFS: ";
    t.bfs(); cout << endl;
    
    cout << "Suma = " << t.sum() << endl;
    cout << "Najde 6?" << (t.find(6) ? "DA" : "NE") << endl;
}
