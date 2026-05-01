#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    static int checkHeight(TreeNode* root) 
    {
        if (!root)
            return (0);

        int left = checkHeight(root->left);
        
        int right = checkHeight(root->right);

        if (left == -1 || right == - 1 ||  std::abs((left - right)) > 1)
            return (-1);

        return (std::max(left, right) + 1);
    }
public:
    static bool isBalanced(TreeNode* root)
    {
        return (checkHeight(root) != -1);
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
   TreeNode tree3(3);
    tree3.left = NULL;
    tree3.right = NULL;

    TreeNode tree9(9);
    tree9.left = NULL;
    tree9.right = NULL;

    TreeNode tree20(20);
    tree20.left = NULL;
    tree20.right = NULL;

    TreeNode tree15(15);
    tree15.left = NULL;
    tree15.right = NULL;

    TreeNode tree7(7);
    tree7.left = NULL;
    tree7.right = NULL;

    TreeNode *root1 = &tree3;

    root1->left = &tree9;
    root1->right = &tree20;

    root1->right->left = &tree15;
    root1->right->right = &tree7;
    // printTreePreorder(root1);

    //  printTreePreorder(root1);
    std::cout <<  Solution::isBalanced(root1) << '\n' << "\n\n";

    // ===============================//


    TreeNode tree1(1);
    tree1.left = NULL;
    tree1.right = NULL;

    TreeNode tree2_l(2);
    tree2_l.left = NULL;
    tree2_l.right = NULL;

    TreeNode tree2_r(2);
    tree2_r.left = NULL;
    tree2_r.right = NULL;

    TreeNode tree3_l(3);
    tree3_l.left = NULL;
    tree3_l.right = NULL;

    TreeNode tree3_r(3);
    tree3_r.left = NULL;
    tree3_r.right = NULL;

    TreeNode tree4_ll(4);
    tree4_ll.left = NULL;
    tree4_ll.right = NULL;

    TreeNode tree4_lr(4);
    tree4_lr.left = NULL;
    tree4_lr.right = NULL;

    TreeNode *root2 = &tree1;

    root2->left = &tree2_l;
    root2->right = &tree2_r;

    root2->left->left = &tree3_l;
    root2->left->right = &tree3_r;

    root2->left->left->left = &tree4_ll;
    root2->left->left->right = &tree4_lr;

   // //  printTreePreorder(root2);
      std::cout <<  Solution::isBalanced(root2) << '\n';


    // TreeNode *t = Solution::lowestCommonAncestor(tree, &p, &q);
    // std::cout << t->val << "\n";



}