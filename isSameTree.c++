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
public:
    static bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!p && !q)
            return (true);
        else if (!p || !q)
            return (false);
        if (p->val != q->val)
            return (false);
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
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
    TreeNode tree1a(1);
    tree1a.left = NULL;
    tree1a.right = NULL;

    TreeNode tree2a(2);
    tree2a.left = NULL;
    tree2a.right = NULL;

    TreeNode tree3a(3);
    tree3a.left = NULL;
    tree3a.right = NULL;

    TreeNode *root1 = &tree1a;

    root1->left = &tree2a;
    root1->right = &tree3a;



    TreeNode tree1b(1);
    tree1b.left = NULL;
    tree1b.right = NULL;

    TreeNode tree2b(2);
    tree2b.left = NULL;
    tree2b.right = NULL;

    TreeNode tree3b(3);
    tree3b.left = NULL;
    tree3b.right = NULL;

    TreeNode *root2 = &tree1b;

    root2->left = &tree2b;
    root2->right = &tree3b;
    printTreeInorder(root2);

    std :: cout << Solution::isSameTree(root1, root2) << "\n";


    TreeNode tree4p(4);
    tree4p.left = NULL;
    tree4p.right = NULL;

    TreeNode tree7p(7);
    tree7p.left = NULL;
    tree7p.right = NULL;

    TreeNode *p = &tree4p;

    p->left = &tree7p;


    TreeNode tree4q(4);
    tree4q.left = NULL;
    tree4q.right = NULL;

    TreeNode tree7q(7);
    tree7q.left = NULL;
    tree7q.right = NULL;

    TreeNode *q = &tree4q;

    q->right = &tree7q;
    std :: cout << Solution::isSameTree(p, q) << "\n";

}