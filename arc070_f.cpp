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
typedef set<LL>::iterator sit;
const int N = 4e3 + 10;
int st[N], top = 0;
 
bool qry(int a, int b) {
	cout <<'?'<<' '<<a - 1<<' '<<b - 1<<endl, cout.flush();
	static char s[2]; scanf("%s",s);
	return s[0] == 'Y';
}
 
char honest[N];
 
int main() {
	int a, b; scanf("%d%d",&a,&b);
	if (a <= b) cout <<"Impossible"<<endl, cout.flush();
	else {
		rep(i,1,a + b) {
			if (top && !qry(i, st[top - 1])) { top--; continue; }
			st[top++] = i;
		}
		rep(i,1,a + b) honest[i] = '0' + qry(st[0], i);
		cout <<'!'<<' '<<honest + 1<<endl;
	}
	return 0;
}			