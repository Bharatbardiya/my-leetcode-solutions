/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*>mp;
        set<int>st;
        for(auto emp : employees){
            int id = emp->id;
            mp[id] = emp;
        }

        queue<int>q; q.push(id); st.insert(id);
        int ans = 0;

        while(q.size()>0){
            int id = q.front(); q.pop();
            Employee*emp = mp[id];
            ans += emp->importance;
            for(auto subid : emp->subordinates){
                if(st.find(subid)==st.end()){
                    q.push(subid); st.insert(subid);
                }
            }
        }
        return ans;
    }
};