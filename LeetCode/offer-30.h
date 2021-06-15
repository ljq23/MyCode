#ifndef OFFER-30_H_INCLUDED
#define OFFER-30_H_INCLUDED

/*
    MinStack s;
    s.push(2147483646);
    s.push(2147483646);
    s.push(2147483647);
    cout << s.top() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    s.push(2147483647);
    s.top();
    cout << s.min() << endl;
    s.push(-2147483648);
    cout << s.top() << endl;
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.print();
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    bool flag = true;
    int minval;
    MinStack() {}

    void push(int x) {
        if(flag){
            minval = x;
            flag = false;
        }else{
            if(x<=minval){
                s.push(minval);
                minval = x;
            }
        }
        s.push(x);
    }

    void pop() {
        if(minval==s.top()){
            s.pop();
            if(s.size()==0){
                flag=true;
                return;
            }
            minval = s.top();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return minval;
    }

    void print(){
        cout << "_______________\n";
        while(s.size()){
            cout << s.top() << endl;
            s.pop();
        }
    }
};

#endif // OFFER-30_H_INCLUDED
