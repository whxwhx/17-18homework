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
typedef pair<int, int> pii;
#define x first
#define y second
const int N = 1e5 + 10;
int n, a[N];
int main() {	
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a + i);	
	sort(a + 1, a + n + 1);
	if (a[1] == a[n]) {
		if (a[1] <= n / 2 || a[1] == n - 1) printf("Yes\n");
		else printf("No\n"); 
	} else if (a[1] + 1 == a[n]) {
		int cnt = 0;
		rep(i,1,n) if (a[i] == a[1]) cnt++;
		if (a[n] <= cnt) printf("No\n");
		else if (a[n] > cnt + (n - cnt) / 2) printf("No\n");
		else printf("Yes\n");
	} else printf("No\n");
	return 0;
}
