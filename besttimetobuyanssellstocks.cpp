 int n = prices.size();
        int i = 0, j = 1;
        int max_profit = 0;
        
        while(i < n && j < n)
        {    
            if(prices[i] > prices[j])
            {
                i = j;
            }
            else 
            {
                int profit = prices[j] - prices[i];
                if(profit > max_profit) max_profit = profit;                
            }
            j++;
        }
        return max_profit;