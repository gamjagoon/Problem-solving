package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)
var T [10001][]int
var ch [10001][10001]bool
var res [10001]int

//===============
// Main
//===============
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	var N, M, a, b int
	N = nextInt()
	M = nextInt()
	for i := 0; i < M; i++ {
		a = nextInt()
		b = nextInt()
		T[b] = append(T[b], a)
	}
	for i := 1; i <= N; i++ {
		res[i] = sumofchild(&ch[i],i)
	}
}


func sumofchild(ch *[10001]bool,root int) int {
	ret := 1
	ch[root] = true
	for _, i := range T[root] {
		if ch[i] != false {
			ret += sumofchild(ch,i)
		}
	}
	return ret
}

//===================
// Fast IO
//===================

var sc = bufio.NewScanner(os.Stdin)
var wr = bufio.NewWriter(os.Stdout)

func netxString() (res string) {
	sc.Scan()
	text := sc.Text()
	return text
}

func nextInt() (res int) {
	sc.Scan()
	text := sc.Text()
	v, _ := strconv.Atoi(text)
	return v
}

func nextInt64() (res int64) {
	sc.Scan()
	text := sc.Text()
	v, _ := strconv.ParseInt(text, 10, 64)
	return v
}
