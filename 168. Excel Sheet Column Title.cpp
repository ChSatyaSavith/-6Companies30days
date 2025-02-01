class Solution {
public:
    string convertToTitle(int columnNumber)
    {
        unordered_map<int, char> ntl;

        for (int num = 1; num <= 26; ++num)
        {
            ntl[num] = 'A' + (num - 1);
        }
        ntl[0] = 'Z';
        string toreturn = "";
        int t = 1;
        while(columnNumber!=0)
        {
            int index = (columnNumber/int(pow(26,t-1)))%26;
            cout<<columnNumber<<" "<<index<<endl;
            toreturn.push_back(ntl[index]);
            if(index==0)
            {
                columnNumber -= pow(26,t);
            }
            else
            {
                columnNumber -= index*pow(26,t-1);
            }
            
            t+=1;
        }
        reverse(toreturn.begin(),toreturn.end());
        return toreturn;
    }
};