package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	Scanner := bufio.NewScanner(os.Stdin)
	res := 0
	Scanner.Split(bufio.ScanLines)
	Scanner.Scan()
	input := Scanner.Bytes()
	cnt := 0
	for _, c := range(input){
		if c <= '9' && c >= '0' {
			cnt++
			continue
		} else if c == ',' && cnt != 0{
			res++
			cnt = 0
		} else {
			cnt = 0
		}
	}
	if cnt != 0 {
		res++
	}
	fmt.Printf("%d",res)
}	