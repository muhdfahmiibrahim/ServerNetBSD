import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class server{

	public static void main(String[] args){
	
	  try{

		System.out.println("Listening to client.....");
		ServerSocket s1 = new ServerSocket(5471);
		Socket s2 = s1.accept();
		System.out.println("Connected");
		BufferedReader in = new BufferedReader(new 
InputStreamReader(s2.getInputStream()));

		String a = in.readLine();
		PrintWriter out = new 
PrintWriter(s2.getOutputStream(),true);

		String text = "Assalamualaikum" ;
		if(a.equalsIgnoreCase(text))

			{ out.println("Server:Waalaikumussalam"); }
		else
	         	{ out.println("Server:Are you muslim?"); }
	}
	catch(Exception e)
	{ e.printStackTrace(); }
  }
}
