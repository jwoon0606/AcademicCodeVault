public class MaxSpan {
  public static void main(String[] args) {
    int[] arr1 = { 1, 2, 1, 1, 3 };
    int[] arr2 = { 1, 4, 2, 1, 4, 1, 4 };
    int[] arr3 = { 1, 4, 2, 1, 4, 4, 4 };

    System.out.println(maxSpan(arr1)); // Output: 4
    System.out.println(maxSpan(arr2)); // Output: 6
    System.out.println(maxSpan(arr3)); // Output: 6
  }

  public static int maxSpan(int[] nums) {
    int max_span = 0;
    for (int i = 0; i < nums.length; i++) {
      int j = 0;
      for (j = nums.length - 1; j >= i; j--) {
        if (nums[i] == nums[j])
          break;
      }
      int span = j - i + 1;
      if (span > max_span)
        max_span = span;
    }

    return max_span;
  }
}
