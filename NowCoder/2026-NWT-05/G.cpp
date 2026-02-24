#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string ops;cin >> ops;
    
    int current_d = 0;
    for (char c : ops) {
        int op = c - '0';
        switch (op) {
            case 0: // 竖直翻转 | : 0<->3, 1<->2
                current_d = 3 - current_d;
                break;
            case 1: // 主对角线 / : 0->0, 2->2, 1<->3
                current_d = (4 - current_d) % 4;
                break;
            case 2: // 水平翻转 - : 0<->1, 3<->2
                if (current_d == 0) current_d = 1;
                else if (current_d == 1) current_d = 0;
                else if (current_d == 2) current_d = 3;
                else if (current_d == 3) current_d = 2;
                break;
            case 3: // 副对角线 \ : 0<->2, 1->1, 3->3
                current_d = (2 - current_d + 4) % 4;
                break;
            case 4: // 顺时针 90
                current_d = (current_d + 1) % 4;
                break;
            case 5: // 逆时针 90
                current_d = (current_d + 3) % 4;
                break;
        }
        cout << current_d;
    }
    cout << endl;
    
    return 0;
}