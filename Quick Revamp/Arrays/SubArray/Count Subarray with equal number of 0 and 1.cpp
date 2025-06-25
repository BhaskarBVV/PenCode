//  Key Idea
// Treat 0 as -1 when calculating sum (but don't actually change the array).
// This way, a subarray with equal number of 0s and 1s will have a net sum of 0.
// Use a prefix sum + hashmap (called frequency_of_sum) to count how many times each sum has occurred.
// If a prefix sum repeats, it means the subarray between those two points has a sum of 0 → equal number of 0s and 1s.


// https://www.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1

long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
   long long current_sum = 0, ans = 0;
   map<int,int> frequency_of_sum;
   frequency_of_sum[0] = 1;  // to handle the case where a prefix itself is a valid subarray

   for(int i = 0; i < n; i++) {
       // Treat 0 as -1 for the purpose of sum calculation
       if(arr[i] == 1){
           current_sum += 1;
       } else {
           current_sum -= 1;
       }

       // If current_sum has been seen before, it means a subarray with sum = 0 exists
     // between the current pointer and previous all positions where the same sum was exists.
       ans += frequency_of_sum[current_sum];

       // Record the frequency of this sum
       frequency_of_sum[current_sum]++;
   }
   return ans;
}


// Index	arr[i]	Treated Value	current_sum	frequency_of_sum	Subarrays Found
// 0	0	-1	-1	{-1:1, 0:1}	0
// 1	0	-1	-2	{-1:1, -2:1, 0:1}	0
// 2	1	1	-1	{-1:2, -2:1, 0:1}	1 (from sum -1)
// 3	0	-1	-2	{-2:2, -1:2, 0:1}	1 (from sum -2)
// 4	1	1	-1	{-1:3, -2:2, 0:1}	2 (from sum -1)
// 5	0	-1	-2	{-2:3, -1:3, 0:1}	2 (from sum -2)
