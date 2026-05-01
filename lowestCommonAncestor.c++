#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {

public:
  static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {   
        if (!root ||  root->val == p->val || root->val == q->val)
            return (root); 
        TreeNode *left= lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
         if (right && left)
            return (root);
        return (left ? left : right);
    }
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
int main(void)
{
    TreeNode tree6(6);
    tree6.left = NULL;
    tree6.right = NULL;

    TreeNode tree2(2);
    tree2.left = NULL;
    tree2.right = NULL;

    TreeNode tree8(8);
    tree8.left = NULL;
    tree8.right = NULL;

    TreeNode tree7(7);
    tree7.val = 7;
    tree7.left = NULL;
    tree7.right = NULL;

    TreeNode tree0(0);
    tree0.left = NULL;
    tree0.right = NULL;

    TreeNode tree3(3);
    tree3.left = NULL;
    tree3.right = NULL;

    TreeNode tree5(5);
    tree5.left = NULL;
    tree5.right = NULL;

    TreeNode tree4(4);
    tree4.left = NULL;
    tree4.right = NULL;

    TreeNode tree9(4);
    tree9.val = 9;
    tree9.left = NULL;
    tree9.right = NULL;


    TreeNode p(3);
    p.left = NULL;
    p.right = NULL;

    TreeNode q(5);
    q.left = NULL;
    q.right = NULL;

    TreeNode *tree = &tree6;
   
    tree->left = &tree2;
    tree->right = &tree8;

    tree->left->left = &tree0;
    tree->left->right = &tree4;

    tree->left->left->left = &tree3;
    tree->left->left->right = &tree5;

     tree->right->left = &tree7;
    tree->right->right = &tree9;
    // printTreePreorder(tree);
    // Solution::lowestCommonAncestor(tree, &p, &q);
    TreeNode *t = Solution::lowestCommonAncestor(tree, &tree3, &tree5);
    std::cout << "==== " << t->val << "\n";

    // ===============================//
    // TreeNode p(6);
    // p.left = NULL;
    // p.right = NULL;

    // TreeNode q(1);
    // q.left = NULL;
    // q.right = NULL;

    // TreeNode tree5(5);
    // tree5.left = NULL;
    // tree5.right = NULL;

    // TreeNode tree3(3);
    // tree3.left = NULL;
    // tree3.right = NULL;

    // TreeNode tree6(6);
    // tree6.left = NULL;
    // tree6.right = NULL;

    // TreeNode tree2(2);
    // tree2.left = NULL;
    // tree2.right = NULL;

    // TreeNode tree4(4);
    // tree4.left = NULL;
    // tree4.right = NULL;

    // TreeNode tree1(1);
    // tree1.left = NULL;
    // tree1.right = NULL;

    // TreeNode *tree = &tree5;

    // tree->left = &tree3;
    // tree->right = &tree6;

    // tree->left->left = &tree2;
    // tree->left->right = &tree4;

    // tree->left->left->left = &tree1;

    //  printTreePreorder(tree);
    // TreeNode *t = Solution::lowestCommonAncestor(tree, &p, &q);
    // std::cout << t->val << "\n";



}