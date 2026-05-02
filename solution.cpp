class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp,seen;
        for(char ch:t){
            mp[ch]++;
        }

        int have=0,need=mp.size();
        int i=0, start=0;
        int len=INT_MAX;

        for(int j=0;j<s.size();j++){
            seen[s[j]]++;
            if(mp.count(s[j]) && seen[s[j]]==mp[s[j]] )
                have++;
            while(have>=need){
                if(j-i+1<len){
                    len=j-i+1;
                    start=i;
                }
                seen[s[i]]--;
                if(seen.count(s[i]) && seen[s[i]]<mp[s[i]])
                    have--;
                i++;
                
                
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};
