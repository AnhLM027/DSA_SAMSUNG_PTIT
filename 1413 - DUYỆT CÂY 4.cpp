#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;	
	Node* right;
	Node() {
		left = right = nullptr;
		val = 0;
	}
	Node(int x) {
		val = x;
		left = right = nullptr;
	}
};


void KhoiPhuc(Node*& root, vector<int>& a, vector<int>& b) {
    root = new Node(b[0]);
    queue<pair<Node*, vector<int>>> qe;
    qe.push({root, a});
    int cnt = 1;

    while (!qe.empty()) {
        auto [node, v] = qe.front();
        qe.pop();

        int i = 0;
        while (i < v.size() && v[i] != node -> val) i++;

        vector<int> a1(v.begin(), v.begin() + i);
        vector<int> a2(v.begin() + i + 1, v.end());

        if (!a1.empty() && cnt < b.size()) {
            node->left = new Node(b[cnt++]);
            qe.push({node->left, a1});
        }

        if (!a2.empty() && cnt < b.size()) {
            node->right = new Node(b[cnt++]);
            qe.push({node->right, a2});
        }
    }
}

void Postorder(Node* root) {
	if(!root) return;
	Postorder(root -> left);
	Postorder(root -> right);
	cout << root -> val << " ";
}

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for(int& x : a) cin >> x;
		for(int& x : b) cin >> x;
		Node* root = nullptr;
		KhoiPhuc(root, a, b);
		Postorder(root);
		cout << endl;
	}
}