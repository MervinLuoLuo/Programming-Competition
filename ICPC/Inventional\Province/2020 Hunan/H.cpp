#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int mod = 1e9 + 7;

int a,b;

int getA(int x1,int y1,int x2,int y2){
    if(x1<=x2&&y1<=y2){
        return (x2-x1)*(y2-y1);
    }else{
        return 0;
    }
    
}

void solve(){
    int x1,x2,y1,y2;cin>>x1>>x2>>y1>>y2;

    int a1 = getA(0,0,a,b);
    int a2 = getA(x1,y1,x2,y2);
    int a3 = getA(x1,y1,a,b);
    cout<<a1+a2-a3<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>a>>b)
    solve();
    return 0;
}