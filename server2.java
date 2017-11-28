server.javaimport java.io.*;
import java.net.*;

public class server{
		public static void main(String []args)throws IOException{
		ServerSocket s2=new ServerSocket(3000);
		while(true){
			Socket connection=s2.accept();
			BufferedReader loadbalancer=new BufferedReader(new InputStreamReader(connection.getInputStream()));
			String csentence=loadbalancer.readLine();
			System.out.println("Received from Load Balancer: "+csentence);
		}
	}
}