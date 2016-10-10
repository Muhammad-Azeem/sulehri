#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

class Record
{
	protected:
		string Name;
		int Score;
	public:
		Record();
		//setter
		void set_name(string Name);
		void set_score(int Score);
		//gettter
		string get_name();
		int get_score();
		friend ostream& operator<<(ostream&,Record);
		void GetScore();
};
////////////////////////////// Get Score   ///////////////////////////////////////
void Record::GetScore()
{
	system("cls");
	ifstream infile("Rcord.txt",ios::app);
	if(!infile.is_open())
	{
		cout << "File Openning Error";
	}
	else
	{
		string line;
		while(getline(infile,line))
		{
			cout << line<<endl;
		}
	}

}
////////////////////////////// operator overloading through friend function ./////////////////
ostream& operator <<(ostream& output , Record obj)
{
	ofstream write("Rcord.txt",ios::app);
	write << obj.Name << "  "<< obj.Score<<endl;
}

//////////////////////////////   Constructor  ///////////////////////////////////
Record::Record()
{
	Name = "";
	Score = 0;
}
//////////////////////////////   Set Name  ///////////////////////////////////
void Record::set_name(string Name)
{
	this->Name = Name;
}
//////////////////////////////   Set Score  ///////////////////////////////////
void Record::set_score(int Score)
{
	this->Score = Score;
}
//////////////////////////////////// Get Name  ////////////////////////////////////////////
string Record::get_name()
{
	return Name;
}
//////////////////////////////////  Get Score  //////////////////////////////////////////////
int Record::get_score()
{
	return Score;
}
class Snake: public Record
{
	private:
		int Level;
		int MapWidth; //map dimension
		int MapHeight; //map dimension
		int size;
		int Map[15][25]; //creating array to hold values for the map
		int HeadxPosition; //snake position x
		int HeadyPosition; //snake position y
		int Direction; // changing snake direction
		int Food ; //snake size
		bool GameOver; //checking game is over or not
		Record obj;
	public:	
		//utility functions
		Snake();
		void Menu();
		void Instruction();
		void Speed();
		void PrintMap(); //print map
		void initiateMap(); //initiate map
		void Move(int dx, int dy); //changing directions
		void Update(); //update map 
		void ChangeDirection(char key); //help to change direction
		void GenerateFood(); //generate food
		char GetMapValue(int value); //getting values for food, map wall and snake
		void HighScore();
		void Run(); //for running game
		void GameFinish(); //printing gameover
};
//////////////////////////////////////// High Score ///////////////////////////////////////////
void Snake::HighScore()
{
	obj.GetScore();
	char opt;
	do
	{
		opt = getch();	
		if(opt==char(27) || opt==char(8))
		{
			Menu();
		}
	}while (opt!=char(27) );	
}
/////////////////////////////////////////////  Menu  /////////////////////////////////////////
void Snake::Menu()
{
	system("cls");
	cout << endl<<endl;
	cout << "\t\t\t ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t        1-->> PLAY GAME";
	cout << "\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t        2-->> INSTRUCTION";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t        3-->> HIGH SCORE";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t        4-->> LEVEL";
	cout << "\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t        5-->> EXIT";
	cout << "\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << endl;
	char opt;
	opt = getch();	
	switch(opt)
	{
		case '1':
			{
				Run();
			}
			break;
		case '2':
			{
				Instruction();
			}
			break;
		case '3':
			{
				HighScore();		
			}
			break;
		case '4':
			{
				Speed();
			}
			break;
		case '5':
			{
				cout << "Thank YOU!";
			}
			break;
		default:
			{
				Menu();
			}
	}
}
//////////////////////////////////////  Instruction  //////////////////////////////////////////////
void Snake::Instruction()
{
	system("cls");
	cout << "\t\t\t ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t   Press W 0r 1 to move up";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t   Press W 0r 2 to move right";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t   Press A 0r 4 to move left";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t   Press S 0r 3 to move Down";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << endl;	
	char opt;
	do
	{
		opt = getch();	
		if(opt==char(27) || opt==char(8))
		{
			Menu();
		}
	}while (opt!=char(27) );	
}
///////////////////////////////// Constructor /////////////////////////////////////////// 
Snake::Snake()
{
	MapWidth = 15;
	MapHeight = 25;
	Level = 3;
	size = MapWidth * MapHeight;
	Direction = 0;
	Food = 2;
	HeadxPosition = MapWidth / 2;
	HeadyPosition = MapHeight / 2;
	for (int i = 0 ; i < 15 ; i++)
	{
		for(int j=0 ; j<25 ; j++)
		{
			Map[i][j] = 0;	
		}
	}
}
////////////////////////////////// Speed ///////////////////////////////////////////////////
void Snake::Speed()
{
	system("cls");
	int opt;
	cout << "\t\t\t ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t   Press 1 For Easy     ";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t   Press 2 For Medium    ";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t   Press 3 For Hard     ";
	cout << "\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);
	cout << "\t\t\t\t\t     ";
	cout << char(219);
	cout << endl;
	cout << "\t\t\t ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << endl;		
	char select;
	do
	{
		select = getch();
		switch(select)
		{
			case '1':
				{
					Level = 1;
					Menu();
				}
				break;
			case '2':
				{
					Level = 2;
					Menu();
				}
				break;
			case '3':
				{
					Level = 3;
					Menu();
				}
				break;
			case char(27):
			case char(8):
				{
					Menu();	
				}
		}
	}while( select != 1 || select != 2 || select != 3 || select != char(8) || select!=char(27) );	
}
////////////////////////////////// Change Direction //////////////////////////////////////
void Snake::ChangeDirection(char key) {
    /*
      W
    A + D
      S

      1
    4 + 2
      3
    */
    switch (key) {
    case 'w':
    case '1':
        Direction = 0;
        break;
    case 'd':
    case '2':
        Direction = 1;
        break;
    case 's':
    case '3':
        Direction = 2;
        break;
    case 'a':
    case '4':
        Direction = 3;
        break;
    }
}
////////////////////////////////////// Move /////////////////////////////////////////////
void Snake::Move(int dx, int dy) 
{
    // determine new head position
    int newx = HeadxPosition + dx;
    int newy = HeadyPosition + dy;

    // Check if there is food at location
    if (Map[newx][newy] == -2) {
        // Increase food value (body length)
        Food++;

        // Generate new food on map
        GenerateFood();
    }

    // Check location is free
    else if (Map[newx][newy] != 0) 
	{
		{
			Map[newx][newy] = -1;
		}
		GameOver = false;
    }

    // Move head to new location
    HeadxPosition = newx;
    HeadyPosition = newy;
	Map[HeadxPosition][HeadyPosition] = Food + 1;		
}
void Snake::GenerateFood()
{
    int x = 0;
    int y = 0;
	do
	{
		srand(time(NULL));
	    x = rand() % (MapWidth - 2) + 1;
  		y = rand() % (MapHeight - 2) + 1;		
	}while(Map[x][y]==-1);

    // Place new food
    Map[x][y]= -2;	
}
////////////////////////////////////////// Initiate Map /////////////////////////////////////
void Snake::initiateMap()
{
	HeadxPosition = MapWidth / 2;
	HeadyPosition = MapHeight / 2;

	for (int i = 0 ; i<1 ; i++ )
	{
		for(int j=0 ; j<25 ; j++ )
		{
			Map[0][j] = -1; //top wall
			Map[14][j]= -1; //bottom wall
		} 
	}
	for (int i = 0 ; i < 15 ; i++)
	{
		for(int j = 0 ; j < 1 ; j++ )
		{
 	 		Map[i][0] = -1; //left wall
			Map[i][24] = -1; //right wall				
		}	
	}
	GenerateFood();
}
//////////////////////////////////// Print Map //////////////////////////////////////
void Snake::PrintMap()
{
		for (int i = 0 ; i < 15 ; i++)
		{
			for(int j = 0 ; j<25 ; j++)
			{
				cout << GetMapValue( Map[i][j] );	
			}
			cout <<endl;
		}
}
////////////////////////////////////////// Update /////////////////////////////////////
void Snake::Update() 
{
    // Move in direction indicated
    switch (Direction) {
    case 0:
		{
			Move(-1, 0); //up
		} 
        break;
    case 1: Move(0, 1); //right
        break;
    case 2: Move(1, 0); //down
        break;
    case 3: Move(0, -1); //left
        break;
    }

    // Reduce snake values on map by 1
    for (int i = 0; i < 15; i++) {
        for(int j=0 ; j<25; j++)
			if (Map[i][j] > 0) 
				Map[i][j]--;
    }
}
////////////////////////////////////////// Getting Values For Map /////////////////////////////////////
char Snake::GetMapValue(int value)
{
	if (value == -1)
		return char(176); //return wall
	if (value > 0 )
		return char(177); //return snake part
	if (value == -2) 
		return char(232); //return food
}
//////////////////////////////////////////  Run   ////////////////////////////////////////////////////
void Snake::Run()
{
    // Initialize the map
  	initiateMap();
  	GameOver = true;
    while (GameOver ) 
	{
        // If a key is pressed
        if (kbhit()) {
            // Change to direction determined by key pressed
            ChangeDirection(getch());
        }
        // Update the map
        Update();
		
        // Clear the screen
        system("CLS");

        // Print the map
        PrintMap();
        if(Level==1)
        {
        	Sleep(700);	
		}
		else if (Level==2)
		{
			Sleep(500);
		}
		else if(Level==3)
		{
			Sleep(200);
		}		
        
    } // while end
    {
    	for (int i = 0 ; i<2 ; i++)
    	{
    		system("cls");
			Sleep(100);
			PrintMap();	
			Sleep(300);
		}
	    	
	}
	system("cls");
	int choice;
	string name;
    // Print out game over text
    GameFinish();
  	Sleep(3000);
    system("cls");
    cout << endl << endl;
    cout << "\t\t\t\t Your Score :: "<<Food-2;
	Sleep(2000);
	system("cls");
    Record r1;
    cout << endl<<endl;
	cout << "\t\t\t Enter Name :: ";
	cin  >> name;
	r1.set_name(name);		
	r1.set_score(Food-2);
	cout << r1;
	Menu();
}//run end
void Snake::GameFinish()
{
	cout <<endl;
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);	
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);	
	cout << "\t\t\t\t\t\t\t\t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);	
	cout << "\t\t\t\t\t\t\t\t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //wall
	cout << "      "<<char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //G
	cout << "   ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//A
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//A
	cout << "    ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//M
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//M
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//M
	cout << char(219);
	cout << "   ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//E
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << endl; // first row end
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//left wall
	cout << "      ";
	cout << char(219); //G
	cout << "                 ";
	cout << char(219);cout << char(219);//A
	cout << "      ";
	cout << char(219);cout << char(219);//A
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//E
	cout << " \t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //Right wall
	cout << endl; //Second row end
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219); //G
	cout << "      ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);//G
	cout << "    ";
	cout << char(219);cout << char(219);//A
	cout << "      ";
	cout << char(219);cout << char(219);//A
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//E
	cout << " \t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall	
	cout << endl; //third row end
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall	
	cout << "      ";
	cout << char(219); //G
	cout << "      ";
	cout << char(219);//G
	cout << "    ";
	cout << char(219);cout << char(219); //G
	cout << "    ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//A
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//A
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);//E
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall	
	cout << endl; //fourth row end
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219);//G
	cout << "           ";
	cout << char(219);cout << char(219);//G
	cout << "    ";
	cout << char(219);cout << char(219);//A
	cout << "      ";
	cout << char(219);cout << char(219);//A
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//E
	cout << " \t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl; //fifth row end
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219);//G
	cout << "           ";
	cout << char(219);cout << char(219);//G
	cout << "    ";
	cout << char(219);cout << char(219);//A
	cout << "      ";
	cout << char(219);cout << char(219);//A
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//E
	cout << " \t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //G
	cout << "    ";
	cout << char(219);cout << char(219);//A
	cout << "      ";
	cout << char(219);cout << char(219);//A
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "    ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);//M
	cout << "   ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//E
	cout << "\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //Right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "\t\t\t\t\t\t\t\t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);	
	cout << endl;
	///////////////////////////////// Over ///////////////////////////////////////////////////////
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      "<<char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //O
	cout << "  ";
	cout << char(219);cout << char(219);//V
	cout << "            ";	
	cout << char(219);cout << char(219);//V
	cout << "   ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//E
	cout << "   ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//R
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall	
	cout << "      ";
	cout << char(219);cout << char(219);//O
	cout << "           ";
	cout << char(219);cout << char(219);//O
	cout << "   ";
	cout << char(219);cout << char(219);//V
	cout << "          ";	
	cout << char(219);cout << char(219);//V
	cout << "    ";
	cout << char(219);cout << char(219);//E
	cout << "  \t  ";
	cout << char(219);cout << char(219);//R
	cout << "      ";
	cout << char(219);cout << char(219);//R
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219);cout << char(219);//O
	cout << "           ";
	cout << char(219);cout << char(219);//O
	cout << "    ";
	cout << char(219);cout << char(219);//V
	cout << "        ";	
	cout << char(219);cout << char(219);//V
	cout << "     ";
	cout << char(219);cout << char(219);//E
	cout << "  \t  ";
	cout << char(219);cout << char(219);
	cout << "     ";
	cout << char(219);cout << char(219);
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219);cout << char(219);//O
	cout << "           ";
	cout << char(219);cout << char(219);//O
	cout << "     ";
	cout << char(219);cout << char(219);//V
	cout << "      ";	
	cout << char(219);cout << char(219);//V
	cout << "      ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);//E
	cout << "     ";
	cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//R
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219);cout << char(219);//O
	cout << "           ";
	cout << char(219);cout << char(219);//O
	cout << "      ";
	cout << char(219);cout << char(219);//V
	cout << "    ";	
	cout << char(219);cout << char(219);//V
	cout << "       ";
	cout << char(219);cout << char(219);//E
	cout << "  \t  ";
	cout << char(219);cout << char(219);//R
	cout << "     ";
	cout << char(219);cout << char(219);//R
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      ";
	cout << char(219);cout << char(219); //O
	cout << "           ";
	cout << char(219);cout << char(219); //O 
	cout << "       ";
	cout << char(219);cout << char(219);//V
	cout << "  ";	
	cout << char(219);cout << char(219);//V
	cout << "        ";
	cout << char(219);cout << char(219);//E
	cout << "  \t  ";
	cout << char(219);cout << char(219);//R
	cout << "      ";
	cout << char(219);cout << char(219);//R
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //left wall
	cout << "      "<<char(219); //O
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //O
	cout << "       ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//V
	cout << char(219);cout << char(219);
	cout << "        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);//E
	cout << "   ";
	cout << char(219);cout << char(219);
	cout << "      ";
	cout << char(219);cout << char(219);
	cout << " \t\t\t\t";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219); //right wall
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//Left wall
	cout << "\t\t\t\t\t\t\t\t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//right wall	
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//Left Wall	
	cout << "\t\t\t\t\t\t\t\t\t\t\t        ";
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);	
	cout << endl;
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);//Left Wall		
	////////////////////////////////////// Bottom wall /////////////////////////////////
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout << char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);cout  <<char(219);cout << char(219);cout << char(219);cout << char(219);
	cout << char(219);
	cout << endl;

}
int main()
{
	system("color 02");
	Snake s1;
	s1.Menu();
}
