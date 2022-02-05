
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
  
public:

    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> prefixSum_toIndex;
        const size_t size = nums.size();
        int maxLength = 0;
        int prefixSum = 0;
        prefixSum_toIndex[prefixSum] = -1;

        for (int i = 0; i < size; i++) {

            if (nums[i] == 0) {
                prefixSum--;
            } else {
                prefixSum++;
            }

            if (prefixSum_toIndex.find(prefixSum) == prefixSum_toIndex.end()) {
                prefixSum_toIndex[prefixSum] = i;
            } else {
                maxLength = max(maxLength, (i - prefixSum_toIndex[prefixSum]));
            }
        }
        return maxLength;
    }
};
