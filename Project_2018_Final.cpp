#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
using namespace std;




enum type { sea , ship   , hit   , miss  };// we define the type of the tiles

	




char* getOrientation()// method that asks for orientation
  {  	
            char* mhnuma = "Orientation.horizontal";
			string Orientation;
			cout << "Thelete katheti h orizontia topothetisi H/V \n";
			cin >> Orientation;
			
			if ( Orientation == "H" ) 
			{
				cout << "epilexate orizontia topothetisi \n";
				
				return mhnuma;
		    }   
			else if ( Orientation == "V" )
			{
				cout << "epilexate katheti topothetisi \n";
				char* mhnuma = "Orientation.vertical";
				return mhnuma;
			}   
			else
			{
			    cout << "LATHOS STOIXEIA\n";
			    system("PAUSE");
			    exit(0);
			}			
  }

class Tile   //tile class
{		
public:	
type typeshell = sea;//the default value is sea 	
int syntetag[2] = {};//array of the coordinates
					 void draw(){//method that print the type of the tile
									if ( typeshell == sea ) 
									{
										cout << "~";										
								    }   
									else if ( typeshell == ship )
									{
										cout << "S";
									}   
									else if (typeshell == hit)
									{
									    cout << "X";
									}
								    else if (typeshell == miss)
								    {
                                        cout << "o";
									}
					            }	
};





class Board   //Board class 
{	
				public:
					string name;
	            Board(string z) {    //passing the name  
				setName(z);
				}
				
				void setName(string x) 
				{
					name = x;
				}
				int j,i;
				Tile pinakas[7][7];// constructing board from tiles
				void perasmasyntetagmenwn(){ // seting the coordinates 		
						for(j=0;j<7;j++)
						{	
									for(i=0;i<7;i++)							
								              {	
											  pinakas[j][i].syntetag[0] = j;
											  pinakas[j][i].syntetag[1]	= i;                    
		                 
								              }
					       }
			       
				}
				/*
				static void drawboards(){
					cout << " mesa sthn drawboards "<<endl;
					player.pinakas[0][0].draw() ; 
                    computer.pinakas[0][0].draw() ;
				}
				*/
					void getAdjacentTiles(Tile object ,int (&panw)[2],int (&katw)[2],int (&aristera)[2],int (&dexia)[2]){   // methodos mas dinei ta geitonika kelia apo ena keli kai epistrefei tis times 
						int i,j;																							// pisw stous pinakes  me call by reference
						 i = object.syntetag[1];
						 j = object.syntetag[0];
						 panw[0]= -1;             // initialiazing the neightboor values
						 panw[1]= -1;
						 katw[0]= -1;
						 katw[1]= -1;
						 aristera[0]= -1;
						 aristera[1]= -1;
						 dexia[0]= -1;
						 dexia[1]= -1;
						            if ( j == 0 && i==0) //checking the location of the tile on the board
									{
										katw[0]	   = j+1;
										katw[1]    = i;
										dexia[0]   = j;
										dexia[1]   = i+1;							
								    }   
									else if ( j == 0 && i == 6 )
									{
									    aristera[0]	 = j;
										aristera[1]  = i-1;
										katw[0]	   = j+1;
										katw[1]    = i;
									}   
									else if (j == 6 && i == 0)
									{
									    panw[0] = j-1;
									    panw[1] = i;
									    dexia[0] = j;
									    dexia[1] = i+1;
									}
								    else if (j == 6 && i == 6)
								    {
                                        aristera[0]	 = j;
										aristera[1]  = i-1;
										panw[0] = j-1;
									    panw[1] = i;
									}
									 else if (j == 0 )
								    {
                                        aristera[0]	 = j;
										aristera[1]  = i-1;
										katw[0]	   = j+1;
										katw[1]    = i;
										dexia[0] = j;
									    dexia[1] = i+1;
									}
									 else if (j == 6)
								    {
                                        aristera[0]	 = j;
										aristera[1]  = i-1;
										panw[0] = j-1;
									    panw[1] = i;
									    dexia[0] = j;
									    dexia[1] = i+1;
									}
									else if (i == 0)
								    {
										panw[0] = j-1;
									    panw[1] = i;
									    dexia[0] = j;
									    dexia[1] = i+1;
									    katw[0]	   = j+1;
										katw[1]    = i;
									}
									else if (i == 6)
								    {
										panw[0] = j-1;
									    panw[1] = i;
									    aristera[0]	 = j;
										aristera[1]  = i-1;
									    katw[0]	   = j+1;
										katw[1]    = i;
									}
									else
								    {
										panw[0] = j-1;
									    panw[1] = i;
									    aristera[0]	 = j;
										aristera[1]  = i-1;
										dexia[0] = j;
									    dexia[1] = i+1;
									    katw[0]	   = j+1;
										katw[1]    = i;
									}			
						}
				
				
                void placeAllShips(){//checking if all ships are sunk
        
				}
				
