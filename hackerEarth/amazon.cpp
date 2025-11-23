import java.util.*;

public class Result {

    private static final long INF = Long.MAX_VALUE / 4;

    private static long computeCost(long v, long mask) {
        if ((v & mask) == mask) return 0;

        long best = INF;

        long candidate = v | mask;
        if ((candidate & mask) == mask && candidate >= v) {
            best = Math.min(best, candidate - v);
        }

        for (int bit = 0; bit <= 31; bit++) {
            long next = ((v >> bit) + 1L) << bit;
            if (next < v) continue;

            long lowerMask = (bit == 0 ? 0 : ((1L << bit) - 1));
            long withMask = next | (mask & lowerMask);

            if ((withMask & mask) == mask && withMask >= v) {
                long cost = withMask - v;
                if (cost < best) best = cost;
            }
        }

        if (mask >= v) {
            best = Math.min(best, mask - v);
        }

        return best;
    }

    public static int getMaxRating(List<Integer> a, int k, int m) {
        long resultMask = 0;
        int n = a.size();

        for (int bit = 30; bit >= 0; bit--) {
            long trialMask = resultMask | (1L << bit);
            long[] costs = new long[n];

            for (int i = 0; i < n; i++) {
                costs[i] = computeCost(a.get(i), trialMask);
            }

            Arrays.sort(costs);

            long sum = 0;
            boolean feasible = true;

            for (int i = 0; i < m; i++) {
                if (costs[i] >= INF / 2) {
                    feasible = false;
                    break;
                }
                sum += costs[i];
                if (sum > k) {
                    feasible = false;
                    break;
                }
            }

            if (feasible) {
                resultMask = trialMask;
            }
        }

        return (int) resultMask;
    }
}
