s=input()
s=s[::-1]
sum=0
for i in range(len(s)):
    try:
        sum+=int(s[i])*16**i
    except:
        sum+=(ord(s[i])-ord('A')+10)*16**i
print(sum)
