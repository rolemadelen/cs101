#include <iostream>
using namespace std;

int main() {
    int arr[10001] = {0};
    int pos = 0;

    int cmds;
    cin >> cmds;
    while(cmds--) {
        string s;
        cin >> s;

        if(s[0] == 'p') {
            if(s[1] == 'u') {
                int data;
                cin >> data;
                arr[pos++] = data;
            } else {
                if(pos == 0) cout << -1 << endl;
                else {
                    --pos;
                    cout << arr[pos] << endl;
                }
            }
        }
        else if(s[0] == 's') {
            cout << pos << endl;
        }
        else if(s[0] == 'e') {
            cout << (pos == 0) << endl;
        }
        else if(s[0] == 't') {
            if(pos == 0) cout << -1 << endl;
            else cout << arr[pos-1] << endl;
        }
    }
}