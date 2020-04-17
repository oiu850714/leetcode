/**
 * Definition for a binary tree node.
 */
// 就走訪一次 BST 然後發現每個數字都比前面大即可
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!isValidBST(root->left)) {
            return false;
        }

        if (Prev_ && Prev_->val >= root->val) {
            return false;
        }

        Prev_ = root;

        return isValidBST(root->right);
    }

private:
    TreeNode *Prev_ = nullptr;
};