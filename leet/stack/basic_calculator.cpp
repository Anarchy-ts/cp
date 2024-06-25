#include <iostream>
#include <stack>
#include <string>

class BasicCalculator {
public:
    int calculate(std::string s) {
        std::stack<int> stk;
        int result = 0;
        int number = 0;
        int sign = 1; // 1 means positive, -1 means negative

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (ch == '(') {
                // Push the current result and sign onto the stack
                stk.push(result);
                stk.push(sign);
                // Reset result and sign for the new sub-expression
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * number;
                number = 0;
                // Pop the sign and result from the stack
                result *= stk.top(); // sign
                stk.pop();
                result += stk.top(); // previous result
                stk.pop();
            }
        }

        // Add the last number to the result
        result += sign * number;
        return result;
    }
};

int main() {
    BasicCalculator calculator;
    std::string expression1 = "1 + 1";
    std::string expression2 = " 2-1 + 2 ";
    std::string expression3 = "(1+(4+5+2)-3)+(6+8)";
    
    std::cout << calculator.calculate(expression1) << std::endl; // Output: 2
    std::cout << calculator.calculate(expression2) << std::endl; // Output: 3
    std::cout << calculator.calculate(expression3) << std::endl; // Output: 23
    
    return 0;
}
