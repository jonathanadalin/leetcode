class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char* cstr = new char [s.length() + 1];
        std::strcpy (cstr, s.c_str());
        for (int i = 0; i < s.length(); i++) {
            switch (cstr[i]) {
                case '(':
                case '{':
                case '[':
                    st.push(cstr[i]);
                    break;
                case ')':
                    if (st.empty()) {
                        return false;
                    }
                    if (st.top() != '(') {
                        return false;
                    }
                    st.pop();
                    break;
                case '}':
                    if (st.empty()) {
                        return false;
                    }
                    if (st.top() != '{') {
                        return false;
                    }
                    st.pop();
                    break;
                case ']':
                    if (st.empty()) {
                        return false;
                    }
                    if (st.top() != '[') {
                        return false;
                    }
                    st.pop();
                    break;
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};