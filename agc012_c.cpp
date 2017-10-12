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
LL n;

string str(int x) {
	string s = "";
	while (x) s = char(x % 10 + '0') + s, x /= 10;
	return s;
}

int main() {	
//	freopen("whx.in","r",stdin);
	cin >>n; n++;
	string s = "", t = "";
	bool flag = false; int cnt = 0;
	dep(i,40,0) if ((1LL << (i + 1)) <= n) {
		cnt += 2;
		if (s.length()) s = s + ' '; 
		s = s + str(i + 1);
		if (t.length()) t = t + ' ';
		t = t + str(i + 1);

		if (n >> i & 1) s = s + ' ' + str(45 + i), t = str(45 + i) + ' ' + t, cnt += 2;
	}
	cout <<cnt<<endl;
	cout <<s<<' '<<t<<endl;
	return 0;
}
