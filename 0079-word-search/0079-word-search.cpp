class Solution {
public:
    bool explore(vector<vector<char>>&board, string &word, vector<vector<bool>>&vis, int itr1, int itr2, int itrWord){
        int n= board.size(), m = board[0].size();
        if(itrWord==word.length()) return true;
        if(itr1>=n or itr1<0 or itr2>=m or itr2<0) return false;
        if(vis[itr1][itr2]==true) return false;
        if(board[itr1][itr2]!=word[itrWord]) return false;

        vis[itr1][itr2] = true;
        if(explore(board, word, vis, itr1+1, itr2, itrWord+1)) return true;
        if(explore(board, word, vis, itr1-1, itr2, itrWord+1)) return true;
        if(explore(board, word, vis, itr1, itr2+1, itrWord+1)) return true;
        if(explore(board, word, vis, itr1, itr2-1, itrWord+1)) return true;
        vis[itr1][itr2] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));

        for(int itr1 = 0; itr1<n; itr1++){
            for(int itr2 = 0; itr2<m; itr2++){
                if(explore(board, word, vis, itr1, itr2, 0)) return true;
            }
        }
        return false;
    }
};