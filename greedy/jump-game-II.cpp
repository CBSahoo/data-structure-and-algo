int jump(vector<int>& nums) {
        int jumps = 0, farthest = 0, current = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, nums[i] + i);

            if(i == current) {
                current = farthest;
                jumps++;
            }
        }

        return jumps;
        /*int n = nums.size();
        int ans = 0;

        int i = 0;
        while(i < n - 1) {
            if(i + nums[i] >= n - 1) {
                ans++;
                break;
            }

            int maxIndex = i + 1;
            int maxValue = 0;

            for (int j = i + 1; j < i + 1 + nums[i]; j++) {
                if(j + nums[j] > maxValue) {
                    maxIndex = j;
                    maxValue = j + nums[j];
                }
            }

            i = maxIndex;
            ans++;
        }

        return ans;*/
    }
