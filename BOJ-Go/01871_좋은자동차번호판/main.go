package main

import (
	"bufio"
	"fmt"
	"os"
)
var sccanner *bufio.Scanner

func init() {
  sccanner = bufio.NewScanner(os.Stdin)
  sccanner.Split(bufio.ScanWords)
}

func calc(line []byte) int {
  A,B,intFlag := 0,0,false
  for _, c := range line {
    if intFlag {
      B *= 10
      B += int(c-'0')
    }else{
      if c == '-'{
        intFlag = true
        continue
      }
      A *= 26
      A += int(c) - 'A'
    }
  }
  return A - B
}

func main() {
  sccanner.Scan()
  bytes := sccanner.Bytes()
  num := 0
  for _, j := range bytes {
    num *= 10
    num += int(j - '0')
  }
  var res int = 0
  for i := 0; i < num; i++ {
    sccanner.Scan()
    res = calc(sccanner.Bytes())
    if res <= 100 && res >= -100 {
      fmt.Println("nice")
    } else{
      fmt.Println("not nice")
    }
  }
}