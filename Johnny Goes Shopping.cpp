/** PROBLEM: JOHNNY - Johnny Goes Shopping
  * LINK: https://www.spoj.com/problems/JOHNNY/
  *
  * AUTHOR: Nikola Mircic
  * PROFILE: https://github.com/Nikola-Mircic
  */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

typedef long long lld; // Since numbers are between 1-10^14 we will use long long to store them

struct packet{
    lld value;
    int orig;
};

bool compare(packet a, packet b){
    return a.value < b.value;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cerr.tie(0);

    int n;
    packet* numbers;

    std::cin >> n;

    numbers = (packet*) calloc(n, sizeof(packet));

    for(int i=0;i<n;++i){
        std::cin >> numbers[i].value;
        numbers[i].orig = i+1;
    }

    std::sort(numbers, numbers+n, compare);

    std::vector<int> left_hand;
    lld diff = 0;// Difference between numbers of packets in each hand ( left hand - right hand)

    for(int i=n-1;i>=0;--i){
        if(diff<=0){
            diff += numbers[i].value;
            left_hand.push_back(numbers[i].orig);
        }else{
            diff -= numbers[i].value;
        }
    }

    int len = left_hand.size();
    for(int pos=0;pos<len;++pos)
        std::cout << left_hand.at(pos) << "\n";

    return 0;
}
