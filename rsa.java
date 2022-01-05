import java.util.*;
import java.lang.Math;
import java.math.*;
class hello
{
    public static int gcd(int a,int b)
    {
        if(a==0) return b;
        else return gcd(b%a,a);
    }
    public static void main(String[] args) throws Exception
    {
        int message = 12;

        int firstPrime = 3;
        int secondPrime = 11;

        int n = firstPrime * secondPrime;
        int z = (firstPrime-1) * (secondPrime -1);
        int e=0;
        for(int i=2;i<z;i++)
        {
            if(gcd(i,z)==1){
                e=i;break;
            } 
        }

        int privateKey = 0;
        for(int i=0;i<=9;i++)
        {
            int x = 1+(i*z);
            if(x%e==0){
                privateKey = x/e;break;
            }
        }

        double c = (Math.pow(message,e) % n);
        
        BigInteger N = BigInteger.valueOf(n);

        BigInteger C = BigDecimal.valueOf(c).toBigInteger();
        BigInteger decrypt = (C.pow(privateKey)).mod(N);
        
        System.out.println("MESSAGE: "+message);
        System.out.println("ENCRYPTED: "+c);
        System.out.println("DECRYPTED: "+decrypt);
    }
}
