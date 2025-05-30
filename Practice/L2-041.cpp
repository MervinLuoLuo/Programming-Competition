#include<iostream>
#define endl "\n"
using namespace std;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m ,k;cin >> n >> m >> k;
    stack<int> box;
    deque<int> ts;
    vector<vector<int>> fi;
    vector<int> tmp;
    for(int i = 0; i < n;i++){
        int x;cin >> x; ts.push_back(x);
    }
    while(!box.empty() or !ts.empty()){
        if(tmp.empty()){
            if(!box.empty()){
                tmp.push_back(box.top());
                box.pop();
            }
            else if(!ts.empty()){
                tmp.push_back(ts.front());
                ts.pop_front();
            }
            else break;
        }
        else if(!box.empty() and box.top() <= tmp.back()){
            tmp.push_back(box.top());box.pop();
        }
        else{
            int t = -1;
            if(!ts.empty()){
                if(ts.front() <= tmp.back()){tmp.push_back(ts.front());ts.pop_front();}
                else{
                    if(box.size() < m){
                        box.push(ts.front());ts.pop_front();
                    }
                    else {
                        fi.push_back(tmp);
                        tmp.clear();
                    }
                }
            }
            else{
                fi.push_back(tmp);
                tmp.clear();
            }
        }
    }
    for(int i = 0; i < fi.size();i++){
        for(int j = 0; j < fi[i].size(); j++){
            cout << fi[i][j] <<' ';
        }
        cout << endl;
    }
    return 0;
}