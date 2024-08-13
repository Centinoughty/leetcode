from typing import List


class Solution:
  def partition(self, s: str) -> List[List[str]]:
    ans = []

    def isPalindrome (s: str) -> bool:
      return s == s[::-1]
    
    def search (s: str, j: int, path: List[str], ans: List[List[str]]) -> None:
      if (j == len(s)):
        ans.append(path)
        return
      
      for i in range (j, len(s)):
        if isPalindrome(s[j: i + 1]):
          search(s, i + 1, path + [s[j: i + 1]], ans)

    search(s, 0, [], ans)
    return ans
  