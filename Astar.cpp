#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct Node
{
  int x, y;
  int g, h, f;

  bool operator>(const Node &other) const
  {
    return f > other.f;
  }
};

int hitungHeuristik(int x, int y, int goalX, int goalY)
{
  return abs(x - goalX) + abs(y - goalY);
}

void aStarSearch(vector<vector<char>> &peta, pair<int, int> start, pair<int, int> goal)
{
  int n = peta.size();

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  priority_queue<Node, vector<Node>, greater<Node>> openList;

  vector<vector<int>> bestG(n, vector<int>(n, 999));

  vector<vector<bool>> closedList(n, vector<bool>(n, false));

  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {-1, -1}));

  int sx = start.first;
  int sy = start.second;
  int gx = goal.first;
  int gy = goal.second;

  bestG[sx][sy] = 0;

  int hAwal = hitungHeuristik(sx, sy, gx, gy);

  openList.push({sx, sy, 0, hAwal, hAwal});

  bool ketemu = false;

  while (!openList.empty())
  {
    Node current = openList.top();
    openList.pop();

    int x = current.x;
    int y = current.y;

    if (current.g != bestG[x][y])
      continue;

    if (closedList[x][y])
      continue;

    closedList[x][y] = true;

    if (x == gx && y == gy)
    {
      ketemu = true;
      break;
    }

    // Periksa tetangga
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;

      if (peta[nx][ny] == '#')
        continue;

      if (closedList[nx][ny])
        continue;

      int cost;

      if (peta[nx][ny] == 'G')
      {
        cost = 0;
      }
      else
      {
        cost = peta[nx][ny] - '0';
      }

      int newG = current.g + cost;

      if (newG < bestG[nx][ny])
      {
        int newH = hitungHeuristik(nx, ny, gx, gy);
        int newF = newG + newH;

        bestG[nx][ny] = newG;
        parent[nx][ny] = {x, y};

        openList.push({nx, ny, newG, newH, newF});
      }
    }
  }

  if (!ketemu)
  {
    cout << "\nGoal tidak bisa dicapai\n";
    return;
  }

  vector<pair<int, int>> path;

  int x = gx;
  int y = gy;

  while (x != sx || y != sy)
  {
    path.push_back({x, y});

    pair<int, int> p = parent[x][y];

    x = p.first;
    y = p.second;
  }

  path.push_back(start);

  reverse(path.begin(), path.end());

  cout << "\nTotal cost: " << bestG[gx][gy] << "\n";

  cout << "\nJalur dari S ke G:\n";

  for (int i = 0; i < (int)path.size(); i++)
  {
    cout << "(" << path[i].first
         << "," << path[i].second << ")";

    if (i < (int)path.size() - 1)
    {
      cout << " -> ";
    }
  }

  vector<vector<char>> hasil = peta;

  for (auto titik : path)
  {
    int px = titik.first;
    int py = titik.second;

    if (hasil[px][py] != 'S' &&
        hasil[px][py] != 'G')
    {
      hasil[px][py] = '*';
    }
  }

  cout << "\nPeta hasil:\n";

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << hasil[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main()
{
  int n;

  cout << "Ukuran peta (N): ";
  cin >> n;

  vector<vector<char>> peta(n, vector<char>(n));

  pair<int, int> start = {-1, -1};
  pair<int, int> goal = {-1, -1};

  cout << "Masukkan peta (S, G, #, dan cost 1-9):\n";

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> peta[i][j];

      if (peta[i][j] == 'S')
      {
        start = {i, j};
      }
      else if (peta[i][j] == 'G')
      {
        goal = {i, j};
      }
    }
  }

  aStarSearch(peta, start, goal);

  return 0;
}