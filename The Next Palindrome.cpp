/** PROBLEM: PALIN - The Next Palindrome
  * LINK: https://www.spoj.com/problems/PALIN/
  *
  * AUTHOR: Nikola Mircic
  * PROFILE: https://github.com/Nikola-Mircic
  */

#include <iostream>
#include <string>

int increaseMiddle(std::string& str){
    int len = str.length();// Store length of input in one variable

    int middlePoint = len/2-((len%2==0) ? 1:0); // Find middle point

    int idx = middlePoint;// Create an iterable variable
    if(str.at(idx)=='9'){
        // Increasing character '9' won't affect only that index,
        // it will increase the index next to the character also,
        // so we will do that process in the while loop

        // For every increased character in the first half of palindrome,
        // we also increase the matching character in the second half.
        // That way the increased number will stay palindrome.
        while(str.at(idx)=='9'){
            if(idx==0){
                // If first character is nine we will put a '0' on begging of the string
                // and increase it on the end of the loop
                str.at(idx) = '0'+((str.at(idx)-'0')+1)%10;
                str.at(len-idx-1) = str.at(idx);
                str.insert(0, 1, '0');
                len+=1;
            }else{
                str.at(idx) = '0'+((str.at(idx)-'0')+1)%10;
                str.at(len-idx-1) = str.at(idx);
                idx--;
            }
        }
        str.at(idx) = '0'+((str.at(idx)-'0')+1);
        str.at(len-idx-1) = str.at(idx);
    }else{
        // Character is not '9', just increase it
        str.at(middlePoint) = '0'+((str.at(middlePoint)-'0')+1);
        str.at(len-middlePoint-1) = str.at(middlePoint);
    }

    return len;
}

std::string findNextPalin(std::string input){
    std::string inputCopy = input; // Create copy of input so original input

    int len = input.length();// Store length of input in one variable

    int middlePoint = len/2-((len%2==0) ? 1:0); // Find middle point

    //Create palindrome from the input copy
    for(int i=middlePoint;i>=0;--i){
        inputCopy.at(len-i-1) = inputCopy.at(i);
    }

    //Check if palindrome will be smaller than original input
    bool equals = true;
    for(int i=middlePoint;i<len;++i){
        if(input.at(i) > inputCopy.at(i)){
            // If new palindrome is smaller than original input, then increase the middle element
            len = increaseMiddle(inputCopy);
            equals = false;
            break;
        }else if(input.at(i) < inputCopy.at(i)){
            // No need for further search, palindrome is bigger than original input
            return inputCopy;
        }
    }

    if(equals){
        increaseMiddle(inputCopy);
    }

    return inputCopy;
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
        sol[i] = findNextPalin(input);
    }

    for(int i=0;i<t;++i){
        std::cout << sol[i] << "\n";
    }

    return 0;
}
