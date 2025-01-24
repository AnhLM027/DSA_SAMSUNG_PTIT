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

void KhoiPhuc(Node*& root, vector<string>& a, int i) {
	if(!root) return;
    if(root -> val == stoi(a[i])) {
    	if(a[i + 2] == "L") {
    		root -> left = new Node(stoi(a[i + 1]));
		}
    	else if(a[i + 2] == "R") {
    		root -> right = new Node(stoi(a[i + 1])); 
		}
		return;
	}
    if(root -> left) KhoiPhuc(root -> left, a, i);
	if(root -> right) KhoiPhuc(root -> right, a, i);
}

void ReverseLevelOrder(Node* node) {
    if (node == nullptr) return;
    queue<Node*> qe;
	qe.push(node);
	vector<int> res;
	while(!qe.empty()) {
		Node* top = qe.front(); qe.pop();
		res.push_back(top -> val);
		if(top -> right) qe.push(top -> right);	
		if(top -> left) qe.push(top -> left);
	}
	for(int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
}

int main() {
    int te;
    cin >> te;
    while (te--) {
        int n; cin >> n;
        vector<string> a(3 * n);
        for(string& x : a) cin >> x;
        Node* root = new Node(stoi(a[0]));
		for(int i = 0; i < a.size(); i += 3) {
    		KhoiPhuc(root, a, i);
		}
        ReverseLevelOrder(root);
        cout << endl;
    }
    return 0;
}
