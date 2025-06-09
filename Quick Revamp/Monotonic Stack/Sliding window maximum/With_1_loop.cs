// https://leetcode.com/problems/sliding-window-maximum/description
public class Solution {    
    public int[] MaxSlidingWindow(int[] nums, int k) {
        var deque = new LinkedList<int>(); // Stores indexes of required max elements. 
        // Acting as a monotonic queue holding index of nums -> These index values' represent strictly decreasing monotonic nature
        int j = 0;
        var ans = new List<int>();

        while (j < nums.Length) {
            // We will keep only maximum values, but if a smaller value is obtained, store it, as this small value might be the largest value in next window.
            // Remove smaller elements from the back (not useful for max)
            while (deque.Count > 0 && nums[deque.Last.Value] <= nums[j]) {
                deque.RemoveLast();
            }

            // Add current index to deque
            deque.AddLast(j);

            // Remove indices that are outside the current window
            while (deque.Count > 0 && deque.First.Value <= j - k) {
                deque.RemoveFirst();
            }

            // Start recording results after the first full window
            if (j >= k - 1) {
                ans.Add(nums[deque.First.Value]); // Front of deque is the max
            }

            j += 1;
        }

        return ans.ToArray();
    }
}
