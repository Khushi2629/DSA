Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.







class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;
        unordered_map<Node*, Node*>mpp;
        queue<Node*> q;
        q.push(node);
        Node* newNode=new Node(node->val);
        mpp[node]=newNode;
        while(q.empty()==false){
            Node* cur=q.front();
            q.pop();
            for(auto it: cur->neighbors){
                if (mpp.find(it)== mpp.end()){
                    q.push(it);
                    Node* newNode=new Node(it->val);
                    mpp[it]=newNode;
                }
                mpp[cur]->neighbors.push_back(mpp[it]);
            }
        }
        return mpp[node];
        
    }
};
