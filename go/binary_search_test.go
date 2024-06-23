package main

import "testing"

func TestBinarySearch(t *testing.T) {
	needle := 2
	haystack := []int{1, 2, 3, 4}

	exists, index := BinarySearch(needle, haystack, 0, len(haystack))
	if exists != true {
		t.Error("Expected to found value in haystack")
	}

	if *index != 1 {
		t.Error("Expected index to be 1")
	}

	haystack = []int{1, 3, 4, 5}
	exists, index = BinarySearch(needle, haystack, 0, len(haystack))
	if exists != false {
		t.Error("Expected not to found value in haystack")
	}

	if index != nil {
		t.Error("Expected index to be nil")
	}
}
