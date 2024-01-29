bool canJump(vector<int>& nums) {
    int index = nums.size() - 1;

    for(int i = nums.size() - 1; i >= 0; i--) {
        if(nums[i] + i >= index) {
            index = i;
        }
    }

    return (index == 0) ? true : false;

    /*
    int n = nums.size();
    int goal = 0;

    for (int i = 0; i < n; i++) {
        if(i > goal) {
            return false;
        }

        goal = max(goal, i + nums[i]);
        if(goal >= n - 1) {
            break;
        } 
    }

    return true;
    */
}
