class MyStack {
public:
    queue<int> q;
    int tp;
    MyStack() {
        tp=0;
    }
    
    void push(int x) {
        q.push(x);
        tp++;
    }
    
    int pop() {
        int tp1 = tp;
        while(tp1 > 1) {
            int e = q.front();
            q.pop();
            q.push(e);
            tp1--;
        }
        int TopEle = q.front();
        q.pop(); tp--;
        return TopEle;
    }
    
    int top() {
        int tp1 = tp;
        while(tp1 > 1) {
            int e = q.front();
            q.pop();
            q.push(e);
            tp1--;
        }
        int TopEle = q.front();
        q.pop();
        q.push(TopEle);
        return TopEle;
    }
    
    bool empty() {
        return tp == 0;
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