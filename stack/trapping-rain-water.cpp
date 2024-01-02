int trap(vector<int>& height) {
	int n = height.size();
	int left = 0, right = n - 1;
	int leftMax = height[left], rightMax = height[right];
	int ans = 0;

	while(left < right) {
		if(leftMax < rightMax) {
			left++;
			leftMax = max(leftMax, height[left]);
			ans += leftMax - height[left];
		} else {
			right--;
			rightMax = max(rightMax, height[right]);
			ans += rightMax - height[right];
		}
	}

	return ans;
}