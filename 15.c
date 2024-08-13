// 3Sum
// MEDIUM

#include <stdio.h>
#include <stdlib.h>

int compare (const void* a, const void* b) {
  const int* num1 = (const int*)a;
  const int* num2 = (const int*)b;
  if (*num1 < *num2) return -1;
  if (*num1 > *num2) return 1;
  return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), compare);

  int** array = (int**)malloc(numsSize * numsSize * sizeof(int));
  int pos = 0;

  for (int i = 0; i + 2 < numsSize; ++ i) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int left = i + 1;
    int right = numsSize - 1;
    while (left < right) {
      int currentSum = nums[i] + nums[left] + nums[right];
      if (currentSum == 0) {
        array[pos] = (int*)malloc(3 * sizeof(int));
        array[pos][0] = nums[i];
        array[pos][1] = nums[left];
        array[pos][2] = nums[right];
        pos ++;

        while (left < right && nums[left] == nums[left + 1]) {
          left ++;
        }

        while (left < right && nums[right] == nums[right - 1]) {
          right --;
        }

        left ++;
        right --;
      } else if (currentSum < 0) {
        left ++;
      } else {
        right --;
      }
    }
  }

  *returnSize = pos;
  *returnColumnSizes = (int*)malloc(pos * sizeof(int));
  for (int i = 0; i < pos; i ++) {
    (*returnColumnSizes)[i] = 3;
  }

  return array;
}


// An alternate approach with O(n^3)

// struct element {
//   int sum;
//   int absoluteSum;
//   long long int product;
// };

// int findElement (struct element* nums, int numsSize, int targetSum, int targetAbsoluteSum, long long int targetProduct) {
//   if (numsSize == 0) {
//     return 1;
//   }

//   for (int i = 0; i < numsSize; i ++) {
//     if (nums[i].sum == targetSum && nums[i].absoluteSum == targetAbsoluteSum && nums[i].product == targetProduct) {
//       return 0;
//     }
//   }

//   return 1;
// }

// int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
//   int** array = (int**)malloc(3000 * sizeof(int*));
//   int pos = 0;
//   struct element* count = (struct element*)malloc(3000 * sizeof(struct element));
  
//   for (int i = 0; i < numsSize - 2; i ++) {
//     for (int j = i + 1; j < numsSize - 1; j ++) {
//       for (int k = j + 1; k < numsSize; k ++) {
//         if (nums[i] + nums[j] + nums[k] == 0) {
//           if (findElement(count, pos, nums[i] + nums[j] + nums[k], abs(nums[i]) + abs(nums[j]) + abs(nums[k]), (long long int)nums[i] * nums[j] * nums[k])) {
//             array[pos] = (int*)malloc(3 * sizeof(int));
//             array[pos][0] = nums[i];
//             array[pos][1] = nums[j];
//             array[pos][2] = nums[k];
//             count[pos].sum = nums[i] + nums[j] + nums[k];
//             count[pos].absoluteSum = abs(nums[i]) + abs(nums[j]) + abs(nums[k]);
//             count[pos].product = (long long int)nums[i] * nums[j] * nums[k];
//             pos ++;
//           }
//         }
//       }
//     }
//   }

//   *returnSize = pos;
//   *returnColumnSizes = malloc(pos * sizeof(int));
//   for (int i = 0; i < pos; i ++) {
//     (*returnColumnSizes)[i] = 3;
//   }

//   return array;
// }