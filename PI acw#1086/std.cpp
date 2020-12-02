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
} f[C][C][C]; //f[i][j][k]表示从i位开始往后,最左侧到i位每位的数之和mod7 余j, 最左侧到i位的数 mod 7 余k

void ten_mi(){
    ten[1] = 1;
    for (int i = 2; i <= 18; i ++)
        ten[i] =  ten[i-1] * 10 % MOD;
}
dp dfs(int pos, int sum, int cur,  bool limit) {

    if (!pos) { //递归出口
        int cnt = 0;
        if (cur !=  0 && sum != 0) cnt = 1; //为一个满足条件的数字，返回1
        return f[pos][sum][cur] = (dp){cnt, 0, 0};
    }
    if (!limit && f[pos][sum][cur].cnt != -1) return f[pos][sum][cur];
    int up = limit? a[pos] : 9;
    dp ans{0, 0, 0};
    for (int i = 0; i <= up; i ++) {
        if (i==7)  continue;
        dp tmp = dfs(pos-1, (sum + i) % 7, (cur * 10 + i) % 7,  limit && (i == a[pos]));
        int k = i * ten[pos] % MOD;// 当前层的基值
        ans.cnt = (ans.cnt + tmp.cnt) %  MOD;
        ans.sum = ((ans.sum + ((tmp.cnt * k) % MOD   +  tmp.sum) % MOD) % MOD) % MOD ;
        ans.sq_sum  += tmp.cnt * k % MOD * k % MOD;
        ans.sq_sum += tmp.sq_sum % MOD;
        ans.sq_sum += 2 * k % MOD * (tmp.sum % MOD) % MOD ;
        ans.sq_sum %= MOD;

    }
    return  limit ? ans : f[pos][sum][cur] = ans;
}

ll solve(ll x) { // 这题要注意数据范围必须是ll，我因为这里调试了很久
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
作者：福如东海
链接：https://www.acwing.com/solution/content/6457/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
