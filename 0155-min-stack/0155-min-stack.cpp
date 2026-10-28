class MinStack {
private:
    stack<long long> s;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int value) {
        if (s.empty()) {
            s.push(value);
            mini = value;
        } else {
            if (value < mini) {
                long long val = 2LL * value - mini;
                s.push(val);
                mini = value;
            } else {
                s.push(value);
            }
        }
    }

    void pop() {
        long long curr = s.top();
        s.pop();

        if (curr < mini) {
            mini = 2LL * mini - curr;
        }
    }

    int top() {
        long long curr = s.top();

        if (curr < mini) {
            return static_cast<int>(mini);
        }

        return static_cast<int>(curr);
    }

    int getMin() {
        return static_cast<int>(mini);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */