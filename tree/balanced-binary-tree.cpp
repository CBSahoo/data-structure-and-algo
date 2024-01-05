int height(TreeNode* root) {
	if(root == NULL) return 0;

	return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode* root) {
	
	if(root == NULL) return true;

	int leftSubTree = height(root->left);
	int rightSubTree = height(root->right);

	int difference = abs(rightSubTree - leftSubTree);

	return (difference <= 1 && isBalanced(root->left) && isBalanced(root->right));
}