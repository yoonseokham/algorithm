class Solution:
    def isHappy(self, n: int) -> bool:
        visit=set()
        def happyNumber(n):
            if n==1:
                visit.add(1)
                return
            else:
                sumed=0
                for i in str(n):
                    sumed+=int(i)**2
                if sumed in visit:
                    return
                else:
                    visit.add(sumed)
                    happyNumber(sumed)
        happyNumber(n)
        return (1 in visit)
        
