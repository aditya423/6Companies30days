#include<bits/stdc++.h>
using namespace std;

// suppose first passenger lost his ticket pics 5th passenger seat (n=5)
// what is the probability that 5th person gets his own seat?
// 5th person will seat on first passenger seat (not getting own 5th seat)

// suppose first passenger lost his ticket pics 1st passenger seat (n=1)
// what is the probability that 5th person gets his own seat?
// 5th person will seat on 5th passenger seat (getting own 5th seat)

// Coin is tossed --> Heads or tails? --> Probability = 0.5
// Similarly,
// 5th passenger seating --> 1st passenger seat or 5th passenger seat --> Probability = 0.5

double nthPersonGetsNthSeat(int n) {
        
    if(n == 1)
        return 1.00000;

    return 0.50000;
}

int main() {

    cout<<nthPersonGetsNthSeat(1)<<endl;

    cout<<nthPersonGetsNthSeat(2)<<endl;

    return 0;
}
