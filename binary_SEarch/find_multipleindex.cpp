class Solution {
    int returnNum(vector<int>& num, int target) {
        int low = 0;
        int high = num.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (num[mid] == target) {
                return mid; 
            } else if (num[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1; 
    }
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> original = nums;  
        sort(nums.begin(), nums.end());  
        int a, b;
        for (int i = 0; i < nums.size(); i++) { 
            int complement = returnNum(nums, target - nums[i]);  
            if (complement != -1 && i != complement) {
                a = i;
                b = complement;
                break;
            }
        }

       
        int first = find(original.begin(), original.end(), nums[a]) - original.begin();
        int second = find(original.begin(), original.end(), nums[b]) - original.begin();
        if (first == second) {  
            second = find(original.begin() + first + 1, original.end(), nums[b]) - original.begin();
        }
        
        return {first,second};  
    }
};
