class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        sort(arr2.begin(),arr2.end());
        int count = 0;
        for(auto i : arr1)
        {
            int index = closest(i,0,arr2.size()-1,arr2);
            int right,left;
            if(index==0 || index==arr2.size()-1)
            {
                if(arr2.size()==1)
                {
                    if(abs(i-arr2[index])>d)
                    {
                        count++;
                    }
                }
                else
                {
                    if(index==0)
                    {
                        left = arr2[index];
                        right = arr2[index+1];
                    }
                    else
                    {
                        left = arr2[index-1];
                        right = arr2[index];
                    }
                    if(abs(i-left)>d && abs(i-right)>d)
                    {
                        count++;
                    }
                }
            }
            else
            {
                if(arr2[index]>i)
                {
                    right = arr2[index];
                    left = arr2[index-1];
                }
                else
                {
                    left = arr2[index];
                    right = arr2[index+1];
                }
                if(abs(i-left)>d && abs(i-right)>d)
                {
                    count++;
                }
            }

        }
        return count;
    }
    int closest(int val,int first,int last,vector<int> arr)
    {
        if(first==last)
        {
            return first;
        }
        int mid = (first+last)/2;
        if(val>arr[mid])
        {
            return closest(val,mid+1,last,arr);
        }
        else
        {
            return closest(val,first,mid,arr);
        }
    }
};