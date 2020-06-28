package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
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

type val struct {
	value int
	dif int
}

func main() {
	defer writer.Flush()
	x := nextInt()
	y := nextInt()
	if x > y {
		x,y = y,x
	}
	res := 0
	if x % 2== 0{
		res += x / 2
		res *= y
	} else {
		res += x / 2
		res *= y
		res += y / 2
	}
	fmt.Fprintf(writer,"%d",res)
}