// //https://leetcode-cn.com/circle/discuss/2kpiZk/

// ��Ŀ������
// С����������һЩ�����ܸ����������ˡ���Щ�������������������������е�һ�֣�

// ������11����������
// ���������ٰ�������1��
// С�����ڸ����������֣�ϣ����ش���������ǲ��������������磺132��11��12������������1��101������1����������2��
// ��������
// ��һ��һ������n����ʾС����n��ѯ��

// ������ÿһ��һ����������ʾС��ѯ�ʵ����֡�
// ���ݱ�֤1 <= n <= 500, ÿ��ѯ�ʵ�������[1, 1e9]��Χ��
// �������
// ����ÿ��ѯ�ʣ�����������������yes�����ǣ����no��
// ��������
// 6
// 22
// 101
// 1234
// 555
// 10001
// 132
// �������
// no
// yes
// yes
// no
// no
// yes
// yes
// #include<iostream>
// using namespace std;
// bool perfectNum(int x)
// {
//     int count = 0;
//     if (x % 11 == 0)
//         return true;
//     while(x)
//     {
//         if (x%10 == 1)
//             count++;
//         if (count >= 2)
//             return true;
//         x /= 10;
//     }
//     return false;

// }
// int main()
// {
//     int x ;
//     while (cin>>x)
//     {
//         if (perfectNum(x))
//             cout << "yes" << endl;
//         else
//             cout << "no" << endl;
//     }
//     return 0;
// }


// // �˻�Ϊ��
// // ʱ�����ƣ� 1000MS
// // �ڴ����ƣ� 65536KB
// // ��Ŀ������С��������һ�����У������н�����1�� - 1�������֡�С��������Ҫ֪�����ж��ٸ������������У������е����ֳ˻�Ϊ����
// // ��������
// // ��һ��һ��������n����ʾС�����е����г��ȡ�
// // �ڶ���n���ո���������֣�ÿ������ֻ����1�� - 1�е�һ�֡�
// // ����80 % �����ݱ�֤1 <= n <= 500
// // ����ʣ��20 % �����ݱ�֤1 <= n <= 5000
// // �������
// // һ��һ����������ʾ�ж���������������������ĿҪ��
// // ��������
// // 4
// // 1 1 - 1 - 1
// // �������
// // 6
// // ��ʾ {1} {1} {1,1} {-1,-1} {1,-1,-1} {1,1,-1,-1}
// // ����6����������������Ҫ��
// #include <iostream>
// #include<vector>

// using namespace std;

// int continstring(vector<int> v)
// {
//     //> dp[i][j] ��ʾ i->j�ĳ˻�֮��
//     vector<vector<int> > dp(v.size(),vector<int> (v.size(), 0));
//     //> do[i][j] ��ʼ����dp[i][i] ��Ϊv[i]ֵ
//     int result = 0;
//     for (int i = 0; i < v.size(); ++i)
//     {
//         dp[i][i] = v[i];
//         if (dp[i][i] > 0)
//             result++;
//     }
//     for (int i = 0; i < v.size(); ++i)
//     {
//         for (int j = i + 1; j < v.size(); ++j)
//         {
//             //> ���ƹ�ʽ��dp[i][j] = dp[i][j-1] * v[j]
//             dp[i][j] = dp[i][j-1] * v[j];
//             if (dp[i][j] > 0)
//                 result++;
//         }
//     }
//     return result;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> v[i];
//     }
//     cout << continstring(v) << endl;
// }
// // #include<bits/stdc++.h>

// // using namespace std;

// // const int N = 5005;

// // int n, a[N];

// // int main() {
// //     scanf("%d", &n);
// //     for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
// //     int ans = 0;
// //     for (int i = 0; i < n; ++i) {
// //         int x = 1;
// //         for (int j = i; j < n; ++j) {
// //             x *= a[j];
// //             if (x > 0) ++ans;
// //         }
// //     }
// //     printf("%d\n", ans);
// //     return 0;
// // }


// С�������ڳ���������С������ʳ������ֻ��ÿ�ֲ���һ�ݡ�
// ����ͬһʱ�̣��������Ⱥ�˳������n���˿͡�ÿ���˿Ͷ���������Ҫ��Ĳˡ�ֻ�е��˿ͳԵ�ȫ���Լ���Ҫ�Ĳ˵�ʱ�򣬹˿ͲŻ����⡣
// ������������ǣ�����ؽ�ȡ�˿͵Ķ���Ҫ�󣬾������ø���Ĺ˿����⣬���������ж��ٹ˿Ϳ������⡣
// ��������
// ��һ������������n, m
// n�����ж��ٹ˿�ǰ����ˣ�m��ʾС�����������Ĳ˵ı�ŷ�Χ��[1, m]��
// ������n�У�ÿ���������֣�����һ���˿͵�����������˵ı�š�
// ����80% �����ݱ�֤2 <= n <= 10, 2 <= m <= 20
// ����20 % �����ݱ�֤2 <= n <= 20, 2 <= m <= 40
// �������
// һ��һ����������ʾ����ж��ٹ˿Ϳ������⡣

