vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	stack<int> st;
	unordered_map<int, int> mp;

	int n = nums2.size(), m = nums1.size();
	vector<int> ans(m);

	for(int i = 0; i < n; i++) {
		while(!st.empty() && (nums2[i] > nums2[st.top()])) {
			mp[nums2[st.top()]] = nums2[i];
			st.pop();
		}

		st.push(i);
	}

	while(!st.empty()) {
		mp[nums2[st.top()]] = -1;
		st.pop();
	}

	for(int i = 0; i < nums1.size(); i++) {
		if(mp.find(nums1[i]) != mp.end()) {
			ans[i] = mp[nums1[i]];
		} else {
			ans[i] = -1;
		}
	}

	return ans;
}