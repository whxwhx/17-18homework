#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
const int N = 2e5 + 10;
int n, k, j;
char s[N];
int a[N];
int main() {
	scanf("%d%d",&n,&k);
	scanf("%s",s + 1);
	rep(i,1,n) if (s[i] == 'A') a[i] = 1; else a[i] = 0;
	int cnt = 0, d = 0;
	rep(i,1,n) {
		if (a[i] ^ d) cnt++, a[i] ^= 1;
		if (cnt == k) {
			bool flag = false; 
			for(int j = i; j != i || !flag; j = j % n + 1, flag = true) 
				if (a[j] ^ d) putchar('A'); else putchar('B');
			return 0;
		}
		cnt++, d ^= 1;
		if (cnt == k) {
			bool flag = false;
			for(int j = i % n + 1; j != i % n + 1 || !flag; j = j % n + 1, flag = true)
				if (a[j] ^ d) putchar('A'); else putchar('B');
			return 0;
		}
	}
	k -= cnt;
	k %= 2 * n;
	int j = 1;
	rep(i,1,k) {
		if (a[j] ^ d) a[j] ^= 1;
		else d ^= 1, j = (j % n + 1);
	}
	int S = j; bool flag = false;
	for(;j != S || !flag; j = j % n + 1, flag = true)
		if (a[j] ^ d) putchar('A'); else putchar('B');
	return 0;
}
