class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp ={}
        for idx,num in enumerate(nums):
            target_element=target-num
            if target_element in mpp:
                return [mpp[target_element],idx]
            mpp[num]=idx
        return [-1,-1]
            