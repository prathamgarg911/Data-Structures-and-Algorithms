class Solution {
public:
    int binary_search(int start,int end, vector<int> nums){
        int mid = start + (end - start)/2;

        while(start <= end){
            
            if(mid == start || mid == end){
                return nums[mid];
            }
            else{
                int first_part = nums[mid - 1]^nums[mid];
                int second_part = nums[mid]^nums[mid + 1];
                if(first_part == 0){
                    if((mid - start - 1) % 2 == 0){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 2;
                    }
                }
                else if(second_part == 0){
                    if((mid - start)%2 == 0){
                        start = mid + 2;
                    }
                    else{
                        end = mid - 1;
                    }
                }
                else{
                    return nums[mid];
                }
            }
            mid = start + (end - start)/2;
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        return binary_search(0,nums.size() - 1,nums);
        
    }
};