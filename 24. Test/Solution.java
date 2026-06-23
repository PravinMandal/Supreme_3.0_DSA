import java.util.*;

class Result {
    private static final long MOD = 1_000_000_007L;

    public static int findTotalPower(List<Integer> power) {
        int n = power.size();
        long[] prefix = new long[n + 1];
        long[] prefixPrefix = new long[n + 2];

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] + power.get(i)) % MOD;
            prefixPrefix[i + 2] = (prefixPrefix[i + 1] + prefix[i + 1]) % MOD;
        }

        int[] previousLess = new int[n];
        int[] nextLessOrEqual = new int[n];
        int[] stack = new int[n];
        int top = -1;

        for (int i = 0; i < n; i++) {
            while (top >= 0 && power.get(stack[top]) >= power.get(i)) {
                top--;
            }
            previousLess[i] = top >= 0 ? stack[top] : -1;
            stack[++top] = i;
        }

        top = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && power.get(stack[top]) > power.get(i)) {
                top--;
            }
            nextLessOrEqual[i] = top >= 0 ? stack[top] : n;
            stack[++top] = i;
        }

        long totalPower = 0;

        for (int i = 0; i < n; i++) {
            int leftBoundary = previousLess[i];
            int rightBoundary = nextLessOrEqual[i];

            long leftCount = i - leftBoundary;
            long rightCount = rightBoundary - i;

            long rightPrefixSum = (prefixPrefix[rightBoundary + 1] - prefixPrefix[i + 1] + MOD) % MOD;
            long leftPrefixSum = (prefixPrefix[i + 1] - prefixPrefix[leftBoundary + 1] + MOD) % MOD;

            long subarraySumContribution = (rightPrefixSum * leftCount - leftPrefixSum * rightCount) % MOD;
            if (subarraySumContribution < 0) {
                subarraySumContribution += MOD;
            }

            totalPower = (totalPower + (power.get(i) % MOD) * subarraySumContribution) % MOD;
        }

        return (int) totalPower;
    }
}
