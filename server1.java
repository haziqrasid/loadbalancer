server.javaimport java.io.*;
import java.net.*;

public class server{
		public static void main(String []args)throws IOException{
		ServerSocket s1=new ServerSocket(2000);
		while(true){
			Socket connection=s1.accept();
			BufferedReader loadbalancer=new BufferedReader(new InputStreamReader(connection.getInputStream()));
			String csentence=loadbalancer.readLine();
			System.out.println("Received from Load Balancer: "+csentence);
		}
	}
}