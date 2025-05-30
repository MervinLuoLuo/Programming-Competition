/*https://www.luogu.com.cn/problem/P1125*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Lucky Word" << endl
#define no cout << "No Answer" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(pii &a,pii &b){
    return a.second < b.second;
}
void solve(){
    unordered_map<char,int> freq;
    string s; cin>> s;
    for(int i =0; i < s.size();i++){
        freq[s[i]]++;
    }
    vector<pii> fre;
    for(auto it : freq){
        int a = it.first;
        int b = it.second;
        fre.push_back({a,b});
    }
    sort(fre.begin(),fre.end(),cmp);
    int n = fre.size();
    int res = fre[n - 1].second - fre[0].second;
    bool flag = 1;
    for(int i =2; i * i <= res; i++){
        if(res % i == 0){
            flag = 0;break;
        }
    }
    if(res == 1 or res == 0) flag = 0;
    if(flag){yes;cout << res << endl;}
    else {no;cout << 0 << endl;}
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}