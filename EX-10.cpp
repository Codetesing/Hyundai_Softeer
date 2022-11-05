#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define MAX 26

int N;
vector<string> map;
bool visited[MAX][MAX] = { 0 };
vector<int> ans;
int map_cnt = 0;

int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, -1, 1, 0 };

void DFS(int x, int y) {

	visited[x][y] = true;

	map_cnt++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
			continue;

		if (!visited[next_x][next_y] && map[next_x][next_y] == '1')
			DFS(next_x, next_y);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	string a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		map.push_back(a);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j] && map[i][j] == '1')
			{
				map_cnt = 0;
				DFS(i, j);
				ans.push_back(map_cnt);
			}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';

	return 0;
}