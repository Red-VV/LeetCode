package main

func canFinish(numCourses int, prerequisites [][]int) bool {
	edge := make([][]bool, numCourses)
	for index := range edge {
		edge[index] = make([]bool, numCourses)
	}
	for _, val := range prerequisites {
		edge[val[0]][val[1]] = true
	}

	indegrees := make([]int, numCourses)
	for _, val := range prerequisites {
		indegrees[val[1]]++
	}

	cnt := 0
	queue := make([]int, 0)
	for index, val := range indegrees {
		if val == 0 {
			queue = append(queue, index)
			cnt++
		}
	}

	for len(queue) != 0 {
		node := queue[0]
		queue = queue[1:]
		for i := 0; i < numCourses; i++ {
			if edge[node][i] {
				indegrees[i]--
				if indegrees[i] == 0 {
					queue = append(queue, i)
					cnt++
				}
			}
		}
	}
	return cnt == numCourses
}

func main() {
	cnt := 2
	arr := make([][]int, 0)
	arr = append(arr, make([]int, 2))
	arr[0][0] = 1
	arr[0][1] = 0
	canFinish(cnt, arr)
}
