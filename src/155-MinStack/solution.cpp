class MinStack {
public:
    /** initialize your data structure here. */
    
    std::vector<int> v;
    int min;
    bool min_known;
    
    MinStack() {
        min_known = false;
    }
    
    // O(1)
    void push(int x) {
        if (v.size() == 0) {
            min = x;
        } else {
            if (x < min) {
                min = x;
            }
        }
        v.push_back(x);
    }
    
    // O(1)
    void pop() {
        if (min == v[v.size() - 1]) {
            min_known = false;
        }
        v.erase(v.begin() + v.size() - 1);
    }
    
    // O(1)
    int top() {
        return v[v.size() - 1];
    }
    
    // O(1) usually, worst case O(n)
    int getMin() {
        if (!min_known) {
            if (v.size() > 0) {
                min = v[0];
            }
            for (int i = 1; i < v.size(); i++) {
                if (v[i] < min) {
                    min = v[i];
                }
            }
            min_known = true;
        }
        return min;
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