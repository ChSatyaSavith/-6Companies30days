class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums)
    {
        int count = 0;
        for(int size = 1;size<=nums.size();size++)
        {
            for(int start = 0;start<nums.size();start++)
            {
                int end = start + size - 1;
                if(end>=nums.size())
                {
                    continue;
                }
                vector<int> temp;
                for(int i = 0;i<start;i++)
                {
                    temp.push_back(nums[i]);
                }
                for(int i = end+1;i<nums.size();i++)
                {
                    temp.push_back(nums[i]);
                }
                auto i2 = adjacent_find(temp.begin(), temp.end(), greater_equal<int>());
                if(i2==temp.end())
                {
                    count++;
                }

            }
        }
        return count;
    }
};