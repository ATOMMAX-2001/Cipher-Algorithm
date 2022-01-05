//AUTHOR: S.ABILASH

import java.util.*;
import java.lang.Math.*;
class hello
{
    static int key =3;

    public static void  print(String payload)
    {
        System.out.println(payload);
    }
    public static String caeser_encrypt(String message)
    {
        String output = "";
        message = message.toLowerCase();
        for(int i=0;i<message.length();i++)
        {
            int value = (int)message.charAt(i);
            output+= (char)(Math.abs( (int)'a'- (value+key) )%26 + (int)'a');
        }
        return output;
    }
    public static String caeser_decrypt(String encrypt)
    {
        String output ="";
        encrypt = encrypt.toLowerCase();
        for(int i=0;i<encrypt.length();i++)
        {
            int value = (int)encrypt.charAt(i);
            output+= (char)(Math.abs( (int)'a'- (value-key) )%26 +(int)'a');
        }       
        return output;
    }
    public static void main(String[] args)
    {
        String message = "hello world";
        String encrypt = caeser_encrypt(message);
        String decrypt = caeser_decrypt(encrypt);
        print("MESSAGE: "+message);
        print("ENCRYPTION: "+encrypt);
        print("DECRYPTION: "+decrypt);
    }
}
