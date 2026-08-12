#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> st;
        std::stringstream ss(path);
        std::string token;

        // Split string by '/'
        while (std::getline(ss, token, '/')) {
            // Ignore empty strings and current directory '.'
            if (token == "" || token == ".") {
                continue;
            }
            
            // Go up one directory if possible
            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                // Push valid directory/file name
                st.push_back(token);
            }
        }

        // Construct canonical path
        std::string result = "";
        for (const std::string& dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};