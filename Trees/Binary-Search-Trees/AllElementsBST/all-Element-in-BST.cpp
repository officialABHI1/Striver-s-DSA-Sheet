#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> mergeList(vector<int>& l1, vector<int>& l2, vector<int>& allElements) {
    size_t n = l1.size(), m = l2.size();
    size_t i = 0, j = 0;

    while (i < n && j < m) {
        if (l1[i] < l2[j]) {
            allElements.emplace_back(l1[i++]);
        } else {
            allElements.emplace_back(l2[j++]);
        }
    }

    while (i < n) {
        allElements.emplace_back(l1[i++]);
    }

    while (j < m) {
        allElements.emplace_back(l2[j++]);
    }

    return allElements;
}

vector<int> helper(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> stk;
    TreeNode* curr = root;

    while (curr != nullptr || !stk.empty()) {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }

    return ans;
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> l1{}, l2{};

    if (!root1 && !root2) {
        return l1;
    } else if (!root1 && root2) {
        l2 = helper(root2);
        return l2;
    } else if (!root2 && root1) {
        l1 = helper(root1);
        return l1;
    } else {
        l1 = helper(root1);
        l2 = helper(root2);
        vector<int> allElements;
        return mergeList(l1, l2, allElements);
    }
}

// Main Function to test the class methods
int main() {
    // Example usage
    TreeNode* root1 = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6));
    TreeNode* root2 = new TreeNode(1, new TreeNode(0), new TreeNode(8));

    auto result = getAllElements(root1, root2);

    for (auto& num : result) {
        cout << num << ' ';
    }
    cout << '\n';

    delete root1;
    delete root2;

    return 0;
}