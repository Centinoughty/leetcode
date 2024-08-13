class Solution(object):
    def reverseWords(self, s):
        l = []
        string = ""
        l = s.split()
        l.reverse()
        for i in l:
            string = string + i + " "

        string = string.rstrip()
        return string