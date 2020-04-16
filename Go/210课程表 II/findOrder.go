func findOrder(numCourses int, prerequisites [][]int) []int {
	res := make([]int, 0)
	edge := make([][]bool, numCourses)
	for index, _ := range edge {
		edge[index] = make([]bool, numCourses)
	}
	indegrees := make([]int, numCourses)
	for _, val := range prerequisites {
		edge[val[1]][val[0]] = true
		indegrees[val[0]]++
	}
	queue := make([]int, 0)
	for index, val := range indegrees {
		if val == 0 {
			queue = append(queue, index)
		}
	}

	for len(queue) != 0 {
		node := queue[0]
		queue = queue[1:]
		res = append(res, node)
		for i := 0; i <numCourses; i++ {
			if edge[node][i] {
				indegrees[i]--
				if indegrees[i] == 0 {
					queue = append(queue, i)
				}
			}
		}
	}

	if len(res) != numCourses {
		return []int{}
	}
	return res
}