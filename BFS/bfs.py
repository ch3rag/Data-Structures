from collections import deque
graph = {}

graph["START"] = ["A", "B"]

graph["A"] = ["FINISH"]

graph["B"] = ["A", "FINISH"]

graph["FINISH"] = []

def BFS(starting_node, destination_node) :
	searched = []
	cameFrom = {}
	queue    = deque()
	cameFrom[starting_node] = None
	for n in graph[starting_node] :
		cameFrom[n] = starting_node
	queue += graph[starting_node]
	while queue :
		node = queue.popleft()
		if node not in searched :
			if node == destination_node :
				path = []
				while node :
					path.append(node)
					node = cameFrom[node]
				path.reverse()
				return path
			else :
				for n in graph[node] :
					if not cameFrom.get(n) :
						cameFrom[n] = node
				queue += graph[node]
				searched.append(node)
	return []
	
print BFS ("START", "FINISH")					
