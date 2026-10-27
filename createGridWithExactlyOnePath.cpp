class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#')); //string(n, '#') repeats '#' n times

        // Make the first row free
        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }

        // Make the last column free
        for (int i = 1; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};