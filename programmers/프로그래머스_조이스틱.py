def solution(name):
    answer = 0
    alpha={chr(ord('A')+i): min(i,26-i) for i in range(26)}
    press_min=lambda target_alpha : alpha[target_alpha]
    for ch in name:
        answer+=press_min(ch)
    def traval_min(name):
        mid_left=len(name)//2-1
        mid_right=len(name)//2
        visit = [ True if value == 'A' or i==0 else False for i,value in enumerate(name) ]
        if False not in visit :
            return 0
        def straight_travel():
            last_not_A=-1
            first_not_A=-1
            for i,value in enumerate(visit):
                if value == False:
                    last_not_A=i
                    if first_not_A == -1:
                        first_not_A=i
            return min(last_not_A,len(name)-first_not_A)
        def round_trip():
            left_not_A=-1
            right_not_A=-1
            for i in range(mid_left,-1,-1):
                if name[i] != 'A':
                    left_not_A=i
                    break
            for i in range(mid_right,len(name)+1):
                if name[i] != 'A':
                    right_not_A=i
                    break
            return 2*left_not_A+len(name)-right_not_A
        return min(straight_travel(),round_trip())
    return answer+traval_min(name)
