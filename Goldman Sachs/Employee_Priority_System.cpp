class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& nums) {
        map<string,vector<string>> mp;
        for(auto it:nums){
            mp[it[0]].push_back(it[1]);
        }
        for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
        }
        vector<string> ans;
        for(auto it:mp){
            vector<string> temp = it.second;
            if(temp.size()<3) continue;
            for(int j=2;j<temp.size();j++){
                if((stoi(temp[j])-stoi(temp[j-2]))<100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};

//Leetcode submission : https://leetcode.com/problems/high-access-employees/submissions/1133597299/