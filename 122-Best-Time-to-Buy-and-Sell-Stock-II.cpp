class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() , sum = 0 ;
        for(int i = 0 ; i<n ; i++){
            int j = i ; 
            while (j+1 < n && prices[j] <= prices[j+1]){
                j++;
            }
            if(prices[j] > prices[i])
                sum += prices[j]-prices[i];
            i=j;
            
        }
        return sum ;
        
    }
};