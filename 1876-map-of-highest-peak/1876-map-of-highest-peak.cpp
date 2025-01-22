class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<bool>>vis(m, vector<bool>(n, false));
        vector<vector<int>>Answer(m, vector<int>(n, 0));
        vector<vector<int>>dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        queue<pair<int,int>>q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        int currHeight = 0;

        while(q.size()>0){
            int len = q.size();
            for(int k = 0; k<len; k++){
                auto pr = q.front();
                q.pop();
                int i = pr.first, j = pr.second;
                Answer[i][j] = currHeight;

                for(auto dir : dirs){
                    int ii = dir[0]+i, jj = dir[1]+j;
                    if(ii>=0 and jj>=0 and ii<m and jj<n and vis[ii][jj]==false){
                        q.push({ii,jj}); vis[ii][jj] = true;
                    }
                }
            }
            currHeight++;
        }
        return Answer;
    }
};