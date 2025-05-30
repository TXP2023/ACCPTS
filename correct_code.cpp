#include<iostream>//万能头文件
#include<algorithm>
using namespace std;
long long L, R, ans, s[110000];
void cdq(int l, int r) {
    if (l == r)return;
    int mid = (l + r) / 2;
    cdq(l, mid), cdq(mid + 1, r);
    int head = l, tail = l - 1;
    for (int i = mid + 1; i <= r; i++) {
        while (tail + 1 <= mid && s[i] >= s[tail + 1] + L)tail++;
        while (head <= mid && s[i] > s[head] + R)head++;
        ans += tail - head + 1;
    }
    sort(s + l, s + r + 1);
}//cdq分治
int main() {
    freopen("input.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    int n;
    scanf("%d%lld%lld", &n, &L, &R);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] + x;//前缀和
    }
    cdq(0, n);
    printf("%lld\n", ans);
    return 0;
}