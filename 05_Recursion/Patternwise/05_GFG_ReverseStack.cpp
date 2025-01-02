/*Almost all same logic for recursion...especially stack..*/

class Solution {
private:
    void insertEle(stack<int>& st, int ele) {
        if (st.empty()) {
            st.push(ele);
            return;
        }
        int top = st.top();
        st.pop();

        insertEle(st, ele);  //not top insert..silly
        st.push(top);
    }

public:
    void Reverse(stack<int>& st) {
        // base case

        if (st.empty()) {
            return;
        }

        int top = st.top();
        st.pop();

        Reverse(st);
        insertEle(st, top);
    }
};
