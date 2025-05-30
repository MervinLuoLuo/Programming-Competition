#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;


int n;
void solve(){
    cin >> n;
    int ans = 0;
    if(n==1){
        cout<< 1 << endl;
        return;
    }
    vector<int> ls;
    int tmp=sqrt(n);
    for(int i = 1; i <= tmp; i++){
        if(n%i==0){
            int j=n/i;
            ls.push_back(i);
            if(j!=i)
                ls.push_back(j);
        }
    }
    sort(ls.begin(),ls.end());
    for(int i=0;i<ls.size()-1;++i){
        ans+=n/ls[i]*(ls[i+1]-ls[i]);
    }
    ans++;
    cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

/*
给定一个数 n
求从  1 -> n 进行函数计算的结果之和
函数: 
int f(a,b){
    i = b
    while(i >= 2){
        if(a % i == 0) return a/i
        else i = i - 1
    }
    return a
}
Input: 
t cases
n
Output: 
和
*/
