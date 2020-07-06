package main

import (
	"bufio"
	"fmt"
	"os"
)


func Reverse(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}

func main() {
  scanner := bufio.NewScanner(os.Stdin)
  scanner.Split(bufio.ScanLines)
  scanner.Scan()
  line := scanner.Text()
  res := ""
  for i := 0; i < len(line); i++ {
    res += "z"
  }
  substrs := make([]string,3)
  for i := 1; i < len(line); i++ {
    for j:= i+1; j < len(line); j++{
      substrs[0] = Reverse(line[:i])
      substrs[1] = Reverse(line[i:j])
      substrs[2] = Reverse(line[j:])
      str := substrs[0] + substrs[1] + substrs[2]
      if str < res {
        res = str
      }
    }
  }
  fmt.Printf("%s",res)
}