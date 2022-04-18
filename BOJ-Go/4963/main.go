package main

import (
	"bufio"
	"os"
	"strconv"
)

//===============
// Main
//===============
func main() {
	sc.Split(bufio.ScanWords)
	defer wr.Flush()

	var r, c int
	var b int
	var arr [51][51]int
	var res int
	for {
		c = nextInt() // row 행 : 행의 갯수 이기 때문에 세로 길이
		r = nextInt() // column 열 : 열의 갯수이기 때문에 가로 길이
		res = 0

		if r|c == 0 {
			break
		}

		for i := 0; i < r; i++ {
			for j := 0; j < c; j++ {
				b = nextInt()
				arr[i][j] = b
			}
		}

		for i := 0; i < r; i++ {
			for j := 0; j < c; j++ {
				if arr[i][j] == 1 {
					res += 1
					fillnextfield(&arr, i, j, r, c)
				}
			}
		}
		wr.WriteString(strconv.Itoa(res) + "\n")
	}
}

func fillnextfield(arr *[51][51]int, r int, c int, rh int, ch int) {
	if arr[r][c] == 0 {
		return
	} else {
		arr[r][c] = 0
	}
	if r+1 < rh {
		fillnextfield(arr, r+1, c, rh, ch) // down
		if c+1 < ch {
			fillnextfield(arr, r+1, c+1, rh, ch) // diagonally to the lower right
		}
		if c-1 >= 0 {
			fillnextfield(arr, r+1, c-1, rh, ch)
		}
	}
	if r-1 >= 0 {
		fillnextfield(arr, r-1, c, rh, ch)
		if c+1 < ch {
			fillnextfield(arr, r-1, c+1, rh, ch) // diagonally to the lower right
		}
		if c-1 >= 0 {
			fillnextfield(arr, r-1, c-1, rh, ch)
		}
	}
	if c+1 < ch {
		fillnextfield(arr, r, c+1, rh, ch)
	}
	if c-1 >= 0 {
		fillnextfield(arr, r, c-1, rh, ch)
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
