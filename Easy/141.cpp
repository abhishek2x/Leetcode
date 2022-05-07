class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        while(size > 1) {
            int ele = q.front();
            q.pop();
            q.push(ele);
            size--;
        }
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        int ele;
        int size = q.size();
        while(size > 0) {
            ele = q.front();
            q.pop();
            q.push(ele);
            size--;
        }
        return ele;
    }
    
    bool empty() {
        return q.size() != 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */