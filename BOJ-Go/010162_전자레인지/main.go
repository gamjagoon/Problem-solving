package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner *bufio.Scanner
var writer *bufio.Writer
var result int

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

func main() {
	defer writer.Flush()
	T := nextInt()
	arr := [3]int{0,0,0}
	arr[0] = T / 300
	T -= arr[0] * 300
	arr[1] = T / 60
	T -= arr[1] * 60
	arr[2] = T / 10
	T -= arr[2] * 10

	if T == 0 {
		fmt.Fprintf(writer,"%d %d %d",arr[0],arr[1],arr[2])
	} else {
		fmt.Fprint(writer,"-1")
	}
}