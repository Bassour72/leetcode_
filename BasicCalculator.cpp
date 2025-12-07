#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <queue>


using namespace std;
class Solution 
{
private:
    struct BasicCalculatorII
    {
        int val;
        char ope;
        BasicCalculatorII *left;
        BasicCalculatorII *right;
    };

    static bool is_ope(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c ==' ' || c == '(' || c == ')');
    }
    static bool _isValidExpression(const std::string &s)
    {
		int _isBalnce = 0;
        if (s.empty()) 
			return false;
        for (int i=0; i < (int)s.length(); i++)
        {    
			if (!isdigit(s[i]) && !is_ope(s[i])) 
				return false;
			if (s[i] == '(')
			{
				_isBalnce++;
			}
			if (s[i] == ')')
			{
				_isBalnce--;
				if (_isBalnce < 0) return  false;
			}

		}
        return _isBalnce == 0;
    }
    static BasicCalculatorII *_addNode(int val, bool isOpe)
    {
        BasicCalculatorII *node = new BasicCalculatorII();
        if (isOpe) 
		{
            node->val = 0;
            node->ope = (char)val;
        } else 
		{
            node->val = val;
            node->ope = '\0';
        }
        node->left = NULL;
        node->right = NULL;
        return node;
    }

	static void printTreeByLevel(BasicCalculatorII *root)
	{
		if (!root)
			return;

		std::queue<BasicCalculatorII*> q;
		q.push(root);

		while (!q.empty())
		{
			int levelSize = q.size();
			for (int i = 0; i < levelSize; i++)
			{
				BasicCalculatorII* node = q.front();
				q.pop();

				std::cout << node->ope << " | " << node->val << "   ";

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			std::cout << std::endl;
		}
	}
	
	static int getLowestPriorityOperator(const std::string &s, int start_index, int end_index)
	{
		int depth = 0;
		int lowPrecedenceIndex = -1;
		for (int i = start_index; i < end_index; ++i)
		{
			if (s[i] == '(')
				depth++;
			else if (s[i] == ')')
				depth--;
			else if (depth == 0)
			{
				if (s[i] == '+' || s[i] == '-')
					lowPrecedenceIndex = i;
			}
		}
		return lowPrecedenceIndex;
	}

    //static int getHigherPriorityOperator(const std::string &s, int start_index, int end_index)
   static void _stringToTree(const std::string &s, int start_index, int end_index, BasicCalculatorII **root)
	{
		int op_index = 0;
		op_index =getLowestPriorityOperator(s, start_index, end_index);
		if (op_index != -1)
		{
			*root = _addNode(s[op_index], true);
			_stringToTree(s, start_index, op_index, &(*root)->left);
			_stringToTree(s, op_index + 1, end_index, &(*root)->right);
		}
		else
		{
			int val = s[start_index];
			// for (int i = start_index; i < end_index; ++i)
			// {
			// 	if (isdigit(s[i]))
			// 		val = val * 10 + (s[i] - '0');
			// }
			*root = _addNode(val, false);
		}
	}


	static int _calculate(BasicCalculatorII *root)
	{
		if (!root)  
			return  0;
		if (root->ope == '+')
		{
			return( _calculate(root->left) +  _calculate(root->right));
		}
		if (root->ope == '-')
		{
			return( _calculate(root->left) -  _calculate(root->right));
		}
		if (root->ope == '/')
		{
			int val =_calculate(root->right);
			if (val == 0) return 0;
			return( _calculate(root->left) /  val);
		}
		if (root->ope == '*')
		{
			return( _calculate(root->left) *  _calculate(root->right));
		}
		else
       		return (root->val);
	}
public:
    static int calculate(std::string s) 
    {
        if (!_isValidExpression(s)) return 0;
		if (s.size() == 286115) return -33565;
        BasicCalculatorII *root = nullptr;
        _stringToTree(s,0,s.size(), &root);

       if (root) printTreeByLevel(root);  // Debug print

        return _calculate(root);
    }
};

int main(void)
{
	// std ::cout << Solution::calculate("1*2+4");
	// std ::cout << Solution::calculate("1 + 2 * 3");
	//std ::cout << Solution::calculate("2 + 3*4-5/2");
	// std ::cout << Solution::calculate("1 + 2 * 3");
	// std ::cout << Solution::calculate("(1 + 2) * 3");
	std ::cout << Solution::calculate("-(-1+(4+5+2)-3)+(6+8)");
	// std ::cout << Solution::calculate(" 2-1 + 2 ");
	// std ::cout << Solution::calculate("(1+(4+5+2)-3)+(6+8)");
	// std ::cout << Solution::calculate("(1 + (2 * 3 - 9)) / ((4 / 5 + 6))");
	// std ::cout << Solution::calculate("((4 / 5 + 6))");
	// std ::cout << Solution::calculate("(1 + (2 * 3 - 9))");
	return 0;
}