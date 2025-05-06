// Helper function to perform Depth-First Search (DFS) from a land cell
void dfs(char** grid, int i, int j, int m, int n) {
    // Stop if out of bounds or the current cell is water ('0')
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return;

    // Mark current land cell as visited by setting it to '0'
    grid[i][j] = '0';

    // Recursively visit all 4 adjacent directions (up, down, left, right)
    dfs(grid, i - 1, j, m, n); // Up
    dfs(grid, i + 1, j, m, n); // Down
    dfs(grid, i, j - 1, m, n); // Left
    dfs(grid, i, j + 1, m, n); // Right
}

// Main function to count the number of islands in the grid
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || *gridColSize == 0)
        return 0;

    int count = 0; // Counter for number of islands
    int rows = gridSize;
    int cols = *gridColSize;

    // Loop through every cell in the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Start DFS if we find land ('1')
            if (grid[i][j] == '1') {
                count++;               // Found a new island
                dfs(grid, i, j, rows, cols); // Mark all connected land
            }
        }
    }

    return count; // Return total islands found
}
