package main

import (
	"testing"
)

func TestCanPerformTrips(t *testing.T) {
	trips := [][]int{
		{2, 1, 3},
		{3, 3, 5},
	}

	result := CanPerformAllTrips(trips)
	if result != true {
		t.Errorf("Expected true but got %v", result)
	}
}

func TestCannotPerformTrips(t *testing.T) {
	trips := [][]int{
		{2, 1, 3},
		{3, 2, 5},
	}

	result := CanPerformAllTrips(trips)
	if result != false {
		t.Errorf("Expected false but got %v", result)
	}
}

func TestNumberOfPassengers(t *testing.T) {
	noDriver := []int{0, 2, 3}

	result := IsTripPossible(noDriver)
	if result != false {
		t.Errorf("Expected false but got %v", result)
	}

	carFull := []int{6, 2, 3}

	result = IsTripPossible(carFull)
	if result != false {
		t.Errorf("Expected false but got %v", result)
	}
}

func TestAlwaysForward(t *testing.T) {
	trip := []int{2, 2, 3}

	result := IsTripPossible(trip)
	if result != true {
		t.Errorf("Expected true but got %v", result)
	}

	backwardsTrip := []int{2, 3, 1}

	result = IsTripPossible(backwardsTrip)
	if result != false {
		t.Errorf("Expected false but got %v", result)
	}
}

func TestRoadLenght(t *testing.T) {
	tripTooLong := []int{3, 998, 1002}

	result := IsTripPossible(tripTooLong)
	if result != false {
		t.Errorf("Expected false but got %v", result)
	}
}
