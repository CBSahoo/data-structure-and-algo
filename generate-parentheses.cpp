void helper(vector<string> &ans, int n, int oc, int cc, string str) {
	if(oc == n && cc == n) {
		ans.push_back(str);
		return;
	}

	if(oc < n) {
		helper(ans, n, oc + 1, cc, str + "(");
	}

	if(cc < oc) {
		helper(ans, n, oc, cc + 1, str + ")");
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	int oc = 0, cc = 0;
	helper(ans, n, oc, cc, "");
	return ans;
}