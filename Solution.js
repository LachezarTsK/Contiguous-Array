
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function (nums) {

    const prefixSum_toIndex = new Map();
    const size = nums.length;
    let maxLength = 0;
    let prefixSum = 0;
    prefixSum_toIndex.set(prefixSum, -1);

    for (let i = 0; i < size; i++) {

        if (nums[i] === 0) {
            prefixSum--;
        } else {
            prefixSum++;
        }

        if (!prefixSum_toIndex.has(prefixSum)) {
            prefixSum_toIndex.set(prefixSum, i);
        } else {
            maxLength = Math.max(maxLength, (i - prefixSum_toIndex.get(prefixSum)));
        }
    }
    return maxLength;
};
