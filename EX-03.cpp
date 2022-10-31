#include<iostream>

#define MOD 1000000007

using namespace std;

int main(int argc, char** argv)
{
	long long N, K, P;

	cin >> K >> P >> N;

	N *= 10;
	int cur = 1;
	
	while(1) {
		if(N == 1)
			break;
		
		if(N % 2 == 0)
		{
			P = P * P;
			P %= MOD;
			N /= 2;
		}
		else
		{
			K *= P;
			K %= MOD;
			N--;
		}
	}

	long long out = K * P;
	out %= MOD;

	cout << out << '\n';

	return 0;
}
