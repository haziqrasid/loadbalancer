import java.net.*;

public class loadbalancer{
		public static void main(String []args)throws IOException{
		ServerSocket s=new ServerSocket(1000);
		while(true){
			Socket connection=s.accept();
			BufferedReader message=new BufferedReader(new InputStreamReader(connection.getInputStream()));
			String csentence=message.readLine();

			if(csentence.contains("server 1")){
			Socket s1=new Socket("192.168.32.128",2000);
			DataOutputStream server1=new DataOutputStream(s1.getOutputStream());
			server1.writeBytes(csentence+"\n");
			s1.close();
			}

			else if(csentence.contains("server 2")){
			Socket s2=new Socket("192.168.32.129",3000);
			DataOutputStream server2=new DataOutputStream(s2.getOutputStream());
			server2.writeBytes(ctsentence+"\n");
			s2.close();
			}

			else{System.out.println(ERROR!!);}
			}
		}
}