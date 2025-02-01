class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> > pq; 
    int k_th;
    KthLargest(int k, vector<int>& nums)
    {
        k_th = k;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        if(k_th>nums.size())
        {
            for(auto i: nums)
            {
                pq.push(i);
            }
        }
        else
        {
            for(int i = 0;i<k_th;i++)
            {
                pq.push(nums[i]);
            }
        }
    }
    int add(int val)
    {
        if(pq.size()<k_th)
        {
            pq.push(val);
            return pq.top();
        }
        else
        {
            if(val<pq.top())
            {
                return pq.top();
            }
            pq.pop();
            pq.push(val);
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */