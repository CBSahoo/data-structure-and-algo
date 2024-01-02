int findMin(vector<int>& nums) {
	int n = nums.size();
	int left = 0, right = n - 1;
	int ans = INT_MAX;
	while(left <= right) {
		if(nums[left] < nums[right]) {
			ans = min(ans, nums[left]);
			break;
		} 

		int mid = left + (right - left) / 2;
		ans = min(ans, nums[mid]);

		if(nums[mid] >= nums[left]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return ans;
}