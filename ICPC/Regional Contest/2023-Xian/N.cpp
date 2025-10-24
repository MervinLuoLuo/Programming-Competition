#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int I,n,*a[3],*b[3],*c[3],ans;
void proc(auto a,auto A) {
    if (!isalpha(*a)) A[n]=new int(stoi(a));
    else A[n]=&I;
}

void solve(){
    string s;
    getline(cin,s);
    for (int _:{0,1}) {
        getline(cin,s);
        char a[9],b[9],c[9]{};
        sscanf(s.c_str(),"%*[\tf]or %*c in range(%[^,)],%[^,)],%[^,)]):",a,b,c);
        if (!*c) *c='1';
        proc(a,::a);proc(b,::b);proc(c,::c);
        ++n;
    }
    int F{**c>0?1:-1};
    for (I=**a;I*F<**b*F;I+=**c) {
        int A{*a[1]},B{*b[1]},C{*c[1]},f{1};
        if (C<0) A*=-1,B*=-1,C*=-1,f*=-1;
        int D{(B-A+C-1)/C};
        if (B>A) ans+=(A*2+(D-1)*C)*D/2*f;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}