class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //calculating no.of elements in final ans
        int n=nums.size();
        int elements=(1<<n);

        vector<vector<int>> ans;
        //Checking if ith bit is set or not. If set we'll add it to our ans
        for(int val=0;val<elements;val++)
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                if(val & (1<<i)) temp.push_back(nums[i]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};