# Remove maximum number of edges to keep graph fully traversable
# HARD

from typing import List


class UF:
  def __init__(self, n: int):
    self.count = n
    self.id = list(range(n))
    self.rank = [0] * n

  def union(self, u: int, v: int) -> bool:
    i = self.find(u)
    j = self.find(v)

    if i == j:
      return False
    
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1
    self.count -= 1
    return True

  def find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self.find(self.id[u])
    return self.id[u]

class Solution:
  def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
    alice, bob = UF(n), UF(n)
    addedEdges = 0

    for type, u, v in sorted(edges, reverse=True):
      u -= 1
      v -= 1
      if type == 3:
        if alice.union(u, v) | bob.union(u, v):
          addedEdges += 1
      elif type == 2:
        if bob.union(u, v):
          addedEdges += 1
      else:
        if alice.union(u, v):
          addedEdges += 1

    if alice.count == 1 and bob.count == 1:
      return len(edges) - addedEdges
    else:
      return -1
