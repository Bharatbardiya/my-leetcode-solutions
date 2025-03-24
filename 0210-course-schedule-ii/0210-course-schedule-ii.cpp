class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>req(numCourses);

        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            req[edge[0]]++;
        }
        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(req[i]==0) q.push(i);
        }

        vector<int>answer;
        while(q.size()>0){
            int course = q.front();
            q.pop();
            answer.push_back(course);

            for(auto c : adj[course]){
                req[c]--;
                if(req[c]==0) q.push(c);
            }
        }
        if(answer.size()!=numCourses) return {};
        return answer;
    }
};