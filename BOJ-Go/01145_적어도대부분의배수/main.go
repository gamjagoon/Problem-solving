package main

import (
	"bufio"
	"fmt"
	"os"
)

var sc *bufio.Scanner

func init () {
  sc = bufio.NewScanner(os.Stdin)
  sc.Split(bufio.ScanWords)
}

func nextInt() int{
  sc.Scan()
  word := sc.Bytes()
  num := 0
  for _, i := range word {
    num *= 10
    num += int(i - '0')
  }
  return num
}

func gcd(a,b int) int{
  for b!= 0 {
    r := a % b
    a = b
    b = r
  }
  return a
}

func main() {
  data := make([]int,5,5)
  for i := 0; i < 5; i++ {
    data[i] = nextInt()
  }
  res := 987654321
  for i := 0; i < 5; i++ {
    for j := i+1; j < 5; j++ {
        tmp := data[i] * data[j] / (gcd(data[i],data[j]))
          for k := j+1; k < 5; k++ {
              lcm := data[k] * tmp / (gcd(data[k], tmp))
              if res > lcm {
                  res = lcm
              }
          }
    }
  }
  fmt.Println(res)

}
