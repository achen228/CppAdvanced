class MinStack {
public:
    // 维持两个栈中的元素数量相等
    // 辅助栈顶中存放数据栈中的最小元素
    stack<int> data, help;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        // 如果辅助栈为空或者x小于辅助栈的最小元素
        if(help.empty() || x <= help.top())
        {
            help.push(x);
        }
        else
        {
            // 否则将辅助栈顶的最小元素再插入一遍，维持两个栈中的元素数量不变
            int tmp = help.top();
            help.push(tmp);
        }
    }
    
    void pop() {
        if(!data.empty() && !help.empty())
        {
            data.pop();
            help.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return help.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
