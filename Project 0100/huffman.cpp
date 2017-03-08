#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
using namespace std;

//buidVector()

/*
newNode(char c)
{
	Node<MinHeapNode> A;
	A.data = c;
	A.frequency = 0;

	return A; //???????

}
*/

int begin(int argc, char *argv[])
{
	char *temp;
	std::vector<MinHeapNode> vect;
	bool contains = false;

	//MinHeapNode<char> node;
	MinHeapNode node;

	if (argc == 3){
		temp = argv[1];
		char blank = temp[1];

		if (blank == 'c'){
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
					for(int i = 0; i < vect.size(); i++){
						if(x == node.data){
							node.freq++;
							contains = true;
						}
						break;
					}
						if(contains == true){
							vect.push_back(node);
							contains = false;
						}


					}
			}
		}

/*
		else if (blank == 'd'){
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
				cout << "This is the decompressor function" << endl;
			            }

			}


		else{
			cout << "Error: verify compression (-c) or decompression (-d)" << endl;
		}

	}//end of  if (argc == 3)

	else{
		cout << "Incorrect format. Use: ./huffman -c filename.txt" << endl;
	}
*/

}


int main(int argc, char *argv[])
{

	begin(argc, *argv[]);
/*
	char *temp;

	int A_count=0;
	int B_count=0;
	int C_count=0;
	int D_count=0;
	int E_count=0;
	int F_count=0;

	if (argc == 3){
		temp = argv[1];
		char blank = temp[1];

		if (blank == 'c'){
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
				cout << "This is the compressor  function" << endl;
			}

		}

		else if (blank == 'd'){
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
				cout << "This is the decompressor function" << endl;
			            }

			}


		else{
			cout << "Error: verify compression (-c) or decompression (-d)" << endl;
		}

	}//end of  if (argc == 3)

	else{
		cout << "Incorrect format. Use: ./huffman -c filename.txt" << endl;
	}

    */

} //end of main
