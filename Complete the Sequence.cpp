/** PROBLEM: CMPLS - Complete the Sequence!
  * LINK: https://www.spoj.com/problems/CMPLS/
  *
  * AUTHOR: Nikola Mircic
  * PROFILE: https://github.com/Nikola-Mircic
  */

#include <iostream>
#include <vector>

typedef long long lld;

void printList(lld* arr, int n){
    for(int i=0;i<n;++i) std::cout << arr[i] << " ";
    std::cout<<"\n";
}

void printList(std::vector<lld>* arr){
    for(int i=0;i<arr->size();++i) std::cout << arr->at(i) << " ";
    std::cout<<"\n";
}

std::vector<lld>* solve(std::vector<lld>& input, int s, int c){
    //Difference table is list of vectors for easy modifications
    std::vector<lld>* diff_table = new std::vector<lld>[s];

    //Result
    std::vector<lld>* result = new std::vector<lld>(c);

    //Set the first row of the difference table to be original array
    diff_table[0] = input;

    //Fill the difference table
    for(int i=1;i<s;++i){
        for(int j=1;j<diff_table[i-1].size();++j){
            diff_table[i].push_back(diff_table[i-1][j]-diff_table[i-1][j-1]);
        }
    }

    int lenght; //Store length of a selected row
    for(int k = 0;k<c;++k){
        diff_table[s-1].push_back(diff_table[s-1][0]);
        for(int i=s-2;i>=0;--i){
            lenght = diff_table[i].size();
            diff_table[i].push_back(diff_table[i][lenght-1]+diff_table[i+1][lenght-1]);
        }
        result->at(k) = diff_table[0][s+k];
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
    std::vector<lld>** solutions;
    std::vector<lld> input;
    int s, c;

    std::cin >> t;

    solutions = new std::vector<lld>*[t];

    for(int phase = 0; phase < t; ++phase){
        std::cin >> s >> c;
        int x;
        for(int i=0;i<s;++i){
            std::cin >> x;
            input.push_back(x);
        };

        solutions[phase] = solve(input, s, c);
        input.clear();
    }

    for(int phase = 0; phase < t; ++phase){
        printList(solutions[phase]);
    }

    //printList(solve(input, s, c), c);

    return 0;
}
