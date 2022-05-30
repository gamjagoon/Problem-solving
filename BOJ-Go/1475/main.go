package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var ch [10]uint32

//===============
// Main
//===============
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	N := uint64(nextInt64())
	for N != 0 {
		ch[N%10] += 1
		N /= 10
	}
	ch[6] += ch[9]
	ch[6] += ch[6] % 2
	ch[6] /= 2
	res := uint32(0)
	for i := 0; i < 9; i++ {
		if res < ch[i] {
			res = ch[i]
		}
	}
	fmt.Println(res)
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
