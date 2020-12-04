public interface EncryptionAlgo{

	String encrypt(String text);
	String decrypt(String text);
}

public class AESEncryption implements EncryptionAlgo{
	private String name;
	
	public :
		String encrypt(String data)
		{
			return "AES Encrypt";
		}
		String decrypt(String data)
		{
			return "AES Descrypt";
			
		}
	}
	
public class BlowFishEncryption implements EncryptionAlgo{
	private String name;
	
	public :
		String encrypt(String data)
		{
			return "Blowfish Encrypt";
		}
		String decrypt(String data)
		{
			return "Blowfish Descrypt";
			
		}
	}

public class Message {

	private EncryptionAlgo encyptAlgo;
	private String text;
	
	Message (EncryptionAlgo encyptionAlgo)
	{
		encryptAlgo = encyptionAlgo;
	}
	public String getText(){
	
		return encryptAlgo.decrypt(text);
	}
	
	public String setText(String data)
	{
		text = encryptAlgo.encrypt(data)
	}
}
