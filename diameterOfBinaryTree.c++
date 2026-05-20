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
    static int checkHeight(TreeNode* root, int& diameter)
    {
        if (!root)
            return 0;

        int left = checkHeight(root->left, diameter);
        int right = checkHeight(root->right, diameter);

        diameter = std::max(diameter, left + right);

        return std::max(left, right) + 1;
    }

public:
    static int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter = 0;

        checkHeight(root, diameter);

        return diameter;
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
//    TreeNode tree3(3);
//     tree3.left = NULL;
//     tree3.right = NULL;

//     TreeNode tree9(9);
//     tree9.left = NULL;
//     tree9.right = NULL;

//     TreeNode tree20(20);
//     tree20.left = NULL;
//     tree20.right = NULL;

//     TreeNode tree15(15);
//     tree15.left = NULL;
//     tree15.right = NULL;

//     TreeNode tree7(7);
//     tree7.left = NULL;
//     tree7.right = NULL;

//     TreeNode *root1 = &tree3;

//     root1->left = &tree9;
//     root1->right = &tree20;

//     root1->right->left = &tree15;
//     root1->right->right = &tree7;
//     // printTreePreorder(root1);

//     //  printTreePreorder(root1);
//     std::cout <<  Solution::diameterOfBinaryTree(root1) << '\n' << "\n\n";

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

    TreeNode tree4_l(4);
    tree4_l.left = NULL;
    tree4_l.right = NULL;

    TreeNode tree5_r(5);
    tree5_r.left = NULL;
    tree5_r.right = NULL;

    TreeNode *root2 = &tree1;

    root2->right = &tree2_r;

    root2->right->left  = &tree3_r;
    root2->right->right = &tree4_l;

     root2->right->left->left =  &tree5_r;

    printTreePreorder(root2);
      std::cout <<  Solution::diameterOfBinaryTree(root2) << '\n';


    // TreeNode *t = Solution::lowestCommonAncestor(tree, &p, &q);
    // std::cout << t->val << "\n";



}