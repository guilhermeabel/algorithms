package main

import (
	"fmt"
	"math"
	"time"
)

func RunTwoCrystalBalls() {
	floors := []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1}

	start := time.Now()
	found, index := MyImplementationTwoCrystalBalls(floors)
	end := time.Now()
	if found {
		fmt.Printf("My implementation: %d, time: %s \n", index, end.Sub(start))
	}

	start = time.Now()
	found, index = ScanForComparison(floors)
	end = time.Now()

	if found {
		fmt.Printf("Scan for comparison: %d, time: %s \n", index, end.Sub(start))
	}

}

func MyImplementationTwoCrystalBalls(floors []int) (bool, int) {
	jumpBy := int(math.Sqrt(float64(len(floors))))
	limit := len(floors) - jumpBy
	for jumpTo := jumpBy; jumpTo < limit; {
		if floors[jumpTo] == 1 {
			lastJump := jumpTo - jumpBy
			for j := lastJump; j < jumpTo; j++ {
				if floors[j] == 1 {
					return true, j
				}
			}
			break
		}
		jumpTo += jumpBy
	}

	return false, -1
}

func ScanForComparison(floors []int) (bool, int) {
	for i, floor := range floors {
		if floor == 1 {
			return true, i
		}
	}

	return false, -1
}
