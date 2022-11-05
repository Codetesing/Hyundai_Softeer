#include<iostream>
#include<vector>

using namespace std;

#define MAX 101

int N, M;
int map[MAX][MAX];
int ori[MAX][MAX];
bool visited[MAX][MAX] = { false };

int ROTATE_X[] = { -1, 0, 0, 1 };
int ROTATE_Y[] = { 0, 1, -1, 0 };

int trans(int x, int y) {
	
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
		{
			cnt++;
			continue;
		}

		if (map[next_x][next_y] == 0)
			cnt++;
	}

	return cnt;
}

bool IS_CLEAR() {

	bool flag = true;
	vector<int> x;
	vector<int> y;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j] == 1)
			{
				flag = false;

				if (trans(i, j) >= 2)
				{
					x.push_back(i);
					y.push_back(j);
				}
			}

	for (int i = 0; i < x.size(); i++)
		map[x[i]][y[i]] = 0;

	return flag;
}

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + ROTATE_X[i];
		int next_y = y + ROTATE_Y[i];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			continue;

		if (!visited[next_x][next_y] && map[next_x][next_y] == 0)
			DFS(next_x, next_y);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			ori[i][j] = map[i][j];
		}

	int ans = 0;

	while (1) {

		DFS(0, 0);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!visited[i][j] && map[i][j] == 0)
					map[i][j] = 1;

		if (IS_CLEAR())
			break;
		ans++;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (ori[i][j] == 0)
					map[i][j] = 0;
				visited[i][j] = false;
			}
	}

	cout << ans << '\n';

	return 0;
}