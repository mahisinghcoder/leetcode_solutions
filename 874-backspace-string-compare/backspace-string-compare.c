

bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;

    while (i >= 0 || j >= 0) {
        int skipS = 0, skipT = 0;

        // Find next valid character in s
        while (i >= 0) {
            if (s[i] == '#') {
                skipS++;
                i--;
            } else if (skipS > 0) {
                skipS--;
                i--;
            } else {
                break;
            }
        }

        // Find next valid character in t
        while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }

        // Compare valid characters
        if (i >= 0 && j >= 0 && s[i] != t[j]) {
            return false;
        }

        // Check if only one string has characters left
        if ((i >= 0) != (j >= 0)) {
            return false;
        }

        i--;
        j--;
    }

    return true;
}