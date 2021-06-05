class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        start=0
        end=len(people)-1
        boat=0
        people.sort()
        while start<=end:
            if start==end:
                boat+=1
                break
            elif people[start]+people[end]<=limit: 
                boat+=1
                start+=1
                end-=1
            else:
                end-=1
                boat+=1
        return boat
                
