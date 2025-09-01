#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int suma = 0, sumb = 0;
    int k = 0;
    for(int i = 0; i < 2 * n; i++){
        if(s[i] == 'A'){
            k++;
            suma += abs((i + 1) - (2 * k - 1));
            sumb += abs((i + 1) - 2 * k);
        }
    }

    cout << min(suma,sumb);

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}