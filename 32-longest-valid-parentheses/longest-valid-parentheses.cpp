class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> temp;
        vector<int> index;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(temp.empty()){
                    temp.push(i);
                }
                else{
                    temp.push(i);
                }
            }
            else if(s[i] == ')'){
                if(temp.empty()){
                    index.push_back(i);
                }
                else{
                    temp.pop();
                }

            }
        }
        //empty the left over indexes
        while(!temp.empty()){
            int x = temp.top();
            temp.pop();
            index.push_back(x);
}
        sort(index.begin(), index.end());
        //Formula
        int local_max = 0;
        int global_max = 0;
        int first = -1;
        for(int k: index){
            local_max = k - first - 1;
            first = k;
            if(local_max > global_max){
                global_max = local_max;
            }
        }
        local_max = s.size() - first - 1;

if(local_max > global_max){
    global_max = local_max;
}
        return global_max;
    }
};