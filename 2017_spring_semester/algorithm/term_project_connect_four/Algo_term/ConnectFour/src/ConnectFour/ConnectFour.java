package ConnectFour;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ConnectFour extends JFrame implements ActionListener {
   public final static int ROW = 9;      // �������� ���� ����
   public final static int COL = 8;      // �������� ���� ����
   // ���ӿ� �ʿ��� �ǳ�, ��, ��ư ����
   JLabel lblPlayer = new JLabel("Player: ");
   JLabel lblCurrentPlayer = new JLabel("Blue");
   JPanel pnlMenu = new JPanel();      // �޴��� ���� �ǳ�
   JPanel pnlBoards = new JPanel();   // ���带 ���� �ǳ�
   JButton btnNewGame2 = new JButton("New Game");   // �� ����
   JButton btnNewGame3 = new JButton("P vs P");   // ��vs��
   JButton btnNewGame4 = new JButton("P vs AI");   // ��vs��
   JButton btnHint = new JButton("Hint");
   JButton btnUndo = new JButton("Undo");

   Board[][] Boards = new Board[ROW][COL]; // ��������� ����

   Location[] Locations = new Location[ROW * COL];   // undo�� �ϱ� ���� ���� ��ġ�� �����ϴ� �迭

   // ���� �ʱ�ȭ
   boolean winnerExists = false;   // �¸��ڰ� �ִ����� Ȯ���� flag
   boolean isHint = false;         // ��Ʈ����� ����ߴ����� ���� flag
   int currentPlayer = 1;         // ���� �÷��̾�(1:blue, 2:red)
   
   boolean AI;      // AI ����� ���� flag
   

   public int NumUndo = 0;   // Undo����� ���� �ε���

   // ������ (���Ӻ��� ����)
   public ConnectFour(boolean AI) {
      super("Smart Four");
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      currentPlayer = (int) (Math.random() * 2) + 1;

      this.AI = AI;

      btnNewGame2.addActionListener(this);
      btnNewGame3.addActionListener(this);
      btnNewGame4.addActionListener(this);
      btnHint.addActionListener(this);
      btnUndo.addActionListener(this);

      switch (currentPlayer) {
      case 1:
         lblCurrentPlayer.setForeground(Color.blue);
         lblCurrentPlayer.setText("Blue");
         break;
      case 2:
         lblCurrentPlayer.setForeground(Color.red);
         lblCurrentPlayer.setText("Red");
         break;
      }

      pnlMenu.add(btnNewGame3);
      pnlMenu.add(btnNewGame4);
      pnlMenu.add(btnNewGame2);
      pnlMenu.add(btnHint);
      pnlMenu.add(btnUndo);
      pnlMenu.add(lblPlayer);
      pnlMenu.add(lblCurrentPlayer);

      pnlBoards.setLayout(new GridLayout(COL, ROW));

      for (int j = 0; j < COL; j++)
         for (int i = 0; i < ROW; i++) {
            Boards[i][j] = new Board(i, j); // ���� ����.
            Boards[i][j].addActionListener(this); // Ŭ��
            pnlBoards.add(Boards[i][j]); // �ǳڿ� ��� �߰�.
         }

      add(pnlMenu, BorderLayout.NORTH); // �޴��� ������ �߰�
      add(pnlBoards, BorderLayout.CENTER); // ���带 ��� �߰�
      setSize(500, 500);
      setVisible(true);

      if (currentPlayer == 2 && AI)
         insertTo(BestChoice());
   }

   // ���콺 Ŭ���� ���� ActionListener
   public void actionPerformed(ActionEvent ae) {
      if (ae.getSource() == btnNewGame2) {
         if (JOptionPane.showConfirmDialog(this, "Are you sure you want to quit?", "Confirmation",
               JOptionPane.YES_NO_OPTION) == 0) {
            dispose();
            new ConnectFour(AI); // true�� ������ AI �ǽ��ϰԵ�.
            return;
         }
      } else if (ae.getSource() == btnNewGame3) {
         if (JOptionPane.showConfirmDialog(this, "Are you sure you want to [P vs P]?", "Confirmation",
               JOptionPane.YES_NO_OPTION) == 0) {
            dispose();
            new ConnectFour(false); //
            return;
         }
      } else if (ae.getSource() == btnNewGame4) {
         if (JOptionPane.showConfirmDialog(this, "Are you sure you want to [P vs AI]?", "Confirmation",
               JOptionPane.YES_NO_OPTION) == 0) {
            dispose();
            new ConnectFour(true); // true�� ������ AI �ǽ��ϰԵ�.
            return;
         }
      } else if (ae.getSource() == btnHint) {
         if(winnerExists) return;
         Hint();
         System.out.println("undonum =" + NumUndo);
      } else if (ae.getSource() == btnUndo) {
         if(isHint) return;
         Undo(AI);
         System.out.println("undonum =" + NumUndo);
      } else if (!winnerExists) {
         
         Board Board = (Board) ae.getSource();
         insertTo(Board);
      }

   }
   
   // ���� ��ġ�� ���� ���� �Լ�
   void insertTo(Board Board) {
      
      if(isHint){
         Undo(false);
         isHint = false;
      }
      
      if (Board.piece != Piece.None)
         return;

      int i = Board.i;
      int j = Board.j;

      while (j < Boards[0].length - 1 && Boards[i][j + 1].piece == Piece.None)
         j++;

      Locations[NumUndo] = new Location(i, j); // undo�� ��ġ�� ����.

      switch (currentPlayer) {
      case 1:
         Boards[i][j].setPiece(Piece.Blue);
         NumUndo++;
         break;
      case 2:
         Boards[i][j].setPiece(Piece.Red);
         NumUndo++;
         break;
      }

      if (boardIsFull()) {
         lblPlayer.setText("DRAW");
         // lblCurrentPlayer.setText(" !!! ");
         winnerExists = true;
      }
      if (thereIsAWinner()) {
         lblPlayer.setText("Winner: ");
         winnerExists = true;
      } else {
         currentPlayer = (currentPlayer % 2) + 1; // �÷��̾� ������ �ٲ�

         switch (currentPlayer) {
         case 1:
            lblCurrentPlayer.setForeground(Color.blue);
            lblCurrentPlayer.setText("Blue");
            break;
         case 2:
            lblCurrentPlayer.setForeground(Color.red);
            lblCurrentPlayer.setText("Red");
            break;
         }

         if (currentPlayer == 2 && AI) {
            insertTo(BestChoice());
         }
      }
   }

   // Undo ���
   void Undo(boolean AI) {
      // ���vs��� ����϶��� Undo���
      if (NumUndo > 0 && !AI) {
         if (winnerExists == false) {
         // ���� ������ ���� ����� ������ ��ġ Location�� �̿��� 
         // ���� �ֱٿ� ���� ���� ��ġ�� ���� ������� ����
            Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
            NumUndo--;   // ���� �� �ε����� 1 ���δ�.
         currentPlayer = (currentPlayer % 2) + 1; // Undo�� �Ͽ����� �÷��̾� ���� �����Ѵ�.
         }
         else{
            Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
            NumUndo--;   // ���� �� �ε����� 1 ���δ�.
         }
         // ���� �÷��̾� ���� ���
         switch (currentPlayer) {
         case 1:
            lblCurrentPlayer.setForeground(Color.blue);
            lblCurrentPlayer.setText("Blue");
            break;
         case 2:
            lblCurrentPlayer.setForeground(Color.red);
            lblCurrentPlayer.setText("Red");
            break;
         }
         // �¸��ڰ� ������ Undo�� �ϸ� �¸��ڰ� ������� ��Ÿ����.
         winnerExists = false;
      } 
      // AI��� �϶��� Undo��� : �÷��̾ ���� ���� ��ǻ�Ͱ� ���� ���� Undo �ؾ� �Ѵ�.
      else if (NumUndo > 0 && AI) {
         // Location�� ����� ���� ���� 2�̻��϶��� ���� �ΰ� ������ �ȴ�.
         if (NumUndo >= 2 && winnerExists == false) {
            Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
            Boards[Locations[NumUndo - 2].i][Locations[NumUndo - 2].j].setPiece(Piece.None);
            NumUndo = NumUndo - 2;
            currentPlayer = 1;
         }
         //  Location�� ����� ���� ���� 2�̻��̰�, �¸��ڰ� ������ ���� ���� ���.
         else if (NumUndo >= 2 && winnerExists) { 
            if (currentPlayer % 2 == 1) { // �¸��ڰ� �Ķ����� ��� ���� 1�� ������.
               Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
               NumUndo--;
            } else { // �¸����� �������� ��� ���� 2�� ������.
               Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
               Boards[Locations[NumUndo - 2].i][Locations[NumUndo - 2].j].setPiece(Piece.None);
               NumUndo = NumUndo - 2;
            }
            currentPlayer = 1;
         }
         // ���� �÷��̾� ���� ���
         switch (currentPlayer) {
         case 1:
            lblCurrentPlayer.setForeground(Color.blue);
            lblCurrentPlayer.setText("Blue");
            break;
         case 2:
            lblCurrentPlayer.setForeground(Color.red);
            lblCurrentPlayer.setText("Red");
            break;
         }
         // �¸��ڰ� ������ Undo�� �ϸ� �¸��ڰ� ������� ��Ÿ����.
         winnerExists = false;
      }

   }
   
   public void Hint() {   // ��Ʈ ���
      if(isHint)      // �� �Ͽ� ��Ʈ ��� �� �� �� ����ϱ� ���Ͽ�
         return;      // ��Ʈ����� ����Ǿ��ٸ� ��Ʈ �Լ��� �������� ����
      
      // ����ġ ����� ���Ͽ� ���� ���� ������ ��ġ�� ã��
      WeightBoard WeightBoard = new WeightBoard(Boards, ROW, COL, currentPlayer);
      WeightBoard.WeightPoint();
      
      // �ش� ��ġ�� Locations�� ����
      // ��Ʈ ��� ���� ������ ��ġ�� ���� ���� ǥ���ϴ� ������
      // ��Ʈ ����� ���� �� ���� ���� ���� �̺�Ʈ �߻� �� Undo�� �ϱ� ����
      Locations[NumUndo] = new Location(WeightBoard.X, WeightBoard.Y);
      NumUndo++;
      currentPlayer = (currentPlayer % 2) + 1;
      
      // ����ġ ������� ã�� ��ġ�� �ʷϻ����� ���
      System.out.println("x = " + WeightBoard.X + "   Y = " + WeightBoard.Y);
      Boards[WeightBoard.X][WeightBoard.Y].setPiece(Piece.Green);
      
      // flag �ʱ�ȭ(��Ʈ����� �����)
      isHint = true;
   }
   public Board BestChoice() {      // AI�� ���� ���� ���� ��ġ�� ��ȯ
      WeightBoard WeightBoard = new WeightBoard(Boards, ROW, COL);
      WeightBoard.WeightPoint();

      System.out.println("x = " + WeightBoard.X + "   Y = " + WeightBoard.Y);
      return Boards[WeightBoard.X][WeightBoard.Y];
   }

   // ���� ���尡 �����ִ��� Ȯ��
   public boolean boardIsFull() {
      for (int i = 0; i < ROW; i++) {
         if (Boards[i][0].piece == Piece.None)
            return false;
      }
      return true;
   }

   /// ����� 4�� �ִ��� ã�� �κ�
   public boolean thereIsAWinner() {

      // ��� ���忡 ���ؼ� �˻��Ѵ�.
      for (int j = 0; j < COL; j++) {
         for (int i = 0; i < ROW; i++) {
            if (Boards[i][j].piece != Piece.None && connectsToFour(i, j))
               return true;
         }
      }
      return false;
   }

   public boolean connectsToFour(int i, int j) {
      // �� ���带 �������� 8���� ���� Ž��
      if (lineOfFour(i, j, -1, -1))
         return true;
      if (lineOfFour(i, j, -1, 0))
         return true;
      if (lineOfFour(i, j, -1, 1))
         return true;
      if (lineOfFour(i, j, 0, -1))
         return true;
      if (lineOfFour(i, j, 0, 1))
         return true;
      if (lineOfFour(i, j, 1, -1))
         return true;
      if (lineOfFour(i, j, 1, 0))
         return true;
      if (lineOfFour(i, j, 1, 1))
         return true;
      return false;
   }

   public boolean lineOfFour(int x, int y, int i, int j) {
      Piece color = Boards[x][y].piece;

      for (int k = 1; k < 4; k++) {
         // ��� ���� Ȯ�ΰ������� ���� ������ ����� �Ǹ� return false
         if (x + i * k < 0 || y + j * k < 0 || x + i * k >= Boards.length || y + j * k >= Boards[0].length)
            return false;
         // Ȯ�ΰ����� ������ �ٸ��� return false
         if (Boards[x + i * k][y + j * k].piece != color)
            return false;
      }
      // 4���� ���� �������� return true
      return true;
   }

   public static void main(String[] args) {
      new ConnectFour(false);
   }
}