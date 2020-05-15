package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewScanner(os.Stdin)

func init() {
	in.Split(bufio.ScanWords)
}

func NextInt() int {
	in.Scan()
	r := 0
	for _, c := range in.Bytes() {
		r *= 10
		r += int(c - '0')
	}
	return r
}

func main() {
	n, h := NextInt(), NextInt()
	u, d := make([]int, h), make([]int, h)
	for k := n / 2; k > 0; k-- {
		u[NextInt()]++
		d[NextInt()]++
	}
	r1, r2 := n/2, 1
	r := n / 2
	for hh := 1; hh < h; hh++ {
		r -= u[hh]
		r += d[h-hh]
		if r1 > r {
			r1, r2 = r, 1
		} else if r1 == r {
			r2++
		}
	}
	fmt.Printf("%d %d\n", r1, r2)
}
