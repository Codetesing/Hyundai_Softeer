#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	
	vector<int> W(N + 1, 0);
	vector<vector<int>> G(N + 1, vector<int>());
	for (int i = 1; i <= N; i++)
		cin >> W[i];

	int a, b;
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int max_val = W[i];
		bool flag = true;

		for (int j = 0; j < G[i].size(); j++)
			if (max_val <= W[G[i][j]])
			{
				flag = false;
				break;
			}

		if (flag)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}