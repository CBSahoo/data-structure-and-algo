bool isValid(TreeNode* root, long left, long right) {

	if(root == NULL) return true;

	if(root->val > left && root->val < right) {
		return (isValid(root->left, left, root->val ) && isValid(root->right, root->val, right)); 
	}

	return false;
}


bool isValidBST(TreeNode* root) {
	return isValid(root, LONG_MIN, LONG_MAX);
}