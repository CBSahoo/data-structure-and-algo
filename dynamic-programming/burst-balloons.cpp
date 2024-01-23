int maxCoins(vector<int>& nums) {  
  vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

  for(int len = 1; len <= nums.size(); len++) {
      for(int i = 0; i <= nums.size() - len; i++) {
          int j = i + len - 1;

          for(int k = i; k <= j; k++) {
              int left = 1, right = 1;

              if(i != 0) left = nums[i - 1];
              if(j != nums.size() - 1) right = nums[j + 1];

              int before = 0, after = 0;

              if(i != k) before = dp[i][k-1];
              if(j != k) after = dp[k+1][j];

              dp[i][j] = max(left * nums[k] * right + before + after, dp[i][j]);
          }
      }
  }

  return dp[0][nums.size() - 1];
  
  /*
  nums.insert(nums.begin(), 1);
  nums.insert(nums.end(), 1);

  int n = nums.size();

  vector<vector<int>> memo(n, vector<int>(n, 0));

  return dp(nums, memo, 1, n - 2);
  */
}

int dp(vector<int> &nums, vector<vector<int>> &memo, int left, int right) {
  if(right - left < 0) {
      return 0;
  }

  if(memo[left][right] > 0) {
      return memo[left][right];
  }

  int ans = 0;
  for(int i = left; i <= right; i++) {
      int curr = nums[left - 1] * nums[i] * nums[right + 1];

      int remaining = dp(nums, memo, left, i - 1) + dp(nums, memo, i + 1, right);
      ans = max(ans, curr + remaining);
  }  

  memo[left][right] = ans;
  return ans; 
}
