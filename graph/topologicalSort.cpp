#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int Max = 501;

int inDegree[Max];
int n;
vector<int>a[Max];
vector <int>res;

bool tqsort() {
	queue<int>q;
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0)
			q.push(i);

	for (int i = 1; i <= n; i++) {
		if (q.empty())
			return false;
		
		int from = q.front();
		q.pop();
		res.push_back(from);
		for (int i = 0; i < a[from].size(); i++) {
			int to = a[from][i];
			inDegree[to] -= 1;
			if (inDegree[to] == 0)
				q.push(to);
		}
	}
	return true;
}

int main() {
	cin >> n;
	while (true) {
		int from, to;
		cin >> from >> to;
		if (from == -1)
			break;

		a[from].push_back(to);
		inDegree[to] += 1;
	}
	bool ans=tqsort();
	if (ans) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << '\n';
			
	}
	else
		cout << "Cycle\n";
}
