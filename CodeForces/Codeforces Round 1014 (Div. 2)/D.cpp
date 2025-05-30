/*https://codeforces.com/contest/2092/problem/D*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin>>n;
    string s;cin>>s;

    vector<int>a(n);  //数字化
    vector<int>count(3);  //计数数组
    for(int i=0;i<n;i++){
        char cur=s[i];
        if(cur =='L') {a[i]=0;count[0]++;}
        if(cur =='I') {a[i]=1;count[1]++;}
        if(cur =='T') {a[i]=2;count[2]++;}
    }
    vector<int>p(3),ip(3);
    p[0] = 0,p[1] = 1,p[2] = 2;
    sort(p.begin(),p.end(),[&](int x,int y){
        return count[x] > count[y];
    });
    for(int i=0; i<3; i++) ip[p[i]] = i;
    for(int i=0; i<n; i++) a[i] = ip[a[i]];
    sort(count.begin(),count.end(),greater<int>());
    if(count[0] == n){no;return;}
    bool flag = 0;
    for(int i = 0;i < n-1; i++){
        if(a[i] + a[i+1] == 1) flag = 1;
    }
    if(!flag){
        for(int i = 0;i < n; i++){
            if(a[i] == 1) a[i] = 2;
            else if(a[i] == 2) a[i] = 1;
        }
        swap(count[1],count[2]);
    }
    int pos = 0;
    for(int i = 0;i < n-1;i++){
        if(a[i] + a[i+1] == 1){pos = i;break;}
    }
    vector<int> ans;
    int maxx = max(count[1], count[2]);
    int d = count[0] - maxx;
    int op = 2 * d;
    if(count [2] >= count[1]) op--;
    if(op == -1){
        if(a[pos] == 0){
            ans.push_back(pos);
            ans.push_back(pos+1);
        } 
        else {
            ans.push_back(pos);
            ans.push_back(pos);
            pos+=2;
        }
        count[0]++,count[2]++;
    } 
    else {
        count[1]+=op/2;
        count[2]+=(op+1)/2;
        if(a[pos]==0){
            while(op--){
                ans.push_back(pos);
            }
        } 
        else {
            for(int i=0;i<op;i++){
                ans.push_back(pos+i);
            }
            pos+=op;
        }
    }
    if(count[1]<count[2]){
        for(int i = 0;i < n; i++){
            if(a[i] == 1) a[i] = 2;
            else if(a[i] == 2) a[i] = 1;
        }
        swap(count[1],count[2]);
    }
    d = count[0] - count[2];
    if(d != 0){
        d--;
        ans.push_back(pos);
        for(int i = 0;i < d*2; i++) ans.push_back(pos);
        for(int i = 0;i < d*2; i++) ans.push_back(pos+d*2+1+i);
    }

    int cnt = ans.size();
    assert(cnt <= 2*n);
    cout << cnt << endl;
    for(auto it:ans){
        cout << it + 1 << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}