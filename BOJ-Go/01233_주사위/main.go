package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

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

type value struct {
	val int
	cnt int
}

func main() {
	defer writer.Flush()
	S := [3]int{}
	res := make([]value,81,81)
	for i := 0; i < 81;i++{
		res[i].val = i
	}
	for i := 0; i < 3; i++ {
		S[i] = nextInt()
	}
	for i := 1; i <= S[0];i++ {
		for j := 1; j <= S[1];j++{
			for k := 1; k <= S[2];k++{
				res[i+j+k].cnt++
			}
		}
	}
	sort.Slice(res,func(i, j int)bool {
		if res[i].cnt != res[j].cnt{
			return res[i].cnt > res[j].cnt
		}
		return res[i].val < res[j].val
	})
	fmt.Fprintf(writer,"%d",res[0].val)
}