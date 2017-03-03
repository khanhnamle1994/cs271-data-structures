#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main ( int argc, char *argv[] )
{
	
	char ctemp[] = "-c";
	char dtemp[] = "-d";
		
	int A_count=0;
	int B_count=0;
	int C_count=0;
	int D_count=0;
	int E_count=0;
	int F_count=0;
	
	if (argc == 3){
		if (*argv[1] == *ctemp){
			// We assume argv[1] is a filename to open
			ifstream the_file ( argv[2] );
				// Always check to see if file opening succeeded
			if ( !the_file.is_open() )
				cout<<"Could not open file\n";
			else {
				char x;
				// the_file.get ( x ) returns false if the end of the file
				//  is reached or an error occurs
				while ( the_file.get ( x ) )
					//cout<< x;
					switch(x){
						case 'A': 
							A_count++;
							break;
						case 'B': 
							B_count++;
							break;
						case 'C': 
							C_count++;
							break;
						case 'D': 
							D_count++;
							break;
						case 'E': 
							E_count++;
							break;
						case 'F': 
							F_count++;
							break;
					}
				cout << "A_count= " << A_count << endl;
				cout << "B_count= " << B_count << endl;
				cout << "C_count= " << C_count << endl;
				cout << "D_count= " << D_count << endl;
				cout << "E_count= " << E_count << endl;
				cout << "F_count= " << F_count << endl;
			}
	
		}
		
		else if (*argv[1] == *dtemp){
			// We assume argv[1] is a filename to open
			ifstream the_file ( argv[2] );
				// Always check to see if file opening succeeded
			if ( !the_file.is_open() )
				cout<<"Could not open file\n";
			else {
				char x;
				// the_file.get ( x ) returns false if the end of the file
				//  is reached or an error occurs
				while ( the_file.get ( x ) )
					switch(x){
						case 'A': 
							A_count++;
							break;
						case 'B': 
							B_count++;
							break;
						case 'C': 
							C_count++;
							break;
						case 'D': 
							D_count++;
							break;
						case 'E': 
							E_count++;
							break;
						case 'F': 
							F_count++;
							break;
					}
				cout << "A_count= " << A_count << endl;
				cout << "B_count= " << B_count << endl;
				cout << "C_count= " << C_count << endl;
				cout << "D_count= " << D_count << endl;
				cout << "E_count= " << E_count << endl;
				cout << "F_count= " << F_count << endl;
			}
					
			}
	
		
		else{
			cout << "Error: verify compression (-c) or decompression (-d)" << endl;
		}
		
	}
	
	else{
		cout << "Incorrect format. Use: ./huffman -c filename.txt" << endl;	
	}
	
    
  
}
