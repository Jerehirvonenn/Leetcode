class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result += (num % 3 != 0)
        return result  