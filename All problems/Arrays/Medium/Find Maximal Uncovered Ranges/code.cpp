class Solution {
    public:
        vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
            //we will first start to find starting and ending ranges
            vector<int> initial(n+1,0);
            for(int i=0;i<ranges.size();i++)
            {
                int start=ranges[i][0];
                int end=ranges[i][1];

                initial[start]+=1;
                if(end+1 < n)    
                {
                    initial[end+1]-=1;
                }   
            }

            //filling 1's
            vector<int> next;
            int current=0;
            for(int i=0;i<initial.size();i++)
            {
                current+=initial[i];
                if(current > 0) next.push_back(1);
                else next.push_back(0);
            }

            //final formalities
            int j=0;
            vector<vector<int>> ans;
            while(j<next.size())
            {
                if(next[j] == 0)
                {
                    int start_index=j;
                    while(j<next.size() && next[j]==0) j++;
                    int end_index=j-1;
                    ans.push_back({start_index,end_index});                                
                }
                else j++;
            }

            return ans;
        }
};
