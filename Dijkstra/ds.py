
#from __future__ import print_function

graph = {}

graph["START"] = {}
graph["A"] = {}
graph["B"] = {}
graph["FINISH"] = {}

graph["START"]["A"] = 6
graph["START"]["B"] = 2
graph["A"]["FINISH"] = 1
graph["B"]["A"] = 3
graph["B"]["FINISH"] = 5 

costs = {}
parent = {}
processed = []

def getLowestCostNode() :
	lowest_cost = float("inf")
	lowest_cost_node = None
	for node in costs :
		cost = costs[node]
		if lowest_cost > cost and not node in processed :
			lowest_cost = cost
			lowest_cost_node = node
	return lowest_cost_node
			

def DIJKSTRA (starting_node) :
	for node in graph[starting_node].keys() :
		costs[node] = graph[starting_node][node]
	for node in graph[starting_node].keys() :
		parent[node] = starting_node
	node = getLowestCostNode()
	while node :
		for neighbour, weight in graph[node].items() :
			newCost = weight + costs[node]
			if not costs.get(neighbour) :
				costs[neighbour] = newCost
				parent[neighbour] = node
			elif newCost < costs[neighbour] :
				costs[neighbour] = newCost
				parent[neighbour] = node
 		processed.append(node)
		node = getLowestCostNode()		


def printPath(starting_node, destination_node) :
		path = []
		node = destination_node
		while not node == starting_node :
			if not parent.get(node) :
				print "No Path!"
				return
			path.append(node)
			node = parent[node]
		path.append(starting_node)
		path.reverse()
		for node in path :
			print "{} -->".format(node),
		print "DONE!"	

DIJKSTRA("START")
printPath("FINISH", "START")

