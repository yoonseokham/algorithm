def transform(keypad):
    mapped={
        1:(0,0),
        2:(0,1),
        3:(0,2),
        4:(1,0),
        5:(1,1),
        6:(1,2),
        7:(2,0),
        8:(2,1),
        9:(2,2),
        0:(3,1)
    }
    return mapped[keypad]

def calDistance(left,right,keypad):
    
    distanceL=abs(left[0]-keypad[0])+abs(left[1]-keypad[1])
    distanceR=abs(right[0]-keypad[0])+abs(right[1]-keypad[1])
    
    return (distanceL,distanceR)
    
def solution(numbers, hand):
    left=(3,0)
    right=(3,2)
    answer=''
    for i in numbers:
        if i ==1 or i==4 or i==7:
            answer+="L"
            left=transform(i)
        elif i ==3 or i==6 or i==9:
            answer+="R"
            right=transform(i)
        else:
            L,R=calDistance(left,right,transform(i))
            if L<R:
                answer+="L"
                left=transform(i)
            elif L>R:
                answer+="R"
                right=transform(i)
            else:
                if hand=='left':
                    answer+="L"
                    left=transform(i)
                else:
                    answer+="R"
                    right=transform(i)
    return answer
