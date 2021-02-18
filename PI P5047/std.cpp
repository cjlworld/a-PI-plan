#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using std::sort;
using std::unique;
using std::vector;

typedef long long ll;
const int N = 100005;

int n, m, s;
ll g[N], res[N], tres; // g 存二次离线的答案
int w[N], diff[N], sz;

// 树状数组
struct BIT
{
    int tr[N];
    void clear() {memset(tr, 0, sizeof tr);}
    void add(int x) {for (; x <= sz; x += x & -x) tr[x] ++ ;}
    int ask(int x) {int t = 0; for (; x; x &= x - 1) t += tr[x]; return t;}
}f;

// 封装一下分块
struct E
{
    int v[N + 330], tag[330]; // 每个位置上的值和懒标记
    void add(int x)
    {
        while (x % s) v[x ++ ] ++ ; // 块内暴力修改
        x /= s;
        while (x * s <= n) tag[x ++ ] ++ ; // 整块修改懒标记
    }
    int ask(int x)
    {
        return v[x] + tag[x / s]; // 该位置上的数 + 懒标记
    }
}z;

// 询问
struct Query
{
    int l, r, id;
    bool operator < (const Query& t) const
    {
        return l / s != t.l / s ? l < t.l : r < t.r != (l / s & 1);
    }
}q[N];

// 二次离线的询问
struct Range
{
    int l, r, id;  // l, r 表示区间，id 表示对应的一次询问编号
    int type, sgn; // type 求比它大的数还是比它小的数，sgn 存答案的正负号
};
vector<Range> range[N]; // 存对于每个点的二次离线的询问
int pre[N], nxt[N]; // pre 记录每个数前面比它小的数，nxt 记录每个数前面比它大的数

// 二分查找每个元素离散化后对应的值
int find(int x)
{
    int l = 0, r = sz - 1, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (diff[mid] >= x) r = mid;
        else    l = mid + 1;
    }
    return r + 1;
}

// 预处理：将所有数离散化 & 预处理每个数前面比它大/小的数的个数 & 将询问排序
void prework()
{
    // 离散化
    sort(diff, diff + n);
    sz = unique(diff, diff + n) - diff;
    for (int i = 1; i <= n; i ++ ) w[i] = find(w[i]);

    // 预处理每个数前面比它大/小的数的个数
    for (int i = 1; i <= n; i ++ )
    {
        f.add(w[i]);
        pre[i] = f.ask(w[i] - 1);
        nxt[i] = i - f.ask(w[i]);
    }

    // 将询问排序
    s = (int) sqrt(n), sort(q, q + m);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", w + i), diff[i - 1] = w[i];
    for (int i = 0; i < m; i ++ ) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;

    prework();

    // 莫队
    for (int i = 0, l = 1, r = 0; i < m; i ++ )
    {
        // 按照上面四种情况分别做
        if (l < q[i].l) range[r].push_back((Range){l, q[i].l - 1, q[i].id, 0, -1});
        else    range[r].push_back((Range){q[i].l, l - 1, q[i].id, 0, 1});
        while (l < q[i].l) tres += pre[l ++ ];
        while (l > q[i].l) tres -= pre[ -- l];
        if (r < q[i].r) range[l - 1].push_back((Range){r + 1, q[i].r, q[i].id, 1, -1});
        else    range[l - 1].push_back((Range){q[i].r + 1, r, q[i].id, 1, 1});
        while (r < q[i].r) tres += nxt[ ++ r];
        while (r > q[i].r) tres -= nxt[r -- ];
        res[q[i].id] = tres;
    }

    // 二次离线
    for (int i = 1; i <= n; i ++ )
    {
        z.add(w[i]); // 先加入这个数
        for (int j = 0; j < range[i].size(); j ++ )
        {
            Range& t = range[i][j]; // 取出当前区间
            for (int k = t.l, v; k <= t.r; k ++ ) // 枚举区间中每个数
            {
                if (t.type) v = i - z.ask(w[k]);  // 如果 type 为 1，则求比它大的数
                else    v = z.ask(w[k] - 1);      // 否则求比它小的数
                g[t.id] += v * 1ll * t.sgn;       // 答案存到 g 里面
            }
        }
    }

    // 求前缀和，注意这里要照莫队中询问的顺序求
    for (int i = 1; i < m; i ++ ) g[q[i].id] += g[q[i - 1].id];
    for (int i = 0; i < m; i ++ ) printf("%lld\n", res[i] + g[i]);

    return 0;
}

