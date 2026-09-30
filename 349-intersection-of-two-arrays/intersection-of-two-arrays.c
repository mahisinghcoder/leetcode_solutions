int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* intersection(int* nums1, int nums1Size,
                  int* nums2, int nums2Size,
                  int* returnSize) {

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int i = 0;
    int j = 0;
    int k = 0;

    int minSize = nums1Size < nums2Size ? nums1Size : nums2Size;

    int* answer = malloc(minSize * sizeof(int));

    while (i < nums1Size && j < nums2Size) {

        if (nums1[i] == nums2[j]) {

            // Add only if this is the first occurrence
            if (k == 0 || answer[k - 1] != nums1[i]) {
                answer[k] = nums1[i];
                k++;
            }

            i++;
            j++;
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    *returnSize = k;

    return answer;
}