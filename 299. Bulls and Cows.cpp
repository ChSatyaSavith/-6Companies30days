class Solution {
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0;
        unordered_map<char,int> hash_sec;
        unordered_map<char,int> hash_guess;
        for(int i = 0;i<secret.length();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls+=1;
                continue;
            }
            if(hash_sec.find(secret[i])==hash_sec.end())
            {
                hash_sec[secret[i]] = 1;
            }
            else
            {
                hash_sec[secret[i]]++;
            }

            if(hash_guess.find(guess[i])==hash_guess.end())
            {
                hash_guess[guess[i]] = 1;
            }
            else
            {
                hash_guess[guess[i]]++;
            }
        }
        int cows = 0;
        for(auto i:hash_sec)
        {
            cout<<i.first<<" "<<i.second<<endl;
            if(hash_sec.find(i.first)==hash_sec.end())
            {
                continue;
            }
            cows+=min(hash_sec[i.first],hash_guess[i.first]);
        }
        // cout<<bulls<<"A"<<cows<<"B"<<endl;
        string toreturn = "";
        toreturn += to_string(bulls);
        toreturn.push_back('A');
        toreturn += to_string(cows);
        toreturn.push_back('B');
        return toreturn;
    }
};