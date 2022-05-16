package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var ch [1000001]bool

//===============
// Main
//===============
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	N := uint32(nextInt())
	i := uint32(0)
	for i = 0; i < N; i++ {
		tmp := uint32(nextInt())
		if tmp < 1000001 {
			ch[tmp] = true
		}
	}
	fnish := 0
	for i = 1; i < 1000001; i++ {
		if !ch[i] {
			fmt.Println(i)
			fnish = 1
			break
		}
	}
	if fnish == 0 {
		fmt.Println(1000001)
	}
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
