#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include "pq.h"

using namespace std;
MinHeapNode* buildTree(MinPriorityQueue<MinHeapNode> pq)
{

}
/*
void compress(char *in, char *out)
{
		ifstream the_file ( argv[2] );//  argv[2] is a filename to open

		if ( !the_file.is_open() )//  see if file opened
			cout<<"Could not open file\n";
		else {
			char x;
			while ( the_file.get ( x ) ){ //returns false if end of file is reached
				node.data = x;
				//cout << "node.data = " << node.data << endl;
				for(int i = 0; i < vect.size(); i++){
					//cout << "vect[i].data = " << vect[i].data << endl;
					contains = false;
					if(x == vect[i].data){
						node.freq++;
						vect[i].freq++;
						contains = true;
					}
					if(contains == true)
						break;
				}

				if((vect.size() == 0) or (contains == false)){
					node.freq = 1;
					vect.push_back(node);
					//cout << "A new node for " << x << " has been inserted" << endl;
				}

				//cout << "vector size = "<< vect.size() << endl;
					//cout << "===================" << endl;
				}

				}


		}
*/

int main(int argc, char *argv[])
{
	char *temp;
	std::vector<MinHeapNode> vect;
	bool contains = false;

	MinHeapNode node;

	if (argc == 4){
		temp = argv[1];
		char blank = temp[1];

		if (blank == 'c'){
			//compress(argv[2], argv[3]);
			ifstream the_file ( argv[2] );//  argv[2] is a filename to open

			if ( !the_file.is_open() )//  see if file opened
				cout<<"Could not open file\n";
			else {
				char x;
				while ( the_file.get ( x ) ){ //returns false if end of file is reached
					node.data = x;
					//cout << "node.data = " << node.data << endl;
					for(int i = 0; i < vect.size(); i++){
						//cout << "vect[i].data = " << vect[i].data << endl;
						contains = false;
						if(x == vect[i].data){
							node.freq++;
							vect[i].freq++;
							contains = true;
						}
						if(contains == true)
							break;
					}

					if((vect.size() == 0) or (contains == false)){
						node.freq = 1;
						vect.push_back(node);
						//cout << "A new node for " << x << " has been inserted" << endl;
					}

					//cout << "vector size = "<< vect.size() << endl;
						//cout << "===================" << endl;
					}

					}
			}
		}
//==========Printing the Vector===========
		cout << "{" ;
		for(int j = 0; j < vect.size(); j++){
			cout << "[" << vect[j].data << ":" << vect[j].freq << "]";
			if (j < vect.size()-1)
				cout << ", ";
		}
		cout << "}" << endl;
//=========================================

		MinPriorityQueue<MinHeapNode> pq;
		for (int k = 0; k < vect.size(); k++){
			pq.insert(&vect[k]);
		}
		cout << pq << endl;
		cout << *pq.extractMin() << endl;
		

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

//}

 //end of main
