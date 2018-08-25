package ConnectFour;

import java.awt.*;

public enum Piece {
	Red(Color.RED), Blue(Color.BLUE), None(Color.WHITE), Green(Color.GREEN);

	// Color 변수 pieceColor 선언.
	public final Color pieceColor; // attributes of the specific constant
	// 생성자,

	private Piece(Color theColor) { // constructor to set these attributes
		this.pieceColor = theColor; // pieceColor값 생성과동시에 초기화
	}
}