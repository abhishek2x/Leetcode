class Solution
{
public:
  int islandPerimeter(vector<vector<int>> &grid)
  {
    int m = grid.size();    //row
    int n = grid[0].size(); //column
    int wSide = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          wSide += 4;

          if (j > 0 && grid[i][j - 1] == 1)
            wSide--;
          if (i > 0 && grid[i - 1][j] == 1)
            wSide--;
          if (j < n - 1 && grid[i][j + 1] == 1)
            wSide--;
          if (i < m - 1 && grid[i + 1][j] == 1)
            wSide--;
        }
      }
    }
    return wSide;
  }
};