#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	bool ok = true;
	bool curr = (s[0] == '1');
	int cnt = (s[0] == '0' ? 1 : 0);
    cout << "i = 0 " << curr << " " << cnt << endl;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0')
			cnt++;
		// if (i == 0)
			// continue;
		if (s[i] == s[i-1] && s[i] == '0')
			curr = false;
		if (s[i] == s[i-1] && s[i] == '1') {
			if (curr && cnt % 2 == 1)
				ok = false;
			curr = true;
			cnt = 0;
		}
        cout << "i = "  << i << " " << curr << " " << cnt << endl; 
	}
	
	if (curr && cnt % 2 == 1 && s[n-1] == '1')
		ok = false;
		
	// cout << (ok ? "YES" : "NO") << "\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--)
		solve();
}