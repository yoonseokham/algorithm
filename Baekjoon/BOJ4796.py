if __name__=="__main__":
    cnt=1
    while True:
        l,p,n=map(int,input().split())
        if (l,p,n)==(0,0,0):break
        print(f"Case {cnt}: {n//p*l+min(l,n%p)}")
        cnt+=1
