class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0,cows=0;
        unordered_map<char,int> umap;
        for(int i=0;i<guess.length();++i){
            umap[guess[i]]++;
        }
        string temp="";
        for(int i=0;i<secret.length();++i){
            if(secret[i] == guess[i]){
                bulls++;
                umap[guess[i]]--;
                if(umap[guess[i]]==0){
                    umap.erase(guess[i]);
                }
            }
            else{
                temp+=secret[i];
            }
        }
        for(int i=0;i<temp.length();i++){
            if(umap.find(temp[i]) != umap.end()){
                cows++;
                umap[temp[i]]--;
                if(umap[temp[i]]==0){
                    umap.erase(temp[i]);
                }
            }
        }
        
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
