int largestRectangleArea(vector<int>& heights) {
	stack<int> st;
	int i = 0, n = heights.size();
	int maxArea = 0;

	while(i < n) {
		if(st.empty() || (heights[st.top()] <= heights[i])) {
			st.push(i++);
		} else {
			int minIndex = st.top();
			st.pop();

			int width = i;
			if(!st.empty()) width = i - 1 - st.top();
			int area = heights[minIndex] * width;
			maxArea = max(maxArea, area);
		}
	}

	while(!st.empty()) {
		int minIndex = st.top();
		st.pop();

		int width = i;
		if(!st.empty()) width = i - 1 - st.top();
		int area = heights[minIndex] * width;
		maxArea = max(maxArea, area);
	}

	return maxArea;
}