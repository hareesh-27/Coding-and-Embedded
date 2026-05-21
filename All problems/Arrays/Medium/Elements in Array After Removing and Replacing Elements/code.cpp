class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int time=queries[i][0];
            int index=queries[i][1];

            int effective_time=time % (2*nums.size());

            if(effective_time < nums.size())
            {
                int original_index = index + effective_time;
                
                if(original_index < nums.size()) ans.push_back(nums[original_index]);
                else ans.push_back(-1);
            }
            else
            {
                int current_size = effective_time - nums.size();
                int original_index=index;
                
                if(original_index < current_size) ans.push_back(nums[original_index]);
                else ans.push_back(-1);
            }
        }

        return ans;
    }
};
