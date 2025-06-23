#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<string> pcs(N, ""); // ����PC��ʼ��Ϊ���ַ���
    string server = "";         // ��������ʼ�ַ���Ϊ��

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            cin >> p;
            pcs[p - 1] = server; // ���������ַ������Ƶ�PC p
        }
        else if (type == 2) {
            int p;
            string s;
            cin >> p >> s;
            pcs[p - 1] += s; // ���ַ���s׷�ӵ�PC p���ַ���ĩβ
        }
        else if (type == 3) {
            int p;
            cin >> p;
            server = pcs[p - 1]; // ��PC p���ַ������Ƶ�������
        }
    }

    // ������ս��
    cout << "" << server << endl;
    return 0;
}