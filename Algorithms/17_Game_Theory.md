### Game Theory

**Game Theory** in algorithms deals with optimal strategies in competitive scenarios where players make decisions to maximize their outcomes. It's used in competitive programming and algorithm design.

**Optimal Play:** Game theory problems involve determining winning strategies for players in competitive games. Common problems include Nim game, stone games, and impartial games. The key is to identify patterns, calculate game states, and determine optimal moves using techniques like XOR operations, Grundy numbers, and dynamic programming.

![Game Theory Payoff Matrix](./assets/Game_Theory_Payoff_Matrix.png)

> **Image Credit:** [Wikipedia - Game Theory](https://en.wikipedia.org/wiki/Game_theory)

**Key Concepts:**
- **Players:** Entities making decisions
- **Strategies:** Choices available to players
- **Payoffs:** Outcomes based on strategies
- **Optimal Play:** Best strategy for each player

### Game Theory Problems

#### 1. Nim Game

Two players take turns removing objects from heaps. Last to remove wins.

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool canWinNim(vector<int>& heaps) {
    int nimSum = 0;
    for (int heap : heaps) {
        nimSum ^= heap; // XOR all heap sizes
    }
    return nimSum != 0; // Non-zero nim-sum means first player wins
}

int main() {
    vector<int> heaps = {3, 4, 5};
    cout << (canWinNim(heaps) ? "First player wins" : "Second player wins") << endl;
    return 0;
}
```

**Strategy:** If XOR of all heap sizes is non-zero, first player wins.

#### 2. Stone Game

Players take stones from pile. Last to take wins.

```cpp
bool canWinStoneGame(int n) {
    // If n is multiple of 4, second player wins
    // Otherwise, first player wins
    return n % 4 != 0;
}
```

#### 3. Predict the Winner

Two players pick from ends of array. Predict if first player can win.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int predictWinnerUtil(vector<int>& nums, int left, int right, 
                     vector<vector<int>>& memo) {
    if (left > right) return 0;
    if (memo[left][right] != -1) return memo[left][right];
    
    int pickLeft = nums[left] - predictWinnerUtil(nums, left + 1, right, memo);
    int pickRight = nums[right] - predictWinnerUtil(nums, left, right - 1, memo);
    
    memo[left][right] = max(pickLeft, pickRight);
    return memo[left][right];
}

bool predictWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return predictWinnerUtil(nums, 0, n - 1, memo) >= 0;
}
```

**Time Complexity:** O(n²)  
**Space Complexity:** O(n²)

#### 4. Tic-Tac-Toe

Check if current board state is winning.

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool checkWin(vector<vector<char>>& board, char player) {
    int n = board.size();
    
    // Check rows and columns
    for (int i = 0; i < n; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < n; j++) {
            if (board[i][j] != player) rowWin = false;
            if (board[j][i] != player) colWin = false;
        }
        if (rowWin || colWin) return true;
    }
    
    // Check diagonals
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < n; i++) {
        if (board[i][i] != player) diag1 = false;
        if (board[i][n - 1 - i] != player) diag2 = false;
    }
    
    return diag1 || diag2;
}
```

#### 5. Minimax Algorithm

Optimal strategy for two-player zero-sum games.

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minimax(vector<int>& scores, int depth, int nodeIndex, 
           bool isMax, int alpha, int beta) {
    if (depth == 0 || nodeIndex >= scores.size()) {
        return scores[nodeIndex];
    }
    
    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 2; i++) {
            int val = minimax(scores, depth - 1, nodeIndex * 2 + i, 
                            false, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha) break; // Alpha-beta pruning
        }
        return best;
    }
    else {
        int best = INT_MAX;
        for (int i = 0; i < 2; i++) {
            int val = minimax(scores, depth - 1, nodeIndex * 2 + i, 
                            true, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha) break; // Alpha-beta pruning
        }
        return best;
    }
}
```

**Time Complexity:** O(b^d) where b is branching factor, d is depth  
**With pruning:** Much better in practice

### Game Theory Patterns

#### Pattern 1: XOR Games (Nim)
- Calculate XOR of all values
- Non-zero XOR → first player wins

#### Pattern 2: Modulo Games
- Check if n % (k+1) != 0
- First player wins if condition true

#### Pattern 3: DP Games
- Use dynamic programming
- Calculate optimal moves recursively

### Common Game Theory Problems

1. Nim Game
2. Stone Game
3. Predict the Winner
4. Tic-Tac-Toe
5. Coin Game
6. Divisor Game
7. Can I Win
8. Flip Game

### Applications

1. **Competitive Programming** - Game theory problems
2. **AI** - Game playing algorithms
3. **Economics** - Strategic decision making
4. **Cryptography** - Security games

### References

- [GeeksforGeeks - Game Theory](https://www.geeksforgeeks.org/combinatorial-game-theory/)
