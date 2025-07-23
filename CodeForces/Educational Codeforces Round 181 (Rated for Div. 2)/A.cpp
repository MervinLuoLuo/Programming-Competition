#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

// void solve(){
//     string s;cin >> s;
//     int n = s.size();
//     int cntf = 0,cntn = 0,cntt = 0;
//     for(char c : s){
//         if(c == 'F') cntf++;
//         else if(c == 'T') cntt++;
//         else if(c == 'N') cntn++;
//     }

//     while(cntt--)cout << 'T';
//     while(cntf--) cout << 'F';
//     while(cntn--) cout << 'N';
//     for(char c : s){
//         if(c != 'F' && c != 'N' && c != 'T') cout << c;
//     }
//     cout << endl;
// }

void solve(){
    string s;cin >> s;
    int n = s.size();
    int cnt = 0;
    for(char c : s){
        if(c == 'T') cnt++;
    }
    while(cnt--) cout << 'T';
    for(char c : s){
        if(c != 'T') cout << c;
    }
    cout << endl;

} 

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}