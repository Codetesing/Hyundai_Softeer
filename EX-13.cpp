#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;

	string in; cin >> in;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (in[i] == 'P') {
			for (int j = i - K; j <= i + K; j++) {
				if (j < 0 || i == j || j >= N)
					continue;
				if (in[j] == 'H') {
					in[j] = 'X';
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}