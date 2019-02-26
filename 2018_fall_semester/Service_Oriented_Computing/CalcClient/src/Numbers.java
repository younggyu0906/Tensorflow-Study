import java.util.HashMap;
import java.io.Serializable;

public class Numbers implements Serializable {
    HashMap numbers;

    public Numbers(int size) {
        numbers = new HashMap(size);
    }

    public void setNumbers(int key, int value) {
        numbers.put(key, value);
    }

    public int getNumbers(int key) {
        return (Integer)numbers.get(key);
    }

    public int size() {
        return numbers.size();
    }
}
