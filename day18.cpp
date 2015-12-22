#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > grid(102,vector<int>(102,0));
vector<vector<int> > new_grid(102,vector<int>(102,0));

int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {0,1,-1,1,-1,0,1,-1};

void step() {

  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++) {
      if (i == 1 && j == 1) {new_grid[i][j] = 1; continue;}
      if (i == 1 && j == 100) {new_grid[i][j] = 1; continue;}
      if (i == 100 && j == 1) {new_grid[i][j] = 1; continue;}
      if (i == 100 && j == 100) { new_grid[i][j] = 1; continue;}
      int sum = 0;
      for (int d = 0; d < 8; d++) {
        sum += grid[i+dr[d]][j+dc[d]];
      }
      if (grid[i][j] == 1) {
        if (!(sum == 2 || sum == 3)) new_grid[i][j] = 0;
        else new_grid[i][j] = 1;
      } else {
        if (sum == 3) new_grid[i][j] = 1;
        else new_grid[i][j] = 0;
      }
    }
  
  swap(grid,new_grid);
}

int main() {
  char c;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++) {
      cin >> c;
      if (c=='.') grid[i][j] = 0;
      else grid[i][j] = 1;
    }
  grid[1][1] = 1;
  grid[1][100] = 1;
  grid[100][1] = 1;
  grid[100][100] = 1;
  for (int i = 0; i < 100; i++) step();

  int res = 0;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++)
      res += grid[i][j];

  cout << res << endl;

  return 0;
}
