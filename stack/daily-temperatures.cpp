vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> ans(n, 0);

	stack<int> st;

	for(int i = 0; i < n; i++) {
		while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
			int temp = st.top();
			st.pop();

			ans[temp] = i - temp;
		}

		st.push(i);
	}

	return ans;
}