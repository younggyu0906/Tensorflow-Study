import java.rmi.*;
import java.rmi.server.*;
import java.util.Random;

public class Main {
    public static void main(String[] args) throws Exception {
        int size = 10;
        Numbers nums = new Numbers(size);
        Random random = new Random(System.currentTimeMillis());

        for (int i = 0; i < size; i++) {
            nums.setNumbers(i , random.nextInt(1000));
        }

        String url = "//172.18.65.129/calc";
        Calc remoteCalcObject = (Calc)Naming.lookup(url);
        System.out.println("Got remote object:" + remoteCalcObject);
        System.out.println(" 1 + 2 = " + remoteCalcObject.sum(1, 2));
        System.out.println(" Sum of " + size + " Random Numbers is " + remoteCalcObject.sumNumbers(nums));
    }
}
