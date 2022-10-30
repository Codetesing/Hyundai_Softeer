#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> arr(N, 0);
	vector<int> cnt(N, 1);

	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < N; i++)
	{
		for(int j = i + 1; j < N; j++)
			if(arr[i] < arr[j] && cnt[j] <= cnt[i])
			{
				cnt[j] = cnt[i] + 1;
			}
	}

	int max_val = *max_element(cnt.begin(), cnt.end());

	cout << max_val << '\n';

	return 0;
}
