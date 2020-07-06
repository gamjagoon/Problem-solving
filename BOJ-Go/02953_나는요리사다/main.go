package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	defer writer.Flush()

	var res, val uint8 = 0, 0
	var tmp uint8
	for i := 1; i <= 5; i++ {
		var sum uint8 = 0
		for j := 0; j < 4; j++ {
			scanf("%d", &tmp)
			sum += tmp
		}
		scanf("\n")
		if val < sum {
			res = uint8(i)
			val = sum
		}
	}
	printf("%d %d", res, val)
}
