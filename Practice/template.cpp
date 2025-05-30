#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;cin >> q;
    vector<deque<int>> dqs(q + 5);
    while(q--){
        string op;cin >> op;
        if(op == "push_back"){
            int num, x;cin >> num >> x;
            num--;
            dqs[num].push_back(x);
        }
        else if(op == "pop_back"){
            int num; cin >> num; num--;
            if(dqs[num].empty()) continue;
            else dqs[num].pop_back();
        }
        else if(op == "push_front"){
            int num, x;cin >> num >> x; num--;
            dqs[num].push_front(x);
        }
        else if(op == "pop_front"){
            int num;cin >> num;num--;
            if(dqs[num].empty()) continue;
            else dqs[num].pop_front();
        }
        else if(op == "size"){
            int num;cin >> num; num--;
            cout << dqs[num].size() << endl;
        }
        else if(op == "front"){
            int num; cin >> num; num--;
            if(dqs[num].empty()) continue;
            cout << dqs[num].front() << endl;
        }
        else{
            int num;cin >> num; num--;
            if(dqs[num].empty())continue;
            cout << dqs[num].back() << endl;
        }
    }

    return 0;
}