class Solution {
  public:
    vector<int> getlps(string &s){
        int n = s.size();
        vector<int> lps(n + 1);
        int j = -1  , i = 0;
        lps[0] = -1;
        while(i < n){
            while(j != -1 && s[i] != s[j]) j = lps[j];
            i++;
            j++;
            lps[i] = j;
        }
        return lps;
    }
    int firstOccurence(string& txt, string& pat) {
        vector<int> lps = getlps(pat);
        int i = 0 , j = 0;
        int m = txt.size() , n = pat.size();
        while(i < m){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }else{
                j = lps[j];
                if(j == -1){
                    i++;
                    j = 0;
                }
            }
            
            if(j == n) return i - j;
        }
        return -1;
    }
};
