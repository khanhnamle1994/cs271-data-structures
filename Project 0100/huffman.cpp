#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include "pq.h"
// Kevin Ly & James Le


using namespace std;

/*================================================
void makecode(MinHeapNode* Root, string Arr[], int top)
Precondition: Requires a node (which is the root of the tree),
							an array of strings, and an integer
Postcondition: Traverses the tree based on presence of
							left child and right child. If left, 0 is added to array.
							if right, 1 is added to arra. Recursively calls itself
							until it reaches a leaf. That node's code is equal to
							the array.
================================================*/
void makecode(MinHeapNode* Root, string Arr[], int top){

string tempcode;
	if (Root->left != NULL){
		Arr[top] = "0";
		makecode(Root->left, Arr, top+1);


	}
	if (Root->right != NULL){
		Arr[top] = "1";
		makecode(Root->right, Arr, top+1);

	}
	if((Root->right == NULL) and (Root->left == NULL)){
		for(int i=0; i < top; i++){
			tempcode += Arr[i];
		}
		Root->code = tempcode;
	}
}

/*================================================
MinHeapNode* buildTree(MinPriorityQueue<MinHeapNode> &pq)
Precondition: Requires a priority queue
Postcondition: Extracts the two minimum nodes based on
							their frequency and adds them together to make
							a new node whose children are the nodes extracted.
							The new node is then added to the pq.
							Continues until only root is left in pq.
							Returns the root of the tree.
================================================*/
MinHeapNode* buildTree(MinPriorityQueue<MinHeapNode> &pq)
{
//cout << "======Start of buildTree========" << endl;
MinHeapNode* leftnode;
MinHeapNode* rightnode;
MinHeapNode* topnode;

// Iterate while size of priority queue doesn't become 1
while (pq.length() != 1)
{

	MinHeapNode temp;

	leftnode = pq.extractMin();
	rightnode = pq.extractMin();
	topnode = temp.newNode('\0', (leftnode->freq + rightnode->freq));

	topnode->left = leftnode;
	topnode->right = rightnode;
  pq.insert(topnode);


}
		return pq.extractMin();
}

/*================================================
std::vector<MinHeapNode> compress(char *in, char *out)
Precondition: Requires a file to be compressed and a file to
							be compressed to.
Postcondition: Produces a file made up of a string of 1's
							and 0's. Traverses the in file and calculates
							the frequency of each character.The node,
							with character and frequency, is then added
							to a vector. Each node is then added to a priority
							queue. A tree is built based on the pq. Calls
							makcode function to assign strings of 1's and 0's
							to represent each character. These strings are then
							added to the out file. Header of out file gives each
							character and their codes.
================================================*/
std::vector<MinHeapNode> compress(char *in, char *out)
{
	MinHeapNode* RootNode;
	std::vector<MinHeapNode> vect;
	bool contains = false;

	MinHeapNode node;
		ifstream in_file ( in );//  argv[2] is a filename to open

		if ( !in_file.is_open() )//  see if file opened
			cout<<"Could not open file\n";
		else {
			char x;
			while ( in_file.get ( x ) ){ //returns false if end of file is reached
				node.data = x;
				for(int i = 0; i < vect.size(); i++){
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

				}
				}
				in_file.close();
			}

//cout << "======Priority Queue======" << endl;
MinPriorityQueue<MinHeapNode> pq;
for (int k = 0; k < vect.size(); k++){
	pq.insert(&vect[k]);
}

RootNode = buildTree(pq);

MinHeapNode tempNode;
tempNode = *RootNode;
string Arr[100000];
int top = 0;

makecode(RootNode, Arr, 0);
//=======Put in out_file========
ofstream out_file ( out );
ifstream in_file2 ( in );
char x;

for(int j = 0; j < vect.size(); j++){
	if(x = vect[j].data)
		out_file << vect[j].data << vect[j].code <<".";
}
out_file << "*";


while(in_file2.get(x)){
	for(int j = 0; j < vect.size(); j++){
		if(x == vect[j].data)
			out_file << vect[j].code;
	}
}

return vect;
}

/*================================================
void decompress(char *in, char *out)
Precondition: Requires a file to be decompressed and a file to
							decompressed to.
Postcondition: Reads the in file and makes nodes based on
							the header (gives character and code). When it
							encounters a '*', it inserts the following
							1's and 0's into an array. The code for each
							character is then compared to the elements
							of the array. When a code corresponds to a key
							the index of the key is saved and the following
							elements are compared to a new (or current) character
							code. Each time a code is read, it is outputted
							into the out file.
================================================*/
void decompress(char *in, char *out)
{
MinHeapNode* RootNode;
std::vector<MinHeapNode> vect;
	bool go = true;
	bool hit = false;
	string temp;
	MinHeapNode node;
	string tempA[100000];
	int A_count = 0;


		ifstream in_file ( in );//  argv[2] is a filename to open

		if ( !in_file.is_open() )//  see if file opened
			cout<<"Could not open file\n";
		else {
			char x;
					while(in_file.get ( x )){
						if(x != '*'){
						while(go == true){
						if(x != '1' and x != '0' and x != '.'){
							temp = '\0';
							node.data = x;
							break;
						}
						else if (x == '1'  or x=='0'){
							temp += x;
							break;
						}
						else if (x=='.'){
							node.code = temp;
							vect.push_back(node);
							go = false;
						}
						}
						go = true;
					}

						if(x == '*'){
							hit = true;
						}
						if ((hit == true) and (x == '*')){

						}
						else if((hit == true) and ((x == '1') or (x == '0' ))){
							tempA[A_count] = x;
							A_count++;
						}
					}


string tempcode;
string read = "";
ofstream out_file ( out );
int counting = 0;
int maxsize=0;
while(counting != A_count){
		for (int i = 0; i < vect.size(); i++){
			tempcode = (vect[i].code);
			string code = "";

			for (int t=0; t < tempcode.size()-1; t++){
				code += tempcode[t+1];
				if (code.size() > maxsize)
					maxsize = code.size();
			}

			while((vect[i].code != read) and (counting < A_count)){
				read += tempA[counting];
				if( code == read){
					out_file << vect[i].data;
					break;
				}
				if(read.size() >= maxsize)
					break;

				counting++;
			}

			if(counting == A_count){
				break;
			}
			else if(code == read){
				counting++;
				read = "";
				break;
			}
			else if( (read.size() >= maxsize)){
				counting = counting - read.size() + 1;
				read = "";
			}


		}

}

	}

				in_file.close();
}

//=====End of Decompressor======================
int main(int argc, char *argv[])
{
	char *temp;
	std::vector<MinHeapNode> vect;
	if (argc == 4){
		temp = argv[1];
		char blank = temp[1];

		if (blank == 'c')
			vect = compress(argv[2], argv[3]);

		else if (blank == 'd'){
			decompress(argv[2], argv[3]);
		}

		else{
			cout << "Error: verify compression (-c) or decompression (-d)" << endl;
		}
	}

}


 //end of main
