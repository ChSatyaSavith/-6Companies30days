class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        vector<pair<int,int>> maintain;
        for(int i = 0;i<nums.size();i++)
        {
            maintain.push_back(make_pair(nums[i],i));
        }
        sort(maintain.begin(),maintain.end());
        reverse(maintain.begin(),maintain.end());
        vector<pair<int,int>> temp;

        for(int i = 0;i<k;i++)
        {
            temp.push_back(maintain[i]);
        }
        sort(temp.begin(), temp.end(), [](auto &left, auto &right) {return left.second < right.second;});
        vector<int> toreturn;
        for(auto i: temp)
        {
            toreturn.push_back(i.first);
        }
        return toreturn;


    }
};