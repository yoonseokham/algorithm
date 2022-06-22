import collections


class Solution:
    COST = 5

    def isPayable(self, wallet, change):
        wallet_money_list = []
        out_money = []
        for price in (20, 10, 5):
            for _ in range(wallet[price]):
                wallet_money_list.append(price)
        for price in wallet_money_list:
            if change:
                if change >= price:
                    change -= price
                    out_money.append(price)
            else:
                break
        if out_money and not change:
            return True, out_money
        return False, []

    def lemonadeChange(self, bills: List[int]) -> bool:
        wallet = collections.defaultdict(int)
        for bill in bills:
            wallet[bill] += 1
            change = bill - self.COST
            if change:
                isPayable, out_money = self.isPayable(wallet, change)
                if isPayable:
                    for bill in out_money:
                        wallet[bill] -= 1
                else:
                    return False
        return True
