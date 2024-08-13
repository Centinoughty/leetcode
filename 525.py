# Contiguous array
# MEDIUM

from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        result = 0
        prefix = 0
        prefIndex = {0: -1}

        for i, num in enumerate(nums):
            prefix += 1 if num else -1
            result = max(result, i - prefIndex.setdefault(prefix, i))

        return result