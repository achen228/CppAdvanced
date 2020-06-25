//使用栈实现队列的下列操作：
//push(x) --将一个元素放入队列的尾部。
//pop() --从队列首部移除元素。
//peek() --返回队列首部的元素。
//empty() --返回队列是否为空。
//示例 :
//MyQueue queue = new MyQueue();
//queue.push(1);
//queue.push(2);
//queue.peek();  // 返回 1
//queue.pop();   // 返回 1
//queue.empty(); // 返回 false
//说明:
//你只能使用标准的栈操作 -- 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//假设所有操作都是有效的（例如，一个空的队列不会调用 pop 或者 peek 操作）。

#include <iostream>
#include <stack>
class MyQueue
{
public:
    MyQueue()
    {}

    void push(int x)
    {
        _pushst.push(x);
    }

    int pop()
    {
        //先判断popst栈中是否有元素，如果有直接删除，如果没有，将pushst栈中的元素搬移过去，再删除。
        IspopstEmpty();
        int ret = _popst.top();
        _popst.pop();
        return ret;
    }

    int peek()
    {
        //先判断popst栈中是否有元素，如果有直接返回，如果没有，将pushst栈中的元素搬移过去，再返回。
        IspopstEmpty();
        return _popst.top();
    }

    bool empty()
    {
        return _pushst.empty() && _popst.empty();
    }
private:
    void IspopstEmpty()
    {
        if (_popst.empty())
        {
            while (!_pushst.empty())
            {
                _popst.push(_pushst.top());
                _pushst.pop();
            }
        }
    }
private:
    std::stack<int> _pushst;
    std::stack<int> _popst;
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    int param_2 = obj->pop();
    printf("%d\n", param_2);
    int param_3 = obj->peek();
    printf("%d\n", param_3);
    bool param_4 = obj->empty();
    printf("%d\n", param_4);
    return 0;
}
