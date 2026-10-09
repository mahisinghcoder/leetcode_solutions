int findUnsortedSubarray(int* nums, int numsSize) {
    int left = -1;
    int right = -1;
    int max = nums[0];
    int min = nums[numsSize - 1];

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < max) {
            right = i;
        } else {
            max = nums[i];
        }
    }

    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] > min) {
            left = i;
        } else {
            min = nums[i];
        }
    }

    if (left == -1) {
        return 0;
    }

    return right - left + 1;
}