class Node{
    public:
    string data;
    Node *next;
    Node *prev;
    Node(): data(0),next(nullptr),prev(nullptr){};
    Node(string x):data(x),next(nullptr),prev(nullptr){}
    Node(string x,Node *next,Node *random):data(x),next(next),prev(random){}
};
class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current=new Node(homepage);
    }
    
    void visit(string url) {
        Node *newNode=new Node(url);
        current->next=newNode;
        newNode->prev=current;
        current=newNode;
    }
    
    string back(int steps) {
        while(steps){
            if(current->prev)
                current=current->prev;
            else
                break;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(current->next)
                current=current->next;
            else
                break;
            steps--;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */