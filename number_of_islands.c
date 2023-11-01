// Number of Islands

void markVisited (char** grid, int m, int n, int row, int col) {
    if (row < 0 || row == m || col < 0 || col == n || grid[row][col] == '0')
        return;
    
    grid[row][col] = '0';
    if (row - 1 >= 0) markVisited(grid, m, n, row - 1, col);
    if (row + 1 < m) markVisited(grid, m, n, row + 1, col);
    if (col - 1 >= 0) markVisited(grid, m, n, row, col - 1);
    if (col + 1 < n) markVisited(grid, m, n, row, col + 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i, j, count = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1') {
                markVisited(grid, gridSize, *gridColSize, i, j);
                count++;
            }
        }
    }

    return count;
}
