#include <iostream>
#define int unsigned long long
using namespace std;
const int MAXN = 1e5 + 7;
int a[MAXN];
signed main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == n * (n + 1) / 2) {
            cout << n << endl;
        }
        else {
            int ans = 0;
            for (int i = 1; i < n; i++) {
                if (i * (i + 1) / 2 + n - i > sum) {
                    break;
                }
                ans = i;
            }
            cout << ans << endl;
        }
    }
}