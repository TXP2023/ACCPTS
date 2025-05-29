#include  <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define rei register int
#define N 100005

char a[N], b[N], h1[N << 1], h2[N << 1];//h ��չ������ 
int n, len, p1[N << 1], p2[N << 1], l1[N << 1], l2[N << 1];//p �ǰ뾶���飬l �洢����Ĵ����� 

void ch(char* x, char* y)//��չ 
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
		l[i - r[i] + 1] = max(l[i - r[i] + 1], r[i] - 1);//����Ըõ�Ϊ��˵������ͻ��Ĵ� 
	}
	for (rei i = 3; i < len; i += 2) l[i] = max(l[i - 2] - 2, l[i]);
	//����Ըõ�Ϊ��˵������Ĵ��������ͻ��Ĵ��벻���ͻ��Ĵ��� 
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
		//ע��ϸ�ڴ���l����ֻ���� # �ַ���ƥ���ַ�ֻ����ԭ���ַ�
		//��ʱ�ǵ�ǰλ�û� û�б�ƥ���� �Ĵ� 
		if (h1[i] != h2[i]) break;
	}
	printf("%d\n", ans); ;
	return 0;
}