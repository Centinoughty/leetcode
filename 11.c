// Container with most water

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int maximumWater = 0;
    int left = 0, right = heightSize - 1;
    while (left < right) {
        int minimum = height[left] < height[right] ? height[left] : height[right];
        if (minimum * (right - left) > maximumWater) {
            maximumWater = minimum * (right - left);
        }
        
        if (height[left] < height[right]) {
            left ++;
        } else {
            right --;
        }
    }

    return maximumWater;
}