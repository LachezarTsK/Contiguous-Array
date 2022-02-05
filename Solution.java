
import java.util.Map;
import java.util.HashMap;

public class Solution {

    public int findMaxLength(int[] nums) {

        Map<Integer, Integer> prefixSum_toIndex = new HashMap<>();
        final int size = nums.length;
        int maxLength = 0;
        int prefixSum = 0;
        prefixSum_toIndex.put(prefixSum, -1);

        for (int i = 0; i < size; i++) {

            if (nums[i] == 0) {
                prefixSum--;
            } else {
                prefixSum++;
            }

            if (!prefixSum_toIndex.containsKey(prefixSum)) {
                prefixSum_toIndex.put(prefixSum, i);
            } else {
                maxLength = Math.max(maxLength, (i - prefixSum_toIndex.get(prefixSum)));
            }
        }

        return maxLength;
    }
}
