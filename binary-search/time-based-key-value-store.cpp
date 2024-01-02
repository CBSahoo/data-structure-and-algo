class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {

        if(mp.find(key) == mp.end()) {
            return "";
        }

        int n = mp[key].size();
        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(mp[key][mid].second > timestamp) {
                right = mid - 1;
            } else if (mp[key][mid].second < timestamp) {
                left = mid + 1;
            } else {
                return mp[key][mid].first;
            }
        }

        return right >= 0 ? mp[key][right].first : "";
    }
};