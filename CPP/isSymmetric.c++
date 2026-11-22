
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isLeftEqualRight(TreeNode *left, TreeNode *right)
    {
        return (left != nullptr && right != nullptr && left->val == right->val);
    }
    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return (true);
        if (!isLeftEqualRight(left, right))
            return (false);
        return (isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
    }

public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root)
            return (false);
        return isSymmetric(root->left, root->right);      
    }
};