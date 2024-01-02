bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix[0].size(), n = matrix.size();
	int left = 0, right = m*n - 1;

	int mid = left + (right - left) / 2;

	while(left <= right) {
		int element = matrix[mid/m][mid%m];

		if(element == target) {
			return true;
		} else if(element < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}

		mid = left + (right - left) / 2;
	}

	return false;
}