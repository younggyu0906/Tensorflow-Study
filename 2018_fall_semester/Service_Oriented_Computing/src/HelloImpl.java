import java.rmi.RemoteException;
import java.rmi.server.*;

//구체적인 내용은 UnicastREmoteObject에 구현되어있음.
public class HelloImpl extends UnicastRemoteObject implements Hello {

    //생성자가 Exception을 처리해줘야한다
    protected HelloImpl() throws RemoteException {
        super();
    }

    @Override
    public String sayHello(String name) throws RemoteException {
        return "Hello World";
    }
}