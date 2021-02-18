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
ll g[N], res[N], tres; // g ��������ߵĴ�
int w[N], diff[N], sz;

// ��״����
struct BIT
{
    int tr[N];
    void clear() {memset(tr, 0, sizeof tr);}
    void add(int x) {for (; x <= sz; x += x & -x) tr[x] ++ ;}
    int ask(int x) {int t = 0; for (; x; x &= x - 1) t += tr[x]; return t;}
}f;

// ��װһ�·ֿ�
struct E
{
    int v[N + 330], tag[330]; // ÿ��λ���ϵ�ֵ�������
    void add(int x)
    {
        while (x % s) v[x ++ ] ++ ; // ���ڱ����޸�
        x /= s;
        while (x * s <= n) tag[x ++ ] ++ ; // �����޸������
    }
    int ask(int x)
    {
        return v[x] + tag[x / s]; // ��λ���ϵ��� + �����
    }
}z;

// ѯ��
struct Query
{
    int l, r, id;
    bool operator < (const Query& t) const
    {
        return l / s != t.l / s ? l < t.l : r < t.r != (l / s & 1);
    }
}q[N];

// �������ߵ�ѯ��
struct Range
{
    int l, r, id;  // l, r ��ʾ���䣬id ��ʾ��Ӧ��һ��ѯ�ʱ��
    int type, sgn; // type �������������Ǳ���С������sgn ��𰸵�������
};
vector<Range> range[N]; // �����ÿ����Ķ������ߵ�ѯ��
int pre[N], nxt[N]; // pre ��¼ÿ����ǰ�����С������nxt ��¼ÿ����ǰ����������

// ���ֲ���ÿ��Ԫ����ɢ�����Ӧ��ֵ
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

// Ԥ��������������ɢ�� & Ԥ����ÿ����ǰ�������/С�����ĸ��� & ��ѯ������
void prework()
{
    // ��ɢ��
    sort(diff, diff + n);
    sz = unique(diff, diff + n) - diff;
    for (int i = 1; i <= n; i ++ ) w[i] = find(w[i]);

    // Ԥ����ÿ����ǰ�������/С�����ĸ���
    for (int i = 1; i <= n; i ++ )
    {
        f.add(w[i]);
        pre[i] = f.ask(w[i] - 1);
        nxt[i] = i - f.ask(w[i]);
    }

    // ��ѯ������
    s = (int) sqrt(n), sort(q, q + m);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", w + i), diff[i - 1] = w[i];
    for (int i = 0; i < m; i ++ ) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;

    prework();

    // Ī��
    for (int i = 0, l = 1, r = 0; i < m; i ++ )
    {
        // ����������������ֱ���
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

    // ��������
    for (int i = 1; i <= n; i ++ )
    {
        z.add(w[i]); // �ȼ��������
        for (int j = 0; j < range[i].size(); j ++ )
        {
            Range& t = range[i][j]; // ȡ����ǰ����
            for (int k = t.l, v; k <= t.r; k ++ ) // ö��������ÿ����
            {
                if (t.type) v = i - z.ask(w[k]);  // ��� type Ϊ 1��������������
                else    v = z.ask(w[k] - 1);      // ���������С����
                g[t.id] += v * 1ll * t.sgn;       // �𰸴浽 g ����
            }
        }
    }

    // ��ǰ׺�ͣ�ע������Ҫ��Ī����ѯ�ʵ�˳����
    for (int i = 1; i < m; i ++ ) g[q[i].id] += g[q[i - 1].id];
    for (int i = 0; i < m; i ++ ) printf("%lld\n", res[i] + g[i]);

    return 0;
}

