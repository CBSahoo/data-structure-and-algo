map<pair<int, int>, bool> dp;
bool isMatch(string s, string p) {
    int len_s = s.length(), len_p = p.length();

    vector<vector<int>> dp(len_s + 1, vector<int>(len_p + 1, -1));

    return stringMatch(dp, s, p, len_s, len_p);
    //return dfs(s, p, 0, 0);
}

int stringMatch(vector<vector<int>> &dp, string s, string p, int len_s, int len_p) {
    if(len_s == 0 && len_p == 0) {
        return 1;
    }

    if(len_p == 0) {
        return 0;
    }

    if(dp[len_s][len_p] != -1) {
        return dp[len_s][len_p];
    }

    if(p[len_p - 1] == '*') {
        int res = stringMatch(dp, s, p, len_s, len_p - 2);
        int len_rep = 0;

        while(1) {
            if(len_s - len_rep > 0 && (s[len_s - 1 - len_rep] == p[len_p -2] || p[len_p - 2] == '.')) {
                len_rep++;
            }
            else break;

            res = res | (stringMatch(dp, s, p, len_s - len_rep, len_p - 2));
        }

        dp[len_s][len_p] = res;
        return dp[len_s][len_p];
    }

    if(len_s == 0) {
        dp[len_s][len_p] = 0;
        return dp[len_s][len_p];
    }

    if(p[len_p - 1] == '.' || s[len_s - 1] == p[len_p - 1]) {
        dp[len_s][len_p] = stringMatch(dp, s, p, len_s - 1, len_p - 1);
        return dp[len_s][len_p];
    }

    dp[len_s][len_p] = 0;
    return dp[len_s][len_p];
}

bool dfs(string s, string p, int i, int j) {
    if(dp.find({i, j}) != dp.end()) {
        return dp[{i, j}];
    }

    if(i >= s.size() && j >= p.size()) {
        return true;
    }

    if(j >= p.size()) {
        return false;
    }

    bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

    if(j + 1 < p.size()  && p[j + 1] == '*') {
        dp[{i, j}] = dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j));
        return dp[{i, j}];
    }

    if(match) {
        dp[{i, j}] = dfs(s, p, i + 1, j + 1);
        return dp[{i, j}];
    }

    dp[{i, j}] = false;
    return dp[{i, j}];
}
