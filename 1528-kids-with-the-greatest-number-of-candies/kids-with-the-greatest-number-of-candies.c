/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {

    int max = candies[0];

    // Step 1: Find the maximum number of candies
    for(int i = 1; i < candiesSize; i++) {
        if(candies[i] > max) {
            max = candies[i];
        }
    }

    // Step 2: Create result array
    bool* result = malloc(candiesSize * sizeof(bool));

    // Step 3: Check each kid
    for(int i = 0; i < candiesSize; i++) {
        if(candies[i] + extraCandies >= max) {
            result[i] = true;
        }
        else {
            result[i] = false;
        }
    }

    *returnSize = candiesSize;

    return result;
}