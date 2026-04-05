class Solution:
    def majorityElement(self, nums):
        mpp = {}
        n = len(nums) // 2

        for num in nums:
            # update count first
            if num in mpp:
                mpp[num] += 1
            else:
                mpp[num] = 1

            # then check
            if mpp[num] > n:
                return num

        return -1