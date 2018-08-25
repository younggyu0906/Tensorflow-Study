package ConnectFour;

import javax.swing.*;

public class Board extends JButton {
	public int i, j; // 보드 위치 X, Y좌표
	public Piece piece = Piece.None; // 하얀색으로 초기화
	public int weight = 0;	// 각 보드의 위치에 대한 가중치

	// 보드 생성자
	public Board(int i, int j) {
		this.i = i;
		this.j = j;
		this.weight = 0;
		setOpaque(true);
		setColor();
	}

	// 접근자
	public void setPiece(Piece piece) {
		this.piece = piece;
		setColor();
	}

	public void setColor() {	// 보드의 색깔 변경
		setBackground(piece.pieceColor);
	}
}