#include<iostream>
#include<vector>

using namespace std;

string option(vector<int> a) {

	int opt = 0;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != i + 1)
		{
			opt = 1;
			break;
		}
	}

	if (opt == 0)
		return "ascending";

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != a.size() - i)
		{
			opt = 2;
			break;
		}
	}

	if (opt == 2)
		return "mixed";
	else
		return "descending";
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N = 8;
	vector<int> arr(N, 0);

	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	string ans = option(arr);

	cout << ans << '\n';

	return 0;
}