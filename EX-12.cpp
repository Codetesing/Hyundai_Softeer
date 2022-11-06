#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	int r = 2;

	for (int i = 0; i < N; i++) {
		r = r * 2 - 1;
	}

	cout << r * r << '\n';

	return 0;
}