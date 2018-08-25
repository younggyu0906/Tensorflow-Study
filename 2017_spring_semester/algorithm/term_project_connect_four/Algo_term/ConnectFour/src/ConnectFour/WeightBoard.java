package ConnectFour;

public class WeightBoard {
	public int i, j;	// 보드 위치(X, Y 좌표)
	public int row, col;	// 게임보드의 가로,세로열의 크기
	public int currentplayer;	// 현재 플레이어(1 : Blue, 2 : Red)
	public int calccolor;		// 현재 계산중인 색깔(1 : Blue, 2 : Red)
	public int X = 0, Y = 0;	// 가중치가 가장 큰 보드 위치의 X, Y좌표
	public int m_temp = 0;		// 가중치 비교를 위한 변수, 가장 큰 가중치 값을 저장
	// public Piece piece = Piece.None;
	// public int value;
	Board[][] Boards; // 게임보드

	// 생성자
	public WeightBoard(int r, int c) {
		row = r;
		col = c;
	}
	// 생성자
	public WeightBoard(Board[][] Boards) {
		this.Boards = Boards;
	}
	// 생성자
	public WeightBoard(Board[][] Boards, int r, int c) { // 현재 플레이어를 지정하지 않았을 경우는
		this.Boards = Boards; // 컴퓨터의 가중치 계산이므로
		row = r;
		col = c;
		currentplayer = 2; // 현재 플레이어 = 빨강
	}
	// 생성자
	public WeightBoard(Board[][] Boards, int r, int c, int cp) {	// 사람vs사람
		this.Boards = Boards;				// 의 경우는 현재 턴의 플레이어 색깔을 알아야 한다
		row = r;
		col = c;
		currentplayer = cp;
	}

	// 연결된 말의 수, 플레이어 턴, 말의 색깔에 따른 가중치 부여 함수
	public int calcWeight(int t) {
		// 연결된 말의 수에 따라 가중치가 각각 다름.
		int value = 0;
		int temp = t;
		// 현재턴의 플레이어와 계산 할 말 색깔이 다를 경우
		if ((currentplayer == 2 && calccolor == 1) || (currentplayer == 1 && calccolor == 2)) {
			if (temp >= 3)
				value += 300;
			else if (temp == 2)
				value += 27;
			else if (temp == 1)
				value += 3;
			else
				value += 0;
		} 
		// 현재턴의 플레이어와 계산 할 말 색깔이 같을 경우
		else if ((currentplayer == 1 && calccolor == 1) || (currentplayer == 2 && calccolor == 2)) {
			if (temp >= 3)
				value += 500;
			else if (temp == 2)
				value += 30;
			else if (temp == 1)
				value += 5;
			else
				value += 0;
		} 
		else {	// 위의 경우가 아닐 경우 에러
			System.out.println("Weight calculation error");
			value = 0;
		}
		return value;
	}
	// 가중치가 가장 큰 보드의 위치를 구함.
	void WeightPoint() {
		Location[] Locations = new Location[row];
		int index = 0;
		int j = 0;
		// int num = 0;
		// int weight = 0;


		for (int i = 0; i < row; i++) { // 말을 놓을 수 있는 위치를 탐색
			if (Boards[i][0].piece == Piece.None) {
				for (int k = 0; k < col; k++) {
					while (j < Boards[0].length - 1 && Boards[i][j + 1].piece == Piece.None)
						j++;
				}

				// 여기서 i,j에 대해서 8방향으로 탐색.
				Boards[i][j].weight = currentTurnWeight(i, j);
				// ******
				System.out.println("[i][j] = [" + i + "][" + j + "] =" + Boards[i][j].weight);
				// ********
				if(m_temp < Boards[i][j].weight )
					 m_temp = Boards[i][j].weight;
				
				j = 0;
			}
		}
		
		for (int i = 0; i < row; i++) {
			if (Boards[i][0].piece == Piece.None) {
				for (int k = 0; k < col; k++) {
					while (j < Boards[0].length - 1 && Boards[i][j + 1].piece == Piece.None)
						j++;
				}
				Boards[i][j].weight = currentTurnWeight(i, j);
				if (m_temp == Boards[i][j].weight) {
					
					Locations[index] = new Location(i, j);
					index++;
				}
				j = 0;
			}
		}
		
		int r_num = (int) (Math.random()*(index));
		X = Locations[r_num].i;
		Y = Locations[r_num].j;

	}

