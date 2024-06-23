package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Run() {

	size := 1_000_000
	haystack := make([]int, 0, size)
	needles := make([]int, 0, size)
	runs := 1000

	for i := 0; i < size; i++ {
		haystack = append(haystack, i)
		needles = append(needles, randomInt(0, size))
	}

	start := time.Now()
	for i := 0; i < runs; i++ {
		_, _ = ScanSearch(needles[i], haystack)
	}
	end := time.Now()

	fmt.Println("ScanSearch time: ", end.Sub(start))

	start = time.Now()
	for i := 0; i < runs; i++ {
		_, _ = BinarySearch(needles[i], haystack, 0, size)
	}
	end = time.Now()

	fmt.Println("BinarySearch time: ", end.Sub(start))
}

func ScanSearch(needle int, haystack []int) (bool, *int) {
	for i, val := range haystack {
		if val == needle {
			return true, &i
		}
	}

	return false, nil
}

func BinarySearch(needle int, haystack []int, low int, high int) (bool, *int) {
	idx := int((high + low/2) / 2)
	midVal := haystack[idx]
	if needle == midVal {
		return true, &idx
	}

	if idx == high || idx == low {
		return false, nil
	}

	if needle < midVal {
		return BinarySearch(needle, haystack, low, idx)
	}

	return BinarySearch(needle, haystack, idx, high)
}

func randomInt(min, max int) int {
	return rand.Intn(max-min+1) + min
}
