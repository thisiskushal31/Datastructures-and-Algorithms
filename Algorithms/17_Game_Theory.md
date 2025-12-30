### Game Theory

**Game Theory** in algorithms deals with optimal strategies in competitive scenarios where players make decisions to maximize their outcomes. It's used in competitive programming and algorithm design.

**Game Theory Framework:** Game theory is a mathematical framework designed for analyzing situations in which players make decisions that are interdependent. This interdependence causes each player to consider the other players' possible decisions or strategies in formulating their own strategy. It has applications in a variety of fields, including economics, political science, psychology, and computer science, particularly in areas related to artificial intelligence (AI) and machine learning.

Game theory can be divided into two main branches: **cooperative** and **non-cooperative**. Cooperative game theory deals with how groups of players can form coalitions and how the collective payoff can be distributed among them. Non-cooperative game theory focuses on how individual players make decisions to maximize their own payoffs.

**Optimal Play:** Game theory problems involve determining winning strategies for players in competitive games. Common problems include Nim game, stone games, and impartial games. The key is to identify patterns, calculate game states, and determine optimal moves using techniques like XOR operations, Grundy numbers, and dynamic programming.

![Game Theory Payoff Matrix](./assets/Game_Theory_Payoff_Matrix.png)

> **Image Credit:** [Wikimedia Commons - Prisoner's Dilemma](https://commons.wikimedia.org/wiki/Category:Payoff_matrices)

**Key Concepts:**
- **Players:** Entities making decisions
- **Strategies:** Choices available to players
- **Payoffs:** Outcomes based on strategies
- **Optimal Play:** Best strategy for each player
- **Payoff Matrix:** A simple 2×2 (or larger) grid in which you pit two or more possible strategies against each other and inspect every possible outcome. It provides a visual representation of the outcomes or payoffs of different choices made by individuals in a strategic scenario.
- **Nash Equilibrium:** A concept where no player can benefit by changing their strategy while the other players keep their strategies unchanged. It is a stable state where no player can gain by unilaterally deviating from their current strategy.

### Understanding Payoff Matrices

A **payoff matrix** is a tool that simplifies decision-making by allowing analysis of every branching path of a strategic decision. Originating from game theory, the payoff matrix provides a simple grid overview of all the potential outcomes of your decision-making process by organizing the possible choices and their consequences.

**Key Components of a Payoff Matrix:**
- **Rows and Columns:** Represent the available strategic decisions for each "player" in any scenario
- **Entries:** Represent the payoffs or outcomes resulting from the combination of choices made by each player
- **Players:** The entities making decisions (can be two competing features, companies, or any two actors)
- **Strategic Decisions:** The choices available to each player

**Types of Payoff Matrices:**
- **Symmetric Payoff Matrix:** Occurs when the payoffs for each player remain the same, regardless of the choices made by other players. The resulting outcomes are identical for all players.
- **Asymmetric Payoff Matrix:** When the payoffs for each player depend on the specific choices made by other players. The resulting outcomes vary significantly based on the combinations of choices made.

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

### Nash Equilibrium

Named after mathematician John Nash, a **Nash Equilibrium** is a concept within game theory where no player can benefit by changing their strategy while the other players keep their strategies unchanged. In other words, it is a stable state of a system involving multiple players where no player can gain by unilaterally deviating from their current strategy.

**Characteristics of Nash Equilibrium:**
- **Mutual Best Responses:** Each player's strategy is the best response to the strategies chosen by the other players
- **No Incentive to Deviate:** No player has anything to gain by changing only their own strategy
- **Possibility of Multiple Equilibria:** A game can have multiple Nash Equilibria or none at all

**Example: The Prisoner's Dilemma**

Consider the classic example of the Prisoner's Dilemma. Two prisoners are accused of a crime and interrogated separately. They can either confess or remain silent. The payoffs are as follows:
- If both confess, they each get 5 years in prison
- If one confesses and the other remains silent, the confessor gets 1 year, and the silent prisoner gets 10 years
- If both remain silent, they each get 2 years

The Nash Equilibrium in this case is for both prisoners to confess, as it is the best response considering the possible choices of the other prisoner.

### Combinatorial Game Theory

**Combinatorial game theory** deals with two-player games with perfect information and no chance elements. The theory is concerned with the mathematical study of such games.

**Key Concepts:**
- **Zero-Sum Games:** Games where one player's gain is exactly the other player's loss
- **Winning and Losing Positions:** A position is a winning position if the player whose turn it is to move can force a win with optimal play. Conversely, a losing position is one where the player will lose if the opponent plays optimally
- **P-Positions and N-Positions:** In combinatorial games, P-positions (previous player wins) and N-positions (next player wins) help determine the outcome based on optimal play

### Applications

1. **Competitive Programming** - Game theory problems
2. **AI** - Game playing algorithms (Chess, Go, AlphaGo)
3. **Economics** - Strategic decision making, auction design, market competition
4. **Cryptography** - Security games
5. **Reinforcement Learning** - Multi-agent RL, Q-learning, Deep Q-Networks
6. **Adversarial Machine Learning** - Generative Adversarial Networks (GANs)
7. **Negotiations** - Business negotiations, diplomacy, conflict resolution

### References

- [GeeksforGeeks - Game Theory](https://www.geeksforgeeks.org/combinatorial-game-theory/)
- [Fibery - Payoff Matrix](https://fibery.io/blog/product-management/payoff-matrix/)
- [Medium - Game Theory and Algorithms](https://medium.com/@rajat01221/game-theory-and-algorithms-a-comprehensive-exploration-55e510535302)
