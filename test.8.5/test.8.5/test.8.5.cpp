//> 占位符替换
class Solution {
private:

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param my_template string字符串
     * @param keys string字符串vector
     * @param values string字符串vector
     * @return string字符串
     */
    string token_replace(string my_template, vector<string>& keys, vector<string>& values) {
        // write code here
        unordered_map<string, string> mp;
        for (int i = 0; i < keys.size(); ++i) {
            mp[keys[i]] = values[i];
        }
        string res;
        int l = 0;
        while (l < my_template.size()) {
            if (l < my_template.size() && my_template[l] != '%') {
                res.push_back(my_template[l]);
                l++;
                continue;
            }
            else {
                int r = l + 1;
                while (r < my_template.size() && my_template[r] != '%') {
                    ++r;
                }
                if (r == my_template.size()) {
                    res += my_template.substr(l);
                    return res;
                }
                string temp = my_template.substr(l + 1, r - l - 1);
                if (mp.find(temp) != mp.end()) {
                    res += mp[temp];
                    l = r + 1;
                    continue;
                }
                else {
                    res.push_back('%');
                }
                ++l;
            }

        }
        return res;
    }
};




//> 同一岛屿内最大曼哈顿距离
class Solution {
public:
    vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    vector<vector<vector<int>>> vec;
    vector<vector<int>> path;
    void dfs(vector<vector<int> >& graph, int row, int col) {
        if (row < 0 || row >= graph.size() || col < 0 || col >= graph[0].size()) {
            return;
        }
        if (graph[row][col] == 0 || graph[row][col] == 2) {
            return;
        }
        path.push_back({ row, col });
        graph[row][col] = 2;
        for (auto& d : dir) {
            dfs(graph, row + d[0], col + d[1]);
        }
    }

    int getMaxDis(vector<vector<int> >& nums) {
        int maxDis = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int t = abs(nums[i][0] - nums[j][0]) + abs(nums[i][1] - nums[j][1]);
                maxDis = max(maxDis, t);
            }
        }
        return maxDis;
    }

    vector<int> solve(vector<vector<int> >& graph) {
        // write code here
        int cnt = 0;
        int maxDis = 0;
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[0].size(); ++j) {
                if (graph[i][j] == 1) {
                    cnt++;
                    dfs(graph, i, j);
                    vec.push_back(path);
                    path.clear();
                }
            }
        }
        for (auto& v : vec) {
            maxDis = max(maxDis, getMaxDis(v));
        }
        return { cnt, maxDis };
    }
};