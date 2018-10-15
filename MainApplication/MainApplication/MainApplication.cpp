#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "SinglyLinkedList.h"

using namespace std;

vector<int> solution(vector<int> &A, int K) {
	// write your code in C++14 (g++ 6.2.0)

	int arrsize = A.size();

	vector<int> result;

	for (int i = A.size() - K; i < A.size(); i++)
	{
		result.push_back(A[i]);
	}

	for (int i = 0; i < A.size() - K; i++)
	{
		result.push_back(A[i]);
	}

	return result;
}


int solution(int X, int Y) {
	// write your code in C++14 (g++ 6.2.0)

	int reqAngle = 0;
	enum Direction
	{
		LEFT = 0,
		RIGHT
	};


	int opposite = X > 180 ? (X + 180) % 180 : X + 180;
	Direction dir = Y > opposite ? RIGHT : LEFT;

	int diff = Y - opposite;

	if (diff > 30 && diff < 90)
	{
		reqAngle = 30;
	}
	else if (diff > 90 && diff < 135)
	{
		reqAngle = 90;
	}
	else if (diff > 135 && diff < 180)
	{
		reqAngle = 135;
	}
	else if (diff == 180)
	{
		reqAngle = 180;
	}



	return -1;

}

int solution(string &q, string &p, string &r) {
	// write your code in C++14 (g++ 6.2.0)

	int maxSize = 0;
	size_t pos = 0;

	string catalog = q; // "Netherlands,1,2500\nNetherlands,2,1000\nNetherlands,3,3000";
	string region = r; // "Netherlands";
	string curVersion = p; // "Netherlands,1";
	string delimiter = "\n";

	vector<string> subCatalog;
	vector<string> subRegion;


	if (catalog.find(region) == -1)
	{
		return -1;
	}

	while ((pos = catalog.find(delimiter)) != std::string::npos) {
		subCatalog.push_back(catalog.substr(0, pos));
		catalog.erase(0, pos + delimiter.length());
	}
	subCatalog.push_back(catalog);

	while ((pos = region.find(delimiter)) != std::string::npos) {
		subRegion.push_back(region.substr(0, pos));
		region.erase(0, pos + delimiter.length());
	}
	subRegion.push_back(region);

	for (vector<string>::iterator itReg = subRegion.begin(); itReg != subRegion.end(); ++itReg)
	{
		string tempReg = *itReg;

		for (vector<string>::iterator itCat = subCatalog.begin(); itCat != subCatalog.end(); ++itCat)
		{
			string tempCat = *itCat;
			if (tempCat.find(tempReg) != -1)
			{
				int comPos = tempCat.find(",");
				string ver = tempCat.substr(0, comPos+2);

				if (curVersion.find(ver) == -1)
				{
					size_t sizepos = tempCat.find_last_of(",");
					string size = tempCat.substr(sizepos+1, tempCat.size()-sizepos);

					maxSize += atoi(size.c_str());

				}

			}
		}

	}

	return maxSize;
}


int main()
{
	//solution("", "", "");

#if 0

	int num = 529;
		int ptr; //Used for bitwise operation.
		for (ptr = 1; ptr>0; ptr <<= 1) //Find the lowest bit 1
			if ((num&ptr) != 0)
				break;
		int cnt = 0; //Count the (possible) gap
		int ret = 0; //Keep the longest gap.
		for (; ptr>0; ptr <<= 1) {
			if ((num&ptr) != 0) { //If it's bit 1
				ret = cnt < ret ? ret : cnt; //Get the bigger one between cnt and ret
				cnt = -1; //Exclude this bit
			}
			cnt++; //Increment the count. If this bit is 1, then cnt would become 0 beause we set the cnt as -1 instead of 0.
		}

	// Rotation

	vector<int> B;
	B.push_back(3);
	B.push_back(8);
	B.push_back(9);
	B.push_back(7);
	B.push_back(6);

	solution(B, 3);
#endif

	cout << "End of the application";
	getchar();

	return 0;
}