// #include <iostream>
// #include <vector>
// #include <math.h>
// using namespace std;
// static int Max = 0;
// int n, m;

// void dfs(vector<bool>& use, vector<vector<int> >& vv, int j ,int now)
// {
//     if (j == n)
//     {
//         Max = max(Max,now);
//         return;
//     }
//     for (int i = j; i < vv.size(); ++i)
//     {
//         if (!use[vv[i][0]] && !use[vv[i][1]])
//         {
//             use[vv[i][0]] = true;
//             use[vv[i][1]] = true;
//             Max = max(Max, now + 1);
//             dfs(use, vv, j + 1, now + 1);
//             use[vv[i][0]] = false;
//             use[vv[i][1]] = false;
//         }
//     }
// }
// int main()
// {
//     cin >> n >> m;
//     vector<vector<int> > vv(n,vector<int>(2));
//     vector<bool> use(m+1,false); //> ���������ݲ��Ƿ�ȡ��
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> vv[i][0] >> vv[i][1];
//     }
//     dfs(use, vv, 0, 0); //> arg: ��� ��Ʒ �ڼ����˿� ����˿���
//     cout << Max << endl;
//     return Max;
// }


// // #include<bits/stdc++.h>

// // using namespace std;

// // const int N = 50;

// // int n, m, a[N], b[N], c[N], ans;

// // void dfs(int pos, int cnt) {
// //     if (pos == n) {
// //         ans = max(ans, cnt);
// //         return;
// //     }
// //     dfs(pos + 1, cnt);
// //     int x = a[pos], y = b[pos];
// //     if (x != y && x >= 1 && x <= m && y >= 1 && y <= m && c[x] && c[y]) {
// //         --c[x];
// //         --c[y];
// //         dfs(pos + 1, cnt + 1);
// //         ++c[x];
// //         ++c[y];
// //     }
// // }

// // int main() {
// //     scanf("%d%d", &n, &m);
// //     for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
// //     for (int i = 1; i <= m; ++i) c[i] = 1;
// //     dfs(0, 0);
// //     printf("%d\n", ans);
// //     return 0;
// // }

// ��Ŀ������
// С�����ڴ����Ρ�������ε��淨�������ģ�
// ���� ����n�����䡣С����ʼӵ��һ��ָ�룬ָ��һ�ŷ��䡣
// ���� ��Ϸ������m�룬ÿ�����һ���������ը����С����ָ�벻������������С�
// ���� ÿ�������˲�䣬С������ʹ��һ��ħ������ָ���л�����һ�������У��ù��̻�����һ��������
// ��������Ǽ���С������ͨ����������Ҫ���ĵ���С������
// ��֤��һ���ը����������һ�ŷ����С�

// ��������
// ��һ������������ n �� m����ʾ������ n ������Ϸ���� m �롣
// �ڶ��� m ����������ÿ����������1~n �ķ�Χ�ڣ��� i ����������ʾ�� i ��ʱը�����ĸ��������ɡ�
// ���ּ��пո����

// ���ݱ�֤ n �� = 10, 1 <= m <= 10000

// �������
// һ��һ������������ʾС������ͨ����������Ҫ���ĵ�����������

// ��������
// 2 4
// 2 1 1 2
// �������
// 2

// ��ʾ
// ��������1
// ��һ������󻨷�1�����л�������2������������󻨷�1�����л�������1������������2��

// ��������2
// 3 10
// 2 3 1 3 2 1 1 2 3 1

// �������2
// 3

// ��������2
// �ڶ���������л�������2��������������л�������3���ڰ���������л�������2������������3.

// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;
// // void print(vector<vector<int> > dp)
// // {
// //     for (int i = 0; i < dp.size(); ++i)
// //     {
// //         for (int j = 0; j < dp[0].size(); ++j)
// //             cout << dp[i][j] << " ";
// //         cout << endl;
// //     }

