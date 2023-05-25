#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct inter{
	int dis;
	int velocity;
} inter;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	vector<inter> limited(N, {0, 0});
	int temp_dis;
	for(int i = 0; i < N; i++) {
		cin >> temp_dis >> limited[i].velocity;
		for(int j = i; j < N; j++) {
			limited[j].dis += temp_dis;
		}
	}
	vector<inter> test(M, {0, 0});
	for(int i = 0; i < M; i++) {
		cin >> temp_dis >> test[i].velocity;
		for(int j = i; j < M; j++)
			test[j].dis += temp_dis;
	}

	int res = 0;
	for(int i = 0, j = 0; i < N && j < M; ) {
		if(limited[i].velocity < test[j].velocity)
			res = max(res, test[j].velocity - limited[i].velocity);

		if(limited[i].dis > test[j].dis) j++;
		else if(limited[i].dis < test[j].dis) i++;
		else {
			i++;
			j++;
		}
	}

	cout << res << '\n';

	return 0;
}
