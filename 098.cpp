#include <exception>

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
        try {
            checkValid_(root);
        } catch (std::exception &e) {
            return false;
        }
        return true;
    }

private:
    void checkValid_(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        // 走訪 left subtree
        checkValid_(root->left);

        // 走訪正中間
        if (Prev_ && Prev_->val >= root->val) {
            // 前一個 node value >= root，不符合 BST 定義，直接 throw
            throw std::exception();
        }
        Prev_ = root;

        // 走訪 right subtree
        checkValid_(root->right);
    }

    TreeNode *Prev_;
};