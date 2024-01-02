class MinStack {
public:
    vector<long> v;
    long minValue;

    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()) {
             v.push_back(val);
             minValue = val;
        } else if(val <= minValue) {
            v.push_back(2ll*val - minValue);
            minValue = val;
        } else {
            v.push_back(val);
        }
    }
    
    void pop() {
        if(v.empty()) return;
        long temp = v.back();

        if(temp < minValue) {
            minValue = 2ll*minValue - temp;
        }

        v.pop_back();
    }
    
    int top() {
        if(v.empty()) return -1;
        long temp = v.back();

        if(temp < minValue) {
            return minValue;
        } else {
            return v.back();
        }
    }
    
    int getMin() {
        if(v.empty()) return -1;
        return minValue;
    }
};