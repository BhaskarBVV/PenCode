
class Solution {

    public static int removeElement(int[] nums, int val) {
        var index = 0;
        var occurences = 0;
        for (var number : nums) {
            if (number == val) {
                occurences += 1;
                continue;
            } else {
                nums[index] = number;
                index += 1;
            }
        }
        return nums.length - occurences;
    }
}
