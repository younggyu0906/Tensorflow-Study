package ConnectFour;

import javax.swing.*;

public class Board extends JButton {
	public int i, j; // ���� ��ġ X, Y��ǥ
	public Piece piece = Piece.None; // �Ͼ������ �ʱ�ȭ
	public int weight = 0;	// �� ������ ��ġ�� ���� ����ġ

	// ���� ������
	public Board(int i, int j) {
		this.i = i;
		this.j = j;
		this.weight = 0;
		setOpaque(true);
		setColor();
	}

	// ������
	public void setPiece(Piece piece) {
		this.piece = piece;
		setColor();
	}

	public void setColor() {	// ������ ���� ����
		setBackground(piece.pieceColor);
	}
}