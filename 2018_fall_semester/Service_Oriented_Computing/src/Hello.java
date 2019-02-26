import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Hello extends Remote {
    //내가 서비스 해야할 메소드 (서버) 원격에서 호출당할 메소드
    public String sayHello(String name) throws RemoteException;
}