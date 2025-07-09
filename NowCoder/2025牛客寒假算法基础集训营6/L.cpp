#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    string ss = "CHICKEN";
    map<char,int> freq;
    int cnt = 0;
    for(auto it : s){
        if(it == ss[cnt]) cnt++;
        else freq[it]++;
    }
    int sum = 0, maxx = -1;
    for(auto it : freq){
        maxx = max(maxx , it.second);
        sum += it.second;
    }
    if(cnt == 7 and sum % 2 == 0 and maxx <= sum /2) yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}