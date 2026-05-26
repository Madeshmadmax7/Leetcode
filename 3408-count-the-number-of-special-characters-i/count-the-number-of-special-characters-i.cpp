class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>st(word.begin(),word.end());
        int ct=0;
        for(char c:st){
            if(islower(c)&&st.count(toupper(c))){
                ct++;
            }
        }
        return ct;
    }
};