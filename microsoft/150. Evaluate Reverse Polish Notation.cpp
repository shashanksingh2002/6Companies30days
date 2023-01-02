class Solution {
public:
    string operation(stack<string> &st){
        string op = st.top();
        st.pop();
        int op2 = stoi(st.top());
        st.pop();
        int op1 = stoi(st.top());
        st.pop();
        if(op=="*"){
            return to_string(op1*op2);
        } if(op=="/"){
            return to_string(op1/op2);
        } if(op=="-"){
            return to_string(op1-op2);
        } if(op=="+"){
            return to_string(op1+op2);
        }
        return "\0";
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            st.push(tokens[i]);
            if(st.top()=="+"){
                st.push(operation(st));
            } else if(st.top()=="-"){
                st.push(operation(st));
            } else if(st.top()=="/"){
                st.push(operation(st));
            } else if(st.top()=="*"){
                st.push(operation(st));
            }
        }
        return stoi(st.top());
    }
};
