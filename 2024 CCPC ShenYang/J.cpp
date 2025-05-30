#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<string, int>
using namespace std;
const int INF = 1e17;
const int maxn = 1e8;

bool cmp (pair<string,int> a,pair<string,int> b){
    return a.second > b.second;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<pii> l(4),r(4);
    for(int i = 0 ; i < 4; i++){
        cin >> l[i].first >> l[i].second;
    }
    sort(l.begin(),l.end(),cmp);
    for(int i = 0; i < 4; i++){
        cin >> r[i].first >> r[i].second;
    }
    sort(r.begin(),r.end(),cmp);
    pii L = max(l[0],r[0],cmp);
    pii R = min(l[0],r[0],cmp);
    cout << R.first << " beats " << L.first;
    return 0;
}