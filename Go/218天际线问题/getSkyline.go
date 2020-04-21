package main

import (
	"container/heap"
	"sort"
)

func getSkyline(buildings [][]int) [][]int {
	res := make([][]int, 0)

	pointArr := make(points, 0, len(buildings)*2)
	heightpNode := make(map[int]*height, 0)
	i := 0
	for _, val := range buildings {
		pointArr = append(pointArr, point{x: val[0], y: -val[2], id: i})
		pointArr = append(pointArr, point{x: val[1], y: val[2], id: i + 1})
		h := &height{height: val[2]}
		heightpNode[i] = h
		heightpNode[i+1] = h
		i += 2
	}
	sort.Sort(pointArr)
	heightHeap := new(myheap)
	zero := &height{height: 0}
	heap.Push(heightHeap, zero)
	curH := 0
	for _, val := range pointArr {
		if val.y < 0 {
			heap.Push(heightHeap, heightpNode[val.id])
		} else {
			heap.Remove(heightHeap, heightpNode[val.id].index)
		}
		if curH != (*heightHeap)[0].height {
			res = append(res, []int{val.x, (*heightHeap)[0].height})
			curH = (*heightHeap)[0].height
		}
	}
	return res
}

type point struct {
	x  int
	y  int
	id int
}
type points []point

func (a points) Len() int      { return len(a) }
func (a points) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a points) Less(i, j int) bool {
	if a[i].x != a[j].x {
		return a[i].x < a[j].x
	}
	return a[i].y < a[j].y
}

type height struct {
	height int
	index  int
}
type myheap []*height

func (h myheap) Len() int           { return len(h) }
func (h myheap) Less(i, j int) bool { return h[i].height > h[j].height }
func (h myheap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
	h[i].index = i
	h[j].index = j
}
func (h *myheap) Push(v interface{}) {
	e := v.(*height)
	e.index = h.Len()
	*h = append(*h, e)
}
func (h *myheap) Pop() (v interface{}) {
	*h, v = (*h)[0:len(*h)-1], (*h)[len(*h)-1]
	return
}

func main() {
}
