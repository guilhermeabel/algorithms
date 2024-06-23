package main

// There is a car with a certain number of seats that only drives forward in a single road 1000km long.

// You are given the capacity of the car and an array of trips in which each trip has:
// - The number of passengers
// - The pick-up location
// - The drop-off location

// Example: given the trip [2,1,5], it means that 2 passengers will be picked up at 1st km and dropped off at 5th.
// Write a function that answers whether this car is able to comply with all the given trips.

// My questions:
// Are the passengers accounting for the driver? ie: should we allow a total of 5 passengers, or 4 passengers (because the driver is not a passenger)

func CanPerformAllTrips(unorderedTrips [][]int) bool {
	trips := OrderByPickup(unorderedTrips)

	for i, lastStop := 0, 0; i < len(trips); i++ {
		if trips[i][1] < lastStop {
			return false
		}

		if !IsTripPossible(trips[i]) {
			return false
		}

		lastStop = trips[i][2]
	}

	return true
}

func OrderByPickup(trips [][]int) [][]int {

	for i := 0; i < len(trips); i++ {
		for j := i + 1; j < len(trips); j++ {
			if trips[i][1] > trips[j][1] {
				trips[i], trips[j] = trips[j], trips[i]
			}
		}
	}

	return trips
}

func IsTripPossible(trip []int) bool {
	if trip[0] < 1 || trip[0] > 5 {
		return false
	}

	if trip[2] < trip[1] {
		return false
	}

	if trip[2] > 1000 {
		return false
	}

	return true
}
