import collections

def upper(a,b):
    if not a%b:
        return a//b
    return a//b+1


def time_to_min(come, go = '23:59'):
    come_h, come_min = map(int,come.split(':'))
    go_h, go_min = map(int,go.split(':'))
    return (go_h - come_h)*60 + go_min - come_min


def fee_clouser(fees):
    def min_to_fee(min):
        basic_time, basic_fee, unit_time, unit_fee = fees
        if min <= basic_time:
            return basic_fee
        return basic_fee + upper(min - basic_time,unit_time)*unit_fee
    return min_to_fee


def solution(fees, records):
    answer = []
    come_go_data = collections.defaultdict(list)
    min_to_fee = fee_clouser(fees)
    for record in records:
        time, number, InOrOut = record.split()
        come_go_data[int(number)].append(time)
    for number in sorted(come_go_data.keys()):
        total_min = 0
        for i in range(0,len(come_go_data[number]),2):
            min = time_to_min(*come_go_data[number][i:i+2])
            total_min += min
        answer.append(min_to_fee(total_min))
    return answer
