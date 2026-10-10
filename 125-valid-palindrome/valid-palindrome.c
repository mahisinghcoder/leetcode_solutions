

bool isPalindrome(char* s) {
    char str[strlen(s) + 1];
    int j = 0;

    // Step 1: Convert to lowercase and remove non-alphanumeric characters
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalnum((unsigned char)s[i])) {
            str[j] = tolower((unsigned char)s[i]);
            j++;
        }
    }
    str[j] = '\0';

    // Step 2: Compare characters from both ends
    int left = 0;
    int right = j - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}
