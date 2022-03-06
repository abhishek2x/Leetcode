class MyQueue {
public:
    stack<int> input, output;
    
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int k = peek();
        output.pop();
        return k;
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};