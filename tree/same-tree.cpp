bool isSameTree(TreeNode* p, TreeNode* q) {
	/* BFS
	queue<TreeNode*> q1;

	q1.push(p);
	q1.push(q);

	while(q1.size() != 0) {
		TreeNode *q2 = q1.front();
		q1.pop();

		TreeNode *q3 = q1.front();
		q1.pop();

		if(!(q2 == NULL && q3 == NULL)) {
			if(q2 == NULL || q3 == NULL) {
				return false;
			}

			if(q2->val != q3->val) return false;

			q1.push(q2->left);
			q1.push(q3->left);
			q1.push(q2->right);
			q1.push(q3->right);
		}
	}

	return true;*/

	if(p == NULL && q == NULL) return true;
	if(p == NULL || q == NULL) return false;

	if(p->val != q->val) return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}