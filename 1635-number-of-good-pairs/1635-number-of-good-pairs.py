class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        seen = {}
        result = 0
        for num in nums:
            if num in seen:
                result += seen[num]
                seen[num] += 1
            else:
                seen[num] = 1
        return result