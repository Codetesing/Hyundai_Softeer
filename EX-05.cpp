#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct jewl {
	int M;
	int P;
} jewl;

bool compare(jewl a, jewl b) {
	return a.P > b.P;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int W, N; cin >> W >> N;

	vector<jewl> arr;

	int a, b;
	for(int i = 0; i < N; i++) {
		cin >> a >> b;

		arr.push_back({a, b});
	}

	sort(arr.begin(), arr.end(), compare);

	int val = 0;
	for(int i = 0; i < N; i++) {
		if(W >= arr[i].M) {
			val += arr[i].M * arr[i].P;
			W -= arr[i].M;
		}
		else {
			val += W * arr[i].P;
			W = 0;
		}

		if(W == 0)
			break;
	}

	cout << val << '\n';

	return 0;
}
