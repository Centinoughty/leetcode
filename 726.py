# Number of atoms
# HARD

from collections import defaultdict

class Solution:
  def countOfAtoms(self, formula: str) -> str:
    stack = [defaultdict(int)]
    i = 0

    while i < len(formula):
      if formula[i] == '(':
        stack.append(defaultdict(int))
        i += 1
      
      elif formula[i] == ')':
        curr = stack.pop()
        i += 1
        count = ""
        while i < len(formula) and formula[i].isdigit():
          count += formula[i]
          i += 1
        
        count = 1 if not count else int(count)
        prev = stack[-1]
        for x in curr:
          prev[x] += curr[x] * count
      
      else:
        element = formula[i]
        i += 1
        while i < len(formula) and formula[i].islower():
          element += formula[i]
          i += 1
        
        count = ""
        while i < len(formula) and formula[i].isdigit():
          count += formula[i]
          i += 1
        
        count = 1 if not count else int(count)
        curr = stack[-1]
        curr[element] += count
    
    curr = stack[-1]
    result = ""
    for x in sorted(curr.keys()):
      count = "" if curr[x] == 1 else curr[x]
      result += x + str(count)
    
    return result
