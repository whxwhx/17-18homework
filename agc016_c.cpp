#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Rep(i,a) for(int i = 0; i < (a); i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)//(a)!
#define dep(i,a,b) for(int i = (a); i >= (b); i--)
#define ab(a) ((a) > 0 ? (a) : -(a))
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back(a)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 510, inf = 1e9 - 1;
int s[N][N];
int main() {
	int n, m, a, b; scanf("%d%d%d%d",&n,&m,&a,&b);
	if (n % a == 0 && m % b == 0) printf("No\n");
	else {
		printf("Yes\n");
		int t = inf / (a * b);
		s[a - 1][b - 1] = - t * (a * b - 1) - 1;
		Rep(i,a) Rep(j,b) if (i < a - 1 || j < b - 1) s[i][j] = t;
		Rep(i,n) Rep(j,m) printf("%d%c",s[i % a][j % b],(j == m - 1 ? '\n' : ' '));
	}
	return 0;
}