				                bool AllShipsSunk(){
				                	 int flag = 0; 
				                	for(j=0;j<7;j++)
										{	
													for(i=0;i<7;i++)							
												              {	
														              if (pinakas[j][i].typeshell == ship){
														              	flag = 1;                                 //1 if it finds ship, 0 otherwise
																	  	}
							              					  }
									    }
						                	if (flag == 0)
											{
												
						    	              	return   true;                               //
																			  	}
						                	else
											{
												
												return false;
											}                	
								}
};

class Ship // ship class
{
	public:
		string nameship = "";
		int size = 0;//ship size
		char orientation;//orientation of ships	
				void placeship( char* orientation, Board& object, int syntetagm[2],int sizeship)// methodos pou topothetoume ta ploia
				{
					int panw[2]={-1,-1};
					int katw[2]={-1,-1};
					int aristera[2]={-1,-1};
					int dexia[2]={-1,-1};
					int i,j;
				//
				bool OversizeException= false;         //initializing with flase
				bool OverlapTilesException = false;
				bool AdjacentTilesException = false;
				                    //checking input data 
									do{	
									
										try	{//checking if the coordinates are on board
																
										if ((syntetagm[1] + sizeship	> 7) && (orientation == "Orientation.horizontal"))
										{
										OversizeException= true;
										throw 1;	
										}
										else if((syntetagm[0] + sizeship	> 7) && (orientation == "Orientation.vertical"))
										 {
										OversizeException= true;
										throw 1;	
										}
										else {
											OversizeException = false;
										}
							            
									}catch(...){
										cout<<"to ploio vgainei ektos pinaka "<<endl;
										cout<<"parakalw dwste xana swstes suntetagmenes kai topothetisi "<<endl;
										
										cout<< "doste kai tis syntetagmenes"<<endl;								
										cin>>syntetagm[0]>>syntetagm[1];
										orientation = getOrientation();
										cin.ignore();
									}
																																	
									try { //checking if there is already ship
									if (orientation == "Orientation.horizontal"){
										
									for(i=0;i<sizeship;i++)							
																		              {	
																		              OverlapTilesException = false;
																					              if (object.pinakas[syntetagm[0]][syntetagm[1]+i].typeshell == ship)
																								{	
																								OverlapTilesException = true;
																								throw 2;	
																								}
																														              	                                 
																					  	
													              					  }	
									                                           }												
									else if(orientation == "Orientation.vertical"){
										for(i=0;i<sizeship;i++)							
																								              {	
																								              OverlapTilesException = false;
																									              if (object.pinakas[syntetagm[0]+i][syntetagm[1]].typeshell == ship)
																													{
																													OverlapTilesException = true;
																													throw 2;	
																													}								              	                                 
																											  	
																			              					  }	
								                                                } 
								    else {
											OverlapTilesException = false;
										}
								    }	
								
									catch(...){
									    cout<<"to ploio tha topothetithei panw se allo ploio "<<endl;
										cout<<"parakalw dwste xana swstes suntetagmenes kai topothetisi "<<endl;
										
										cout<< "doste kai tis syntetagmenes"<<endl;								
										cin>>syntetagm[0]>>syntetagm[1];
										orientation = getOrientation();	
										cin.ignore();		
									}
		
									try{//checking if there is a ship on neightboor shells
									object.getAdjacentTiles(object.pinakas[syntetagm[0]][syntetagm[1]],panw,katw,aristera,dexia);
									if (orientation == "Orientation.horizontal"){
										
									for(i=0;i<sizeship;i++)							
																		              {	
																		              AdjacentTilesException = false;
																					              if (object.pinakas[panw[0]][panw[1]+i].typeshell == ship)
																								{
	
																								AdjacentTilesException = true;
																								throw 2;	
																								}
																								if (object.pinakas[katw[0]][katw[1]+i].typeshell == ship)
																								{
	
																								AdjacentTilesException = true;
																								throw 2;	
																								}
																								if (object.pinakas[aristera[0]][aristera[1]-1].typeshell == ship)
																								{
	
																								AdjacentTilesException = true;
																								throw 2;	
																								}							              	                                 
																					  			if (object.pinakas[syntetagm[0]][syntetagm[1]+sizeship].typeshell == ship)
																								{	
																								AdjacentTilesException = true;
																								throw 2;	
																								}
													              					  }	
													              					  
									                                           }
												
									else if(orientation == "Orientation.vertical"){
										for(i=0;i<sizeship;i++)							
																								              {	
																								              AdjacentTilesException = false;
																					              if (object.pinakas[dexia[0]+i][dexia[1]].typeshell == ship)
																								{
																							//	cout<<"mesa stin try2222fsdfs"<<endl;	
																								AdjacentTilesException = true;
																								throw 2;	
																								}
																								if (object.pinakas[aristera[0]+i][aristera[1]].typeshell == ship)
																								{
																								//cout<<"mesa stin try2222fsdfs"<<endl;	
																								AdjacentTilesException = true;
																								throw 2;	
																								}
																								if (object.pinakas[panw[0]-1][panw[1]].typeshell == ship)
																								{
																								//cout<<"mesa stin try2222fsdfs"<<endl;	
																								AdjacentTilesException = true;
																								throw 2;	
																								}							              	                                 
																					  			if (object.pinakas[syntetagm[0]+sizeship][syntetagm[1]].typeshell == ship)
																								{
																								//cout<<"mesa stin try2222fsdfs"<<endl;	
																								AdjacentTilesException = true;
																								throw 2;	
																								}								              	                                 
																											  	
																			              					  }	
								                                                } 
								    else {
											AdjacentTilesException = false;
										}
								    }
									
									
									catch(...){
									    cout<<"to ploio tha topothetithei dipla se allo ploio "<<endl;
										cout<<"parakalw dwste xana swstes suntetagmenes kai topothetisi "<<endl;
										
										cout<< "doste kai tis syntetagmenes"<<endl;									
										cin>>syntetagm[0]>>syntetagm[1];
										orientation = getOrientation();
										cin.ignore();	
																				
									}
									} while ( OversizeException || OverlapTilesException || AdjacentTilesException); // loop doesnt stop if all three conditions are true
										//we place the ship
																		
				if ( orientation == "Orientation.horizontal" ) 
									{
									
												for(i=0;i<sizeship;i++)							
												              {	
												              
														              object.pinakas[syntetagm[0]][syntetagm[1]+i].typeshell = ship;								              	                                 
															  	
							              					  }												
								    }
				else if	( orientation == "Orientation.vertical" )
				                    {
				            
						                    	for(i=0;i<sizeship;i++)							
										              {	
												              object.pinakas[syntetagm[0]+i][syntetagm[1]].typeshell = ship;								              	                                 
													  	
					              					  }
									}
			
				for(j=0;j<7;j++)
								{	
													cout<<j; 
											for(i=0;i<7;i++)
										              {		 
													                    
										                    object.pinakas[j][i].draw() ;
															                
										              }
										              cout<<"\n"; 
				      			 }				 
				cout<<"to ploio pou topothetithike einai :" << nameship<<endl;
				cout<<"\n";
				}	
	
};

