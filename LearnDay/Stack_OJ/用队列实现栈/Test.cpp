//用队列实现栈
//使用队列实现栈的下列操作：
//push(x) --元素x入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :
//你只能使用队列的基本操作--也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。你可以使用list或者deque（双端队列）来模拟一个队列,只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用pop或者top操作）。

#include <iostream>
#include <queue>
class MyStack
{
public:
    MyStack()
    {}

    void push(int x)
    {
        if (!q1.empty())
        {
            q1.push(x);
        }
        else
        {
            q2.push(x);
        }
    }

    int pop()
    {
        if (!q1.empty())
        {
            while (q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            int top = q1.front();
            q1.pop();
            return top;
        }
        else
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            int top = q2.front();
            q2.pop();
            return top;
        }
    }

    int top()
    {
        if (!q1.empty())
        {
            return q1.back();
        }
        else
        {
            return q2.back();
        }
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
private:
    std::queue<int> q1;
    std::queue<int> q2;
};

int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);

    int param_2 = obj->pop();
    printf("%d\n", param_2);

    int param_3 = obj->top();
    printf("%d\n", param_3);

    bool param_4 = obj->empty();
    printf("%d\n", param_4);

    delete obj;
    return 0;
}
