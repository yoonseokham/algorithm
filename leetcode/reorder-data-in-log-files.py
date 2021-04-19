class Solution:
    def keyOfSort(self,s :str):
        a=s.split(" ")
        identifer=a[0]
        logsExceptIdent=' '.join(a[1:])
        return (logsExceptIdent,identifer)
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter=[i for i in logs if ''.join(i.split()[1:]).isdigit()==False]
        dig=[i for i in logs if ''.join(i.split()[1:]).isdigit()==True]
        letter.sort(key=self.keyOfSort)
        return letter+dig
        
