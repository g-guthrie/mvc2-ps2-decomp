# Agent model and effort experiment

Running comparison of which model and reasoning effort recover the most
verified bytes per batch and per cost. Every batch is a random slice of the
same target pool for its row's stratum, so strata are comparable within
themselves but not across them (later pools are harder: "retry" rows are
units or functions an earlier batch attempted and left).

`agent_model_effort_ledger.csv` has one row per agent: targets assigned,
verified matches, bytes credited after integration (matches rejected at
integration, such as stand-in callees or pad-only data, are not counted),
total tokens, and wall time. Cost assumes Sonnet tokens cost about three
times Haiku tokens.

## Findings so far

- **Code:** Sonnet at low effort matched 27-50% of its targets per batch,
  against 10-13% for every Haiku effort level. Per token cost the two are
  similar, but failed attempts use up a finite target pool, so hit rate per
  target decides: code batches now go to Sonnet low.
- **Fresh data:** Haiku at medium effort gave the most bytes per cost; low
  effort gave about half as much and often stopped early.
- **Data retries** (units an earlier batch left as placeholder): Sonnet low
  reconstructed 42%, Haiku 4-28%.
- **Haiku low** is not a free substitute: it attempts fewer targets and
  recovers roughly half as much as medium on the same pools.

## Decision: Haiku dropped

Haiku retry waves at low, high, xhigh and max matched 0–3 of 15 targets per
batch; Sonnet low matched 3–11. Haiku was retired from the fleet. The next
phase compares Sonnet low against Sonnet medium on the same retry pool.

## Decision: Sonnet medium

Wave 6 ran Sonnet low and Sonnet medium side by side on the same retry pool:

| Effort | Batches | Matched | Hit rate | Tokens/batch | Tokens/match |
|---|---|---|---|---|---|
| low | 5 | 13 / 75 | 17% | 270k | 104k |
| medium | 6 | 28 / 90 | 31% | 313k | 67k |

Medium costs about 15% more per batch and roughly 35% less per matched
function. All further batches run on Sonnet medium.
