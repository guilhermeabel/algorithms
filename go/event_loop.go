package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

type Task func()

type SimpleEventLoop struct {
	queue chan Task
	wg    sync.WaitGroup
}

type SemaphoreEventLoop struct {
	queue     chan Task
	semaphore chan struct{}
	wg        sync.WaitGroup
}

func NewSimpleEventLoop(size int) *SimpleEventLoop {
	return &SimpleEventLoop{
		queue: make(chan Task, size),
	}
}

func NewSemaphoreEventLoop(size int, maxParallelism int) *SemaphoreEventLoop {
	return &SemaphoreEventLoop{
		queue:     make(chan Task, size),
		semaphore: make(chan struct{}, maxParallelism),
	}
}

func (sel *SimpleEventLoop) Start() {
	go func() {
		for task := range sel.queue {
			go func(t Task) {
				defer sel.wg.Done()
				t()
			}(task)
		}
	}()
}

// func (oel *SemaphoreEventLoop) Start() {
// 	go func() {
// 		for task := range oel.queue {
// 			oel.semaphore <- struct{}{}
// 			go func(t Task) {
// 				defer oel.wg.Done()
// 				defer func() { <-oel.semaphore }()
// 				t()
// 			}(task)
// 		}
// 	}()
// }

func (oel *SemaphoreEventLoop) Start() {

}

func (sel *SimpleEventLoop) AddTask(task Task) {
	sel.queue <- task
	sel.wg.Add(1)
}

func (oel *SemaphoreEventLoop) AddTask(task Task) {
	oel.queue <- task
	oel.wg.Add(1)
}

func GetMaxParallelism() int {
	maxProcs := runtime.GOMAXPROCS(0)
	numCPU := runtime.NumCPU()
	if maxProcs < numCPU {
		return maxProcs
	}
	return numCPU
}

func RunEventLoop() {
	arr := make([]int, 1000000)

	sel := NewSimpleEventLoop(100)
	sel.Start()

	start := time.Now()
	for i := 0; i < 100; i++ {
		sel.AddTask(func() {
			NotIOBoundTask(arr)
		})
	}

	sel.wg.Wait()
	end := time.Now()

	fmt.Println("Simple Event Loop (NOT IO BOUND): ", end.Sub(start))

	sel = NewSimpleEventLoop(100)
	sel.Start()

	start = time.Now()
	for i := 0; i < 100; i++ {
		sel.AddTask(func() {
			IOBoundTask(arr)
		})
	}

	sel.wg.Wait()
	end = time.Now()

	fmt.Println("Simple Event Loop (IO BOUND): ", end.Sub(start))

	maxParallelism := GetMaxParallelism()

	oel := NewSemaphoreEventLoop(100, maxParallelism)
	oel.Start()

	start = time.Now()
	for i := 0; i < 100; i++ {
		oel.AddTask(func() {
			NotIOBoundTask(arr)
		})
	}
	end = time.Now()

	oel.wg.Wait()
	fmt.Println("Semaphore Event Loop (NOT IO BOUND): ", end.Sub(start))

	oel = NewSemaphoreEventLoop(100, maxParallelism)
	oel.Start()

	start = time.Now()
	for i := 0; i < 100; i++ {
		oel.AddTask(func() {
			IOBoundTask(arr)
		})
	}
	end = time.Now()

	oel.wg.Wait()
	fmt.Println("Semaphore Event Loop (IO BOUND): ", end.Sub(start))
}

func IOBoundTask(arr []int) {
	time.Sleep(time.Duration(100+time.Now().UnixNano()%200) * time.Millisecond)
}

func NotIOBoundTask(arr []int) {
	for i := 0; i < len(arr); i++ {
		arr[i] = arr[i] + 1
	}
}
