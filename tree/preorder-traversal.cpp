vector<int> ans;
vector<int> preorderTraversal(TreeNode* root) {
    if(root == NULL) return ans;

    /* //Recursive
    ans.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);*/

    //Iterative
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode *temp = st.top();
        st.pop();

        ans.push_back(temp->val);

        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }

    return ans;
}
