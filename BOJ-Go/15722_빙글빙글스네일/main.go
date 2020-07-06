package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
  scanner := bufio.NewScanner(os.Stdin)
  scanner.Split(bufio.ScanWords)
  scanner.Scan()
  word := scanner.Bytes()
  N := 0
  for _, c := range word {
    N *= 10
    N += int(c - '0')
  }
  x, y, v := 0,0,1
  flag := false
  for {
    for i := 0; i < v; i++{
      y++
      N--
      if N == 0{
        flag = true
        break
      }
    }
    if flag {
      break
    }
    for i := 0; i < v; i++ {
      x++
      N--
      if N == 0{
        flag = true
        break
      }
    }
    if flag {
      break
    }
    v++
    for i := 0; i < v; i++ {
      y--
      N--
      if N == 0{
        flag = true
        break
      }
    }
    if flag {
      break
    }
    for i := 0; i < v; i++ {
      x--
      N--
      if N == 0{
        flag = true
        break
      }
    }
    if flag {
      break
    }
    v++
  }
  fmt.Printf("%d %d",x,y)
}