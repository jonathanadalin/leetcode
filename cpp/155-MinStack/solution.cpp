class MinStack {
public:
    /** initialize your data structure here. */
    
    std::vector<int> v;
    std::stack<int> min;
    
    MinStack() {

    }
    
    // O(1)
    void push(int x) {
        if (v.size() == 0) {
            min.push(x);
        } else {
            if (x <= min.top()) {
                min.push(x);
            }
        }
        v.push_back(x);
    }
    
    // O(1)
    void pop() {
        if (min.top() == v[v.size() - 1]) {
            min.pop();
        }
        v.erase(v.begin() + v.size() - 1);
    }
    
    // O(1)
    int top() {
        return v[v.size() - 1];
    }
    
    // O(1)
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */