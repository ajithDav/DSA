class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        element={}
        for i,n in enumerate(nums):
            result=target-n
            if result in element :
                return [element[result],i]
            element[n]=i
        return []

            