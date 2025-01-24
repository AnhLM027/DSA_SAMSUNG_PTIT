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

int findMaxPathSum(Node* root, int& maxSum) {
    if (!root) return 0;

    int leftSum = findMaxPathSum(root->left, maxSum);
    int rightSum = findMaxPathSum(root->right, maxSum);

    // Cập nhật maxSum nếu cả hai con tồn tại
    if (root->left && root->right) {
        maxSum = max(maxSum, leftSum + rightSum + root -> val);
        return max(leftSum, rightSum) + root -> val;
    }

    // Nếu chỉ có một con, trả về tổng của con đó
    return (root->left ? leftSum : rightSum) + root->val;
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
		int ans = -1e9;
		findMaxPathSum(root, ans);
		cout << ans << endl;
    }
    return 0;
}       
