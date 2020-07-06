package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func nextInt() int{
	scanner.Scan()
	sign, val := 1, 0
	for _, b := range scanner.Bytes() {
		if(b == '-'){
			sign = -1
		}
		val *= 10
		val += int(b - '0')
	}
	return sign*val
}


func main() {
	N := nextInt()
	data := make([][]int,N,N)
	for i := range data {
		data[i] = make([]int, N,N)
		for j := range data[i]{
			data[i][j] = nextInt()
		}
	}
	data[N-1][N-1] = 1
	dp := make([][]int,N,N)
	for i := range dp {
		dp[i] = make([]int, N,N)
		for j := range dp[i] {
			dp[i][j] = 0
		}
	}
	dp[0][0] = 1
	for i := range dp {
		for j := range dp[i] {
			if dp[i][j] != 0{
				if j + data[i][j] < N {
					dp[i][j+data[i][j]]+=dp[i][j]
				}
				if i + data[i][j] < N {
					dp[i+data[i][j]][j]+=dp[i][j]
				}
			}
		}
	}
	fmt.Printf("%d",dp[N-1][N-1])
}