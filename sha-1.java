import java.util.*;
import java.math.BigInteger;
import java.security.MessageDigest;

class hello
{
    public static void main(String[] args) throws Exception
    {
        String message = "hello world";

        MessageDigest md = MessageDigest.getInstance("SHA1");
        byte[] bytes = md.digest(message.getBytes());

        BigInteger no = new BigInteger(1,bytes);

        String hashValue = no.toString(16);

        while(hashValue.length() < 32)
        {
            hashValue = "0"+hashValue;
        }
        
        System.out.println(hashValue);
    }
}
