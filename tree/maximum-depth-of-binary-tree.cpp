int maxDepth(TreeNode* root) {
        
	if(root == NULL) return 0;
	
	/* 
	Recursive DFS
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
	*/
	/* 
	Iterative DFS
	stack<pair<TreeNode*, int>> st;

	st.push({root, 1});
	int level = 1;

	while(!st.empty()) {
		pair<TreeNode*, int> temp = st.top();
		st.pop();

		level = max(level, temp.second);

		if(temp.first->left) {
			st.push({temp.first->left, temp.second + 1});
		}

		if(temp.first->right) {
			st.push({temp.first->right, temp.second + 1});
		}
	}

	return level;
	*/

	queue<TreeNode*> q;
	q.push(root);

	int level = 0;

	while(!q.empty()) {
		level++;
		int qSize = q.size();

		for(int i = 0; i < qSize; i++) {
			TreeNode* temp = q.front();
			q.pop();

			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return level;
}