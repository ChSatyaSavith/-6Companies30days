class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int median;
        if(n%2==0)
        {
            median = (n/2)+1;
        }
        else
        {
            median = ((n+1)/2);
        }
        int median_num = nums[median-1];
        cout<<median_num<<endl;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(i==median-1)
            {
                continue;
            }
            sum+=abs(nums[i]-median_num);
        }
        return sum;
    }
};