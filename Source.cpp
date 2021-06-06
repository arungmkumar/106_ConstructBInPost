#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	
};

TreeNode* build(vector<int>& inorder, int start, int end, int p, vector<int>& postorder)
{


	//find the root index


	if (p<0) return nullptr;
	if (start>end) return nullptr;
	TreeNode* root = new TreeNode(postorder[p]);
	int rootIndex = 0;
	for (int i = 0; i<inorder.size(); i++)
	{
		if (inorder[i] == postorder[p])
		{
			rootIndex = i;
		}
	}

	p--;
	root->right = build(inorder, rootIndex + 1, end, p, postorder);
	root->left = build(inorder, start, rootIndex - 1, p, postorder);



	return root;

}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	int p = postorder.size() - 1;
	int start = 0;
	int end = inorder.size() - 1;
	return build(inorder, start, end, p, postorder);
}

int main()
{

	/*
	Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
	*/

	/*
	TreeNode* root = new TreeNode(3);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	root->left = new TreeNode(10);
	*/

	vector<int> inorder = { 9, 3, 15, 20, 7 };
	vector<int> postorder = { 9, 15, 7, 20, 3 };

	TreeNode* root = buildTree(inorder, postorder);


	
	return 0;
}
