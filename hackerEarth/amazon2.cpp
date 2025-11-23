import java.util.*;

public class Result {

    public static int minimizeReleaseDays(List<Integer> sched, List<Integer> ref) {
        int n = sched.size();
        int m = ref.size();

        int l = 1, r = n, ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(ok(mid, sched, ref)) {
                ans = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    private static boolean ok(int d, List<Integer> sched, List<Integer> ref) {
        int m = ref.size();
        int[] last = new int[m + 1];

        for(int i = 1; i <= d; i++) {
            int x = sched.get(i - 1);
            if(x >= 1 && x <= m) last[x] = i;
        }

        for(int j = 1; j <= m; j++) {
            if(last[j] == 0) return false;
        }

        int[][] a = new int[m][2];
        for(int j = 1; j <= m; j++) {
            a[j - 1][0] = last[j];
            a[j - 1][1] = j;
        }

        Arrays.sort(a, (u, v) -> u[0] - v[0]);

        long s = 0;
        for(int i = 0; i < m; i++) {
            int deadline = a[i][0];
            int mod = a[i][1];
            s += ref.get(mod - 1);
            if(s > deadline - (i + 1)) return false;
        }

        return true;
    }
}
