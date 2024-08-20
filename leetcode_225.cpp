Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.





  class MyStack {
    queue<pair<int, int>> q;
    int i=0;
public:
    MyStack() {}
        void push(int x)
        {
            q.push({x,i});
            i++;
        }
        int pop()
        {
            auto x=q.back();
            while(q.front() !=x)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
            return x.first;
        }
        int top()
        {
            return q.back().first;
        }
        bool empty()
        {
            return q.empty();
        }
        
    
    
   
        
    
};
