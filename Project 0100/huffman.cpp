#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include "pq.h"

using namespace std;

/*
void inOrder(int curIndex) {
	// inOrderTraversal explores the left, then the current, and finally the right index
	int l = (2*curIndex + 1);
	int r = (2*curIndex + 2);

	if (l < capacity and *(A[l]) != NULL)
		inOrder(l);
	cout << *(A[curIndex]) << " ";
	if (r < capacity and *(A[r]) != NULL)
		inOrder(r);
}

void inOrderTraversal(MinPriorityQueue<MinHeapNode> &pq) {
	if (pq.empty()) {
		cout << "Priority Queue is empty!" << endl;
	}
	inOrder(0);
	cout << endl;
}
*/


void makecode(MinHeapNode* Root, string Arr[], int top){
//cout << "MAKECODE CALLED" << endl;
//cout << "["<< Root->data << ":" << Root->freq << "]" <<endl;
//cout << "root.left = " << (Root->left)->data <<endl;

string tempcode;
	if (Root->left != NULL){
		//cout << "entered root.left != NULL" << endl;
		Arr[top] = "0";
		//cout << "["<< (Root->left)->data << ": " << (Root->left)->freq << "]"<<endl;
		makecode(Root->left, Arr, top+1);
		//cout << "leaving root.left != NULL" << endl;


	}
	//cout << "root -> left == NULL" << endl;
	if (Root->right != NULL){
		Arr[top] = "1";
		makecode(Root->right, Arr, top+1);

	}
	if((Root->right == NULL) and (Root->left == NULL)){
		cout << Root->data << "= ";
		for(int i=0; i < top; i++){
			//cout << "Arr[i]= " << Arr[i] << endl;
			tempcode += Arr[i];
			//cout << Root->code;
		}
		cout << tempcode<< endl;
		Root->code = tempcode;
	}
}

MinHeapNode* buildTree(MinPriorityQueue<MinHeapNode> &pq)
{
//cout << "======Start of buildTree========" << endl;
MinHeapNode* leftnode;
MinHeapNode* rightnode;
MinHeapNode* topnode;

// Iterate while size of priority queue doesn't become 1
while (pq.length() != 1)
{
  // Extract the 2 minimum freq items from priority queue
	MinHeapNode temp;

	leftnode = pq.extractMin();
	rightnode = pq.extractMin();


	//cout << "leftnode = [" << leftnode->data << ":" << leftnode->freq << "]" << endl;
	//cout << "rightnode = [" << rightnode->data << ":" << rightnode->freq << "]" << endl;

  // Create a new internal node with frequency equal to the sum of the 2 nodes frequencies.
  // Make the 2 extracted node as left and right children of this new node. Add this node
  // to the minheap.
	topnode = temp.newNode('\0', (leftnode->freq + rightnode->freq));

	topnode->left = leftnode;
	topnode->right = rightnode;


	//cout << "topnode = [" << topnode->data << ":" << topnode->freq << "]" << endl;
	//cout << "topnode = " << topnode << endl;
  pq.insert(topnode);
	//cout << "Priority Q: " << pq << endl;
	//cout << "-------" << endl;

}
		return pq.extractMin();
}
//===========End of BuildTree==================================================

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
				in_file.close();
			}

//==========Printing the Vector===========
		cout << "======Vector======" << endl;
		cout << "{" ;
		for(int j = 0; j < vect.size(); j++){
			cout << "[" << vect[j].data << ":" << vect[j].freq << "]";
			if (j < vect.size()-1)
				cout << ", ";
		}
		cout << "}" << endl;
//=========================================
		//cout << "======Priority Queue======" << endl;
		MinPriorityQueue<MinHeapNode> pq;
		for (int k = 0; k < vect.size(); k++){
			pq.insert(&vect[k]);
		}
		//cout << pq << endl;


RootNode = buildTree(pq);

MinHeapNode tempNode;
tempNode = *RootNode;
string Arr[10000];
int top = 0;

makecode(RootNode, Arr, 0);
//=======Put in out_file========
ofstream out_file ( out );
if ( !out_file.is_open() )//  see if file opened
	cout<<"Could not open out file\n";
else {
	for(int j = 0; j < vect.size(); j++){
		out_file << vect[j].data << vect[j].code <<".";
	}
	out_file << "*";

	for(int j = 0; j < vect.size(); j++){
		out_file << vect[j].code;
	}
	out_file << endl;
}
return vect;
}
//==========End of Compress=============================

void decompress(char *in, char *out)
{
MinHeapNode* RootNode;
std::vector<MinHeapNode> vect;
	bool go = true;
	string temp;
	MinHeapNode node;
	string tempA[10000];
	int A_count = 0;

	string read;
		ifstream in_file ( in );//  argv[2] is a filename to open

		if ( !in_file.is_open() )//  see if file opened
			cout<<"Could not open file\n";
		else {
			char x;
					while(in_file.get ( x )){
						cout << "x = " << x << endl;
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
							cout << "Node's code is: " << temp << endl;
							vect.push_back(node);
							go = false;
						}
						}
						go = true;
					}



						tempA[A_count] = x;
						A_count++;
						}
						for (int k; k < A_count; k++){
							cout << tempA[k];
						}
						cout << endl;

/*
						if(x!='*'){
						for (int i = 0; i < vect.size(); i++){
							while(vect[i].code != read){
								read += x;
								cout << read << endl;
							}
							cout << vect[i].data;
						}
					}
*/
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
