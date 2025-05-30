#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;cin >> n >> k;
    unordered_map<int,int> cnt;
    vector<int> a(n + 5), good;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        cnt[a[i]] ++;
    }
    for(auto &[num,count] : cnt){
        if(count == k) good.push_back(num);
    }
    if(good.empty()) {cout << -1 << endl;return 0;}
    sort(good.begin(),good.end());
    cout << good.back() << endl;
    return 0;
}