package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner *bufio.Scanner
var writer *bufio.Writer
var result int

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
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

func dfs(cnt int,chois byte,T []int) {
	if cnt == 2 {
		A,B := 0,0
		for i:=0;i<4;i++{
			if chois >> i & 1 == 1{
				A += T[i]
			} else {
				B += T[i]
			}
		}
		A -= B
		if A < 0 {
			A *= -1
		}
		if result > A {
			result = A
		}
		return
	}
	for i:=0;i<4;i++{
		if chois >> i & 1 == 1 {
			continue
		} 
		var b byte = 1 << i
		chois |= b
		dfs(cnt + 1,chois,T)
		chois &^= b
	}
}

func main() {
	defer writer.Flush()
	result = 1000000
	team := make([]int, 4,4)
	for i := range team{
		team[i] = nextInt()
	}
	dfs(0,0,team)
	fmt.Fprintf(writer,"%d",result)
}