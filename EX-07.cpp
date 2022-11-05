#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> A(N, 0);
    vector<int> B(N, 0);
    vector<int> WA(N + 1, 0);
    vector<int> WB(N + 1, 0);
    vector<vector<int>> DP(N, vector<int>(2, 0));

    for(int i = 0; i < N - 1; i++)
        cin >> A[i] >> B[i] >> WB[i + 1] >> WA[i + 1];
    cin >> A[N - 1] >> B[N - 1];

    DP[0][0] = A[0];
    DP[0][1] = B[0];

    for(int i = 1; i < N; i++) {
        DP[i][0] = min(DP[i - 1][0], DP[i - 1][1] + WA[i]) + A[i];
        DP[i][1] = min(DP[i - 1][1], DP[i - 1][0] + WB[i]) + B[i];
    }

    int ans = min(DP[N - 1][0], DP[N - 1][1]);

    cout << ans << '\n';

	return 0;
}