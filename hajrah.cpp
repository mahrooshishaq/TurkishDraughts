//#include<SFML/Graphics.hpp>
//#include<time.h>
//#include<string.h>
//using namespace sf;
//
//int block_size = 50; //block size
//Vector2i offset(45, 22);
//int grid[8][8];
//int score = 0;
//
//int Random()
//{
//	int r = rand() % 5 + 1;
//	return r;
//}
//void swapc(int x, int y, int x1, int y1)
//{
//	int temp = grid[x][y];
//	grid[x][y] = grid[x1][y1];
//	grid[x1][y1] = temp;
//}
//void specialgemradius(int grid[][8], int x, int y) //eliminating gems within a radius and adding new gems
//{
//
//	int row = x + 1;
//	int col = y + 1;
//	int tempc = col;
//	for (; row >= 0 && row - 3 >= 0; row--)
//	{
//		for (int i = 1; i <= 3; i++)
//		{
//			grid[row][col] = grid[row + 3][col];
//			col--;
//		}
//	}
//	for (; row >= 0; row--) //generate gems
//	{
//		for (int k = 1; k <= 3; k++)
//		{
//			grid[row][tempc] = Random();
//			tempc--;
//		}
//	}
//}
//void fillgrid(int grid[][8], int R) // fill the grid randomly //
//{
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			grid[i][j] = Random();
//		}
//		//cout << "\n";
//	}
//}
//bool rowchecker(int grid[][8], int R)
//{
//	int x, y;
//	int spec;
//	int count = 1;
//	bool flag = 0;
//	bool isSpecial = false;
//	for (int j = 0; j < 8 && flag == 0; j++) //handling columns
//	{
//		count = 1;
//		isSpecial = false;
//		for (int i = 0; i < 7 && flag == 0; i++) //handling rows
//		{
//			if (grid[i][j] == grid[i + 1][j])
//			{
//				// is special found, change the value of isSpecial to true
//
//				count++;
//			}
//			else if (count >= 3)
//			{
//				x = i - count;
//				y = j;
//				flag = 1;
//			}
//			else
//			{
//				count = 1;
//				isSpecial = false;
//			}
//		}
//		if (!flag && count >= 3)
//		{
//			x = 7 - count;
//			y = j;
//			flag = 1;
//
//		}
//	}
//	if (flag) // when there are 3 same gems in a row /
//	{
//		score += count;
//		if (isSpecial)
//		{
//			// explode the radius
//		}
//		else
//		{
//			if (count >= 4)
//			{
//				// create your special gem
//			}
//			for (int j = y; y > 0; y--)
//			{
//				for (int i = x; i < x + count; i++)
//				{
//					grid[i][j] = grid[i][j - 1];
//				}
//			}
//
//			for (int i = x; i < x + count; i++)
//			{
//				grid[i][0] = Random();
//			}
//		}
//
//
//	}
//	return flag;
//}
//bool columnchecker(int grid[][8], int R)
//{
//
//	int x, y;
//	int spec;
//	int count = 1;
//	bool flag = 0;
//	bool isSpecial = false;
//	for (int i = 0; i < R && flag == 0; i++) // handling columns /
//	{
//		count = 1;
//		isSpecial = false;
//		for (int j = 0; j < 7; j++) // handling rows /
//		{
//			if (grid[i][j] == grid[i][j + 1])
//				// is special found, change the value of isSpecial to true
//				count++;
//			else if (count >= 3)
//			{
//				x = i;
//				y = j - count;
//				flag = 1;
//
//
//			}
//			else
//			{
//				count = 1;
//				isSpecial = false;
//			}
//		}
//		if (!flag && count >= 3)
//		{
//			x = i;
//			y = 7 - count;
//			flag = 1;
//		}
//	}
//
//	if (flag)
//	{
//		score += count;
//		if (isSpecial)
//		{
//			// explode the radius
//		}
//		if (count >= 4)
//		{
//			// create your destroyer gem			
//		}
//		for (int j = y - 1; j >= 0; j--)
//		{
//			grid[x][j + count] = grid[x][j];
//		}
//		for (int j = 0; j < count + 1; j++)
//		{
//			grid[x][j] = Random();
//		}
//	}
//
//
//	return flag;
//}
//void elbowgems(int grid[][8], int R)
//{
//	int x, y;
//	bool flag = 0;
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < 8 && flag == 0; j++)
//		{
//			x = i;
//			y = j;
//			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2])
//			{
//				flag = 1;
//			}
//			else if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && i > 1)
//			{
//				flag = 1;
//			}
//			else if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j] && grid[i][j] == grid[i][j - 1] && grid[i][j] == grid[i][j - 2] && i > 1)
//			{
//				flag = 1;
//			}
//			else if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i][j - 1] && grid[i][j] == grid[i][j - 2])
//			{
//				flag = 1;
//			}
//		}
//
//	}
//	if (flag == 1)
//	{
//		grid[x][y] = 11;
//		int m = x;
//		int a = 0;
//		for (int k = 0; k < 8; k++) //to fill a whole column
//		{
//			grid[x + a][y] = rand() % 5 + 1;
//			a++;
//		}
//
//		int b = 0;
//		for (; x >= 0; x--) //to fill rows before the column filled
//		{
//			for (; b < y; b++)
//			{
//				grid[x][b] = grid[x - 1][b];
//			}
//		}
//		b = b + 1;
//		for (; m >= 0; m--) //to fill rows after the column filled
//		{
//			for (; b < 8; b++)
//			{
//				grid[m][b] = grid[m - 1][b];
//
//			}
//		}
//	}
//
//
//}
//void printgems(int grid[][8], int R)
//{
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			if (grid[i][j] == 1)
//			{
//				//enter graphics for gems
//			}
//			if (grid[i][j] == 2)
//			{
//
//			}
//			if (grid[i][j] == 3)
//			{
//
//			}
//			if (grid[i][j] == 4)
//			{
//
//			}
//			if (grid[i][j] == 5)
//			{
//
//			}
//			//special gems
//			if (grid[i][j] == 6)
//			{
//				//special version of 1
//			}
//			if (grid[i][j] == 7)
//			{
//				//special version of 2
//			}
//			if (grid[i][j] == 8)
//			{
//				//special version of 3
//			}
//			if (grid[i][j] == 9)
//			{
//				//special version of 4
//			}
//			if (grid[i][j] == 10)
//			{
//				//special version of 5
//			}
//			//flame gem made by elbow gems
//			if (grid[i][j] == 11)
//			{
//
//			}
//		}
//	}
//}
//void timer(int minutes, int seconds)
//{
//	for (;;)
//	{
//		if (minutes == 0 && seconds == 0)
//		{
//			minutes = 60;
//		}
//		else
//		{
//			if (seconds == 0)
//			{
//				minutes--;
//				seconds = 60;
//			}
//		}
//
//	}
//
//
//}
//
//void main()
//{
//	float r, row, col;
//	int x = 0, y = 0;
//
//	srand(time(0));
//	RenderWindow app(VideoMode(800, 500), "Match-3 Game");
//	app.setFramerateLimit(60);
//
//	Texture t1, t0, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
//	t1.loadFromFile("Images/darktemptation.png");
//	t0.loadFromFile("Images/Gridx.png");
//	t2.loadFromFile("Images/crystal.png");
//	t3.loadFromFile("Images/purple.png");
//	t4.loadFromFile("Images/red.png");
//	t5.loadFromFile("Images/diamond.png");
//	t6.loadFromFile("Images/pink.png");
//	t7.loadFromFile("Images/cursor.png");
//	t8.loadFromFile("Images/red.focus.png");
//	t9.loadFromFile("Images/scorecard.png");
//	t10.loadFromFile("Images/blank-clock.png");
//	t11.loadFromFile("Images/red.focus.png");
//
//
//
//
//	RectangleShape background;
//	background.setSize(Vector2f(800.f, 500.f));
//	background.setTexture(&t1);
//	RectangleShape backdrop;
//	backdrop.setSize(Vector2f(400.f, 400.f));
//	backdrop.setPosition(Vector2f(350.f, 50.f));
//	backdrop.setTexture(&t0);
//
//	Font Arial;
//	Arial.loadFromFile("GothicA1-Bold.ttf");
//
//	Text ScoreLabel;
//	ScoreLabel.setCharacterSize(35);
//	ScoreLabel.setPosition(Vector2f(150.f, 95.f));
//	ScoreLabel.setFillColor(Color::White);
//	ScoreLabel.setFont(Arial);
//
//
//	Text TimerLabel;
//	TimerLabel.setCharacterSize(45);
//	TimerLabel.setPosition(Vector2f(100.f, 325.f));
//	TimerLabel.setFillColor(Color::White);
//	TimerLabel.setFont(Arial);
//
//
//	int time_i = clock(), time_f = clock();
//
//
//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			grid[i][j] = Random();
//
//
//		}
//	}
//
//	bool finish = false;
//
//	int cx = 0, cy = 0, cselected = 0;
//	int x1, y1;
//	while (app.isOpen() && finish == false)
//	{
//
//		time_f = clock();
//
//
//		bool col = true;
//		bool row = true;
//		do
//		{
//			col = columnchecker(grid, 8);
//			row = rowchecker(grid, 8);
//		} while (row == true || col == true);
//
//		ScoreLabel.setString(std::to_string(score));
//		int diff = (time_f - time_i) / 1000;
//
//		int remain = 60 - diff;
//		if (remain < 0) remain = 0;
//		if (remain == 0) finish = true;
//
//		TimerLabel.setString("00     " + std::to_string(remain));
//
//
//
//		Event e;
//		while (app.pollEvent(e))
//		{
//			if (e.type == Event::Closed)
//				app.close();
//
//			else if (e.type == Event::KeyPressed)
//			{
//				if (e.key.code == Keyboard::Left)
//				{
//					if (cx > 0)
//					{
//						if (cselected)
//						{
//							cselected = 0;
//							swapc(cx, cy, cx - 1, cy);
//							bool crow = rowchecker(grid, 8);
//							if (!crow)
//							{
//								bool ccol = columnchecker(grid, 8);
//								if (!ccol)
//									swapc(cx, cy, cx - 1, cy);
//							}
//
//						}
//						cx--;
//					}
//
//				}
//				else if (e.key.code == Keyboard::Right)
//				{
//					if (cx < 7)
//					{
//						if (cselected)
//						{
//							cselected = 0;
//							swapc(cx, cy, cx + 1, cy);
//							bool crow = rowchecker(grid, 8);
//							if (!crow)
//							{
//								bool ccol = columnchecker(grid, 8);
//								if (!ccol)
//									swapc(cx, cy, cx + 1, cy);
//							}
//						}
//						cx++;
//					}
//
//				}
//				else if (e.key.code == Keyboard::Up)
//				{
//					if (cy > 0) {
//						if (cselected)
//						{
//							cselected = 0;
//							swapc(cx, cy, cx, cy - 1);
//							bool crow = rowchecker(grid, 8);
//							if (!crow)
//							{
//								bool ccol = columnchecker(grid, 8);
//								if (!ccol)
//									swapc(cx, cy, cx, cy - 1);
//							}
//						}
//						cy--;
//					}
//				}
//				else if (e.key.code == Keyboard::Down)
//				{
//					if (cy < 7) {
//						if (cselected)
//						{
//							cselected = 0;
//							swapc(cx, cy, cx, cy + 1);
//							bool crow = rowchecker(grid, 8);
//							if (!crow)
//							{
//								bool ccol = columnchecker(grid, 8);
//								if (!ccol)
//									swapc(cx, cy, cx, cy + 1);
//							}
//						}
//						cy++;
//					}
//				}
//				else if (e.key.code == Keyboard::Return)
//				{
//					if (cselected) cselected = 0;
//					else cselected = 1;
//				}
//			}		app.clear();
//			// draw
//
//		}
//		app.clear();
//		app.draw(background);
//		app.draw(backdrop);
//
//
//		for (int i = 0; i < 8; i++)
//		{
//
//
//			for (int j = 0; j < 8; j++)
//			{
//				RectangleShape gem;
//				gem.setPosition(Vector2f(350.f + (i * 50), 50.f + (j * 50)));
//				gem.setSize(Vector2f(50.f, 50.f));
//				if (grid[i][j] == 1) gem.setTexture(&t2);
//				else if (grid[i][j] == 2) gem.setTexture(&t3);
//				else if (grid[i][j] == 3) gem.setTexture(&t4);
//				else if (grid[i][j] == 4) gem.setTexture(&t5);
//				else gem.setTexture(&t6);
//				app.draw(gem);
//
//
//			}
//		}
//
//		RectangleShape click;
//		click.setPosition(Vector2f(350.f + (cx * 50), 50.f + (cy * 50)));
//		click.setSize(Vector2f(50.f, 50.f));
//		if (cselected) click.setTexture(&t11);
//		else click.setTexture(&t7);
//
//
//		app.draw(click);
//
//
//
//
//		RectangleShape scoreboard;
//		scoreboard.setPosition(Vector2f(100.f, 40.f));
//		scoreboard.setSize(Vector2f(150.f, 150.f));
//		scoreboard.setTexture(&t9);
//		app.draw(scoreboard);
//		RectangleShape timer;
//		timer.setPosition(Vector2f(80.f, 300.f));
//		timer.setSize(Vector2f(210.f, 100.f));
//		timer.setTexture(&t10);
//		app.draw(timer);
//
//		app.draw(ScoreLabel);
//		app.draw(TimerLabel);
//		app.display();
//	}
//}