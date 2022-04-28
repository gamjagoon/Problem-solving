package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

//===============
// Main
//===============
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	var n, w, l uint32
	n = uint32(nextInt())
	l = uint32(nextInt())
	w = uint32(nextInt())
	var t []uint32
	t = make([]uint32, n)
	for i := uint32(0); i < n; i++ {
		t[i] = uint32(nextInt())
	}

	nw := uint32(0)
	bridge := make([]uint32, l)

	res := uint32(0)
	for {
		if len(t) > 0 {
			res += 1
			if nw+t[0]-bridge[0] <= w {
				nw += (t[0] - bridge[0])
				bridge = append(bridge[1:], t[0])
				t = t[1:] // MOVE first truck
			} else {
				nw -= bridge[0]
				bridge = append(bridge[1:], uint32(0))
			}
		} else {
			res += l
			break
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
