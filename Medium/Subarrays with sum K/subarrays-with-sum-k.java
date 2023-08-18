//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int Arr[]= new int[N];
            for(int i = 0; i < N; i++)
                Arr[i] = Integer.parseInt(input_line[i]);
            int k = Integer.parseInt(read.readLine());
            
            Solution ob = new Solution();
            System.out.println(ob.findSubArraySum(Arr, N, k));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    static int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        long[] prefix = new long[N+1];
        int count = 0;

        HashMap<Long, Integer> m = new HashMap<>();
        m.put(0L, 1); // Initial frequency of sum 0

        for (int i = 0; i < N; i++) {
            prefix[i+1] = prefix[i] + Arr[i];
            m.put(prefix[i+1], m.getOrDefault(prefix[i+1], 0) + 1);
        }

        for (int i = 0; i < N; i++) {
            m.put(prefix[i], m.get(prefix[i]) - 1);
            count += m.getOrDefault(prefix[i] + k, 0);
        }

        return count;
    }
}