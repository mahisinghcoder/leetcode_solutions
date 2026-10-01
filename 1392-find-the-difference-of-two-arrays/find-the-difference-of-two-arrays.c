/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 */
int** findDifference(int* nums1, int nums1Size,
                     int* nums2, int nums2Size,
                     int* returnSize, int** returnColumnSizes) {

    int **ans = (int **)malloc(2 * sizeof(int *));

    ans[0] = (int *)malloc(nums1Size * sizeof(int));
    ans[1] = (int *)malloc(nums2Size * sizeof(int));

    int size1 = 0;
    int size2 = 0;

    // Find elements in nums1 but not in nums2
    for (int i = 0; i < nums1Size; i++) {

        int found = 0;

        // Check if nums1[i] exists in nums2
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                found = 1;
                break;
            }
        }

        // If not found in nums2
        if (found == 0) {

            // Check whether already added
            int duplicate = 0;

            for (int k = 0; k < size1; k++) {
                if (ans[0][k] == nums1[i]) {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0) {
                ans[0][size1] = nums1[i];
                size1++;
            }
        }
    }

    // Find elements in nums2 but not in nums1
    for (int i = 0; i < nums2Size; i++) {

        int found = 0;

        // Check if nums2[i] exists in nums1
        for (int j = 0; j < nums1Size; j++) {
            if (nums2[i] == nums1[j]) {
                found = 1;
                break;
            }
        }

        // If not found in nums1
        if (found == 0) {

            // Check whether already added
            int duplicate = 0;

            for (int k = 0; k < size2; k++) {
                if (ans[1][k] == nums2[i]) {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0) {
                ans[1][size2] = nums2[i];
                size2++;
            }
        }
    }

    *returnSize = 2;

    *returnColumnSizes = (int *)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = size1;
    (*returnColumnSizes)[1] = size2;

    return ans;
}