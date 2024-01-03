#include <iostream>
#include <vector>

using namespace std;

vector<int> ips;
string ip;
int length;

void printSol() {
    for (int i = 0; i < ips.size(); i++) {
        cout << ips[i];
        if (i < ips.size() - 1) {
            cout << ".";
        }
    }
    cout << endl;
}

void convert(int start, int path) {
    if (start == length && path == 4) {
        printSol();
        // return;
    }

    for (int i = 1; i <= 3; i++) {
        if (start + i <= length) {
            string sub = ip.substr(start, i);
            int num = stoi(sub);
            if (sub[0] == '0') {
                ips.push_back(num);
                convert(start + i, path + 1);
                ips.pop_back();
                break;
            }
            if (num > 0 && num <= 255) {
                ips.push_back(num);
                convert(start + i, path + 1);
                ips.pop_back();
            }
        }
    }
}

int main() {
    cin >> ip;
    length = ip.length();
    convert(0, 0);
    return 0;
}