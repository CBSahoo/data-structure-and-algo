int maxFrequencyElements(vector<int>& nums) {
         map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        int maxElement = 0, count = 0;
        for(auto i: mp) {
            if(maxElement == i.second) {
                count++;
            } else if(maxElement < i.second){
                maxElement = i.second;
                count = 1;
            }
        }

        return maxElement*count;
        
        
    }
