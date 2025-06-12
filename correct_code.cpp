#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <cstdarg>
#include <climits>
#include <time.h>
#include <iostream>
#include <stdint.h>
#include <math.h>
#include <cmath>
using namespace std;

const int INT_SIZE = sizeof(int);
const int MAXN = 1000000 + 7;
const int MAXBLOCK = 1000 + 7;

int a[MAXN], d[MAXN], belong[MAXN];
int L[MAXBLOCK], R[MAXBLOCK], lazy[MAXBLOCK];
int n, q, block, tot, x, y, k;


void build() {
    block = (int)sqrt(n);
    tot = (n + block - 1) / block;
    for (int i = 1; i <= n; i++) {
        belong[i] = (i - 1) / block + 1;
    }
    for (int i = 1; i <= tot; i++) {
        L[i] = (i - 1) * block + 1;
        R[i] = min(i * block, n);
        sort(d + L[i], d + R[i] + 1);
    }
}

void modify_part(int bid, int st, int ed) {
    for (int i = st; i <= ed; i++) {
        a[i] += k;
    }
    int len = R[bid] - L[bid] + 1;
    memcpy(d + L[bid], a + L[bid], len * INT_SIZE);
    sort(d + L[bid], d + R[bid] + 1);
}

void modify() {
    if (belong[x] == belong[y]) {
        modify_part(belong[x], x, y);
        return;
    }

    modify_part(belong[x], x, R[belong[x]]);
    modify_part(belong[y], L[belong[y]], y);

    for (int i = belong[x] + 1; i < belong[y]; i++) {
        lazy[i] += k;
    }
}

int query_part(int bid, int st, int ed) {
    int ret = 0;
    for (int i = st; i <= ed; i++) {
        if (a[i] + lazy[bid] >= k) {
            ++ret;
        }
    }
    return ret;
}

int query() {
    if (belong[x] == belong[y]) {
        return query_part(belong[x], x, y);
    }

    int ansL = query_part(belong[x], x, R[belong[x]]);
    int ansR = query_part(belong[y], L[belong[y]], y);
    int ansM = 0;

    for (int i = belong[x] + 1; i < belong[y]; i++) {
        int pos = lower_bound(d + L[i], d + R[i] + 1, k - lazy[i]) - d;
        ansM += R[i] - pos + 1;
    }

    return ansL + ansR + ansM;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    build();
    while (q--) {
        char op;
        cin >> op >> x >> y >> k;
        switch (op) {
        case 'M': {
            modify();
            break;
        }
        case 'A': {
            cout << query() << '\n';
            break;
        }
        }
    }
    return 0;
}