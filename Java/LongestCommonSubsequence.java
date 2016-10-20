import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class  LongestCommonSubsequence
{    
    public String lcs(String str1, String str2)
    {
        int l1 = str1.length();
        int l2 = str2.length();
        int[][] arr = new int[l1 + 1][l2 + 1];
        for (int i = l1 - 1; i >= 0; i--)
        {
            for (int j = l2 - 1; j >= 0; j--)
            {
                if (str1.charAt(i) == str2.charAt(j))
                    arr[i][j] = arr[i + 1][j + 1] + 1;
                else 
                    arr[i][j] = Math.max(arr[i + 1][j], arr[i][j + 1]);
            }
        }

        int i = 0, j = 0;
        StringBuffer sb = new StringBuffer();
        while (i < l1 && j < l2) 
        {
            if (str1.charAt(i) == str2.charAt(j)) 
            {
                sb.append(str1.charAt(i));
                i++;
                j++;
            }
            else if (arr[i + 1][j] >= arr[i][j + 1]) 
                i++;
            else
                j++;
        }
        return sb.toString();
    }

    public static void main(String[] args) throws IOException
    {    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("\nEnter first string sequence:");
        String str1 = br.readLine();
        System.out.println("\nEnter second string sequence:");
        String str2 = br.readLine();
        LongestCommonSubsequence obj = new LongestCommonSubsequence(); 
        String result = obj.lcs(str1, str2);
        System.out.println("\nLongest Common Subsequence : "+ result + "\nIts length is : " + result.length());
    }
}

