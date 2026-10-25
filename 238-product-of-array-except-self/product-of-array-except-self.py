class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        prefix=1
        answer=[1]*len(nums)
        for i in range(len(nums)):
            answer[i]=prefix
            prefix*=nums[i]
        suffix=1
        for i in range(len(nums)-1,-1,-1):
            answer[i]*=suffix
            suffix*=nums[i]
        return answer