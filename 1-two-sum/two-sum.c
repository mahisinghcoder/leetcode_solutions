#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j;
    int complement;

    for (i = 0; i < numsSize; i++)
    {
        complement = target - nums[i];

        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == complement)
            {
                int* answer = (int*)malloc(2 * sizeof(int));

                answer[0] = i;
                answer[1] = j;

                *returnSize = 2;

                return answer;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}