#include <bits/stdc++.h>
typedef unsigned long long int ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freeopen("input.txt", "r", stdin);
	// freeopen("output.txt", "w", stdout);
	// #endif

	vector<int> v={1,6,8,6,5};
	sort(v.begin(), v.end(),greater<int>());
	for(auto &it:v)
	{
		cout<<it<<" ";
	}

	return 0;
}
