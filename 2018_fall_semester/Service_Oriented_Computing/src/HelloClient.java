import java.rmi.*;

public class HelloClient {
    public static void main(String[] args) throws Exception {
        Hello h = (Hello)Naming.lookup("//172.18.65.129/hello");       //원격주소
        String message = h.sayHello("ygkim");
        System.out.println(message);
    }
}
