int pivotIndex(int* nums, int numsSize) {
    int totalSum = 0;
    int leftSum = 0;

    // Calculate total sum
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    // Check every index
    for (int i = 0; i < numsSize; i++) {
        int rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}