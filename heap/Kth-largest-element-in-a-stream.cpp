priority_queue<int, vector<int>, greater<int>> pq;
int size;

KthLargest(int k, vector<int>& nums) {
    size  = k;

    for(int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);

        if(pq.size() > k) {
            pq.pop();
        }
    }

    /*
    for(int i : nums) {
        add(i);
    }
    */
}

int add(int val) {

    pq.push(val);

    if(pq.size() > size) {
        pq.pop();
    }

    return pq.top();

    /*
    if(minHeap.size() < size) {
        minHeap.push(val);
    } else {
        if(val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
    }

    return pq.top();
    */
}
