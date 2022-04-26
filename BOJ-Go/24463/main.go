package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type pt struct {
	r int
	c int
}

type path struct {
	ch   bool
	path pt
}

var R, C int
var MAP [][]uint8
var CK [][]path
var fifo_queue []pt

//===============
// Main
//===============
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()
	R = nextInt()
	C = nextInt()
	MAP = make([][]uint8, R)
	CK = make([][]path, R)
	for i := 0; i < R; i++ {
		MAP[i] = make([]uint8, C)
		CK[i] = make([]path, C)
	}

	for i := 0; i < R; i++ {
		MAP[i] = []uint8(netxString())
	}
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if MAP[i][j] == '.' {
				MAP[i][j] = '@'
			}
		}
	}

	sr := -1
	sc := -1
	er := -1
	ec := -1
	for i := 0; i < C; i++ {
		if MAP[0][i] == '@' {
			sr = 0
			sc = i
			break
		}
		if MAP[R-1][i] == '@' {
			sr = R - 1
			sc = i
			break
		}
	}
	if sr < 0 {
		for i := 1; i < R-1; i++ {
			if MAP[i][0] == '@' {
				sr = i
				sc = 0
				break
			}
			if MAP[i][C-1] == '@' {
				sr = i
				sc = C - 1
				break
			}
		}
	}
	MAP[sr][sc] = '.'

	for i := 0; i < C; i++ {
		if MAP[0][i] == '@' {
			er = 0
			ec = i
			break
		}
		if MAP[R-1][i] == '@' {
			er = R - 1
			ec = i
			break
		}
	}
	if er < 0 {
		for i := 1; i < R-1; i++ {
			if MAP[i][0] == '@' {
				er = i
				ec = 0
				break
			}
			if MAP[i][C-1] == '@' {
				er = i
				ec = C - 1
				break
			}
		}
	}

	fifo_queue = append(fifo_queue, pt{sr, sc})
	CK[sr][sc].ch = true
	var nq pt
	for {
		nq = fifo_queue[0]
		if nq.r == er && nq.c == ec {
			break
		}
		fifo_queue = fifo_queue[1:] // pop
		if nq.r+1 < R && !CK[nq.r+1][nq.c].ch && MAP[nq.r+1][nq.c] == '@' {
			CK[nq.r+1][nq.c].ch = true
			CK[nq.r+1][nq.c].path = nq
			next_q := pt{nq.r + 1, nq.c}
			fifo_queue = append(fifo_queue, next_q)
		}
		if nq.r-1 >= 0 && !CK[nq.r-1][nq.c].ch && MAP[nq.r-1][nq.c] == '@' {
			CK[nq.r-1][nq.c].ch = true
			next_q := pt{nq.r - 1, nq.c}
			CK[nq.r-1][nq.c].path = nq
			fifo_queue = append(fifo_queue, next_q)
		}
		if nq.c+1 < C && !CK[nq.r][nq.c+1].ch && MAP[nq.r][nq.c+1] == '@' {
			CK[nq.r][nq.c+1].ch = true
			next_q := pt{nq.r, nq.c + 1}
			CK[nq.r][nq.c+1].path = nq
			fifo_queue = append(fifo_queue, next_q)
		}
		if nq.c-1 >= 0 && !CK[nq.r][nq.c-1].ch && MAP[nq.r][nq.c-1] == '@' {
			CK[nq.r][nq.c-1].ch = true
			next_q := pt{nq.r, nq.c - 1}
			CK[nq.r][nq.c-1].path = nq
			fifo_queue = append(fifo_queue, next_q)
		}
	}

	for {
		MAP[er][ec] = '.'
		nr := CK[er][ec].path.r
		nc := CK[er][ec].path.c
		er = nr
		ec = nc
		if er == sr && ec == sc {
			break
		}
	}
	for i := 0; i < R; i++ {
		fmt.Printf("%s\n", MAP[i])
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
