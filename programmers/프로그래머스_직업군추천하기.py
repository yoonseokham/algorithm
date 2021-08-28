from collections import defaultdict

def solution(table, languages, preference):
    database =  defaultdict()
    for instance in table:
        temp = instance.split()
        field, language = temp[0], temp[1:]
        database[field]=defaultdict(int)
        for i,lang in enumerate(reversed(language)):
            database[field][lang]=i+1
    answer=defaultdict(int)
    for key in database.keys():
        for lang,value in zip(languages,preference):
            answer[key]+=database[key][lang]*value
    return sorted([(j,i) for i,j in answer.items() ],key = lambda x: (-x[0] ,x[1]))[0][1]
