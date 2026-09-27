class Solution {
public:
    int maxVowels(string s, int k) {
        // max and local max vars
        int maxx = 0;
        int local_maxx = 0;
        // window variables
        int a = 0;
        int b = k - 1;
        // unordered_set for fast vowel lookups
        unordered_set<char> vowles = {'a', 'e', 'i', 'o', 'u'};
        // first iteration
        for(int i = 0; i <= b; i++){
            if(vowles.contains(s[i])){
                local_maxx++;
            }
        }
        maxx = local_maxx;
        //main loop
        // check if a is a vowel if yes then local_maxx--;
        // itertate a and b
        // check if b is a vowel if yetr then local_maxx ++;
        //if local_maxx > maxx then maxx = local_maxx;
        while(b <= s.size()){
            if(vowles.contains(s[a])){
                local_maxx--;
            }
            a++;
            b++;
            if( b > s.size()){
                break;
            }
            if(vowles.contains(s[b])){
                local_maxx++;
            }
            if(local_maxx > maxx){
                maxx = local_maxx;
            }
        } 
        return maxx;
    }
};