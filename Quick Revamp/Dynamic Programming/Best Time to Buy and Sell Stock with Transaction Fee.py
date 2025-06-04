# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy_state_profit = -1 * prices[0] # Buying the stock on the first day will take you only to loss, so buy state profit is negative
        sell_state_profit = 0 # What can you sell on first day without buying...
        for price in prices[1:]: # Now start buying selling from 2nd day...
        # In the buy state, there will always be a un-sold stock at the end
        # Ans in the sold state, there will no stock left to you except the profit or loss
            buy_state_profit = max(buy_state_profit, sell_state_profit-price) # Either don't buy on the current day and stay on the current buy profit or buy new stock from your sold state as you can only buy when you don't have any stock in your hand !
            sell_state_profit = max(sell_state_profit, buy_state_profit+price-fee) # Eihter don't sell on the current day and stay on the current sell profit or sell today on the basis of current buy state as you can sell only when you have some stock in your hand to sell and stock is present in your hand with buy state profit.
            print(buy_state_profit, sell_state_profit)
        return sell_state_profit

# When you buy at X and sell at Y, the difference in Y-X
# Suppose you have 10rs in your hand and you buy at 50
# And you sell at 100 -> amount in hand = 100 - 50 + 10
# Could also write as: 10(amount in hand) -50(buying price) + 100(selling price)
# Means when you buy stock, we subtract the price
# And when we sell stock, we add the price -> which is nothing but the difference in prices
