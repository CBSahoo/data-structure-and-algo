int dfs(TreeNode* root, int maxVal){
	if(root == NULL) return 0;

	int result = (root->val >= maxVal) ? 1 : 0;
	maxVal = max(maxVal, root->val);
	result += dfs(root->left, maxVal);
	result += dfs(root->right, maxVal);

	return result;
}

int goodNodes(TreeNode* root) {
	if(root == NULL) return 0;

	int ans = dfs(root, root->val);

	return ans;
}