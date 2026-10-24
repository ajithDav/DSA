class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        count1,count2={},{}
        for n in s :
            count1[n]=count1.get(n,0)+1
        for n in t : 
            count2[n]=count2.get(n,0)+1
        return count1==count2
        