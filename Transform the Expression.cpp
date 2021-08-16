/** PROBLEM: ONP - Transform the Expression
  * LINK: https://www.spoj.com/problems/ONP/
  *
  * AUTHOR: Nikola Mircic
  * PROFILE: https://github.com/Nikola-Mircic
  */

#include <iostream>
#include <string>
#include <vector>


bool isSign(char c){
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^');
}

std::string toRPN(std::string input){
    std::string result = "";
    std::vector<std::string> signs; // Vector to store indices of +,-,*,/,^ signs
    std::vector<std::string> operands; // Vector to store operands in the order they were in the input

    int n = input.length();
    for(int i=0;i<n;++i){
        if(isSign(input.at(i))){
            std::string s(1, input.at(i));
            signs.push_back(s);
        }else if(input.at(i) == ')'){
            int k = operands.size();
            operands[k-2].append(operands[k-1]);
            operands[k-2].append(signs.back());

            result = operands[k-2];

            operands.erase(operands.end());
            signs.erase(signs.end());
        }else{
            char c = input.at(i);
            if(c == '(')
               continue;
            std::string s(1, c);
            operands.push_back(s);
        }
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cerr.tie(0);

    int t;
    std::string input;

    std::cin >> t;

    std::string sol[t] = {};
    std::getline(std::cin, input);
    for(int i=0;i<t;++i){
        std::getline(std::cin, input);
        sol[i] = toRPN(input);
    }

    for(int i=0;i<t;++i){
        std::cout << sol[i] << "\n";
    }

    return 0;
}
