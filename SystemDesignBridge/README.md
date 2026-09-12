# SystemDesignBridge

Coding patterns that **directly support** system design interviews — implementation here, trade-offs in [System-Design-Concepts](https://github.com/thisiskushal31/System-Design-Concepts).

*(New section — stubs August 2026)*

## Pattern map

| # | File | LeetCode / pattern | System Design topic |
|---|------|-------------------|---------------------|
| 1 | [LRU cache](./1_LRU_Cache.md) | 146 | [Caching/7 eviction](../System-Design-Concepts/Caching/7_Cache_Eviction_Policies.md) |
| 2 | [LFU cache](./2_LFU_Cache.md) | 460 | Cache layers, CDN edge |
| 3 | [Top K / streaming median](./3_Top_K_and_Streaming.md) | 215, 295, 347 | [Performance/2 rate limiting](../System-Design-Concepts/Performance/2_Rate_Limiting.md), hot keys |
| 4 | [Consistent hashing (impl sketch)](./4_Consistent_Hashing_Impl.md) | — | [Fundamentals/17 consistent hashing](../System-Design-Concepts/Fundamentals/17_Consistent_Hashing.md) |
| 5 | [Token bucket (impl sketch)](./5_Token_Bucket_Impl.md) | — | [Cases/10 rate limiter](../System-Design-Concepts/Cases/10_Rate_Limiter_Design.md) |
| 6 | [URL shortener key gen](./6_URL_Shortener_Keys.md) | 380, 535 | [Cases/6 URL shortener](../System-Design-Concepts/Cases/6_URL_Shortener.md) |
| 7 | [Trie / prefix search](./7_Trie_Prefix_Search.md) | 208, 211 | Search, autocomplete |
| 8 | [Union find / connectivity](./8_Union_Find_Connectivity.md) | 547, 684 | Shard membership, networks |

## How to use

1. Solve the LeetCode problem in [Leetcode/](../Leetcode/Readme.md)
2. Read the matching System Design topic for **why** the pattern exists at scale
3. Write one paragraph in the bridge file linking both

## Inbound

[System Design Concepts](../../System-Design-Concepts/README.md)
