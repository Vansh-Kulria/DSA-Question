class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= 0) continue;

                long long sum = 0;
                vector<pair<int,int>> st;
                st.push_back({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;              // mark visited

                while (!st.empty()) {
                    auto [x, y] = st.back();
                    st.pop_back();
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if (grid[nx][ny] <= 0) continue;
                        sum += grid[nx][ny];
                        grid[nx][ny] = 0;    // mark visited
                        st.push_back({nx, ny});
                    }
                }

                if (sum % k == 0) count++;
            }
        }
        return count;
    }
};