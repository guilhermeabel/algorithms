package main

import "fmt"

type Node struct {
	value int
	next  *Node
}

type LinkedList struct {
	head *Node
}

func NewLinkedList() *LinkedList {
	return &LinkedList{}
}

func (list *LinkedList) AddToStart(val int) *LinkedList {
	node := Node{value: val}

	if list.head == nil {
		list.head = &node
		return list
	}

	node.next = list.head
	list.head = &node
	return list
}

func (list *LinkedList) DeleteByValue(val int) *LinkedList {
	// TODO
	// current := list.head
	// if current != nil && current.value == val {
	// 	return NewLinkedList()
	// }

	// for current != nil {
	// 	if current.value == val {

	// 	}

	// 	current = current.next
	// }
	return list
}

func (list *LinkedList) AddToEnd(val int) *LinkedList {
	current := list.head
	for current.next != nil {
		current = current.next
	}

	node := Node{value: val}
	current.next = &node

	return list
}

func (list *LinkedList) PrintList() {
	current := list.head
	for current != nil {
		fmt.Printf("%d -> ", current.value)
		current = current.next
	}
	fmt.Println("nil")
}

func LinkedListExample() {

	linkedList := NewLinkedList()

	linkedList.AddToStart(5)
	linkedList.AddToStart(1)
	linkedList.AddToStart(3)
	linkedList.AddToStart(7)

	linkedList.AddToEnd(100)

	linkedList.PrintList()

}
