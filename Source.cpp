#include <iostream>
#include <algorithm>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int diameterHelp(TreeNode* node, int maxdiameter) {
	if (node == nullptr) {
		return 0;
	}

	int leftHeight = diameterHelp(node->left, maxdiameter);
	int rightHeight = diameterHelp(node->right, maxdiameter);

	maxdiameter = std::max(maxdiameter, leftHeight + rightHeight);

	return std::max(leftHeight, rightHeight) + 1;
}

int Calculatediameter(TreeNode* root) {
	int maxdiameter = 0;
	diameterHelp(root, maxdiameter);
	return maxdiameter;
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	int diameter = Calculatediameter(root);
	std::cout << "Tree diameter: " << diameter << std::endl;

	return 0;
}