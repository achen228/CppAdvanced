class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st1.empty())
        {
            return -1;
        }

        while(!st1.empty())
        {
            int tmp = st1.top();
            st1.pop();
            st2.push(tmp);
        }

        int ret = st2.top();
        st2.pop();
        while(!st2.empty())
        {
            int tmp = st2.top();
            st2.pop();
            st1.push(tmp);
        }

        return ret;
    }

    stack<int> st1;
    stack<int> st2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
