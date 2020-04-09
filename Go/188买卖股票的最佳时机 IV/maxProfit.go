func maxProfit(k int, prices []int) int {
	cnt := len(prices)
	if cnt == 0 {
		return 0
	}
	if k >= cnt / 2 {
		k = cnt / 2
	}
	dp := make([]int, cnt)
	for i := 0; i < k; i++ {
		for j := 1; j < cnt; j++ {
			dp[j] = max(dp[j], dp[j-1] + prices[j] - prices[j-1])
		}
		for j := 1; j < cnt; j++ {
			dp[j] = max(dp[j], dp[j-1])
		}
	}
	return dp[cnt-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}