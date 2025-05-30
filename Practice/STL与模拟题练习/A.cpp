/*https://vjudge.net/contest/685207#problem/A*/
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
    string s;
    while(cin >> s){
        sort(s.begin(),s.end());
        for(int i = 0; i < s.size() - 1; i++){
            cout << s[i] << ' ';
        }
        cout << s[s.size() - 1] << endl;
    }
    return 0;
}