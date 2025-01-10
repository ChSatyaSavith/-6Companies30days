class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> zero(m, vector<int>(n, 0));
        vector<vector<int>> pairs = {{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int count = 0;
                int add = 0;
                for(auto calc:pairs)
                {
                    int neighbourx,neighboury;
                    neighbourx = i+calc[0];
                    if(neighbourx<0 || neighbourx>=m)
                    {
                        continue;
                    }
                    neighboury = j+calc[1];
                    if(neighboury<0||neighboury>=n)
                    {
                        continue;
                    }
                    count++;
                    add+=img[neighbourx][neighboury];
                }
                zero[i][j] = floor(float(add)/count);
            }
        }
        return zero;

    }
};