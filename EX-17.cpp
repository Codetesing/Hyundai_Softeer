#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> origin = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1110010", "1111111", "1111011"};

int turn_count(int a, int b) {
	int cnt = 0;

	if(b == -1) {
		for(int i = 0; i < 7; i++) {
			if(origin[a][i] == '1')
				cnt++;
		}
	}
	else {
		for(int i = 0; i < 7; i++) {
			if(origin[a][i] != origin[b][i])
				cnt++;
		}
	}

	return cnt;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for(int tc = 0; tc < T; tc++) {
		string a, b; cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		if(a.size() < b.size())
			swap(a, b);

		int i, cnt = 0;
		for(i = 0; i < b.size(); i++) {
			cnt += turn_count(a[i] - '0', b[i] - '0');
		}
		for(; i < a.size(); i++) {
			cnt += turn_count(a[i] - '0', -1);
		}

		cout << cnt << '\n';
	}

	return 0;
}
