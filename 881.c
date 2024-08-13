// Boats to save people
// MEDIUM

#include <stdio.h>

void countSort (int A[], int n, int pos) {
    int count[10];
    int b[n];
    for (int i = 0; i < 10; i ++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i ++) {
        count[(A[i] / pos) % 10] ++;
    }

    for (int i = 1; i < 10; i ++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i --) {
        b[--count[(A[i] / pos) % 10]] = A[i];
    }

    for (int i = 0; i < n; i ++) {
        A[i] = b[i];
    }
}


void radixSort (int A[], int n) {
    int max = A[0];
    for (int i = 0; i < n; i ++) {
        if (A[i] > max) {
            max =A[i];
        }
    }

    for (int i = 1; max / i > 0; i *= 10) {
        countSort(A, n, i);
    }
}


int numRescueBoats(int* people, int peopleSize, int limit) {
    int count = 0;
    radixSort(people, peopleSize);
    int l = 0, r = peopleSize - 1;
    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l ++;
            r --;
        } else {
            r --;
        }

        count ++;
    }

    return count;
}