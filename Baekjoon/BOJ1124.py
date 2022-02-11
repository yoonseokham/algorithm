import math
import sys

def getPrimeTable(num):
    isPrime = [ True for _ in range(num+1)]
    isPrime[0] = False
    isPrime[1] = False
    for i in range(int(math.sqrt(num))+1):
        if isPrime[i]:
            for j in range(i*i,num+1,i):
                isPrime[j] = False
    return isPrime


def prime_generator(prime_num_list):
    yield from prime_num_list


def getElement(num,prime_num_list):
    Element = []
    prime_gen = prime_generator(prime_num_list)
    curPrime = next(prime_gen)
    while num!= 1:
        if num%curPrime == 0:
            num//=curPrime
            Element.append(curPrime)
        else:
            curPrime = next(prime_gen)
    return Element


if __name__ == '__main__':
    n, k = map(int,sys.stdin.readline().split())
    isPrime = getPrimeTable(k)
    prime_num_list = [i for i,value in enumerate(isPrime) if value]
    answer = 0
    for i in range(n,k+1):
        if  isPrime[len(getElement(i,prime_num_list))]:
            answer += 1
    print(answer)
