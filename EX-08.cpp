#include<iostream>

using namespace std;

#define DIV 1000000007

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int K, P, N; cin >> K >> P >> N;

	long long ans = K;

	for (int i = 0; i < N; i++) {
		ans *= P;
		ans %= DIV;
	}

	cout << ans << '\n';

	return 0;
}