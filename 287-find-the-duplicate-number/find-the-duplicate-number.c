
int findDuplicate(int* nums, int numsSize)
{
    int slow = 0;
    int fast = 0;

    // Phase 1: Find the meeting point
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while (slow != fast);

    // Phase 2: Find the duplicate number
    slow = 0;

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
