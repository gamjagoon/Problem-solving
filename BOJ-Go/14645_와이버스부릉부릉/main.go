package main

import (
	"bufio"
	"fmt"
	"os"
)
var scanner *bufio.Scanner

func init()  {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func nextInt() int {
	scanner.Scan()
	sigh, x := 1, 0

	// 바이트로 읽어 들인다
	// char 형으로 하나씩 읽어 들인다 즉 문자로 읽는다
	for _, b := range scanner.Bytes() {
		if b == '-' {
			sigh = -1
			continue
		}
		x *= 10
		x += int(b-'0')
	}
	return sigh * x
}

var (
	n int
	k int
)

func main() {
	n = nextInt()
	k = nextInt()
	for i := 0 ; i < n ; i++{
		_ = nextInt()
		_ = nextInt()
	}
	fmt.Printf("비와이")
}