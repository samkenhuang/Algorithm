#include "../../util/stl.h"

class MinStack {
private:
    stack<int> s;
    stack<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (!mins.empty()) {
            int currMin = mins.top();
            s.push(x);
            if (currMin > x) currMin = x;
            mins.push(currMin);
        } else {
            s.push(x);mins.push(x);
        }
        
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

int main() {
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;   // -3
    minStack->pop();
    cout << minStack->top() << endl;      // 0
    cout << minStack->getMin() << endl;   // -2
    return 0;
}