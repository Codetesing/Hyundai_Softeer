#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K; cin >> N >> K;
	vector<int> arr(N, 0);
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	int A, B;
	for(int i = 0; i < K; i++)
	{
		cin >> A >> B;

		float out = 0;
		for(int j = A - 1; j < B; j++)
			out += arr[j];
		out /= (float)(B - A + 1);

		printf("%.2f\n", out);
	}

	return 0;
}
