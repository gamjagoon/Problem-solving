package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

type work struct {
	t int;end int
}

func main() {
	N := nextInt()
	list := make([]work,N,N)
	for i := range list {
		list[i].t = nextInt()
		list[i].end = nextInt()
	}
	sort.Slice(list,func(i, j int) bool {
		return list[i].end < list[j].end
	})
	result := list[N-1].end - list[N-1].t
	for i:= N-2; i >= 0;i--{
		if list[i].end > result {
			list[i].end = result
		}
		result = list[i].end - list[i].t
	}
	if result < 0 {
		fmt.Print("-1")
	} else {
		fmt.Print(result)
	}
}