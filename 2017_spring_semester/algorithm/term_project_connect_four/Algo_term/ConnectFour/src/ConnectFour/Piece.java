package ConnectFour;

import java.awt.*;

public enum Piece {
	Red(Color.RED), Blue(Color.BLUE), None(Color.WHITE), Green(Color.GREEN);

	// Color ���� pieceColor ����.
	public final Color pieceColor; // attributes of the specific constant
	// ������,

	private Piece(Color theColor) { // constructor to set these attributes
		this.pieceColor = theColor; // pieceColor�� ���������ÿ� �ʱ�ȭ
	}
}