#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int l = 0, r = tokens.size() - 1;
        int score = 0, maxScore = 0;

        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                score++;
                l++;
                maxScore = max(maxScore, score);
            } 
            else if (score > 0) {
                power += tokens[r];
                score--;
                r--;
            } 
            else {
                break;
            }
        }

        return maxScore;
    }
};

int main() {
    int n;
    cout << "Enter number of tokens: ";
    cin >> n;

    vector<int> tokens(n);
    cout << "Enter token values: ";
    for(int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    int power;
    cout << "Enter initial power: ";
    cin >> power;

    Solution obj;
    int result = obj.bagOfTokensScore(tokens, power);

    cout << "Maximum Score: " << result << endl;

    return 0;
}