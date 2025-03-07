class MinStack {
public:
    vector<int> st;
    vector<int> minSt;

    MinStack() {
        st={};
        minSt = {};
    }
    
    void push(int val) {
        st.push_back(val);
        // Push to minSt only if it's empty or val is the new minimum
        if(minSt.empty() || val <= minSt.back()){
            minSt.push_back(val);
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        //if popping the current min, remove it from the minSt
        if(st.back()==minSt.back()) minSt.pop_back();
        st.pop_back();//removes the last element
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.back();//to access the last element in the vector
    }
    
    int getMin() {
        if(minSt.empty()) return -1;
        return  minSt.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */