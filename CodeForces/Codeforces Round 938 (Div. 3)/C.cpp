#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e17;
const int  maxn = 1e7;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, k;cin >> n >> k;
        vector<int> ship(n + 5), pre(n  + 5), ba(n + 5);
        for(int i = 1; i <= n; i++){
            cin >> ship[i];
            pre[i] = pre[i - 1] + ship[i];
        }
        ba[n + 1] = 0;
        for(int i = n; i >= 1; i--){
            ba[i]=ba[i + 1] + ship[i];
        }
        if(pre[n] <= k){cout << n << endl; continue;}
        int tmp = 1000;
        int res = min(tmp, k);
        int L = 1, R = n;
        if(k > 1000){
            if(k % 2) res++;
            k -= res;
            int half = k / 2;
            k = res;
            while(pre[L] < half) L++;
            int gap = half - pre[L - 1];
            ship[L] -= gap;
            while(ba[R] < half) R--;
            gap = half - ba[R + 1];
            ship[R]-= gap;
        }

        deque<int> dq;
        for(int i = L; i <= R ; i++){
            if(ship[i] > 0)dq.push_back(ship[i]);
        }
        int now = 0;
        while(k-- and !dq.empty()){
            if(now == 0)dq.front()--;
            else dq.back()--;
            if(dq.front() == 0)dq.pop_front();
            if(dq.back() == 0) dq.pop_back();
            now ^= 1;
        }
        cout << n - dq.size() << endl;
    }
    return 0;
}
/*
n 艘船 i-th 艘船的耐久为 a[i]
攻击 k 次
先攻击第一艘船 再攻击最后一艘船 deque
每攻击一次船的耐久减少 1
船的耐久为 0 时就沉了 不再承受伤害
所有船都沉了就就停止攻击
问 k 为 0 时沉了几艘船
Input: 
t cases
n 船的数量 k 攻击次数
a[i] 船的耐久
2*1e5
Output: 
剩余船数
*/