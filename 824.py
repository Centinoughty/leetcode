# Goat latin
# EASY

class Solution(object):
  def toGoatLatin(self, sentence):
    array = sentence.split()

    for i in range(len(array)):
      if self.isVowel(array[i][0]):
        l = array[i][0]
        array[i] = array[i][1:] + l
      
      array[i] += 'ma'
      array[i] += 'a' * (i + 1)

    return " ".join(array)
      
  def isVowel(self, c):
    return c.lower() not in ['a', 'e', 'i', 'o', 'u']
