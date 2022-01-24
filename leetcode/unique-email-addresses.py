class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        answer = set()
        def email_fillter(email):
            local_name,domain_name = email.split('@')
            real_local_name = ''
            if '+' in local_name:
                plus_index = local_name.index('+')
                local_name = local_name[:plus_index]
            for i in local_name:
                if i=='.':
                    continue
                real_local_name += i
            return real_local_name+'@'+domain_name
        for email in emails:
            answer.add(email_fillter(email))
        return len(answer)
