import java.util.*;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.Signature;

class hello
{
    public static void main(String[] args) throws Exception
    {
        String message = "hello world";

        KeyPairGenerator keyPair = KeyPairGenerator.getInstance("DSA");
        keyPair.initialize(2048);

        KeyPair pair = keyPair.generateKeyPair();
        
        PrivateKey privateKey = pair.getPrivate();
        Signature sign = Signature.getInstance("SHA256withDSA");
        sign.initSign(privateKey);
        
        byte[] bytes  = message.getBytes();
        sign.update(bytes);
        byte[] signature = sign.sign();

        System.out.println(new String(signature,"UTF8"));
    }
}