//subclasses for the different ships

class Carrier : public Ship {
	public :
	Carrier(){
		size = 5;
		nameship = "Carrier";
	};
};

class Battleship : public Ship {
	public :
	Battleship(){
		size = 4;
		nameship = "Battleship";
	};		
};

class Cruiser : public Ship {
	public :
	Cruiser(){
		size = 3;
		nameship = "Cruiser";
	};	
};

class Submarine : public Ship {
	public :
	Submarine(){
		size = 3;
		nameship = "Submarine";
	};
};

class Destroyer : public Ship {
	public :
	Destroyer(){
		size = 2;
		nameship = "Destroyer";
	};
};

	
class Player //players class	
{
public:
	
			string name;
			int sunolovolwn = 0;
			int sunoloastoxiwn = 0;
			int success = 0;
			int epanalipsivolis =0;
				
				Player(string z) {//constructor to pass name 
				setName(z);
				}
				
				void setName(string x) 
				{
					name = x;
				}
				
				string getName() 
				{		
					return name;
				}
				
				void placeAllShips(){}
				void placeShip(){}
				
				void fire( Board& object,int syntetagm[2]){                    // method fire 
				int i,j;					                                   // change the type of a tile
					cout<<"\n";
				        if ( object.pinakas[syntetagm[0]][syntetagm[1]].typeshell == sea ) 
									{
										sunoloastoxiwn++;
										object.pinakas[syntetagm[0]][syntetagm[1]].typeshell = miss;
										cout << name<<" ---->  "<<"miss "<<endl;	
										//return object.pinakas[syntetagm[0]][syntetagm[1]].typeshell;									
								    }   
									else if ( object.pinakas[syntetagm[0]][syntetagm[1]].typeshell == ship )
									{
										success++;
										object.pinakas[syntetagm[0]][syntetagm[1]].typeshell = hit;
										cout << name<<" ---->  "<<"HIT "<<endl;
									}   
									else if (object.pinakas[syntetagm[0]][syntetagm[1]].typeshell == hit)
									{
										epanalipsivolis++;
										object.pinakas[syntetagm[0]][syntetagm[1]].typeshell = hit;
									    cout <<name<<" ---->  "<< "already hit "<<endl;
									}
								    else if (object.pinakas[syntetagm[0]][syntetagm[1]].typeshell == miss)
								    {
								    	epanalipsivolis++;
                                        cout <<name<<" ---->  "<< "already miss "<<endl;
									}
					sunolovolwn++;	
				}
				
