bool containsDuplicate(int* nums, int numsSize) {
    int tableSize = numsSize * 2 + 1;
    
    int* table = (int*)malloc(tableSize * sizeof(int));
    bool* used = (bool*)calloc(tableSize, sizeof(bool));

    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i] % tableSize + tableSize) % tableSize;

        while (used[index]) {
            if (table[index] == nums[i]) {
                free(table);
                free(used);
                return true;
            }

            index = (index + 1) % tableSize;
        }

        table[index] = nums[i];
        used[index] = true;
    }

    free(table);
    free(used);
    return false;
}