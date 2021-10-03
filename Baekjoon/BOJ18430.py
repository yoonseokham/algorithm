import sys
if __name__ == '__main__':
    boomerangList=[[(1,0),(0,1)]]
    segcheck= lambda i,j :True if 0<=i<n and 0<=j<m else False

    def rotate_90degree(elements):
        return [(-j,i) for i,j in elements]
    
    for _ in range(3):
        boomerangList.append(rotate_90degree(boomerangList[-1]))
    n,m = map(int,sys.stdin.readline().split())
    ingrediant=[]
    used=[[False]*m for i in range(n)]
    for i in range(n):
        ingrediant.append(list(map(int,sys.stdin.readline().split())))
    
    def solve():
        global_answer=0
        def find_max(answer=0,start_i=0):
            nonlocal global_answer
            for i in range(start_i,n):
                for j in range(m):
                    for boomerang in boomerangList:
                        first,second = boomerang
                        first_new_i=i+first[0]
                        first_new_j=j+first[1]
                        second_new_i=i+second[0]
                        second_new_j=j+second[1]
                        boomerang_index_list=[(i,j),(first_new_i,first_new_j),(second_new_i,second_new_j)]
                        if segcheck(first_new_i,first_new_j) and segcheck(second_new_i,second_new_j):
                            for index,jndex in boomerang_index_list:
                                if used[index][jndex]:
                                    break
                            else:
                                answer+=2*ingrediant[i][j]+ingrediant[first_new_i][first_new_j]+ingrediant[second_new_i][second_new_j]
                                for index,jndex in boomerang_index_list:
                                    used[index][jndex]=True
                                global_answer=max(global_answer,answer)
                                find_max(answer,i)
                                for index,jndex in boomerang_index_list:
                                    used[index][jndex]=False
                                answer-=2*ingrediant[i][j]+ingrediant[first_new_i][first_new_j]+ingrediant[second_new_i][second_new_j]
        find_max()
        return global_answer
    print(solve())
