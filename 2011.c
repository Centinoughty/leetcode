// Final value of variable after performing operations

#include <stdio.h>

int finalValueAfterOperations(char** operations, int operationsSize) {
    int ans = 0;
    for (int i = 0; i < operationsSize; i ++) {
        if (operations[i][1] == '+') {
            ans ++;
        } else {
            ans --;
        }
    }

    return ans;
}