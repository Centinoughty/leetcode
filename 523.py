# Continuous subarray sum
# MEDIUM

from typing import List

class Solution:
  def checkSubarraySum(self, nums: List[int], k: int) -> bool:
    prefixSum = 0
    prefixToIndex = {0: -1}

    for i, num in enumerate(nums):
      prefixSum += num
      prefixSum %= k
      if prefixSum in prefixToIndex:
        if i - prefixToIndex[prefixSum] > 1:
            return True
      else:
        prefixToIndex[prefixSum] = i

    return False
