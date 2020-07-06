package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
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
	res := make([]val,10,10)
	for i := range res{
		res[i].value = nextInt()
		if i > 0 {
			res[i].value += res[i-1].value
		}
		res[i].dif = 100 - res[i].value
		if res[i].dif < 0 {
			res[i].dif *= -1
		}
	}
	sort.Slice(res,func(i, j int)bool {
		if(res[i].dif == res[j].dif) {
			return res[i].value > res[j].value
		}
		return res[i].dif < res[j].dif
	})
	fmt.Fprintf(writer,"%d",res[0].value)
}