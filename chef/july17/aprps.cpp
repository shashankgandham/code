#include <bits/stdc++.h>
#define MOD int(1e9 + 7)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = 1 << 20;
int fac[maxn], ifac[maxn], n, a[maxn], x[maxn], y[maxn];

inline ll fpow(ll n, ll k, int p = MOD) {
	ll r = 1; 
	for (; k; k >>= 1) {
		if (k & 1) 
			r = r * n % p; 
		n = n * n % p;
	} 
	return r;
}

struct cplex {
    long double r, i;
    cplex() : r(0), i(0) {}
    cplex(long double n) : r(n), i(0) {}
    cplex(long double r, long double i) : r(r), i(i) {}
    long double real() {return r;}
    cplex operator + (cplex b) {return cplex (r + b.r, i + b.i);}
    cplex operator += (cplex b) {r += b.r, i += b.i; return *this;}
    cplex operator - (cplex b) {return cplex(r - b.r, i - b.i);}
    cplex operator * (cplex b) {return cplex(r * b.r - i * b.i, r * b.i + i * b.r);}
    cplex operator *= (cplex b) {long double r2 = r * b.r - i * b.i, i2 = r * b.i + i * b.r; r = r2, i = i2; return *this;}
    cplex operator /= (long double n) {r /= n, i /= n; return *this;}
};
void fft(cplex a[], int n, int invert) {
    static long double PI = 2 * acos((long double) 0);
    for (int i = 1, j = 0; i < n; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s;);
        if (i < j) swap(a[i], a[j]);
    }
    for (int m = 1; m < n; m <<= 1) {
        long double p = PI / m * (invert ? -1 : 1);
        cplex w = cplex(cos(p), sin(p));
        for (int i = 0; i < n; i += m << 1) {
            cplex unit = 1;
            for (int j = 0; j < m; j++) {
                cplex& x = a[i + j + m], &y = a[i + j], t = unit * x;
                x = y - t;
                y = y + t;
                unit *= w;
            }
        }
    }
    if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}
void modularmultiply(int a[], int b[], int c[], int na, int nb, int mod, int dup = 0) {
    static const int K = 2;
    static cplex ap[K][maxn << 1], bp[K][maxn << 1], cc[maxn << 1];
    int n = 1; while (n < na + nb - 1) n <<= 1;
    int base = (int) pow(MOD, 1.0 / K) + 1;
    for (int i = 0; i < n; i++) {
        int ta = i < na ? a[i] : 0, tb = i < nb ? b[i] : 0;
        for (int j = 0; j < K; j++) {
            ap[j][i] = ta % base;
            ta /= base;
            if (!dup) {
                bp[j][i] = tb % base;
                tb /= base;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        fft(ap[i], n, 0);
        if (!dup) {
            fft(bp[i], n, 0);
        }
        else {
            for (int j = 0; j < n; j++) {
                bp[i][j] = ap[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) c[i] = 0;
    for (int i = 0; i < K; i++) for (int j = 0; j < K; j++) {
        for (int k = 0; k < n; k++) cc[k] = ap[i][k] * bp[j][k];
        fft(cc, n, 1);
        for (int k = 0; k < n; k++) {
            long long z = (long long) (cc[k].real() + 0.5);
            z = (z % MOD + MOD) % MOD;
            for (int l = 0; l < i + j; l++) z = z * base % MOD;
            c[k] += z; if (c[k] >= MOD) c[k] -= MOD;
        }
    }
}

void multiply(int a[], int b[], int c, int n) {
    static int fa[maxn];
    static int fb[maxn];
    for (int step = 0; step < 2; step++) {
        for (int i = 0; i < n; i++) {
            fa[i] = (long long) a[n - i - 1] * fac[n - i - 1] % MOD;
        }
        int t = 1;
        for (int i = 0; i < n; i++) fb[i] = 0;
        for (int i = 0; i < n; i++) if (!(i + step & 1)) {
            fb[i] = (long long) t * ifac[i] % MOD;
            t = (long long) t * c % MOD;
        }
        modularmultiply(fa, fb, fa, n, n, MOD);
        reverse(fa, fa + n);
        for (int i = 0; i < n; i++) {
            fa[i] = (long long) fa[i] * ifac[i] % MOD;
        }
        modularmultiply(fa, fa, fa, n, n, MOD, 1);
        for (int i = 0; i < n + n - 1; i++) {
            if (!step) {
                b[i] = fa[i];
            }
            else {
                b[i] -= (long long) fa[i] * c % MOD;
                if (b[i] < 0) b[i] += MOD;
            }
        }
    }
}

void solve() {
    fac[0] = 1; for (int i = 1; i < 100005; i++) fac[i] = (long long) fac[i - 1] * i % MOD;
    for (int i = 0; i < 100005; i++) 
		ifac[i] = fpow(fac[i], MOD - 2, MOD);
    
	int test; cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 0; i < n; i++) 
			cin >> a[i];
        x[0] = 0, x[1] = 1;
        for(int i = 0; i < n; i++) {
            int k = 1 << i;
            multiply(x, y, a[i], k + 1);
            for(int j = 0; j < 2*k + 1; j++) {
                x[j] = y[j];
            }
        }
        cout << (1 << n) << "\n";
		for(int i = 0; i < (1 << n) + 1; i++) {
            cout << x[i] << " \n"[i == (1 << n)];
        }
    }
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}
