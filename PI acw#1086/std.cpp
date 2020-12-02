#include <iostream>
#include <cstring>

using namespace std;
typedef  long long ll;

const int C = 30, MOD = 1e9 + 7;
int t;
int a[C];
ll ten[C];

struct dp {
    ll cnt;
    ll sum;
    ll sq_sum;
} f[C][C][C]; //f[i][j][k]��ʾ��iλ��ʼ����,����ൽiλÿλ����֮��mod7 ��j, ����ൽiλ���� mod 7 ��k

void ten_mi(){
    ten[1] = 1;
    for (int i = 2; i <= 18; i ++)
        ten[i] =  ten[i-1] * 10 % MOD;
}
dp dfs(int pos, int sum, int cur,  bool limit) {

    if (!pos) { //�ݹ����
        int cnt = 0;
        if (cur !=  0 && sum != 0) cnt = 1; //Ϊһ���������������֣�����1
        return f[pos][sum][cur] = (dp){cnt, 0, 0};
    }
    if (!limit && f[pos][sum][cur].cnt != -1) return f[pos][sum][cur];
    int up = limit? a[pos] : 9;
    dp ans{0, 0, 0};
    for (int i = 0; i <= up; i ++) {
        if (i==7)  continue;
        dp tmp = dfs(pos-1, (sum + i) % 7, (cur * 10 + i) % 7,  limit && (i == a[pos]));
        int k = i * ten[pos] % MOD;// ��ǰ��Ļ�ֵ
        ans.cnt = (ans.cnt + tmp.cnt) %  MOD;
        ans.sum = ((ans.sum + ((tmp.cnt * k) % MOD   +  tmp.sum) % MOD) % MOD) % MOD ;
        ans.sq_sum  += tmp.cnt * k % MOD * k % MOD;
        ans.sq_sum += tmp.sq_sum % MOD;
        ans.sq_sum += 2 * k % MOD * (tmp.sum % MOD) % MOD ;
        ans.sq_sum %= MOD;

    }
    return  limit ? ans : f[pos][sum][cur] = ans;
}

ll solve(ll x) { // ����Ҫע�����ݷ�Χ������ll������Ϊ��������˺ܾ�
    int len = 0;
    while (x) {
        a[++len] = x % 10;
        x /= 10;
    }
    dp ans = dfs(len, 0, 0, true);
    return ans.sq_sum  % MOD;
}


int main() {
    cin >> t;
    ten_mi();
    for (int i = 0; i < t; i ++) {
        ll l, r;
        cin >> l >> r;
        memset(f, -1, sizeof f);
        int x = solve(r);
        int y = solve(l-1);
        cout << (x - y + MOD) % MOD << endl;
    }
    return 0;
}
/*
���ߣ����綫��
���ӣ�https://www.acwing.com/solution/content/6457/
��Դ��AcWing
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
