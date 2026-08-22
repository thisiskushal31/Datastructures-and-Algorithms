# System design bridge

Coding patterns that **directly support** system design interviews — implementation here, trade-offs in [System-Design-Concepts](../System-Design-Concepts/COVERAGE_MATRIX.md).

*(New section — stubs August 2026)*

## Pattern map

| # | File | LeetCode / pattern | System Design topic |
|---|------|-------------------|---------------------|
| 1 | [LRU cache](./1-lru-cache.md) | 146 | [caching/7-eviction](../System-Design-Concepts/caching/7-cache-eviction-policies.md) |
| 2 | [LFU cache](./2-lfu-cache.md) | 460 | Cache layers, CDN edge |
| 3 | [Top K / streaming median](./3-top-k-and-streaming.md) | 215, 295, 347 | [performance/2-rate-limiting](../System-Design-Concepts/performance/2-rate-limiting.md), hot keys |
| 4 | [Consistent hashing (impl sketch)](./4-consistent-hashing-impl.md) | — | [fundamentals/17-consistent-hashing](../System-Design-Concepts/fundamentals/17-consistent-hashing.md) |
| 5 | [Token bucket (impl sketch)](./5-token-bucket-impl.md) | — | [cases/10-rate-limiter](../System-Design-Concepts/cases/10-rate-limiter-design.md) |
| 6 | [URL shortener key gen](./6-url-shortener-keys.md) | 380, 535 | [cases/6-url-shortener](../System-Design-Concepts/cases/6-url-shortener.md) |
| 7 | [Trie / prefix search](./7-trie-prefix-search.md) | 208, 211 | Search, autocomplete |
| 8 | [Union find / connectivity](./8-union-find-connectivity.md) | 547, 684 | Shard membership, networks |

## How to use

1. Solve the LeetCode problem in [Leetcode/](../Leetcode/Readme.md)
2. Read the matching System Design topic for **why** the pattern exists at scale
3. Write one paragraph in the bridge file linking both

## Inbound

[System-Design-Concepts/Entry-Points/DSA.md](../System-Design-Concepts/Entry-Points/DSA.md)
