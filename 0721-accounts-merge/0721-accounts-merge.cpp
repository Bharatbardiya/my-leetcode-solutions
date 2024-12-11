class Solution {
public:
    class UnionFind {
        vector<int> parent;
        vector<int> rank;

    public:
        UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                parent.push_back(i);
            }
            rank.resize(n, 0);
        }

        void _union(int x, int y) {
            int pr_x = find(x), pr_y = find(y);
            if (pr_x != pr_y) {
                if (rank[pr_x] > rank[pr_y]) {
                    parent[pr_y] = pr_x;
                } else if (rank[pr_x] < rank[pr_y]) {
                    parent[pr_x] = pr_y;
                } else {
                    parent[pr_y] = pr_x;
                    rank[pr_x]++;
                }
            }
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> mp;
        // map<int,string>mp1;
        int count = 0;
        for (auto v : accounts) {
            string name = v[0];
            for (int i = 1; i < v.size(); i++) {
                if (mp.find(v[i]) == mp.end()) {
                    mp[v[i]] = count;
                    count += 1;
                }
            }
        }
        map<int, string> mp2;
        UnionFind emails(count);

        for (auto v : accounts) {
            string name = v[0];
            int n = v.size();
            for (int i = 1; i < n - 1; i++) {
                int ind1 = mp[v[i]], ind2 = mp[v[i + 1]];
                emails._union(ind1, ind2);
            }
            int ind = mp[v[1]];
            int parent = emails.find(ind);
            mp2[parent] = name;
        }

        map<int, set<string>> mp3;

        for (auto pr : mp) {
            string email = pr.first;
            int ind = pr.second;
            int parent = emails.find(ind);
            mp3[parent].insert(email);
        }

        vector<vector<string>> Answer;
        for (auto pr : mp3) {
            vector<string>temp;
            temp.push_back(mp2[pr.first]);
            for (auto s : pr.second) {
                temp.push_back(s);
            }
            Answer.push_back(temp);
        }
        return Answer;
    }
};