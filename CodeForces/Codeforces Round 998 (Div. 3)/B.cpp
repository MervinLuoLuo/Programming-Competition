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
    int t; cin >> t;
    while(t--){
        int n,m;cin >> n >> m;
        if(n == 1){cout << 1 << endl;continue;}
        vector<vector<int>> a(n,vector<int>(m));
        bool flag = 0;
        int pos = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x;cin >> x;
                if(x == -1){
                    flag = 1;
                    pos = i;
                }
                a[i][j] = x;
            }
        }
        for(int i = 0; i < n; i++){
            sort(a[i].begin(),a[i].end());
        }
        queue<int> q, aq;
        if(flag) q.push(pos);
        int be = 0;
        int cir = 0;
        if(flag) cir = 1;
        int flag2 = 1;
        while(q.size() != n){
            if(cir == n){break;flag2 = 0;}
            for(int i = 0; i < n; i++){
                if(a[i][0] == be){q.push(i);aq.push(i);be++;}
                cir++;
            }
        }
        if(flag2 == 0){cout << -1 << endl;continue;}
        /*int curl = 1,curn = a[q.front()][1],cnt = 1;
        bool flag1 = 1;
        while(curl <= m){
            if(cnt == n){curl++;cnt = 1;}
            int cur = q.front();
            q.pop();
            q.push(cur);
            if(a[cur][curl] != curn){
                flag1 = 0;break;
            }
            curn++;
            cnt++;
        }
        if(flag1){
            while(!aq.empty()){
                cout << aq.front() << ' ';
                aq.pop();
            }
        } 
        else cout << -1 << endl;*/
    }
    return 0;
}
/*
编号为0 ~ n*m-1 的牌 n 头牛 发 m 张牌
堆叠 要求放的牌必须比前者放的牌的点数大
存在 -1 牌
问是否存在一个 n 的排列  p 使得能够把所有牛的牌都出完
Input: 
n m
各牛收到的牌
n*m <= 2000
Output:
p or -1 
*/