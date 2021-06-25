from collections import defaultdict
if __name__ == "__main__":
    for i in range(int(input())):
        clothes=defaultdict(lambda:1)
        for j in range(int(input())):
            temp=input().split()
            clothes[temp[1]]+=1
        values=[j for _,j in clothes.items()]
        del clothes
        sum=1
        for k in values:
            sum*=k
        print(sum-1)
