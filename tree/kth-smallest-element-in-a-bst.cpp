int count = 0, ans;
void findValue(TreeNode* root, int k) {
	if(root == NULL) return;

	findValue(root->left, k);
	count++;
	if(count == k) {
		ans = root->val;
		return;
	}
	findValue(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
	
	findValue(root, k);
	return ans;
}