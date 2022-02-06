class Solution:
    def isInsert(self, s:str, t:str) -> bool:
        s_list = list(s)
        t_list = list(t)
        s_index = 0
        t_index = 0
        deathCount = 0
        while s_index < len(s_list) and t_index < len(t_list):
            if s_list[s_index] == t_list[t_index]:
                s_index += 1
                t_index += 1
            else:
                s_index += 1
                deathCount += 1
        if deathCount < 2 and ( s_index == len(s_list) and t_index == len(t_list) ):
            return True
        if deathCount == 0 and ( s_index == len(s_list)-1 and t_index == len(t_list) ):
            return True
        return False
    
    def isDelete(self, s:str, t:str) -> bool :
        return self.isInsert(t,s)
    
    def isReplace(self, s:str, t:str) -> bool :
        s_list = list(s)
        t_list = list(t)
        s_index = 0
        t_index = 0
        deathCount = 0
        while s_index < len(s_list) and t_index < len(t_list):
            if s_list[s_index] != t_list[t_index]:
                deathCount += 1
            s_index += 1
            t_index += 1
        if deathCount < 2 and ( s_index == len(s_list) and t_index == len(t_list) ):
            return True
        return False
    def isOneEditDistance(self, s: str, t: str) -> bool:
        return s != t and (self.isDelete(s,t) or self.isInsert(s,t) or self.isReplace(s,t))
        
