/*https://ac.nowcoder.com/acm/problem/16417*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
vector<int> dsu;
struct Node{
    int x = 0,y = 0,z = 0;
};
vector<Node> node;

int find(int cur){
    if(dsu[cur] != cur) dsu[cur] = find(dsu[cur]);
    return dsu[cur];
}

void solve(){
    int n,h,r;cin >> n >> h >> r;
    dsu.assign(n + 5, 0);
    node.assign(n + 5,Node());
    for(int i = 1; i <= n; i++) dsu[i] = i;
    for(int i = 1; i <= n; i++) cin >> node[i].x >> node[i].y >> node[i].z;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
                int dis =  pow((node[i].x - node[j].x),2) 
                    + pow((node[i].y - node[j].y),2) 
                    + pow((node[i].z - node[j].z),2);
            if(dis <= 4 * r * r){
                int fx = find(i), fy = find(j);
                if(fx != fy) dsu[fx] = fy;
            }
        }
    }
    vector<int> bottom, top;
    for(int i = 1; i <= n; i++){
        if(node[i].z - r <= 0) bottom.push_back(i);
        if(node[i].z + r >= h) top.push_back(i);
    }

    for(int i = 0; i < bottom.size(); i++){
        for(int j = 0; j < top.size(); j++){
            if(find(bottom[i]) == find(top[j])){yes;return;}
        }
    }
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}