# Max number of k-sum pairs
# MEDIUM

class Solution(object):
  def maxOperations(self, nums, k):
    count = 0
    hashmap = {}

    for num in nums:
      complement = k - num
      if complement in hashmap and hashmap[complement] > 0:
        count += 1
        hashmap[complement] -= 1
      else:
        hashmap[num] = hashmap.get(num, 0) + 1

    return count
