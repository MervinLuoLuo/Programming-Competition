/*https://ac.nowcoder.com/acm/contest/99990/D*/
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
    int n, m , k;cin >> n >> m >> k;
    priority_queue<int> pq[2];
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        pq[x % 2].push(x);
    }
    for(int i = 1; i <= m; i++){
        if(k > 0 and !pq[1].empty() and (pq[0].empty() or ((pq[1].top() ^ 1) >= pq[0].top()))){
            pq[0].push(pq[1].top() ^ 1);
            pq[1].pop();
            k--;
        }
        if(pq[0].empty() or pq[0].top() == 0) break;
        int cur = pq[0].top();
        pq[0].pop();
        pq[(cur / 2) % 2].push(cur / 2);
    }
    int sum = 0;
    while(!pq[0].empty()){
        sum += pq[0].top();
        pq[0].pop();
    }
    while(!pq[1].empty()){
        int cur = pq[1].top();
        if(k > 0){
            cur ^= 1;
            k--;
        }
        sum += cur;
        pq[1].pop();
    }
    cout << sum << endl;
    return 0;
}