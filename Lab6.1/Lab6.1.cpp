#include <stack>
#include <iostream>
#include <string>

int main()
{
	std::stack<char> st;

    std::string expr;
    std::cout << "Input expression:";
    std::cin >> expr;
    for (int i = 0; i < expr.size(); i++) {
        switch (expr[i]) {
        case '(':
            st.push(expr[i]);
            break;
        
        case '[':
            st.push(expr[i]);
            break;
        
        case '{':
            st.push(expr[i]);
            break;

        case ')':
            if (st.top() == '(')
                st.pop();
            else {
                std::cout << "Incorrect expression\n";
                return 0;
            }
            break;
            
        case ']':
            if (st.top() == '[')
                st.pop();
            else {
                std::cout << "Incorrect expression\n";
                return 0;
            }
            break;

        case '}':
            if (st.top() == '{')
                st.pop();
            else {
                std::cout << "Incorrect expression\n";
                return 0;
            }
            break;

        }
    }
    if (!st.empty())
        std::cout << "Incorrect expression\n";
    else
        std::cout << "Correct expression\n";
    return 0;
}


