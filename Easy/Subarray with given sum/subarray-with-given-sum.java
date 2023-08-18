//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class Main{
	static BufferedReader br;
    static PrintWriter ot;
    public static void main(String[] args) throws IOException{
        
        br = new BufferedReader(new InputStreamReader(System.in));
        ot = new PrintWriter(System.out);

        int t = Integer.parseInt(br.readLine());

        while(t-->0){
            
            String s[] = br.readLine().trim().split(" ");
            
            int n = Integer.parseInt(s[0]);
            int k = Integer.parseInt(s[1]);
            int a[] = new int[n];
            s = br.readLine().trim().split(" ");
            for(int i = 0; i < n; i++)
                a[i] = Integer.parseInt(s[i]);
            Solution obj = new Solution();
            ArrayList<Integer> res = obj.subarraySum(a, n, k);
            for(int ii = 0;ii<res.size();ii++)
                ot.print(res.get(ii) + " ");
            ot.println();
        }
        ot.close();
    }

}
// } Driver Code Ends


class Solution
{
    //Function to find a continuous sub-array which adds up to a given number.
    static ArrayList<Integer> subarraySum(int[] arr, int n, int k) 
    {
        Map<Long, Integer> mp = new HashMap<>();
        mp.put(0L, Integer.MAX_VALUE);
        long psum = 0;
        ArrayList<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < arr.length; i++) {
            psum += arr[i];
            if (mp.containsKey((psum-k))) {
                if (mp.get(( psum-k)) == Integer.MAX_VALUE) {
                    result.add(1);
                    result.add(i + 1);
                    return result;
                }
                result.add(mp.get(psum - k) + 1);
                result.add(i + 1);
                return result;
            }
            if (!mp.containsKey(psum)) {
                mp.put(psum, i + 1);
            }
        }
        
        result.add(-1);
        return result;
    }
}