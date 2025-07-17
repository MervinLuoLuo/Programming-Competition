#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
void sor(int c,int n,int *ran,int *f){
    int num[n],max=0,m;
    for(int i=1;i<c;i++)
        num[i]=ran[i]-ran[i-1];
    for(int i=1;i<c;i++){
        if(max<num[i]){
            max=num[i];
            m=i;
        }
    }
    f[ran[m-1]+1]=2;
}
void solve(){
    int sum=0,c=1,n,t0;
    cin >> n >> t0;
    int f[n],ran[n];
    for(int i=0;i<n;i++)
        cin >> f[i];
    for(int i=0;i<n;i++){
        if(f[i]==0)sum+=1;
        else {
            ran[c]=i;
            c++;
        }
        if(c==2)f[ran[c-1]+1]=2;
        else sor(c,n,ran,f);
    }
    for(int i=0;i<t0;i++){
        for(int j=1;j<c;j++){
            if(f[ran[j]+1]==2)continue;
            else f[ran[j]+1]=1;
            if(f[ran[j]-1]==2)continue;
            else f[ran[j]-1]=1;
            if(ran[j]==0)f[n]=1;
            if(ran[j]==n)f[0]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(f[i]==0)ans+=1;
    }
    cout << ans << endl;
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