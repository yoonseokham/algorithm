class Solution:

    def inadjacentChoice(self, plantAbleSet, n):
        plantAbles = sorted(list(plantAbleSet))
        stack = []
        for i, value in enumerate(plantAbles):
            if not stack:
                stack.append(value)
            elif stack[-1] - value == -1:
                continue
            else:
                stack.append(value)
        return len(stack) >= n

    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        isPlantAble = set([i for i in range(len(flowerbed))])
        for index, planted in enumerate(flowerbed):
            if planted:
                for i in (-1, 0, 1):
                    isPlantAble.discard(index - i)
        return self.inadjacentChoice(isPlantAble, n)
    
