#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M, N, K; cin >> M >> N >> K;
	vector<int> key(M);
	for(int i = 0; i < M; i++)
		cin >> key[i];
	vector<int> pressed(N);
	for(int i = 0; i < N; i++)
		cin >> pressed[i];

	string out = "normal";
	for(int i = 0; i <= N - M; i++) {
		if(pressed[i] == key[0]) {
			bool flag = true;
			for(int j = 1; j < M; j++) {
				if(pressed[i + j] != key[j]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				out = "secret";
				break;
			}
		}
	}

	cout << out << '\n';

	return 0;
}
