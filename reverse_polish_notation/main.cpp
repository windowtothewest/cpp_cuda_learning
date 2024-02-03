#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <unordered_map>
#include <functional>

float reverse_polish_notation(std::string rpn_expression) {
    int str_length = rpn_expression.length();
    float result = 0;
    std::stack<float> rpnStack; // Initialize the stack 
    using OperatorFunction = std::function<float(float, float)>;
    std::unordered_map <char, OperatorFunction> operatorMap; // Initialize map function
    // Just supporting these for the time being
    operatorMap['+'] = [](float a, float b) -> float { return a + b; }; 
    operatorMap['-'] = [](float a, float b) -> float { return b - a; };
    operatorMap['*'] = [](float a, float b) -> float { return a * b; };
    operatorMap['/'] = [](float a, float b) -> float { return b / a; };

    for (int i = 0; i <= str_length + 1; i++) {
        // By selecting a single element of the std::string, the type must be char not std::string
        char currentChar = rpn_expression[i]; 
        if (currentChar == ' ') { // There is a difference btwn ' ' and " " rip Python devs
            continue;
        }
        else if (isdigit(currentChar)) {
            std::string numberStr = "";
            int j = i;
            while (isdigit(rpn_expression[j]) && j < str_length - 1) {
                numberStr += rpn_expression[j];
                j++;
            }
            float number = std::stof(numberStr);
            rpnStack.push(number);
        }
        else if (operatorMap.count(currentChar) > 0) {
            if (rpnStack.size() < 2) {
                throw std::runtime_error("Invalid RPN expression");
            };
            float a = rpnStack.top();
            rpnStack.pop();
            float b = rpnStack.top();
            rpnStack.pop();
            rpnStack.push(operatorMap[currentChar](a, b));
        };
    }
    result = rpnStack.top();
    return result;
};

int main() {
    std::string rpn_expression = "3 4 + 2 - 1 +";
    std::string output = "Evaluted expression: ";
    std::cout << output << reverse_polish_notation(rpn_expression) << std::endl;
    return 0;
}