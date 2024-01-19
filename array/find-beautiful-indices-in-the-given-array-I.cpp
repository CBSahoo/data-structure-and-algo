vector<int> beautifulIndices(string s, string a, string b, int k) {
    int n = s.size(), s1 = a.size(), s2 = b.size(), i = 0, j = 0;
    vector<int> ans, tmp1, tmp2;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == a[0]){
            string g = s.substr(i, s1);
            if(g == a)
                tmp1.push_back(i);
        }
        if(s[i] == b[0]){
            string g = s.substr(i, s2);
            if(g == b)
                tmp2.push_back(i);
        }
    }
    s1 = tmp1.size(), s2 = tmp2.size();
    while(i < s1 && j < s2){
        int val = abs(tmp1[i] - tmp2[j]);
        if(val <= k)
            ans.push_back(tmp1[i++]);
        else if(tmp1[i] < tmp2[j])
            i++;
        else
            j++;
    }
    return ans;
}
