void dfs(vector<vector<char>>& grid, int i, int j) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
        return;
    }

    if(grid[i][j] == '0') {
        return;
    }

    grid[i][j] = '0';

    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int m = grid.size(), n = grid[0].size();

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;

    /*int m = grid.size(), n = m ? grid[0].size() : 0;
    int offset[] = {0, 1, 0, -1, 0};
    int islands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if(grid[i][j] == '1') {
                islands++;
                grid[i][j] = '0';
                queue<pair<int, int>> q;

                q.push({i, j});
                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    
                    for(int k = 0; k < 4; k++) {
                        int r = p.first + offset[k];
                        int c = p.second + offset[k+1];

                        if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                            grid[r][c] = '0';
                            q.push({r, c});
                        }
                    }
                }
            }
        }
    }

    return islands;*/
}
