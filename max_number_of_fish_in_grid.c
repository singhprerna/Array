// Maximum Number of Fish in a Grid

#define max(a, b) (a > b ? a : b)

void helper (int i, int j, int m, int n, int *sum, int *ans, int** grid) {
    *ans = max (*ans, *sum);

    if (i < 0 || j < 0 || i >= m || j >= n || !grid[i][j])
        return;

    *sum += grid[i][j];
    grid[i][j] = 0;

    if (i + 1 < m) helper (i + 1, j, m, n, sum, ans, grid);
    if (i - 1 >= 0) helper (i - 1, j, m, n, sum, ans, grid);
    if (j + 1 < n) helper (i, j + 1, m, n, sum, ans, grid);
    if (j - 1 >= 0) helper (i, j - 1, m, n, sum, ans, grid);
}

int findMaxFish(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 1 && *gridColSize == 1)
        return grid[0][0];
        
    int m = gridSize, n = *gridColSize, i, j, sum = 0, ans = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++){
            if (grid[i][j]) {
                sum = 0;
                helper(i, j, m, n, &sum, &ans, grid);
            }
        }
    }

    return ans;
}
