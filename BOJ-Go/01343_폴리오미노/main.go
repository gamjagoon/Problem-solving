package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
}

func main() {
	scanner.Scan()
	line := scanner.Bytes()
	result := make([]string,0)
	cnt,L,flag := 0,len(line),true
	for i := 0; i < L; i++{
		if line[i] == 'X'{
			cnt++
		} else {
			if cnt % 2 == 0{
				j := cnt / 4
				cnt -= j * 4
				for k:= 0; k < j;k++{
					result = append(result,"AAAA")
				} 
				if cnt != 0 {
					result = append(result,"BB")
				}
				result = append(result,".")
				cnt = 0
			} else {
				flag = false
				break
			}
		}
	}
	if cnt % 2 == 0{
		j := cnt / 4
		cnt -= j * 4
		for k:= 0; k < j;k++{
			result = append(result,"AAAA")
		} 
		if cnt != 0 {
			result = append(result,"BB")
		}
	} else {
		flag = false
	}
	if flag {
		for _, str := range result{
			fmt.Print(str)
		}
	} else{
		fmt.Print("-1")
	}
}