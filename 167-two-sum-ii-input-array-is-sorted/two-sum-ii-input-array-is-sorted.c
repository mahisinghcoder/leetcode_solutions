int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    int left = 0;
    int right = numbersSize - 1;
    
    while (left < right) {
        
        int sum = numbers[left] + numbers[right];
        
        if (sum == target) {
            int* result = malloc(2 * sizeof(int));
            result[0] = left + 1;// because the question wants as an integer array
            result[1] = right + 1;
            *returnSize = 2;//length 2
            return result;
        }
        
        else if (sum < target) {
            left++;
        }
        
        else {
            right--;
        }
    }
    
    *returnSize = 0;
    return NULL;
}