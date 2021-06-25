def R_Binder(R,M):
    def hashFunc(string):
        r=R
        m=M
        return sum([(ord(j)-96)*r**i for i,j in enumerate(string)])%m
    return hashFunc

L=int(input())
print(R_Binder(31,1234567891)(input().rstrip()))
