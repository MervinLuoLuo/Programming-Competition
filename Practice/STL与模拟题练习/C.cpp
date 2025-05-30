/*https://vjudge.net/contest/685207#problem/C*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        string s;cin >> s;
        int cnt = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i] <= '9' and s[i] >= '0') cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}