#include  <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define rei register int
#define N 100005

char a[N], b[N], h1[N << 1], h2[N << 1];//h 是展开数组 
int n, len, p1[N << 1], p2[N << 1], l1[N << 1], l2[N << 1];//p 是半径数组，l 存储最长回文串长度 

void ch(char* x, char* y)//扩展 
{
	rei k = 0; y[k++] = '$', y[k++] = '#';
	for (rei i = 0; i < n; i++) y[k++] = x[i], y[k++] = '#';
	y[len = k] = '&';
}

void manacher(char* op, int* r, int* l) {
	int mr = 0, c;
	for (rei i = 1; i < len; i++) {
		if (i < mr) r[i] = min(r[2 * c - i], mr - i);
		else r[i] = 1;
		while (op[i + r[i]] == op[i - r[i]]) r[i]++;
		if (i + r[i] - 1 > mr) mr = i + r[i] - 1, c = i;
		l[i - r[i] + 1] = max(l[i - r[i] + 1], r[i] - 1);//求出以该点为左端点的最长饱和回文串 
	}
	for (rei i = 3; i < len; i += 2) l[i] = max(l[i - 2] - 2, l[i]);
	//求出以该点为左端点的最长回文串（含饱和回文串与不饱和回文串） 
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	scanf("%s", a); n = strlen(a);
	int ans = 0;
	for (rei i = 0; i < n; i++) b[i] = a[n - i - 1];
	ch(a, h1), manacher(h1, p1, l1);
	ch(b, h2), manacher(h2, p2, l2);
	for (rei i = 2; i <= len; i += 2) {
		ans = max(max(i - 2 + l1[i - 1], i - 2 + l2[i - 1]), ans);
		//注意细节处理，l数组只考虑 # 字符，匹配字符只考虑原串字符
		//此时是当前位置还 没有被匹配上 的答案 
		if (h1[i] != h2[i]) break;
	}
	printf("%d\n", ans); ;
	return 0;
}