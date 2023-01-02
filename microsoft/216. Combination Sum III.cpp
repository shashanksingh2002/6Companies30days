class Solution {
public:
    void f(vector<int> &temp,vector<vector<int>> &ans,int k,int n,int st){
        if(n<0 || temp.size()>k) return;
        if(n==0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int idx = st;idx<=9;idx++){
            temp.push_back(idx);
            f(temp,ans,k,n-idx,idx+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        f(temp,ans,k,n,1);
        return ans;
    }
};
