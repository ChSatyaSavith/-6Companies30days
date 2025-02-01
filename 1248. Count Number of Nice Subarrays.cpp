class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        vector<int> num_subs;
        for(auto i: nums)
        {
            if(i%2!=0)
            {
                num_subs.push_back(1);
            }
            else
            {
                num_subs.push_back(0);
            }
        }
        return sum_return(num_subs,k) - sum_return(num_subs,k-1);
    }
    int sum_return(vector<int> nums,int goal)
    {
        
        if(goal<0)
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        int count = 0;
        int sum = 0;

        while(j<nums.size())
        {
            sum+=nums[j];

            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};