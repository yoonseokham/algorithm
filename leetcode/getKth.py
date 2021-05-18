class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        
        def OneMaker(num:int)->int:
            count=0
            while num!=1:
                if num%2==0:
                    num//=2
                else:
                    num=3*num+1
                count+=1
            return count
        
        answer=[(i,OneMaker(i)) for i in range(lo,hi+1)]
        answer.sort(key=lambda x:(x[1],x[0]))
        return answer[k-1][0]
