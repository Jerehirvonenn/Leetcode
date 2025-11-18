class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        zx = abs(x - z)
        zy = abs(y - z)
        if zy is zx:
            return 0
        elif zx < zy:
            return 1
        else:
            return 2
        