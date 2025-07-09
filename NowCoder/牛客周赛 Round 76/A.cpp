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
    int n;cin >> n;
    if(n <= 5) {cout << 3 * n << endl;return 0;}
    if(n > 5 and n <= 7){cout << 15 << endl;return 0;}
    int week = n / 7;
    int left = n % 7;
    if(left > 5) left = 5;
    int ans = (week * 5 * 3) + (left * 3);
    cout << ans << endl;
    return 0;
}