class Solution {
public:
    int findTheWinner(int n, int k)
    {
        int start = 0;
        vector<int> temp;
        for(int i = 1;i<=n;i++)
        {
            temp.push_back(i);
        }
        while(n!=1)
        {
            int toremove = (start+k-1)%n;
            start = toremove;
            temp.erase(temp.begin() + toremove);
            n-=1;
        }
        return temp[0];
    }
};