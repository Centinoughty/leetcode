# Step-by-step directions from a binary tree node to another
# MEDIUM

from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
    def getPath(root, target, path, ans):
      if root is None:
        return
      
      if root.val == target:
        ans.append("".join(path))
      
      path.append('L')
      getPath(root.left, target, path, ans)
      path[-1] = 'R'
      getPath(root.right, target, path, ans)
      path.pop(-1)
    
    temp = []
    start = []
    dest = []

    getPath(root, startValue, temp, start)
    getPath(root, destValue, temp, dest)

    start = start[0]
    dest = dest[0]

    i = 0
    while i < min(len(start), len(dest)) and start[i] == dest[i]:
      i += 1
    
    return "U" * (len(start) - i) + dest[i:]
