vector<int> rightSideView(TreeNode* root) {
	if(root == NULL) return {};

	vector<int> level;
	queue<TreeNode*> q;

	q.push(root);

	while(!q.empty()) {
		int size = q.size();

		for(int i = 0; i < size; i++) {
			TreeNode *temp = q.front();
			q.pop();

			if(i == size - 1) {
				level.push_back(temp->val);
			}

			if(temp->left) {
				q.push(temp->left);
			}

			if(temp->right) {
				q.push(temp->right);
			}
		}
	}
	return level;
}