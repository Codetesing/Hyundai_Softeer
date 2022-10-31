#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1000000001

using namespace std;

typedef struct lect{
	int s;
	int e;
}lect;

bool compare(lect a, lect b) {
	return a.e < b.e;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<lect> arr;

	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({a, b});
	}

	sort(arr.begin(), arr.end(), compare);

	int cur = arr[0].e;
	int cnt = 1;

	for(int i = 1; i < N; i++) {
		if(cur <= arr[i].s)
		{
			cur = arr[i].e;
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