	// 다음 턴의 가중치
	public int nextTurnWeight(int x, int y) {
		//currentplayer = currentplayer%2 + 1;
		int temp = weightCalc(x, y) - 40;
		return temp;
	}

	// 가중치 계산
	public int weightCalc(int x, int y) {
		int temp = 0; 
		int value = 0;
		// 빨강색 탐색
		calccolor = 2;
		temp += countRedConnect(x, y, -1, -1);
		temp += countRedConnect(x, y, 1, 1);
		value += calcWeight(temp);
		temp = 0;

		temp += countRedConnect(x, y, 1, 0);
		temp += countRedConnect(x, y, -1, 0);
		value += calcWeight(temp);
		temp = 0;

		temp += countRedConnect(x, y, 0, 1);
		temp += countRedConnect(x, y, 0, -1);
		value += calcWeight(temp);
		temp = 0;

		temp += countRedConnect(x, y, 1, -1);
		temp += countRedConnect(x, y, -1, 1);
		value += calcWeight(temp);
		temp = 0;

		// 파란색
		calccolor = 1;
		temp += countBlueConnect(x, y, -1, -1);
		temp += countBlueConnect(x, y, 1, 1);
		value += calcWeight(temp);
		temp = 0;

		temp += countBlueConnect(x, y, 1, 0);
		temp += countBlueConnect(x, y, -1, 0);
		value += calcWeight(temp);
		temp = 0;

		temp += countBlueConnect(x, y, 0, 1);
		temp += countBlueConnect(x, y, 0, -1);
		value += calcWeight(temp);
		temp = 0;

		temp += countBlueConnect(x, y, 1, -1);
		temp += countBlueConnect(x, y, -1, 1);
		value += calcWeight(temp);
		temp = 0;

		return value;
	}

	// 가중치 : 현재 가중치 , 다음 턴 가중치를 비교.
	public int currentTurnWeight(int x, int y) {
		int value = 0;
		value += weightCalc(x, y);

		int n = nextTurnWeight(x, y - 1);
		if (n > 250)
			if (value > n)
				return value;
			else
				return value=0;

		return value;
	}

	// 파라미터 설명 : x,y는 보드위치 i,j는 방향을 나타냄
	public int countRedConnect(int x, int y, int i, int j) {
		int connectedNum = 0;

		// 1<k<4 인이유.. 4목이라서... 1칸떨어질때... 2칸 떨어질때.. ..4칸떨어질때 차례대로 계산한다.
		for (int k = 1; k < 4; k++) {
			// 선택한 보드 기준으로 떨어진 보드위치를 확인하는데... 보드 범위, 즉 바깥으로 나가면 return 0;
			if (x + i * k < 0 || y + j * k < 0 || x + i * k >= Boards.length || y + j * k >= Boards[0].length)
				return connectedNum;
			// if(Boards[x+i][y+j].piece == Piece.None)
			// return 0;
			// 한 방향을 이웃한 보드칸이 같은 색이면 가중치값을 1증가 시킴
			if (Boards[x + i * k][y + j * k].piece != Piece.Red)
				return connectedNum;
			else
				connectedNum++;
		}
		return connectedNum;
	}

	public int countBlueConnect(int x, int y, int i, int j) {
		int connectedNum = 0;

		// 1<k<4 인이유.. 4목이라서... 1칸떨어질때... 2칸 떨어질때.. ..4칸떨어질때 차례대로 계산한다.
		for (int k = 1; k < 4; k++) {
			// 선택한 보드 기준으로 떨어진 보드위치를 확인하는데... 보드 범위, 즉 바깥으로 나가면 return 0;
			if (x + i * k < 0 || y + j * k < 0 || x + i * k >= Boards.length || y + j * k >= Boards[0].length)
				return connectedNum;
			// if(Boards[x+i][y+j].piece != Piece.Blue)
			// return 0;
			// 한 방향을 이웃한 보드칸이 같은 색이면 가중치값을 1증가 시킴
			if (Boards[x + i * k][y + j * k].piece != Piece.Blue)
				return connectedNum;
			else
				connectedNum++;
		}
		return connectedNum;
	}
}