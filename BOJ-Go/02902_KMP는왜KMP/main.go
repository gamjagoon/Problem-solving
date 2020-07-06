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
	writer = bufio.NewWriter(os.Stdout)
	myfunc := func(data []byte, atEOF bool) (advance int,token[]byte,err error){
		for i := 0; i < len(data);i++{
			if data[i] == '-' {
				return i+1,data[:i],nil
			}
		}
		if !atEOF {
			return 0, nil,nil
		}
		return 0, data, bufio.ErrFinalToken
	}
	scanner.Split(myfunc)
}

func main() {
	defer writer.Flush()
	for scanner.Scan() {
		fmt.Fprintf(writer,"%c",scanner.Text()[0])
	}
}