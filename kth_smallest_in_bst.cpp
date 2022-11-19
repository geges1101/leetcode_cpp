class Solution {
public:
    void inorder(TreeNode* root, int& k, int& res) {
        if (!root) return;
        inorder(root->left, k, res);
        if (--k == 0){
            res = root->val;
            return;
        }
        inorder(root->right, k, res);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        inorder(root, k, res);
        return res;
    }
};