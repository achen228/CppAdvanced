//最小栈
//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//push(x) —— 将元素 x 推入栈中。
//pop() —— 删除栈顶的元素。
//top() —— 获取栈顶元素。
//getMin() —— 检索栈中的最小元素。
#include <iostream>
#include <stack>
using namespace std;
class MinStack
{
public:
    MinStack()
    {}

    void push(int x)
    {
        _st.push(x);
        if (_minst.empty() || _minst.top() >= x)
        {
            _minst.push(x);
        }
    }

    void pop()
    {
        if (_st.top() == _minst.top())
        {
            _minst.pop();
        }
        _st.pop();
    }

    int top()
    {
        return _st.top();
    }

    int getMin()
    {
        return _minst.top();
    }
private:
    stack<int> _st;
    stack<int> _minst;
};
