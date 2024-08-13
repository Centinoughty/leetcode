# Zigzag conversion
# MEDIUM

class Solution:
  def convert(self, s: str, numRows: int) -> str:
    if numRows == 1:
      return s
    
    result = ""
    length = len(s)
    for i in range(numRows):
      upValue = 2 * (numRows - 1)
      for j in range(i, length, upValue):
        result += s[j]
        if (i > 0 and i < numRows - 1 and j + upValue - 2 * i < length):
          result += s[j + upValue - 2 * i]

    return result