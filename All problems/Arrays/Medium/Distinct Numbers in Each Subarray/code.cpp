class Solution {
public:
 vector<int> distinctNumbers(vector<int>& nums, int k) {
    vector<int> ans;
    map<int,int> mp;

    for(int i=0;i<k;i++) mp[nums[i]]++;

    ans.push_back(mp.size());

    for(int i=k;i<nums.size();i++)
    {
        int out_going=nums[i-k];
        mp[out_going]--;
        if(mp[out_going] == 0) mp.erase(out_going);

        int incoming=nums[i];
        mp[incoming]++;

        ans.push_back(mp.size());
    }

    return ans;
 }
};
