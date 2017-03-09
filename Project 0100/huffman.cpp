#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include "pq.h"

using namespace std;
MinHeapNode* buildTree(MinPriorityQueue<MinHeapNode> &pq)
{
cout << "======Start of buildTree========" << endl;
MinHeapNode leftnode;
MinHeapNode rightnode;
MinHeapNode topnode;
MinHeapNode temp;
	  // Iterate while size of priority queue doesn't become 1
	  while (!pq.empty())
	  {
	    // Extract the 2 minimum freq items from priority queue

			leftnode = *pq.extractMin();
			rightnode = *pq.extractMin();


			cout << "leftnode = [" << leftnode.data << ":" << leftnode.freq << "]" << endl;
			cout << "rightnode = [" << rightnode.data << ":" << rightnode.freq << "]" << endl;

	    // Create a new internal node with frequency equal to the sum of the 2 nodes frequencies.
	    // Make the 2 extracted node as left and right children of this new node. Add this node
	    // to the minheap. '$' is a special value for internal nodes.
			topnode.left = &leftnode;
			topnode.right = &rightnode;
	    topnode.data = '$';
			topnode.freq = (leftnode.freq + rightnode.freq);

			//topnode.data = '\0';
			cout << "topnode = [" << topnode.data << ":" << topnode.freq << "]" << endl;

	    pq.insert(&topnode);
			cout << "Priority Q: " << pq << endl;
			cout << "-------" << endl;

			if (pq.length() == 1) // only the root node exists
				break;
	  }

		return pq.extractMin();
}

void compress(char *in, char *out)
{
MinHeapNode RootNode;
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
		cout << "======Priority Queue======" << endl;
		MinPriorityQueue<MinHeapNode> pq;
		for (int k = 0; k < vect.size(); k++){
			pq.insert(&vect[k]);
		}
		cout << pq << endl;
		//cout <<"Min extracted is: "<< *pq.extractMin() << endl;

buildTree(pq);




ofstream out_file ( out );
if ( !out_file.is_open() )//  see if file opened
	cout<<"Could not open out file\n";
else {
	//out_file << "Hello World" << endl;

	for(int j = 0; j < vect.size(); j++){
		out_file << "[" << vect[j].data << ":" << vect[j].freq << "]";
		if (j < vect.size()-1)
			out_file << ", ";
	}

}

}


int main(int argc, char *argv[])
{
	char *temp;

	if (argc == 4){
		temp = argv[1];
		char blank = temp[1];

		cout << "compress about to be called" << endl;
		if (blank == 'c')
			compress(argv[2], argv[3]);

		else if (blank == 'd'){

		}

		else{
			cout << "Error: verify compression (-c) or decompression (-d)" << endl;
		}
	}



}
/*
		else if (blank == 'd')

		else{
			cout << "Error: verify compression (-c) or decompression (-d)" << endl;
		}

	}//end of  if (argc == 4)

	else{
		cout << "Incorrect format. Use: ./huffman -c filename.txt" << endl;
	}
*/

//}

 //end of main
