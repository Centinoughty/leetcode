# Intersection of two arrays
# EASY

class Solution(object):
  def intersection(self, nums1, nums2):
    res = []
    nums2 = set(nums2)

    for num in nums1:
      if num in nums2:
        res.append(num)
        nums2.remove(num)
    
    return res
