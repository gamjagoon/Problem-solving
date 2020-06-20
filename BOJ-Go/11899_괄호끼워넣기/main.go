package main

import (
	"bufio"
	"fmt"
	"os"
)

var Scanner *bufio.Scanner

func init() {
	Scanner = bufio.NewScanner(os.Stdin)
	Scanner.Split(bufio.ScanLines)
}

func readline() []byte {
	Scanner.Scan()
	ret := Scanner.Bytes()
	return ret
}

func main() {
	input := readline()
	mstack := []byte{}
	sz := 0
	for _, ch := range input {
		if sz > 0 && mstack[sz-1] == '(' && ch == ')' {
			mstack = mstack[0 : sz-1]
			sz--
		} else {
			mstack = append(mstack, ch)
			sz++
		}
	}
	fmt.Print(len(mstack))
}
