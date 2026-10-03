/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int count1 = 0;
    int count2 = 0;

    // Count elements of nums1 that are present in nums2
    for(int i = 0; i < nums1Size; i++) {

        for(int j = 0; j < nums2Size; j++) {

            if(nums1[i] == nums2[j]) {
                count1++;
                break;
            }
        }
    }

    // Count elements of nums2 that are present in nums1
    for(int i = 0; i < nums2Size; i++) {

        for(int j = 0; j < nums1Size; j++) {

            if(nums2[i] == nums1[j]) {
                count2++;
                break;
            }
        }
    }

    // Create answer array
    int* result = malloc(2 * sizeof(int));

    result[0] = count1;
    result[1] = count2;

    *returnSize = 2;

    return result;
}