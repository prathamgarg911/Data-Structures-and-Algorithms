class Solution {
public:
    int min_ban(vector<int>& piles,int h){
        int max = piles[0],min = 1;
        for(int i = 0;i < piles.size();i++){
            if(piles[i] < min){
                min = piles[i];
            }
            if(piles[i] > max){
                max = piles[i];
            }
        }
        int start = min;
        int end = max;
        int ans = (end + start)/2;
        while(start < end){
            int hours = 0;
            for(int j = 0;j < piles.size();j++){
                if(piles[j]%ans == 0){
                    hours = hours + piles[j]/ans;
                }
                else{
                    hours = hours + (piles[j]/ans) + 1;
                }
            }
            if(hours > h){
                start = ans + 1;
            }
            else{
                end = ans;
            }
            ans = (start + end)/2;
            
        }
        return ans;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        return min_ban(piles,h);
        
    }
};