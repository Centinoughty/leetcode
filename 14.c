// Longest common prefix
// EASY

#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }

    int minLength = 0;
    for (int i = 1; i < strsSize; i++) {
        if (strlen(strs[i]) < strlen(strs[minLength])) {
            minLength = i;
        }
    }

    int prefixLength = 0;
    while (strs[minLength][prefixLength]) {
        char ch = strs[minLength][prefixLength];
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][prefixLength] != ch) {
                char* prefix = (char*)malloc((prefixLength + 1) * sizeof(char));
                if (!prefix) return NULL;
                strncpy(prefix, strs[minLength], prefixLength);
                prefix[prefixLength] = '\0';
                return prefix;
            }
        }
        prefixLength++;
    }

    return strdup(strs[minLength]);
}