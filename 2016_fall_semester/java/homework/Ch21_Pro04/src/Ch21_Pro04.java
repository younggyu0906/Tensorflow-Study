class NegativeBalanceException extends Exception {
	public NegativeBalanceException() {
		super("Negative Balance Exception");
	}
}

class BankAccount {
	private int balance = 0;
	// �Ա� �޼ҵ�
	public void deposit(int money) {
		balance += money;
	}
	// ��� �޼ҵ�
	public void withdraw(int money) throws NegativeBalanceException {
		if(money > balance)	// ����Ϸ��� �ݾ��� �ܾ׺��� ũ�� ���ܸ� �߻����� ����
			throw new NegativeBalanceException();
		else
			balance -= money;
	}
	// �ܾ� ��� �޼ҵ�
	public void display() {
		System.out.println("balance = " + balance);
	}
}

public class Ch21_Pro04 {
	public static void main(String[] args) {
		BankAccount b = new BankAccount();
		b.display();		// �ܾ� 0
		b.deposit(10000);	// 10000�Ա�
		b.display();		// �ܾ� 10000
		try {	// ���ܰ� �߻��� �� �ִ� �ڵ�
			b.withdraw(6000);	// 6000 ���
		} catch (NegativeBalanceException e) {	// ����ó��
			System.out.println(e.getMessage());	// �ֿܼ� ���� �޽��� ���
			e.printStackTrace();				// ������ �߻��� ���� ���
		}
		b.display();		// �ܾ� 4000
		try {	// ���ܰ� �߻��� �� �ִ� �ڵ�
			b.withdraw(6000);	// 6000 ��� ���ܹ߻�!!
		} catch (NegativeBalanceException e) {	// ����ó��
			System.out.println(e.getMessage());	// �ֿܼ� ���� �޽��� ���
			e.printStackTrace();				// ������ �߻��� ���� ���
		}
		b.display();		// �ܾ� 4000��
	}
}
