/*
    TCP JAVA CHAT
    SUSHRUT PATIL
    3162083
*/

import java.io.*;
import java.net.*;
public class client {
	public static void main(String[] args) throws Exception
	{
		Socket sock = new Socket("localhost", 8001); 
		// reading from keyboard (keyRead object)
		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
		// sending to server (pwrite object)
		OutputStream ostream = sock.getOutputStream(); 
		PrintWriter pwrite = new PrintWriter(ostream, true);
		//receiving from server ( receiveRead  object)
		InputStream istream = sock.getInputStream();
		BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));
		System.out.println("Start the chitchat, type and press Enter key");
		String receiveMessage, sendMessage;
		while(true)
		{
			sendMessage = keyRead.readLine(); //keyboard reading
			pwrite.println(sendMessage); // sending to server
			pwrite.flush(); // flush the data
			if((receiveMessage = receiveRead.readLine()) != null) //receive from server
			{
				System.out.println("From Server: "+receiveMessage); // displaying at DOS prompt
			}
		}
	}
}
