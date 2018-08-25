import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class KYGWebServer {
    public static void main(String[] args) throws Exception {
        System.out.println("The capitalization server is running.");
        int clientNumber = 1;
        ServerSocket listener = new ServerSocket(8080);
        try {
            while (true) {
                new Capitalizer(listener.accept(), clientNumber++).start();
            }
        } finally {
            listener.close();
        }
    }

    private static class Capitalizer extends Thread {
        private Socket socket;
        private int clientNumber;
        private String temp;

        public Capitalizer(Socket socket, int clientNumber) {
            this.socket = socket;
            this.clientNumber = clientNumber;
            log("New connection with client # " + clientNumber + " at " + socket);
        }

        public void run() {
            try {
                BufferedReader in = new BufferedReader(
                        new InputStreamReader(socket.getInputStream()));
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

                out.println("Hello, you are client #" + clientNumber + ".");
                out.println("Enter a file\n");

                while (true) {
                    String input = in.readLine();
                    temp = input;
                    out.println(input);
                    if (input == "text" || input == "TEXT") {
                    	out.println("text file");
                    }
                    else {
                    	break;
                    }
                }
            } catch (IOException e) {
                log("404 Not Found\n");
            } finally {
                try {
                    socket.close();
                } catch (IOException e) {
                    log("Couldn't close a socket, what's going on?");
                }
                log("Connection with client# " + clientNumber + " closed");
            }
        }

        private void log(String message) {
            System.out.println(message);
        }
    }
}