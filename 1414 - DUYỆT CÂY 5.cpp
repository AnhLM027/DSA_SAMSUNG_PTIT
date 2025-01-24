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

void spiralPrint(struct Node* root) {
    deque<Node*> dq;
    dq.push_back(root);
    bool reverse = true;
    
    while (!dq.empty()) {
        int n = dq.size();
        if (!reverse) {
            while (n--) {
                if (dq.front() -> left != NULL)
                    dq.push_back(dq.front() -> left);

                if (dq.front() -> right != NULL)
                    dq.push_back(dq.front() -> right);

                cout << dq.front() -> val << " ";
                dq.pop_front();
            }
            reverse = !reverse;
        }
        else {
            while (n--) {
                if (dq.back() -> right != NULL)
                    dq.push_front(dq.back() -> right);

                if (dq.back() -> left != NULL)
                    dq.push_front(dq.back() -> left);

                cout << dq.back() -> val << " ";
                dq.pop_back();
            }
            reverse = !reverse;
        }
    }
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
        spiralPrint(root);
        cout << endl;
    }
    return 0;
}
