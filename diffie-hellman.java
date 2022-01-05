import java.util.*;
import java.lang.Math;
class hello
{
    public static void main(String[] args) throws Exception
    {
        String message = "abc";
        
        long primeNo = 23;
        long primitiveRoot = 5;

        long  alicePrivateKey = 4;
        long AliceOutput = (((long)Math.pow(primitiveRoot,alicePrivateKey)) % primeNo);

        long bobPrivateKey = 3;
        long BobOutput = (((long)Math.pow(primitiveRoot,bobPrivateKey)) % primeNo);
        
        long AliceSecretKey = (((long)Math.pow(BobOutput,alicePrivateKey)) % primeNo);
        long BobSecretKey = (((long)Math.pow(AliceOutput,bobPrivateKey))% primeNo);

        System.out.println("ALICE KEY: "+AliceSecretKey);
        System.out.println("BOB KEY: "+BobSecretKey);
    }
}
