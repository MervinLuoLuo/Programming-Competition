#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    string s;cin >> s;
    int n = s.size();
    int cnt0 = 0,cnt1=  0;
    for(char c : s){
        if(c == '0') cnt0++;
        else cnt1++;
    }
    if(cnt1 != cnt0){
        cout << -1 << endl;
        return;
    }
    stack<int> st;
    int pos = 1,type = 1;
    vector<PII> ans;

    for(char c : s){
        if(st.empty()){
            if(c == '0'){
                type = 1;
                ans.push_back({pos,type});
                st.push(0);
            }
            else{
                type = 2;
                ans.push_back({pos,type});
                st.push(1);
            }
        }
        else{
            if(type == 1){
                if(c == '0'){
                    ans.push_back({pos,type});
                    st.push(0);
                }
                else{
                    st.pop();
                    pos++;
                }
            }
            else{
                if(c == '1'){
                    ans.push_back({pos,type});
                    st.push(1);
                }
                else{
                    st.pop();
                    pos++;
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(auto [p,op] : ans) cout << p << " " << op << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}