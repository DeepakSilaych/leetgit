class Solution {
private:
    int minimumArea(vector<vector<int>>& grid, int s_i, int s_j, int e_i, int e_j) {
        int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
        for(int i = s_i; i <= e_i; i++) {
            for(int j = s_j; j <= e_j; j++) {
                if(grid[i][j]) {
                    x1 = min(x1, j);
                    x2 = max(x2, j);
                    y1 = min(y1, i);
                    y2 = max(y2, i);
                }
            }
        }
        if (x1 == INT_MAX || y1 == INT_MAX) return 0; // No 1s found
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }

    int div2sum(vector<vector<int>>& grid, vector<int>& vert, vector<int>& horz, int s_i, int s_j, int e_i, int e_j) {
        int ans = INT_MAX;
        for(int j = s_j; j < e_j; j++) {
            if(vert[j] && (vert[e_j] - vert[j])) {
                int x = minimumArea(grid, s_i, s_j, e_i, j);
                int y = minimumArea(grid, s_i, j + 1, e_i, e_j);
                ans = min(ans, x + y);
            }
        }
        for(int i = s_i; i < e_i; i++) {
            if(horz[i] && (horz[e_i] - horz[i])) {
                int x = minimumArea(grid, s_i, s_j, i, e_j);
                int y = minimumArea(grid, i + 1, s_j, e_i, e_j);
                ans = min(ans, x + y);
            }
        }
        return ans;
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size(), m = grid[0].size();
        vector<int> vert(m), horz(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vert[j] += grid[i][j];
                horz[i] += grid[i][j];
            }
        }
        for(int j = 1; j < m; j++) vert[j] += vert[j - 1];
        for(int i = 1; i < n; i++) horz[i] += horz[i - 1];
        for(int j = 0; j < m - 1; j++) {
            if(vert[j] && (vert[m - 1] - vert[j])) {
                if(vert[j] > 1) {
                    int x = div2sum(grid, vert, horz, 0, 0, n - 1, j);
                    int y = minimumArea(grid, 0, j + 1, n - 1, m - 1);
                    ans = min(ans, x + y);
                }
                if((vert[m - 1] - vert[j]) > 1) {
                    int x = div2sum(grid, vert, horz, 0, j + 1, n - 1, m - 1);
                    int y = minimumArea(grid, 0, 0, n - 1, j);
                    ans = min(ans, x + y);
                }
            }
        }
        for(int i = 0; i < n - 1; i++) {
            if(horz[i] && (horz[n - 1] - horz[i])) {
                if(horz[i] > 1) {
                    int x = div2sum(grid, vert, horz, 0, 0, i, m - 1);
                    int y = minimumArea(grid, i + 1, 0, n - 1, m - 1);
                    ans = min(ans, x + y);
                }
                if((horz[n - 1] - horz[i]) > 1) {
                    int x = div2sum(grid, vert, horz, i + 1, 0, n - 1, m - 1);
                    int y = minimumArea(grid, 0, 0, i, m - 1);
                    ans = min(ans, x + y);
                }
            }
        }
        return ans;
    }
};