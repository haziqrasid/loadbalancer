import java.io.*;
import java.net.*;

public class client{
		public static void main(String []args)throws IOException{
		Socket c=new Socket("192.168.23.129",1000);
		DataOutputStream server=new DataOutputStream(c.getOutputStream());
		BufferedReader user=new BufferedReader(new InputStream(System.in));
		String csentence=user.readLine();
		oserver.writeBytes(csentence);
		c.close();
		}
}
