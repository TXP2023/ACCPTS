#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<string> pcs(N, ""); // 所有PC初始化为空字符串
    string server = "";         // 服务器初始字符串为空

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            cin >> p;
            pcs[p - 1] = server; // 将服务器字符串复制到PC p
        }
        else if (type == 2) {
            int p;
            string s;
            cin >> p >> s;
            pcs[p - 1] += s; // 将字符串s追加到PC p的字符串末尾
        }
        else if (type == 3) {
            int p;
            cin >> p;
            server = pcs[p - 1]; // 将PC p的字符串复制到服务器
        }
    }

    // 输出最终结果
    cout << "" << server << endl;
    return 0;
}