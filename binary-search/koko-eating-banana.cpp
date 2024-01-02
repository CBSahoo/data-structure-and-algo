int minEatingSpeed(vector<int>& piles, int h) {
	int left = 1, right = *max_element(piles.begin(), piles.end());
	int ans = INT_MAX, n = piles.size();
	double time = 0.0;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		time = 0;

		for(int i = 0; i < n; i++) {
			time += ceil( (piles[i] * 1.0) / mid);
		}

		if (time <= h) {
			ans = min(ans, mid);
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return ans;
}