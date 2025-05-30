#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(pii a, pii b){
    return a.first < b.first;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<pii> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i].first >> w[i].second;
    }
    sort(w.begin(), w.end(),cmp);
    //for(auto it : w) cout << it.first << ' ';
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0; i < n; i++){
        if(w[i].first <= q.size()){
            if(w[i].second > q.top()){
                ans -=q.top();
                q.pop();
                q.push(w[i].second);
                ans += w[i].second; 
            }
        }
        else{
            q.push(w[i].second);
            ans+=w[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
n 种工作
每个工作消耗 1 单位时间
每个工作的 Deadline 为 d[i] 得到的利润为 p[i]
求 FJ 获得利润最大值
Input: 
n
d[i] p[i]
Output: 
max sump

*/