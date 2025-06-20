#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define R register int
using namespace std;
inline int read()
{
	int f = 1, x = 0; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return f * x;
}
const int maxn = 100005;
struct Data
{
	int x, y, e;
}a[maxn];
inline bool cmp(Data x, Data y)
{
	return x.e > y.e;
}
int t, n, f[maxn], b[maxn << 2];//b��������Ҫ��������С����Ȼ�ҿ���4��������Ϊ�տ�ʼҪͬʱ��¼����ֵ
inline int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}
int main()
{
	t = read();
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(f, 0, sizeof(f));
		n = read(); int tot = 0;
		for (R i = 1; i <= n; ++i)
		{
			a[i].x = read(); a[i].y = read(); a[i].e = read();
			b[++tot] = a[i].x;//��¼��Щֵ
			b[++tot] = a[i].y;
		}
		sort(b + 1, b + 1 + tot);
		int tott = unique(b + 1, b + 1 + tot) - b;//algorithm�еĺ�����������ȥ�أ�Ȼ�󷵻�ĩβָ�롣�����һ��b�Ϳ��Ա�ʾb���ڵĴ�С��
		for (R i = 1; i <= n; ++i)
		{
			a[i].x = lower_bound(b + 1, b + 1 + tott, a[i].x) - b;//ʮ��ʵ�õ�lower_bound��Ѱ��b��>=a[i].x�ĵ�һ������ָ�루��Ϊa[i].x��b��һ�����ڣ�������ֱ�����a[i].x��ɢ�����Ӧ��ֵ������ȥb��������λ�á�
			a[i].y = lower_bound(b + 1, b + 1 + tott, a[i].y) - b;
		}
		//--------------����Ϊ��������
		for (R i = 1; i <= tott; ++i) f[i] = i;
		sort(a + 1, a + 1 + n, cmp);
		bool ff = true;
		for (R i = 1; i <= n; ++i)
		{
			if (a[i].e == 1)
			{
				int f1 = find(a[i].x), f2 = find(a[i].y);
				if (f1 != f2)
				{
					f[f1] = f2;
				}
			}
			else {
				int f1 = find(a[i].x), f2 = find(a[i].y);
				if (f1 == f2)
				{
					ff = false;//�ҵ�һ��������Ϳ����˳���
					break;
				}
			}
		}
		if (ff == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}