import copy

def permute(nums):
  array = [[]]
  i = 0

  while i < len(nums):
    temp = copy.deepcopy(nums)
    j = 0
    while j < len(nums):
      if i == j:
        j += 1
      else:
        new = temp[i]
        temp[i] = temp[j]
        temp[j] = new
      
        if temp not in array:
          array.append(temp[:])
        
        j += 1
    i += 1

  array.append(nums[:])
  return array

print(permute([1,2,3]))