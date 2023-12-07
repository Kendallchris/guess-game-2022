#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(0));
    int magic, guess, cont = 1, maxNum;
    double close;

    while (cont == 1) {
        cout << "What is the maximum number you want?" << endl;
        cin >> maxNum;
        magic = rand() % maxNum + 1;
        cout << maxNum;
        cout << magic;
        cout << "Please guess a number" << endl;
        for (int curTry = 0; curTry < 3; ++curTry) {
            cout << "Attempt #" << curTry + 1 << ": ";
            cin >> guess;
            close = abs(magic - guess) / static_cast<double>(maxNum);
            if (guess == magic) {
                cout << "You win!" << endl;
                break;
            } else if (curTry < 2){
                cout << "Try again!" << endl;
                if (close < 0.25) {
                    cout << "Hot!" << endl;
                } else if (0.25 < close > 0.50) {
                    cout << "Warm!" << endl;
                } else if (0.50 < close > 0.75) {
                    cout << "Cold!" << endl;
                } else {
                    cout << "Freezing!" << endl;
                }
            }

        }
        if (guess != magic) {
            cout << "Loser" << endl;
        }
        cout << "Wanna go again? [0 for no]";
        cin >> cont;
    }
    return 0;

}
