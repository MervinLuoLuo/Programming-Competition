/*https://codeforces.com/contest/2057/problem/B*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(const pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k;cin >> n >> k;
        map<int,int> freq;
        for(int i = 0; i < n; i++){
            int x;cin >> x;
            freq[x]++;
        }
        vector<int> a;
        for(auto [_ ,x] : freq){
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        int ans = a.size();
        for(int i = 0; i < a.size(); i++){
            if(k >= a[i]){
                ans--;
                k -= a[i];
            }
        }
        if(ans == 0) ans++;
        cout << ans << endl;
    }
    return 0;
}
/*
给一个数组 b 
函数 f(b) 为使得数组 b 为空的操作的最小次数
    取整数 l r (l <= r) 使 x = min(b[i] to b[r])
    删除数组中 [l ,r] 且 b[i] = x 的元素
给定长度为 n 的数组
p 为数组中的数字 可以令任意 a[i]替换为 p 次数不超过 k
求 f(a) min
Input: 
n(1e5) k
a[i]
1e5
Ouput: 
f(a) min
*/ 