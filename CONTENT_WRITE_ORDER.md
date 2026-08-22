# Data Structures & Algorithms — content write order

**Created:** August 2026  
**Repo #6** after [System-Design-Concepts](../System-Design-Concepts/CONTENT_WRITE_ORDER.md).

**Unlike System Design:** this repo has **strong theory** (19 algorithm + 23 data structure topic files, Foundation patterns) but a **thin problem bank** (~18 LeetCode folders solved; Leetcode/Readme lists 100+ unchecked).

---

## What is already solid (maintain only)

| Section | Files | Status |
|---------|-------|--------|
| [Algorithms/](./Algorithms/README.md) | 19 topics (00–18) | **Written** — logic, complexity, DP, graphs, etc. |
| [DataStructures/](./DataStructures/README.md) | 23 topics | **Written** — array through RB-tree, trie, segment tree |
| [Foundation/](./Foundation/Readme.md) | 2 + patterns | **Written** — 16 coding patterns cheatsheet |
| [Template/](./Template/) | C++/Java snippets | **Written** — BIT, segtree, graph, math |
| [Leetcode/](./Leetcode/Readme.md) | 18 solved folders | **Partial** — Two Pointers, Binary Search, Linked List only |
| [GeekforGeeks/](./GeekforGeeks/Readme.md) | ~19 topic folders | **Partial** — mostly code, sparse READMEs |

---

## Lane J — recommended fill order

| Step | Location | Why |
|------|----------|-----|
| 1 | [0_Start_Here.md](./0_Start_Here.md) + [Entry-Points/](./Entry-Points/README.md) | On-ramp + sister repos |
| 2 | [PLANNED_PROBLEMS.md](./PLANNED_PROBLEMS.md) | Track empty LeetCode categories + target count |
| 3 | [system-design-bridge/](./system-design-bridge/README.md) | Map patterns → System Design (rate limit, LRU, top-K) |
| 4 | Fill **Design** + **Heap** LeetCode categories | Interview staples (LRU, LFU, 295, 703) |
| 5 | Fill **Graph** + **BFS/DFS** + **Union Find** | SD-relevant (connectivity, islands) |
| 6 | Fill **Dynamic Programming** (classic 15) | Interview core |
| 7 | Expand **GeekforGeeks** READMEs per problem | Match LeetCode quality |
| 8 | Tag solved problems with `SD:` in Readme when relevant | Link to system-design-bridge |

---

## Sister repos

| Domain | Repository | Entry file |
|--------|------------|------------|
| Architecture trade-offs | [System-Design-Concepts](https://github.com/thisiskushal31/System-Design-Concepts) | [Entry-Points/System_Design.md](./Entry-Points/System_Design.md) |
| Command templates | [Commands-and-Cheatsheets](https://github.com/thisiskushal31/Commands-and-Cheatsheets) | [Entry-Points/Cheatsheets.md](./Entry-Points/Cheatsheets.md) |
| Delivery / interview loops | [DevOps-Handbook](https://github.com/thisiskushal31/DevOps-Handbook) | [Entry-Points/DevOps_Handbook.md](./Entry-Points/DevOps_Handbook.md) |

**Inbound:** [System-Design-Concepts/Entry-Points/DSA.md](../System-Design-Concepts/Entry-Points/DSA.md)

---

## Repo #6 done when

- [ ] [PLANNED_PROBLEMS.md](./PLANNED_PROBLEMS.md) — every empty LeetCode category has ≥3 solved OR explicitly deferred
- [ ] [system-design-bridge/](./system-design-bridge/README.md) — ≥8 pattern writeups with SD links
- [ ] 50+ curated problems with Readme + solution (realistic v1; 150 = stretch)
- [ ] `0_Start_Here.md` checkbox learning path complete

---

## Marking problems complete

Use `- [x]` in [Leetcode/Readme.md](./Leetcode/Readme.md) and [PLANNED_PROBLEMS.md](./PLANNED_PROBLEMS.md). Each new problem folder: `Readme.md` (approach, complexity) + `.cpp`/`.java` solution.
