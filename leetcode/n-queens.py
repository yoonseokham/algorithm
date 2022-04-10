import copy
import collections
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        Point = collections.namedtuple("Point","i j")
        QueenLocation = set()
        answer_form = [["." for _ in range(n)] for _ in range(n)]        
        n_queen_answers = []
        
        def kill_condition(p1, p2):
            kill_list = [p1.j==p2.j,abs(p1.i-p2.i)==abs(p1.j-p2.j)]
            return any(kill_list)
        
        def isQueenAble(point):
            for p in QueenLocation:
                if kill_condition(p,point):
                    return False
            return True
        
        def dfs(curI=0):
            if len(QueenLocation) == n:
                n_queen_answers.append(list(QueenLocation))
                return
            else:
                for curJ in range(n):
                    curPoint = Point(curI,curJ)
                    if isQueenAble(curPoint):
                        QueenLocation.add(curPoint)
                        dfs(curI+1)
                        QueenLocation.remove(curPoint)
        
        def get_formated_answer(n_queen_answers):
            answer_form = [["." for _ in range(n)] for _ in range(n)]
            formated_answer = []
            for n_queen_answer in n_queen_answers:
                temp_answer = copy.deepcopy(answer_form)
                temp_formed_answer = []
                for i,j in n_queen_answer:
                    temp_answer[i][j]='Q'
                for row in temp_answer:
                    temp_formed_answer.append("".join(row))
                formated_answer.append(temp_formed_answer)
            return formated_answer
        
        dfs()
        return get_formated_answer(n_queen_answers)
