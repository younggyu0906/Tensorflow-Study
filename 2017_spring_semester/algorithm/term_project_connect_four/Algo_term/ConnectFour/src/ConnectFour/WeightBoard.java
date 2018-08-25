package ConnectFour;

public class WeightBoard {
	public int i, j;	// ���� ��ġ(X, Y ��ǥ)
	public int row, col;	// ���Ӻ����� ����,���ο��� ũ��
	public int currentplayer;	// ���� �÷��̾�(1 : Blue, 2 : Red)
	public int calccolor;		// ���� ������� ����(1 : Blue, 2 : Red)
	public int X = 0, Y = 0;	// ����ġ�� ���� ū ���� ��ġ�� X, Y��ǥ
	public int m_temp = 0;		// ����ġ �񱳸� ���� ����, ���� ū ����ġ ���� ����
	// public Piece piece = Piece.None;
	// public int value;
	Board[][] Boards; // ���Ӻ���

	// ������
	public WeightBoard(int r, int c) {
		row = r;
		col = c;
	}
	// ������
	public WeightBoard(Board[][] Boards) {
		this.Boards = Boards;
	}
	// ������
	public WeightBoard(Board[][] Boards, int r, int c) { // ���� �÷��̾ �������� �ʾ��� ����
		this.Boards = Boards; // ��ǻ���� ����ġ ����̹Ƿ�
		row = r;
		col = c;
		currentplayer = 2; // ���� �÷��̾� = ����
	}
	// ������
	public WeightBoard(Board[][] Boards, int r, int c, int cp) {	// ���vs���
		this.Boards = Boards;				// �� ���� ���� ���� �÷��̾� ������ �˾ƾ� �Ѵ�
		row = r;
		col = c;
		currentplayer = cp;
	}

	// ����� ���� ��, �÷��̾� ��, ���� ���� ���� ����ġ �ο� �Լ�
	public int calcWeight(int t) {
		// ����� ���� ���� ���� ����ġ�� ���� �ٸ�.
		int value = 0;
		int temp = t;
		// �������� �÷��̾�� ��� �� �� ������ �ٸ� ���
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
		// �������� �÷��̾�� ��� �� �� ������ ���� ���
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
		else {	// ���� ��찡 �ƴ� ��� ����
			System.out.println("Weight calculation error");
			value = 0;
		}
		return value;
	}
	// ����ġ�� ���� ū ������ ��ġ�� ����.
	void WeightPoint() {
		Location[] Locations = new Location[row];
		int index = 0;
		int j = 0;
		// int num = 0;
		// int weight = 0;


		for (int i = 0; i < row; i++) { // ���� ���� �� �ִ� ��ġ�� Ž��
			if (Boards[i][0].piece == Piece.None) {
				for (int k = 0; k < col; k++) {
					while (j < Boards[0].length - 1 && Boards[i][j + 1].piece == Piece.None)
						j++;
				}

				// ���⼭ i,j�� ���ؼ� 8�������� Ž��.
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

	// ���� ���� ����ġ
	public int nextTurnWeight(int x, int y) {
		//currentplayer = currentplayer%2 + 1;
		int temp = weightCalc(x, y) - 40;
		return temp;
	}

	// ����ġ ���
	public int weightCalc(int x, int y) {
		int temp = 0; 
		int value = 0;
		// ������ Ž��
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

		// �Ķ���
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

	// ����ġ : ���� ����ġ , ���� �� ����ġ�� ��.
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

	// �Ķ���� ���� : x,y�� ������ġ i,j�� ������ ��Ÿ��
	public int countRedConnect(int x, int y, int i, int j) {
		int connectedNum = 0;

		// 1<k<4 ������.. 4���̶�... 1ĭ��������... 2ĭ ��������.. ..4ĭ�������� ���ʴ�� ����Ѵ�.
		for (int k = 1; k < 4; k++) {
			// ������ ���� �������� ������ ������ġ�� Ȯ���ϴµ�... ���� ����, �� �ٱ����� ������ return 0;
			if (x + i * k < 0 || y + j * k < 0 || x + i * k >= Boards.length || y + j * k >= Boards[0].length)
				return connectedNum;
			// if(Boards[x+i][y+j].piece == Piece.None)
			// return 0;
			// �� ������ �̿��� ����ĭ�� ���� ���̸� ����ġ���� 1���� ��Ŵ
			if (Boards[x + i * k][y + j * k].piece != Piece.Red)
				return connectedNum;
			else
				connectedNum++;
		}
		return connectedNum;
	}

	public int countBlueConnect(int x, int y, int i, int j) {
		int connectedNum = 0;

		// 1<k<4 ������.. 4���̶�... 1ĭ��������... 2ĭ ��������.. ..4ĭ�������� ���ʴ�� ����Ѵ�.
		for (int k = 1; k < 4; k++) {
			// ������ ���� �������� ������ ������ġ�� Ȯ���ϴµ�... ���� ����, �� �ٱ����� ������ return 0;
			if (x + i * k < 0 || y + j * k < 0 || x + i * k >= Boards.length || y + j * k >= Boards[0].length)
				return connectedNum;
			// if(Boards[x+i][y+j].piece != Piece.Blue)
			// return 0;
			// �� ������ �̿��� ����ĭ�� ���� ���̸� ����ġ���� 1���� ��Ŵ
			if (Boards[x + i * k][y + j * k].piece != Piece.Blue)
				return connectedNum;
			else
				connectedNum++;
		}
		return connectedNum;
	}
}