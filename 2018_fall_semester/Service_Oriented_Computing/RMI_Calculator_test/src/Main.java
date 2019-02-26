import java.rmi.*;
import java.rmi.server.*;

public class Main {

    public static void main(String[] args) throws Exception {
        CalcImpl h = new CalcImpl();
        Naming.bind("//localhost/hello", h);
        System.out.println("h = ");
        System.out.println("h = " + h);
    }
}
