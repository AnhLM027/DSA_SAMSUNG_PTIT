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

bool check(Node* node1, Node* node2) {
    if(!node1 && !node2) return 1;
	if(node1 -> val != node2 -> val) return false;
	return check(node1 -> right, node2 -> right) && check(node1 -> left, node2 -> left);
}
	
int main() {
    int te;
    cin >> te;
    while (te--) {
        int n; cin >> n;
        vector<string> a(3 * n);
        for(string& x : a) cin >> x;
		int m; cin >> m;
		vector<string> b(3 * m);
        for(string& x : b) cin >> x;
        
        if(n != m) {
        	cout << 0 << endl;
        	continue;
		}
		Node* root1 = new Node(stoi(a[0]));
		for(int i = 0; i < a.size(); i += 3) {
    		KhoiPhuc(root1, a, i);
		}
        Node* root2 = new Node(stoi(b[0]));
		for(int i = 0; i < b.size(); i += 3) {
    		KhoiPhuc(root2, b, i);
		}
        if(check(root1, root2)) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}       
