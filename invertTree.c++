#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    static TreeNode* invertTree(TreeNode* root) 
    {
        if (!root)
            return (root);
        TreeNode *left = root->left;
        root->left = root->right;
        root->right = left;
        invertTree(root->left);
        invertTree(root->right);
        return (root);
    }
    //  static void invertTree(TreeNode* root) 
    // {
    //     if (!root)
    //         return ;
    //     TreeNode *left = root->left;
    //     root->left = root->right;
    //     root->right = left;
    //     invertTree(root->left);
    //     invertTree(root->right);
    // }
};




void printTreePostOrder(TreeNode *tree)
{
    if (!tree)
        return;
    printTreePostOrder(tree->left);
    printTreePostOrder(tree->right);
    std :: cout << " => " << tree->val << "\n";

}
void printTreeInorder(TreeNode *tree)
{
    if (!tree)
        return;
    printTreeInorder(tree->left);
    std :: cout << " => " << tree->val << "\n";
    printTreeInorder(tree->right);

}

void printTreePreorder(TreeNode *tree)
{
    if (!tree)
        return;
    std :: cout << " => " << tree->val << "\n";
    printTreePreorder(tree->left);
    printTreePreorder(tree->right);

}
// 1,3,2,6,9,7,4   | PostOrder
// 1,2,3,4,6,7,9  |inorder 
// 4,7,2,9,6,3,1  |  preorder 
// 4,2,7,1,3,6,9
int main(void)
{ 
    TreeNode tree4;
    tree4.val = 4;
    tree4.left = NULL;
    tree4.right = NULL;

    TreeNode tree2;
    tree2.val = 2;
    tree2.left = NULL;
    tree2.right = NULL;

    TreeNode tree7;
    tree7.val = 7;
    tree7.left = NULL;
    tree7.right = NULL;

    TreeNode tree1;
    tree1.val = 1;
    tree1.left = NULL;
    tree1.right = NULL;

    TreeNode tree3;
    tree3.val = 3;
    tree3.left = NULL;
    tree3.right = NULL;

    TreeNode tree6;
    tree6.val = 6;
    tree6.left = NULL;
    tree6.right = NULL;

    TreeNode tree9;
    tree9.val = 9;
    tree9.left = NULL;
    tree9.right = NULL;

    TreeNode *tree = &tree4;
   
    tree->left = &tree2;
    tree->right = &tree7;

    tree->left->left = &tree1;
    tree->left->right = &tree3;
     tree->right->left = &tree6;
    tree->right->right = &tree9;
    // printTreePreorder(tree);
    Solution::invertTree(tree);
    printTreePreorder(tree);
    // TreeNode *tree_after = tree;
    // printTree(tree_after);

}
/*
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
*/