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

int maximalRectangle(vector<vector<char>>& matrix) {
	if(matrix.empty()) return 0;

	int maxRectangle = 0;
	vector<int> height(matrix[0].size(), 0);

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			if(matrix[i][j] == '0') {
				height[j] = 0;
			} else {
				height[j]++;
			}
		}

		maxRectangle = max(maxRectangle, largestRectangleArea(height));
	}

	return maxRectangle;
}