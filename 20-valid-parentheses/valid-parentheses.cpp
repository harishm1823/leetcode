class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // If stack is empty or top doesn't match current closing bracket
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop(); // Matching pair found
                } else {
                    return false; // Mismatched bracket types
                }
            }
        }

        // Return true only if all opening brackets were properly closed
        return st.empty();
    }
};