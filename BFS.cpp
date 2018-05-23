#include <iostream>
#include <list>

class Node {
	public :

		std :: string label;
		Node * cameFrom;
		bool visited;
		std :: list <Node *> neighbours;

		Node(std :: string label) {
		 	this->label = label;
		 	cameFrom    = NULL;
		 	visited     = false;
		}

	static void addEdge(Node& source, Node& destination);
	static void doBFS(Node& root);
	static void getShortestPath(Node& source, Node& destination);

	bool operator == (Node& node) {
		return (this->label == node.label);
	}	
};

void Node :: addEdge(Node& source, Node& destination) {
	source.neighbours.push_back(&destination);
	destination.neighbours.push_back(&source);
}

void Node :: doBFS(Node& root) {
	
	std :: list <Node *> queue;
	std :: list <Node *> :: iterator i;
	Node * temp;
	queue.push_back(&root);
	root.visited = true;	
	while(!queue.empty()) {

		temp = queue.front();
		queue.pop_front();
		std :: cout << temp->label << " ";

		for(i = temp->neighbours.begin(); i != temp->neighbours.end() ; i++) {

			if((*i)->visited == false) {

				queue.push_back(*i);

				(*i)->cameFrom = temp;

				(*i)->visited = true;

			}
		}

	}
}

void Node :: getShortestPath(Node& root, Node& destination) {
	int flag = 0;
	std :: list <std :: string> path;
	path.push_back(destination.label);

	while(destination.cameFrom != NULL)  {
		destination = *(destination.cameFrom);
		path.push_back(destination.label);
		if(root == destination) {
			flag = 1;
			break;
		}
	}

	if(flag == 1) {
		path.reverse();
		std :: list <std :: string> :: iterator i;
		for(i = path.begin() ; i != path.end() ; i++) {
			std :: cout << (*i) << " ";
		}

	} else {

		std :: cout << "No Path Found!";
	}
}


int main() {
	Node a("A");
	Node b("B");
	Node c("C");
	Node d("D");
	Node e("E");
	Node f("F");

	Node :: addEdge(a,b);
	Node :: addEdge(a,c);
	Node :: addEdge(b,d);
	Node :: addEdge(c,d);
	Node :: addEdge(d,e);
	Node :: addEdge(b,f);
	Node :: addEdge(e,f);
	Node :: doBFS(a);
	std :: cout << std :: endl;
	Node :: getShortestPath(a,f);


}



