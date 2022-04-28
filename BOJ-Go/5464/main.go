package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type park struct {
	cost uint32
	busy bool
}

type car struct {
	w  uint32
	pn uint32
}

var arr [100]park
var carmap [2001]car
var queue []int32

//===============
// Main
//===============
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	var N, M uint32
	N = uint32(nextInt())
	M = uint32(nextInt())
	for i := uint32(0); i < N; i++ {
		arr[i].cost = uint32(nextInt())
		arr[i].busy = false
	}
	for i := uint32(1); i <= M; i++ {
		carmap[i].w = uint32(nextInt())
	}

	var n, res uint32
	var tmp, nq int32
	n = uint32(0)
	for i := uint32(0); i < M*2; i++ {
		tmp = int32(nextInt())
		if tmp > 0 { // in car
			if n == N {
				queue = append(queue, tmp)
			} else {
				for j := uint32(0); j < N; j++ {
					if !arr[j].busy {
						arr[j].busy = true
						res += arr[j].cost * carmap[tmp].w
						carmap[tmp].pn = j
						n += 1
						break
					}
				}
			}
		} else { // out car
			if n == N && len(queue) != 0 {
				nq = queue[0]
				queue = queue[1:]
				carmap[nq].pn = carmap[tmp*-1].pn
				res += arr[carmap[nq].pn].cost * carmap[nq].w
			} else {
				arr[carmap[tmp*-1].pn].busy = false
				n -= 1
			}
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
