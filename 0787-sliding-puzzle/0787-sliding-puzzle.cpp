class Solution {
public:
    vector<vector<int>>dir = {{0,1},{0,-1}, {1,0},{-1,0}};
    int slidingPuzzle(vector<vector<int>>& board) {
        using vvi = vector<vector<int>>;

        vvi target = {{1,2,3}, {4,5,0}};
        set<vvi>st;
        queue<pair<vvi,pair<int,int>>>q;
        pair<int,int>pos = {0,0};
        int level = 0;

        for(int i = 0; i<2; i++){
            for(int j = 0; j<3; j++){
                if(board[i][j]==0) pos = {i,j};
            }
        }
        q.push({board, pos});
        
        while(q.size()>0){
            int qSize = q.size();
            for(int itr = 0; itr<qSize; itr++){
                auto curr = q.front(); q.pop();
                auto currBoard = curr.first;
                auto currPos = curr.second;
                int i = currPos.first, j = currPos.second;
                if(currBoard==target) return level;
                for(auto v : dir){
                    int ii = i+v[0], jj = j+v[1];
                    if(ii>=0 and ii<2 and jj>=0 and jj<3){
                        auto newBoard = currBoard;
                        swap(newBoard[ii][jj], newBoard[i][j]);
                        if(st.find(newBoard)==st.end()){
                            st.insert(newBoard);
                            q.push({newBoard, {ii,jj}});
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};