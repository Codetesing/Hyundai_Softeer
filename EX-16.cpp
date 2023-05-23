#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> find_available_time(vector<bool> v) {
	vector<string> st;

	for(int i = 9; i < 18; i++) {
		if(!v[i]) {
			int s = i;
			while(i <= 18 && !v[i])
				i++;
			
			int e = i;
			if(i != 19) i--;
			else e--;

			string t = "";
			if(s < 10)
				t += "0";
			t += to_string(s) + "-" + to_string(e);

			st.push_back(t);
		}
	}

	return st;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	map<string, vector<bool>> reserved;
	string conf_name;
	for(int i = 0; i < n; i++) {
		cin >> conf_name;
		reserved[conf_name] = vector<bool>(19, false);
	}

	int start, end;
	for(int i = 0; i < m; i++) {
		cin >> conf_name >> start >> end;
		for(int j = start; j < end; j++)
			reserved[conf_name][j] = true;
	}

	for(auto i = reserved.begin(); i != reserved.end(); i++) {
		if(i != reserved.begin())
			cout << "-----" << '\n';
		
		cout << "Room " << i->first << ":\n";
		vector<string> temp = find_available_time(i->second);

		if(temp.empty()) {
			cout << "Not available" << '\n';
		}
		else {
			cout << temp.size() << " available:\n";
			for(auto i : temp)
				cout << i << '\n';
		}
	}

	return 0;
}
