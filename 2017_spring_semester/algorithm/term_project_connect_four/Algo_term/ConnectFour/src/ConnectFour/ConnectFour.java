package ConnectFour;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ConnectFour extends JFrame implements ActionListener {
   public final static int ROW = 9;      // 게임판의 가로 길이
   public final static int COL = 8;      // 게임판의 세로 길이
   // 게임에 필요한 판넬, 라벨, 버튼 생성
   JLabel lblPlayer = new JLabel("Player: ");
   JLabel lblCurrentPlayer = new JLabel("Blue");
   JPanel pnlMenu = new JPanel();      // 메뉴에 대한 판넬
   JPanel pnlBoards = new JPanel();   // 보드를 위한 판넬
   JButton btnNewGame2 = new JButton("New Game");   // 새 게임
   JButton btnNewGame3 = new JButton("P vs P");   // 사vs사
   JButton btnNewGame4 = new JButton("P vs AI");   // 사vs컴
   JButton btnHint = new JButton("Hint");
   JButton btnUndo = new JButton("Undo");

   Board[][] Boards = new Board[ROW][COL]; // 보드게임판 설정

   Location[] Locations = new Location[ROW * COL];   // undo를 하기 위해 말의 위치를 저장하는 배열

   // 변수 초기화
   boolean winnerExists = false;   // 승리자가 있는지를 확인할 flag
   boolean isHint = false;         // 힌트기능을 사용했는지에 대한 flag
   int currentPlayer = 1;         // 현재 플레이어(1:blue, 2:red)
   
   boolean AI;      // AI 기능을 위한 flag
   

   public int NumUndo = 0;   // Undo기능을 위한 인덱스

   // 생성자 (게임보드 생성)
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
            Boards[i][j] = new Board(i, j); // 보드 생성.
            Boards[i][j].addActionListener(this); // 클릭
            pnlBoards.add(Boards[i][j]); // 판넬에 모두 추가.
         }

      add(pnlMenu, BorderLayout.NORTH); // 메뉴를 맨위에 추가
      add(pnlBoards, BorderLayout.CENTER); // 보드를 가운데 추가
      setSize(500, 500);
      setVisible(true);

      if (currentPlayer == 2 && AI)
         insertTo(BestChoice());
   }

   // 마우스 클릭에 따른 ActionListener
   public void actionPerformed(ActionEvent ae) {
      if (ae.getSource() == btnNewGame2) {
         if (JOptionPane.showConfirmDialog(this, "Are you sure you want to quit?", "Confirmation",
               JOptionPane.YES_NO_OPTION) == 0) {
            dispose();
            new ConnectFour(AI); // true값 넣으면 AI 실시하게됨.
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
            new ConnectFour(true); // true값 넣으면 AI 실시하게됨.
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
   
   // 보드 위치에 말을 놓는 함수
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

      Locations[NumUndo] = new Location(i, j); // undo할 위치를 저장.

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
         currentPlayer = (currentPlayer % 2) + 1; // 플레이어 순서를 바꿈

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

   // Undo 기능
   void Undo(boolean AI) {
      // 사람vs사람 모드일때의 Undo기능
      if (NumUndo > 0 && !AI) {
         if (winnerExists == false) {
         // 말을 놓을때 마다 저장된 보드의 위치 Location을 이용해 
         // 가장 최근에 놓은 말의 위치의 색을 흰색으로 변경
            Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
            NumUndo--;   // 변경 후 인덱스를 1 줄인다.
         currentPlayer = (currentPlayer % 2) + 1; // Undo를 하였으니 플레이어 턴을 변경한다.
         }
         else{
            Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
            NumUndo--;   // 변경 후 인덱스를 1 줄인다.
         }
         // 현재 플레이어 정보 출력
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
         // 승리자가 있을때 Undo를 하면 승리자가 사라짐을 나타낸다.
         winnerExists = false;
      } 
      // AI모드 일때의 Undo기능 : 플레이어가 놓은 말과 컴퓨터가 놓은 말을 Undo 해야 한다.
      else if (NumUndo > 0 && AI) {
         // Location에 저장된 말의 수가 2이상일때는 수를 두개 무르게 된다.
         if (NumUndo >= 2 && winnerExists == false) {
            Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
            Boards[Locations[NumUndo - 2].i][Locations[NumUndo - 2].j].setPiece(Piece.None);
            NumUndo = NumUndo - 2;
            currentPlayer = 1;
         }
         //  Location에 저장된 말의 수가 2이상이고, 승리자가 있을때 수를 무를 경우.
         else if (NumUndo >= 2 && winnerExists) { 
            if (currentPlayer % 2 == 1) { // 승리자가 파란색일 경우 수를 1개 무른다.
               Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
               NumUndo--;
            } else { // 승리가자 빨간색일 경우 수를 2개 무른다.
               Boards[Locations[NumUndo - 1].i][Locations[NumUndo - 1].j].setPiece(Piece.None);
               Boards[Locations[NumUndo - 2].i][Locations[NumUndo - 2].j].setPiece(Piece.None);
               NumUndo = NumUndo - 2;
            }
            currentPlayer = 1;
         }
         // 현재 플레이어 정보 출력
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
         // 승리자가 있을때 Undo를 하면 승리자가 사라짐을 나타낸다.
         winnerExists = false;
      }

   }
   
   public void Hint() {   // 힌트 기능
      if(isHint)      // 한 턴에 힌트 기능 딱 한 번 사용하기 위하여
         return;      // 힌트기능이 실행되었다면 힌트 함수를 실행하지 않음
      
      // 가중치 계산을 통하여 현재 턴의 최적의 위치를 찾아
      WeightBoard WeightBoard = new WeightBoard(Boards, ROW, COL, currentPlayer);
      WeightBoard.WeightPoint();
      
      // 해당 위치를 Locations에 저장
      // 힌트 기능 또한 보드의 위치에 말을 놓아 표시하는 것으로
      // 힌트 기능이 끝난 후 다음 말을 놓는 이벤트 발생 시 Undo를 하기 위함
      Locations[NumUndo] = new Location(WeightBoard.X, WeightBoard.Y);
      NumUndo++;
      currentPlayer = (currentPlayer % 2) + 1;
      
      // 가중치 계산으로 찾은 위치를 초록색으로 출력
      System.out.println("x = " + WeightBoard.X + "   Y = " + WeightBoard.Y);
      Boards[WeightBoard.X][WeightBoard.Y].setPiece(Piece.Green);
      
      // flag 초기화(힌트기능을 사용함)
      isHint = true;
   }
   public Board BestChoice() {      // AI가 놓기 가장 좋은 위치를 반환
      WeightBoard WeightBoard = new WeightBoard(Boards, ROW, COL);
      WeightBoard.WeightPoint();

      System.out.println("x = " + WeightBoard.X + "   Y = " + WeightBoard.Y);
      return Boards[WeightBoard.X][WeightBoard.Y];
   }

   // 게임 보드가 꽉차있는지 확인
   public boolean boardIsFull() {
      for (int i = 0; i < ROW; i++) {
         if (Boards[i][0].piece == Piece.None)
            return false;
      }
      return true;
   }

   /// 연결된 4목 있는지 찾는 부분
   public boolean thereIsAWinner() {

      // 모든 보드에 대해서 검사한다.
      for (int j = 0; j < COL; j++) {
         for (int i = 0; i < ROW; i++) {
            if (Boards[i][j].piece != Piece.None && connectsToFour(i, j))
               return true;
         }
      }
      return false;
   }

   public boolean connectsToFour(int i, int j) {
      // 한 보드를 기준으로 8방향 으로 탐색
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
         // 모든 보드 확인과정에서 보드 범위를 벗어나게 되면 return false
         if (x + i * k < 0 || y + j * k < 0 || x + i * k >= Boards.length || y + j * k >= Boards[0].length)
            return false;
         // 확인과정중 색깔이 다르면 return false
         if (Boards[x + i * k][y + j * k].piece != color)
            return false;
      }
      // 4개로 연결 되있으면 return true
      return true;
   }

   public static void main(String[] args) {
      new ConnectFour(false);
   }
}