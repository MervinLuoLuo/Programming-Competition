#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int lc(int a,int b){
    int k;
    while(b!=0){
        k=b;
        b=a%b;
        a=k;
    }
    return a;
}
int lm(int x,int y,int p){
    int sum;
    sum=x/lc(x,y)*y;
    return sum;
}
void solve(){
    int n;cin >> n;
    int p;cin >> p;
    // int arr[n];
    // vector<int> arr(n);
    // for(int i=0;i<n;i++){
    //     arr[i]=i+1;
    // }
    int temp= 1,result;
    for(int i=1;i<n;i++){
        int m = lm(temp,i + 1,p);
        temp = m;
    }
    result = temp % p;
    cout << result;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}