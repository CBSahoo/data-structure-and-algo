unordered_map<Node*, Node*> visited;
Node* cloneGraph(Node* node) {
    // DFS
    /*
    if(node == NULL) return NULL;

    if(visited[node]) return visited[node];

    Node *clone = new Node(node->val);
    visited[node] = clone;

    for(auto neighbourNode: node->neighbors) {
        clone->neighbors.push_back(cloneGraph(neighbourNode));
    }

    return clone;
    */

    //BFS
    if(node == NULL) return node;

    queue<Node*> q;
    q.push(node);

    visited[node] = new Node(node->val);

    while(!q.empty()) {
        //int n = q.size();
        Node* curr = q.front();
        q.pop();

        for(auto nei: curr->neighbors) {
            if(!visited[nei]) {
                visited[nei] = new Node(nei->val);
                q.push(nei);
            }

            visited[curr]->neighbors.push_back(visited[nei]);
        }
    }

    return visited[node];
}
