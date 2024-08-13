# Simplify path
# MEDIUM

class Solution(object):
  def simplifyPath(self, path):
    stack = []

    for direc in path.split('/'):
      if direc in ('', '.'):
        continue
      elif direc == '..':
        if stack:
          stack.pop()
      else:
        stack.append(direc)

    return '/' + '/'.join(stack)