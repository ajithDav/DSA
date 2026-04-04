class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        cnt=0
        maxi=float("-inf")
        for num in nums:
            if num==1:
                cnt+=1
            else:
                cnt=0
            maxi=max(cnt,maxi)
        return maxi
        