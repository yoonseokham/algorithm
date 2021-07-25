def solution(phone_book):
    phone_set=set(phone_book)
    for numbers in phone_book:
        for i in range(1,len(numbers)):
            if numbers[:i] in phone_set: return False
    return True