				void  getStats()//printing statistics
				{
					
				cout << " To sunolo volwn  einai :   "<<sunolovolwn<<endl;
				cout << " To sunolo astoxiwn  einai :   "<<sunoloastoxiwn<<endl;
				cout << " To sunolo epitiximenwn volwn  einai :   "<<success<<endl;
				cout << " To sunolo epanalamvanomenwn volwn  einai :   "<<epanalipsivolis<<endl;
				}
		
};	

	bool RandomPlace()
	{                         //checking if we have random placement or not
	string topothetisi;	
	
			    cout << "Thelete tuxaia topothetisi Y/N \n";
				cin >> topothetisi;
				
				if ( topothetisi == "Y" ) 
				{
					return true;
			    }   
				else if ( topothetisi == "N" )
				{
					return false;
				}   
				else
				{
				    cout << "LATHOS STOIXEIA\n";
				    system("PAUSE");
				    exit(0);
				}	
	}


  

	void  getInput(int &a , int &b)//method tha passes the values 
	{
	cout << "Dwste tis suntetagmenes\n";	
	char str[20];
    int syntetagmeniX =-100 ;
    int syntetagmeniY =-100;
	int synt[2]; 
		
    cin.getline(str, 20);
    
    
    
	syntetagmeniX = str[0] - '0';
    syntetagmeniY = str[2] - '0';  
    
    
    
	while (  !(syntetagmeniX >=0 && syntetagmeniX<=6 ) ||  !(syntetagmeniY>=0 && syntetagmeniY<=6 )  )
	{
	cout << "oi suntetagmenes pou dwsate den einai swstes\n";
	cout << "Parakalw dwste xana suntetagmenes\n";
	cout << "oi suntetagmenes pou dwsate einai: " << syntetagmeniX<< syntetagmeniY << str[0] <<str[2]<< endl;
	cin.getline(str, 20);
	syntetagmeniX = str[0] - '0';
    syntetagmeniY = str[2] - '0';
	
		
	}
	
    a = syntetagmeniX;
	b = syntetagmeniY;
	cout << "oi suntetagmenes pou dwsate einai: " << a<< b;
	cout<<"\n";									
	}





	int* getRandInput()// generation of numbers from 1 to 6
		{
		int syn[2];	
		syn[0]	= (rand() % 7) ;
		syn[1]	= (rand() % 7);
		return syn;
		}
	
	
	
