// Compare version numbers
// MEDIUM

#include <stdio.h>

int compareVersion(char* version1, char* version2) {
    int i = 0, j = 0;
    long int v1 = 0, v2 = 0;
    while (1) {
        v1 = 0;
        v2 = 0;
        while (version1[i] != '.' && version1[i] != '\0') {
            v1 = v1 * 10 + version1[i] - '0';
            i ++;
        }

        if (version1[i] == '.') {
            i ++;
        }

        while (version2[j] != '.' && version2[j] != '\0') {
            v2 = v2 * 10 + version2[j] - '0';
            j ++;
        }

        if (version2[j] == '.') {
            j ++;
        }

        if (v1 != v2) {
            break;
        }

        if (version1[i] == '\0' && version2[j] == '\0') {
            break;
        }
    }

    if (v1 > v2) {
        return 1;
    } else if (v2 > v1) {
        return -1;
    } else {
        return 0;
    }
}