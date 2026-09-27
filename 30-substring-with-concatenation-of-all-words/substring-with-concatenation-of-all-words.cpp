class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string_view, int> stat;
        unordered_map<string_view, int> win;
        string point;
        vector<int> result;
        // make the static map
        for(int i = 0; i <= words.size() - 1; i++){
            string_view p = string_view(words[i]);
            stat[p]++;
        }
        
        // make the outer moving window 
        int size = words.size()*words[0].size();
        int a = 0;
        int b = size - 1;

        // outside window loop 
        // it does three things
        // 1) iterate outside variables - DONE
        // 2) checks if static hashmap == window hashmap - DONE
        // 3) skips the window if the first inner window doesn't exist as the key for static window - DONE
        // 4) clear the win hashmap so that we can start adding it again - DONE
        while(b <= s.size()){
            // make the inner moivng window
            int c = a;
            int d = a +words[0].size() - 1;
            if(!stat.contains(string_view(s).substr(c, d-c+1))){
                a++;
                b++;
                continue;
            }

            // inner window loop
            // 1) iterate inner variables in chunks of words[0].size(); - DONE
            // 2) add the the current inner window to the win hash map - DONE
            while(d <= b){
                win[string_view(s).substr(c,d-c+1)]++;
                c = c + words[0].size();
                d = d + words[0].size();
            }
            if(stat == win){
                result.push_back(a);
            }
            a++;
            b++;
            win = {};

        }
        return result;


        

    }
};