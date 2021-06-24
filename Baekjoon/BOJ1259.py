isPalindrome=lambda num: (num==num[::-1])
while True:
    temp=input()
    if temp=="0": break
    print("yes" if isPalindrome(temp) else "no")
