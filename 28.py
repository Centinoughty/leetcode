# Find the index of the first occurence in a string
# EASY

class Solution:
  def strStr(self, haystack: str, needle: str) -> int:
    return haystack.find(needle)