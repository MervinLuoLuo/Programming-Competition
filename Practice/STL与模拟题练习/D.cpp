/*https://vjudge.net/contest/685207#problem/D*/
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
    while(getline(cin, s)){
        s[0] -= 32;
        for(int i = 1; i < s.size();i++){
            if(s[i - 1] == ' ') s[i] -= 32;
        }
        cout << s << endl;
    }
    return 0;
}