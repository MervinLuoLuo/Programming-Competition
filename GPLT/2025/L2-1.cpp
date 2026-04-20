/*https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1913922872972247048&page=1*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int MAXN = 1e9;
constexpr int INF = 1e18;

void solve(){
    string s;cin >> s;
    stack<char> st;
    for(char c : s){
        if(c == ')'){
            string res = "";
            while(st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
            reverse(res.begin(),res.end());
            cout << res << endl;
        }
        else st.push(c);
    }
    string res = "";
    while(!st.empty()) {res += st.top();st.pop();}
    reverse(res.begin(),res.end());
    cout << res;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}