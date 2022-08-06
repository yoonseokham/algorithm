class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people=sorted(people)
        start= 0
        end = len(people) - 1
        boat = 0
        while start<=end:
            if start != end:
                if people[start] + people[end] <= limit:
                    start += 1
                    end -= 1
                    boat += 1
                elif people[start] + people[end] > limit:
                    end -= 1
                    boat += 1
            else:
                boat += 1
                break
        return boat