void drawboards (Board object1 , Board object2 ){
	int i,j;
cout<< " --YOU--  -OPPONENT- \n";
    cout<< " 0123456   0123456 \n";
    for(j=0;j<7;j++)
								{	
													cout<<j; 
													
													
											for(i=0;i<7;i++)
										              {		 
													                    
										                    object1.pinakas[j][i].draw() ;
																														              
										              }
										              cout << "  " ;
										              cout<<j;
										    for(i=0;i<7;i++)
										              {		 
													                    
															object2.pinakas[j][i].draw() ;              
										              }
										              
										              cout<<"\n"; 
				      			 }	
				      			 
	
}		


	
// main class	
int main()
{
	int panw[2]={0,0};
	int katw[2];
	int aristera[2];
	int dexia[2];
    int testsyntetag[2] = {2,2};
	int *syntetagmenes,i,j;
	char *apotelesma;	
	string playername, ploio, winner;
	type typeshell;

	Tile testkeli[7][7];
	
    
	cout << "Dwste to onoma tou paikti \n";
	cin  >> playername;
	cout << " To onoma tou paikti pou dwsate einai :   "<<playername<<endl;
	cin.ignore();
	cout<<"\n";
     cout<<"\n";
	
	Board playerboard("playername");
	
    Board computerboard("computer");
	
    Player user(playername);
    Player computer("computer");
     
     
     
     cout<<"\n";
	 cout<< "################################################################################" ; 
     cout<<"\n";
     cout<< "## Ta ploia tha topothetithoun analoga me to megethos tous me tis exis seira: ## \n##    Carrier --> Battleship  --> Submarine --> Cruiser --> Destroyer         ##\n";
     cout<< "################################################################################" ;
     
     cout<<"\n";
     cout<<"\n";
     
     
     
     //construction of the board of each player
     for (int i=0; i<5; i++){
     	
     		if (i == 0) {
     			ploio = "Carrier" ;
     			Carrier ploiouser;
     			 cout<< "topothetiste to " << ploio <<endl;
			    getInput(testsyntetag[0], testsyntetag[1]);
			    
			    apotelesma = getOrientation();
			    cin.ignore();
			    ploiouser.placeship(apotelesma,playerboard,testsyntetag,ploiouser.size);
     			
			 }	
     		else if (i == 1) {
     			ploio = "Battleship" ;
     			Battleship ploiouser;
     			 cout<< "topothetiste to " << ploio <<endl;
			    getInput(testsyntetag[0], testsyntetag[1]);
			    
			    apotelesma = getOrientation();
			    cin.ignore();
			    ploiouser.placeship(apotelesma,playerboard,testsyntetag,ploiouser.size);
			 }
     		else if (i == 2) {
     			ploio = "Submarine" ;
     			Submarine ploiouser;
     			 cout<< "topothetiste to " << ploio <<endl;
			    getInput(testsyntetag[0], testsyntetag[1]);
			    
			    apotelesma = getOrientation();
			    cin.ignore();
			    ploiouser.placeship(apotelesma,playerboard,testsyntetag,ploiouser.size);
			 }
			else if (i == 3) {
     			ploio = "Cruiser" ;
     			Cruiser ploiouser;
     			 cout<< "topothetiste to " << ploio <<endl;
			    getInput(testsyntetag[0], testsyntetag[1]);
			    
			    apotelesma = getOrientation();
			    cin.ignore();
			    ploiouser.placeship(apotelesma,playerboard,testsyntetag,ploiouser.size);
			 } 
			 
     		else if (i == 4) {
     			ploio = "Destroyer" ;
     			Destroyer ploiouser;
     			 cout<< "topothetiste to " << ploio <<endl;
			    getInput(testsyntetag[0], testsyntetag[1]);
			    
			    apotelesma = getOrientation();
			    cin.ignore();
			    ploiouser.placeship(apotelesma,playerboard,testsyntetag,ploiouser.size);
			 } 
			 		 
	}
	
	
	
	
 
	
	
cout<<" \n";	
cout<<" \n";
cout<<" \n";
 cout<<"topothetisi twn ploiwn tou upologisti \n";
cout<<" \n";
cout<<" \n";
cout<<" \n";			   
    apotelesma = "Orientation.horizontal";
    
    int carriersynt[2] = {0,0};
    int battleshipsynt[2] = {2,0}; 
    int submarinesynt[2] = {4,0};
    int cruisersynt[2] = {6,0};
    int destroyersynt[2] = {6,5};
     
 
    Carrier carriercomputer;
    carriercomputer.placeship(apotelesma,computerboard,carriersynt,carriercomputer.size);
    
    Battleship battleshipcomputer;
    battleshipcomputer.placeship(apotelesma,computerboard,battleshipsynt,battleshipcomputer.size);
    
    Submarine submarinecomputer;
    submarinecomputer.placeship(apotelesma,computerboard,submarinesynt,submarinecomputer.size);
    
    
    Cruiser cruisercomputer;
    cruisercomputer.placeship(apotelesma,computerboard,cruisersynt,cruisercomputer.size);
    
    Destroyer destroyercomputer;
    destroyercomputer.placeship(apotelesma,computerboard,destroyersynt,destroyercomputer.size);
    
   cout<<" \n";
   cout<<" \n";
   cout<<" \n";
   drawboards(playerboard,computerboard);
   cout<<" \n";
   cout<<" \n";
   cout<<" \n";
   
   cout<<"Dokimazotas tin fire";
   cout<<"\n";
   cout<<"\n";
   winner = "computer" ;
       
    do{
    	   cout<<"Einai i seira tou xristi na paixei\n";
    	   getInput(testsyntetag[0], testsyntetag[1]);
		  
		   user.fire(computerboard, testsyntetag);
		  
		   drawboards(playerboard,computerboard);
		   
		   if   ( computerboard.AllShipsSunk() ){
		   	winner = playername;
		   	continue;
  	       
           }	
		   
		   
		   
    	
    	   cout<<"Einai i seira tou upologisti na paixei \n";
    	
		   getInput(testsyntetag[0], testsyntetag[1]);
		  
		   computer.fire(playerboard, testsyntetag);
		  
		   drawboards(playerboard,computerboard);
		   cout<<"\n";
		   cout<<"\n";	
	}
	while ( !(computerboard.AllShipsSunk()) && !(playerboard.AllShipsSunk()) );
    
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";	

  
  cout<<"NIKITIS EINAI O "<< winner<<endl;
  cout<<"NIKITIS EINAI O "<< winner<<endl;
  cout<<"NIKITIS EINAI O "<< winner<<endl;
  cout<<"NIKITIS EINAI O "<< winner<<endl;
  
  cout<<"\n";
  cout<<"\n";	
  user.getStats();	

	system("PAUSE");
	//return 0;


		
			
}


			 


