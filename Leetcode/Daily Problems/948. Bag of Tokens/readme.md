# [948. Bag of Tokens](https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04)

You start with an initial **power**  of `power`, an initial **score**  of `0`, and a bag of tokens given as an integer array `tokens`, where each`tokens[i]` donates the value of token<sub>i</sub>.

Your goal is to **maximize**  the total **score**  by strategically playing these tokens. In one move, you can play an **unplayed**  token in one of the two ways (but not both for the same token):

- **Face-up** : If your current power is **at least**  `tokens[i]`, you may play token<sub>i</sub>, losing `tokens[i]` power and gaining `1` score.
- **Face-down** : If your current score is **at least**  `1`, you may play token<sub>i</sub>, gaining `tokens[i]` power and losing `1` score.

Return the **maximum**  possible score you can achieve after playing **any**  number of tokens.

**Example 1:** 

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: 0.875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
Input: tokens = [100], power = 50

Output: 0

Explanation
**:**  Since your score is `0` initially, you cannot play the token face-down. You also cannot play it face-up since your power (`50`) is less than `tokens[0]`(`100`).

**Example 2:** 

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: 0.875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
Input: tokens = [200,100], power = 150

Output: 1

Explanation: Play token<sub>1</sub> (`100`) face-up, reducing your power to`50` and increasing your score to`1`.

There is no need to play token<sub>0</sub>, since you cannot play it face-up to add to your score. The maximum score achievable is `1`.

**Example 3:** 

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: 0.875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
Input: tokens = [100,200,300,400], power = 200

Output: 2

Explanation: Play the tokens in this order to get a score of `2`:

- Play token<sub>0</sub> (`100`) face-up, reducing power to `100` and increasing score to `1`.
- Play token<sub>3</sub> (`400`) face-down, increasing power to `500` and reducing score to `0`.
- Play token<sub>1</sub> (`200`) face-up, reducing power to `300` and increasing score to `1`.
- Play token<sub>2</sub> (`300`) face-up, reducing power to `0` and increasing score to `2`.

The maximum score achievable is <code style="color: var(--text-secondary); font-size: 0.875rem;">2`.

**Constraints:** 

- `0 <= tokens.length <= 1000`
- `0 <= tokens[i], power < 10^4`