#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
 
struct job {
    int sad, start, to;
};
bool cmps(job p, job q) {
	return p.start < q.start;
}
class compare{
	public: 
		bool operator() (job p, job q) {
			return p.sad < q.sad;
		}
};
int main() {
	int t, n, d, to, st, sad;
	ll tsad, asad;
	job a[100005], temp;
	scanf("%d", &t);
	while(t--) {
		priority_queue<job, vector<job>, compare> s;
		tsad = 0;
		scanf("%d%d", &n, &d);
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d", &a[i].start, &a[i].to, &a[i].sad);
			tsad += (ll)a[i].sad*a[i].to;
		}
		sort(a, a+n, cmps);
		asad = 0;
		for(int i = 1, j = 0; i <= d; i++) {
			while(a[j].start == i && j < n)
				s.push(a[j++]);
			if(s.size()) {
				temp = s.top();
				temp.to--;
				s.pop();
				if(temp.to) 
					s.push(temp);
				asad += temp.sad;
			}
		}
		printf("%lld\n", tsad - asad);
	}
	return 0;
}
