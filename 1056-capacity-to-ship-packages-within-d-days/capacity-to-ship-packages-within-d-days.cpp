class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight = 0;
        int min_weight = 0;
        for(int i = 0;i < weights.size();i++){
            max_weight = max_weight + weights[i];
            if(weights[i]>min_weight){
                min_weight = weights[i];
            }
        }

        cout<<min_weight;

        int ans = INT_MAX;

        while(min_weight <= max_weight){
            int mid = min_weight + (max_weight - min_weight)/2;
            int day = 0;
            int sum = 0;
            for(int j = 0;j < weights.size();j++){
                sum = sum + weights[j];
                if(sum > mid){
                    day++;
                    sum = weights[j];
                }
                if(sum == mid){
                    day++;
                    sum = 0;
                }
            }
            if(sum < mid && sum!= 0){
                day++;
            }
            if(day <= days){
                max_weight = mid - 1;
                if(mid < ans){
                    ans = mid;
                }
            }
            if(day > days){
                min_weight = mid + 1;
            }

        }
        return ans;
        
    }
};