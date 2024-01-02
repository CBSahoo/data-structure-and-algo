int carFleet(int target, vector<int>& position, vector<int>& speed) {
	vector<pair<int, int>> v;
	int n = position.size();

	for(int i = 0; i < n; ++i) {
		v.push_back({position[i], speed[i]});
	}

	sort(v.begin(), v.end());

	stack<float> st;

	for(int i = n - 1; i >= 0; --i) {
		st.push((float)(target - v[i].first) / v[i].second);

		if(st.size() >= 2) {
			float curr = st.top();
			st.pop();

			float prev = st.top();

			if(curr > prev) st.push(curr);
		}
	}

	return st.size();
}