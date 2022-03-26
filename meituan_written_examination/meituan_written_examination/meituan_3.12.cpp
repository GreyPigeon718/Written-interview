// //https://leetcode-cn.com/circle/discuss/2kpiZk/

// 题目描述：
// 小美现在相信一些数字能给他带来好运。这些数字至少满足以下两个特征中的一种：

// 数字是11的整数倍。
// 数字中至少包含两个1。
// 小美现在给你若干数字，希望你回答这个数字是不是幸运数。例如：132是11的12倍，满足条件1，101有两个1，满足条件2。
// 输入描述
// 第一行一个数字n，表示小美有n组询问

// 接下来每一行一个正整数表示小美询问的数字。
// 数据保证1 <= n <= 500, 每个询问的数字在[1, 1e9]范围内
// 输出描述
// 对于每组询问，如果是幸运数，输出yes，不是，输出no。
// 样例输入
// 6
// 22
// 101
// 1234
// 555
// 10001
// 132
// 样例输出
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


// // 乘积为正
// // 时间限制： 1000MS
// // 内存限制： 65536KB
// // 题目描述：小美现在有一个序列，序列中仅包含1和 - 1两种数字。小美现在想要知道，有多少个连续的子序列，序列中的数字乘积为正。
// // 输入描述
// // 第一行一个正整数n，表示小美手中的序列长度。
// // 第二行n个空格隔开的数字，每个数字只能是1和 - 1中的一种。
// // 对于80 % 的数据保证1 <= n <= 500
// // 对于剩余20 % 的数据保证1 <= n <= 5000
// // 输出描述
// // 一行一个正整数表示有多少连续的子序列满足题目要求。
// // 样例输入
// // 4
// // 1 1 - 1 - 1
// // 样例输出
// // 6
// // 提示 {1} {1} {1,1} {-1,-1} {1,-1,-1} {1,1,-1,-1}
// // 共有6个连续子序列满足要求。
// #include <iostream>
// #include<vector>

// using namespace std;

// int continstring(vector<int> v)
// {
//     //> dp[i][j] 表示 i->j的乘积之和
//     vector<vector<int> > dp(v.size(),vector<int> (v.size(), 0));
//     //> do[i][j] 初始化，dp[i][i] 就为v[i]值
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
//             //> 递推公式：dp[i][j] = dp[i][j-1] * v[j]
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


// 小美现在在厨房做饭。小美发现食材现在只够每种菜做一份。
// 现在同一时刻（即不分先后顺序）来了n个顾客。每个顾客都有想两份要点的菜。只有当顾客吃到全部自己想要的菜的时候，顾客才会满意。
// 现在你的任务是，合理地接取顾客的订单要求，尽可能让更多的顾客满意，并输出最多有多少顾客可以满意。
// 输入描述
// 第一行两个正整数n, m
// n表明有多少顾客前来点菜，m表示小美现在能做的菜的编号范围在[1, m]。
// 接下来n行，每行两个数字，表明一名顾客的所点的两道菜的编号。
// 其中80% 的数据保证2 <= n <= 10, 2 <= m <= 20
// 另外20 % 的数据保证2 <= n <= 20, 2 <= m <= 40
// 输出描述
// 一行一个正整数表示最多有多少顾客可以满意。

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
//     vector<bool> use(m+1,false); //> 用来标记这份菜是否取过
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> vv[i][0] >> vv[i][1];
//     }
//     dfs(use, vv, 0, 0); //> arg: 标记 菜品 第几名顾客 满意顾客数
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

// 题目描述：
// 小美现在打音游。这个音游的玩法是这样的：
// —— 共有n个房间。小美初始拥有一个指针，指在一号房间。
// —— 游戏共持续m秒，每秒会有一个房间产生炸弹，小美的指针不能在这个房间中。
// —— 每秒结束的瞬间，小美可以使用一次魔法，把指针切换到另一个房间中，该过程会消耗一个能量。
// 你的任务是计算小美无伤通过音游所需要消耗的最小能量。
// 保证第一秒的炸弹不发生在一号房间中。

// 输入描述
// 第一行两个正整数 n 和 m，表示房间有 n 个，游戏持续 m 秒。
// 第二行 m 个正整数，每个正整数在1~n 的范围内，第 i 个正整数表示第 i 秒时炸弹在哪个房间生成。
// 数字间有空格隔开

// 数据保证 n ＜ = 10, 1 <= m <= 10000

// 输出描述
// 一行一个正整数，表示小美无伤通过音游所需要消耗的最少能量。

// 样例输入
// 2 4
// 2 1 1 2
// 样例输出
// 2

// 提示
// 样例解释1
// 第一秒结束后花费1能量切换到房间2，第三秒结束后花费1能量切换到房间1，共消耗能量2。

// 输入样例2
// 3 10
// 2 3 1 3 2 1 1 2 3 1

// 输出样例2
// 3

// 样例解释2
// 第二秒结束后切换到房间2，第四秒结束后切换到房间3，第八秒结束后切换到房间2，共消耗能量3.

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
//     //> dp[i][j] : 第i秒结束时，处于第j个房间需要的最小能量
//     vector<vector<int> > dp(m+1, vector<int> (n+1));
//     //> 初始化 ：dp[0][1] = 0
//     for (int i = 0; i <= m; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//             dp[i][j] = 1e9+7;
//     }
//     //print(dp);
//     dp[0][1] = 0;
//     //> 状态方程dp[i][j] = min(dp[i][j-1] + 1, do[i-1][j])
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


// 黑白树涂色
// 时间限制： 1000MS
// 内存限制： 65536KB
// 题目描述：
// 现在给你一颗树，每个树上的节点会被涂成黑色或白色。

// 现在定义好节点：

// 对于白色的节点：若该节点没有子节点，或该节点子节点中至少有一个为黑色节点，则该节点是好节点

// 对于黑色的节点：若该节点没有子节点，或该节点的所有子节点均为白色节点，则该节点是好节点

// 你的任务是找出这棵树上黑色的好节点和白色的好节点各有几个。

// 输入描述
// 第一行一个正整数n，表示这棵树共有n个节点，编号1到n。
// 第二行n个空格隔开的正整数，代表每个节点的颜色。0是白色，1是黑色。
// 接下来n个空格隔开的正整数，第 i 个正整数v表示节点 i 的父节点是v。其中，数字0表示这个节点是根。
// 1 <= n <= 10000

// 输出描述
// 一行两个正整数，以空格分开，第一个正整数表示白色的好节点有几个，第二个正整数表示黑色的好节点有几个。

// 样例输入
// 6
// 1 0 1 1 0 0
// 0 1 2 1 4 4
// 样例输出
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
//     //> 该节点为叶子节点，必为号节点
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
//     //> 白节点
//     if (color[m] == 0 && Black > 0)
//         res[color[m]]++;
//     //> 黑节点
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

