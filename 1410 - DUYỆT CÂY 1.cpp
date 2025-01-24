#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node() {
        val = 0;
        left = right = nullptr;
    }
    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};

void KhoiPhuc(Node*& c, vector<int>& a, vector<int>& b) {
	
    if (a.empty() || b.empty()) return;
    
    c = new Node(b[0]);
    int i = 0;
    while (i < a.size() && a[i] != b[0]) i++;

    vector<int> a1(a.begin(), a.begin() + i);
    vector<int> b1(b.begin() + 1, b.begin() + 1 + i);
    KhoiPhuc(c -> left, a1, b1);

    vector<int> a2(a.begin() + i + 1, a.end());
    vector<int> b2(b.begin() + 1 + i, b.end());
    KhoiPhuc(c -> right, a2, b2);
}

void Postorder(Node* node) {
    if (node == nullptr) return;
    Postorder(node->left);
    Postorder(node->right);
    cout << node -> val << " ";
}

int main() {
    int te;
    cin >> te;
    while (te--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
        Node* root = nullptr;
        KhoiPhuc(root, a, b);
        Postorder(root);
        cout << endl;
    }
    return 0;
}