// // }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<int> v(m+1);
//     for (int i = 1; i <= m; ++i)
//         cin >> v[i];
//     //> dp[i][j] : ��i�����ʱ�����ڵ�j��������Ҫ����С����
//     vector<vector<int> > dp(m+1, vector<int> (n+1));
//     //> ��ʼ�� ��dp[0][1] = 0
//     for (int i = 0; i <= m; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//             dp[i][j] = 1e9+7;
//     }
//     //print(dp);
//     dp[0][1] = 0;
//     //> ״̬����dp[i][j] = min(dp[i][j-1] + 1, do[i-1][j])
//     for (int i = 1; i <= m; ++i)
//     {
/ home / SENSETIME / zhuyang / interview / meituan_3.12.cpp//         for (int j = 1; j <= n; ++j)
//         {
//             if(j == v[i])Untitled Folder 2
//                 continue;
//             for (int k = 1; k <= n; ++k) 
//             { 
//                 if (k == j) 
//                     dp[i][j] = min(dp[i][j], dp[i - 1][k]);
//                 else 
//                     dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
//             }Untitled Folder 2
//         }
//         //print(dp);
//     }
//     int res = INT_MAX;
//     for (int i = 1; i <= n; ++i)
//         res = min (res, dp[m][i]);
//     cout << res << endl;
//     return 0;
// }


// �ڰ���Ϳɫ
// ʱ�����ƣ� 1000MS
// �ڴ����ƣ� 65536KB
// ��Ŀ������
// ���ڸ���һ������ÿ�����ϵĽڵ�ᱻͿ�ɺ�ɫ���ɫ��

// ���ڶ���ýڵ㣺

// ���ڰ�ɫ�Ľڵ㣺���ýڵ�û���ӽڵ㣬��ýڵ��ӽڵ���������һ��Ϊ��ɫ�ڵ㣬��ýڵ��Ǻýڵ�

// ���ں�ɫ�Ľڵ㣺���ýڵ�û���ӽڵ㣬��ýڵ�������ӽڵ��Ϊ��ɫ�ڵ㣬��ýڵ��Ǻýڵ�

// ����������ҳ�������Ϻ�ɫ�ĺýڵ�Ͱ�ɫ�ĺýڵ���м�����

// ��������
// ��һ��һ��������n����ʾ���������n���ڵ㣬���1��n��
// �ڶ���n���ո������������������ÿ���ڵ����ɫ��0�ǰ�ɫ��1�Ǻ�ɫ��
// ������n���ո���������������� i ��������v��ʾ�ڵ� i �ĸ��ڵ���v�����У�����0��ʾ����ڵ��Ǹ���
// 1 <= n <= 10000

// �������
// һ���������������Կո�ֿ�����һ����������ʾ��ɫ�ĺýڵ��м������ڶ�����������ʾ��ɫ�ĺýڵ��м�����

// ��������
// 6
// 1 0 1 1 0 0
// 0 1 2 1 4 4
// �������
// 3 2
// #include <iostream>
// #include <vector>

// using namespace std;
// int root;
// vector<int> res(2);
// vector<int> v[1005];
// int color[1005];

// void DFS(int m)
// {
//     //> �ýڵ�ΪҶ�ӽڵ㣬��Ϊ�Žڵ�
//     if (v[m].size()== 0)
//     {
//         res[color[m]]++;
//         return ;
//     }
//     int Black = 0;
//     for (int i = 0; i < v[m].size(); ++i)
//     {
//         DFS(v[m][i]);
//         if (color[v[m][i]] == 1)
//             Black++;
//     }
//     //> �׽ڵ�
//     if (color[m] == 0 && Black > 0)
//         res[color[m]]++;
//     //> �ڽڵ�
//     else if (color[m] == 1 && Black == 0)
//         res[color[m]]++;
// }
// int main()
// {
//     int n ;
//     cin >> n;
//     for (int i = 1; i <= n ;++i)
//         cin >> color[i];
//     int start;
//     for (int j = 1,x; j <= n; ++j)
//     {
//         cin >> x;
//         if (x == 0)
//             root = j;
//         else
//             v[x].push_back(j);
//     }
//     DFS(root);
//     cout << res[0] << " " << res[1] << endl;

//     return 0;
// }

// class Solution {
// private:
//     unordered_map<char, int> symbolValues = {
//         {'I', 1},
//         {'V', 5},
//         {'X', 10},
//         {'L', 50},
//         {'C', 100},
//         {'D', 500},
//         {'M', 1000},
//     };

// public:
//     int romanToInt(string s) {
//         int ans = 0;
//         int n = s.length();
//         for (int i = 0; i < n; ++i) {
//             int value = symbolValues[s[i]];
//             if (i < n - 1 && value < symbolValues[s[i + 1]]) {
//                 ans -= value;
//             } else {
//                 ans += value;
//             }
//         }
//         return ans;
//     }
// };

