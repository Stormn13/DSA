class WordFilter {
public:
    unordered_map<string, int> map;
    int index = 0;
    WordFilter(vector<string>& words) {
        for(int k = 0; k < words.size(); k++){
            string word = words[k];
            for(int i=0; i<=word.size(); i++){
                for(int j=0;j<=word.size(); j++){
                    string prefixAndSuffix = word.substr(0,i) + "#" + word.substr(j);
                    map[prefixAndSuffix] = index;
                }

            }
            index++;
        }
        
    }
    
    int f(string pref, string suff) {
            string key = pref + "#" + suff;

    if(map.contains(key)){
        return map[key];
    }

    return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */