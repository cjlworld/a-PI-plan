#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define aut vector<int>::iterator
const int N = 100010;

int a[N], pos[N], t[N], c[N], f[2000][2000];
vector<int> v[N];

int getcnt(int l, int r, int x) {
    aut lt = lower_bound(v[x].begin(), v[x].end(), l);
    aut rt = upper_bound(v[x].begin(), v[x].end(), r);
    return rt - lt;
}

int main() {
    int n, m = 0;
    scanf("%d", &n);
    int k = 200;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[i] = (i - 1) / k + 1;
        t[++m] = a[i];
    }
    sort(t + 1, t + m + 1);
    m = unique(t + 1, t + m + 1) - t - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(t + 1, t + m + 1, a[i]) - t;
        v[a[i]].push_back(i);
    }
    for (int i = 1; i <= pos[n]; i++) {
        memset(c, 0, sizeof(c));
        int cnt = 0, val = 0;
        for (int j = (i - 1) * k + 1; j <= n; j++) {
            c[a[j]]++;
            if (c[a[j]] > cnt || (c[a[j]] == cnt && a[j] < val)) {
                cnt = c[a[j]];
                val = a[j];
            }
            if (j == n || j % k == 0)
                f[i][(j - 1) / k + 1] = val;
        }
    }
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int cnt = 0, val = 0;
        if (pos[l] + 1 <= pos[r] - 1) {
            val = f[pos[l] + 1][pos[r] - 1];
            cnt = getcnt(l, r, val);
        }
        for (int j = l; j <= min(r, pos[l] * k); j++) {
            int tmp = getcnt(l, r, a[j]);
            if (tmp > cnt || (tmp == cnt && a[j] < val)) {
                cnt = tmp;
                val = a[j];
            }
        }
        if (pos[l] != pos[r]) {
            for (int j = (pos[r] - 1) * k + 1; j <= r; j++) {
                int tmp = getcnt(l, r, a[j]);
                if (tmp > cnt || (tmp == cnt && a[j] < val)) {
                    cnt = tmp;
                    val = a[j];
                }
            }
        }
        printf("%d\n", t[val]);
    }
    return 0;
}
