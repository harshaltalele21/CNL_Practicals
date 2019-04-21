package udp;
import java.io.*;
import java.util.logging.Logger;
import java.net.*;

public class LogUDPThread extends Thread {

    protected DatagramSocket socket = null;
    protected boolean listen = true;

    public LogUDPThread() throws IOException {
        this("UDPThread");
    }

    public LogUDPThread(String name) throws IOException {
        super(name);
        socket = new DatagramSocket(4445); //Java DatagramSocket class represents a connection-less socket for sending and receiving datagram packets.

    }

    public void run() {
        byte[] buf = new byte[10000];
        DatagramPacket packet = new DatagramPacket(buf, buf.length); //DatagramPacket(byte[] barr, int length): it creates a datagram packet. This constructor is used to receive the packets
        
        while (listen) {
            try {
                // receive request
                socket.receive(packet);
                
                // figure out response
                String packetData = new String(packet.getData(), "UTF8");
                RawLog log = new RawLog();
                log.dataString = packetData;
                log.timestamp = new Date();
                log.sourceAddress = packet.getAddress().getHostAddress();
                log.sourceName = packet.getAddress().getCanonicalHostName();
                log.sourceType = "UDP";
                
                Main.messagesToLog.add(log);

            } catch (Exception e) {
                e.printStackTrace();
                listen = false;
            }
        }
        socket.close();
    }
}