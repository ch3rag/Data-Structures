from collections import deque

graph = {}
graph["START"] = ["A","B"]
graph["A"]     = ["C","FINISH"]
graph["B"]     = ["C", "D"]
graph["C"]	   = ["E"]
graph["D"]	   = ["FINISH"]
graph["FINISH"]	   = []
graph["E"]         = []



def BFS (startingNode, destinationNode) :
	queue = deque()
	cameFrom = {}
	searched = []
	queue += graph[startingNode]
	cameFrom[startingNode] = None
	for n in graph[startingNode] :
		cameFrom[n] = startingNode
	while queue :
		node = queue.popleft()
		if not node in searched :
			if node == destinationNode :
				path = []
				while not node == None :
					path.append(node)
					node = cameFrom[node]
				path.reverse()
				return path

			else :
				for n in graph[node] :
					cameFrom[n] = node
				queue += graph[node]
				searched.append(node)
	return []			


print BFS("START", "FINISH")
print BFS("START", "E")
