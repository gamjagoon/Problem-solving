package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

var arr [10]int

func main() {
	defer writer.Flush()
	res := nextInt()
	for i,j:=0,0; i < 2; i++{
		j = nextInt()
		res *= j
	}
	str := strconv.Itoa(res)
	for _,b := range(str){
		arr[int(b-'0')]++
	}
	for _,i:=range(arr) {
		fmt.Fprintf(writer,"%d\n",i)
	}
}	