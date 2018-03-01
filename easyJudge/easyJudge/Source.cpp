#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

string rootDir = "C:\\Users\\fishtoby\\Desktop\\code\\myJudge\\";
inline unsigned long long myRan1() {
	static unsigned long long ranX = 20180209;
	return ranX = ranX * 0xdefacedll + 1ll;
}
inline unsigned long long myRan(long long n) {
	return (unsigned long long)rand() * (unsigned long long)rand() % (unsigned long long) n;
}
inline string i2s(int x) {
	if (x == 0) return "0";
	string s;
	s.clear();
	while (x) {
		s.push_back(x % 10 + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
vector<string> testData;
inline void vs2file(string nowS) {
	for (int i = 0; i < testData.size(); i++) {
		fstream fp;
		string outFile = rootDir + "test" + nowS + "_" + i2s(i) + ".txt";
		fp.open(outFile, ios::out);
		if (!fp) {//如果開啟檔案失敗，fp為0；成功，fp為非0
			cout << "Fail to open file: " << outFile << endl;
		}
		fp << testData[i];
		fp.close();
	}
	return;
}
inline void genP0() {
	vector<pair<int, int> > v;
	v.push_back(make_pair(3,5));
	v.push_back(make_pair(10,20));
	v.push_back(make_pair(0,100));
	v.push_back(make_pair(2147483647,2147483647));
	v.push_back(make_pair(13213,312312312));
	v.push_back(make_pair(32983,938231 ));
	testData.clear();
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		testData.push_back("");
		testData[cnt] = i2s(v[i].first) + " " + i2s(v[i].second) + "\n";
		cnt++;
	}
}
inline void genP1(int maxC,int maxN) {
	int nv[7] = { 3,10,100,1000,10000,30000,100000 };
	int cv[3] = { 100,100000,1000000000 };
	testData.clear();
	int cnt=0;
	
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			if (nv[i] > maxN || cv[j] > maxC) continue;
			testData.push_back("");
			testData[cnt].clear();
			testData[cnt] = i2s(nv[i]) + "\n";
			for (int k = 0; k < nv[i]; k++) {
				testData[cnt] += i2s(myRan(cv[j])) + " " + i2s(myRan(cv[j])) + "\n";
			}
			cnt++;
		}
	}
	return ;
}
inline void genP2(int maxN) {
	int nv[10] = { 3,10,12,13,15,20,100,1000,10000,100000 };
	testData.clear();
	int cnt = 0;
	vector<int> numV;
	for (int i = 0; i < 10; i++) {
		if (nv[i] > maxN) continue;
		int nowM;
		if (nv[i] > 1000) nowM = 100000;
		else nowM = nv[i] * nv[i];

		numV.clear();
		for (int j = 1; j <= nv[i]; j++) numV.push_back(j);
		random_shuffle(numV.begin(), numV.end());

		testData.push_back("");
		testData[cnt].clear();
		testData[cnt] = i2s(nv[i]) + " " + i2s(nowM) + "\n";
		for (int j = 0; j < nowM; j++) {
			int a, b;
			a = myRan(nv[i]-1) ; 
			b = myRan(nv[i]-a-1)+a+1 ; 
			testData[cnt] += i2s(numV[a]) + " " + i2s(numV[b]) + "\n";
		}
		cnt++;
	}
	return;

}
inline void genP3(int maxN,int maxQ) {
	int nv[7] = { 3,10,100,1000,10000,30000,100000 };
	int qv[7] = { 3,10,100,1000,10000,30000,100000 };
	testData.clear();
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 7) {
				if (nv[i] > maxN) continue;
				testData.push_back("");
				testData[cnt].clear();
				testData[cnt] = i2s(nv[i]) + " " + i2s(nv[i]) + "\n";
				for (int k = 0; k < nv[i]-1; k++) {
					testData[cnt] += i2s(0) + " ";
				}
				testData[cnt] += i2s(100000000);
				testData[cnt] += "\n";
				for (int k = 0; k < nv[i]; k++) {
					int l, r;
					l = 1;
					r = nv[i];
					if (l > r) swap(l, r);
					testData[cnt] += i2s(l) + " " + i2s(r) + "\n";
				}
				cnt++;
			}
			else {
				if (nv[i] > maxN || qv[j] > maxQ) continue;
				testData.push_back("");
				testData[cnt].clear();
				testData[cnt] = i2s(nv[i]) + " " + i2s(qv[j]) + "\n";
				for (int k = 0; k < nv[i]; k++) {
					testData[cnt] += i2s(myRan(1000000000)) + " ";
				}
				testData[cnt] += "\n";
				for (int k = 0; k < qv[j]; k++) {
					int l, r;
					l = myRan(nv[i]) + 1;
					r = myRan(nv[i]) + 1;
					if (l > r) swap(l, r);
					testData[cnt] += i2s(l) + " " + i2s(r) + "\n";
				}
				cnt++;
			}
		}
	}
	return ;
}
inline void genP4(int maxN) {
	int nv[6] = { 3,10,100,1000,10000,100000 };
	int nb[6] = { 100,10,5,3,2,1 };
	vector<int> vv;
	testData.clear();
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		
		
		for (int k = 0; k < 6; k++) {
			int nowM;
			if (nv[i] >= 1000) nowM = 100000;
			else nowM = myRan(nv[i] * nv[i] / 2);
			if (nv[i] > maxN || nowM/nb[k] < 2) continue;
			
			testData.push_back("");
			testData[cnt].clear();
			testData[cnt] = i2s(nv[i]) + " " + i2s(nowM) + " " + i2s(nowM/nb[k]) + "\n";
			for (int j = 0; j < nowM; j++) {
				testData[cnt] += i2s(myRan(nv[i]) + 1) + " " + i2s(myRan(nv[i]) + 1) + "\n";
			}
			vv.clear();
			for (int j = 1; j <= nowM; j++) vv.push_back(j);
			random_shuffle(vv.begin(), vv.end());
			for (int j = 0; j < nowM / nb[k]; j++) {
				testData[cnt] += i2s(vv[j]) + "\n";
			}
			cnt++;
		}
	}
	return;
}
inline void genP5(int maxN) {
	int nv[6] = { 3,10,100,1000,10000,100000 };
	int nb[6] = { 100,10,5,3,2,1 };
	vector<int> vv;
	testData.clear();
	int cnt = 0;
	for (int i = 0; i < 6; i++) {


		for (int k = 0; k < 6; k++) {
			int nowM;
			if (nv[i] >= 1000) nowM = 100000;
			else nowM = myRan(nv[i] * nv[i] / 2);
			if (nv[i] > maxN || nowM / nb[k] < 2) continue;

			testData.push_back("");
			testData[cnt].clear();
			testData[cnt] = i2s(nv[i]) + " " + i2s(nowM) + " " + i2s(nowM / nb[k]) + "\n";
			for (int j = 0; j < nowM; j++) {
				testData[cnt] += i2s(myRan(nv[i]) + 1) + " " + i2s(myRan(nv[i]) + 1) + "\n";
			}
			vv.clear();
			for (int j = 1; j <= nowM; j++) vv.push_back(j);
			random_shuffle(vv.begin(), vv.end());
			for (int j = 0; j < nowM / nb[k]; j++) {
				testData[cnt] += i2s(vv[j]) + "\n";
			}
			cnt++;
		}
	}
	return;
}
inline void genP6(int maxN) {
	int nv[7] = { 3,10,100,1000,10000,30000,100000 };
	testData.clear();
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (nv[i] > maxN) continue;
		testData.push_back("");
		testData[cnt].clear();
		testData[cnt] = i2s(nv[i]) + "\n";
		for (int j = 0; j < nv[i]; j++) {
			testData[cnt] += i2s(myRan(1000000000)) + " ";
		}
		testData[cnt] += "\n";
		cnt++;
	}
	return;
}
inline void genP7(int maxN,int maxC) {
	int nv[12] = { 3,10,20,30,50,100,200,1000,3000,5000,10000,20000 };
	int cv[3] = { 2,5,11 };
	testData.clear();
	int cnt = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 3; j++) {
			if (nv[i] > maxN || cv[j] > maxC) continue;
			testData.push_back("");
			testData[cnt].clear();
			testData[cnt] = i2s(myRan(nv[i])) + "\n";
			for (int k = 0; k < 8; k++) {
				testData[cnt] += i2s(myRan(cv[j])) + " ";
			}
			testData[cnt] += "\n";
			cnt++;
		}
	}
	return;

}
inline void genP8() {

}
pair<long long, int> deg[100005];
inline void genYs() {
	int nv[7] = { 5,10,100,1000,10000,30000,100000 };
	int cnt = 0;
	testData.clear();
	for (int i = 0; i < 5; i++) {
		testData.push_back("");
		testData[cnt] += i2s(nv[i])+" "+i2s(nv[i]*5/3)+"\n";
		for (int j = 0; j < nv[i]; j++) {
			deg[j].first = 0;
			deg[j].second = j+1;
		}
		for (int j = 0; j < nv[i] * 5 / 3; j++) {
				int a, b;
				a = 1, b = 1;
				while (a == b || deg[a].first>=9 || deg[b].first>=9) {
					a = myRan(nv[i]*nv[i])/nv[i];
					b = myRan(nv[i]*nv[i])%nv[i];
				}
				deg[a].first++;
				deg[b].first++;
				testData[cnt] += i2s(deg[a].second) + " " + i2s(deg[b].second) + " " + i2s(myRan(10)+1) + "\n";
		}
		testData[cnt] += i2s(myRan(nv[i])+1) + " " + i2s(myRan(nv[i])+1) + "\n";
		cnt++;
	}
}
inline void genHw() {
	int nv[7] = { 3,10,100,1000,10000,30000,100000 };
	testData.clear();
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		//if (nv[i] > maxN) continue;
		testData.push_back("");
		testData[cnt].clear();
		testData[cnt] = i2s(nv[i]) + "\n";
		for (int j = 0; j < nv[i]; j++) {
			testData[cnt] += i2s(myRan(1000000000)) + " ";
		}
		testData[cnt] += "\n";
		cnt++;
	}
	return;
}
inline int sameTxt(string dir1, string dir2) {
	ifstream inFile;
	inFile.open(dir1);// Open the input file

	stringstream strStream;
	strStream << inFile.rdbuf();// Read the file
	string s1 = strStream.str();

	ifstream inFile2;
	inFile2.open(dir2);// Open the input file

	stringstream strStream2;
	strStream2 << inFile2.rdbuf();// Read the file
	string s2 = strStream2.str();

	string fs1, fs2;
	int i = 0, j = 0;
	if (s1.empty() && s2.empty()) return 1;
	if (s1.empty() || s2.empty()) return 0;
	while (s1.back() == '\n' || s1.back() == ' ') s1.pop_back();
	while (s2.back() == '\n' || s2.back() == ' ') s2.pop_back();
	while (1) {
		fs1.clear();
		fs2.clear();
		while (i < s1.size() && s1[i] != '\n') {
			fs1.push_back(s1[i]);
			i++;
		}
		i++;
		while (fs1.back() == ' ') fs1.pop_back();
		while (j < s2.size() && s2[j] != '\n') {
			fs2.push_back(s2[j]);
			j++;
		}
		j++;
		while (fs2.back() == ' ') fs2.pop_back();
		if (fs1 != fs2) {
			return 0;
		}
		if (i >= s1.size() && j >= s2.size()) return 1;
		else if (i >= s1.size() || j >= s2.size()) return 0;
	}
	return 1;
}
inline void getAns(string rightCode,string nowS,int n) {
	string cmdS;
	cmdS = "g++	-O2 -Wall -std=c++11 " + rootDir + rightCode + " -o " + rootDir + "rightexe";
	system(cmdS.c_str());
	
	cmdS = "g++	-O2 -Wall -std=c++11 " + rootDir + "submitCode" + ".cpp -o " + rootDir + "submitexe";
	if (system(cmdS.c_str())) {
		cout << "I think there is a Compile Error!" << endl;
		return ;
	}
	int key = 1;
	cout << "Test Start!" << endl;
	if (n == -1) n = (int)testData.size();
	for (int i = 0; i < n; i++) {
		
		auto startTime = steady_clock::now();

		cmdS = rootDir + "rightexe.exe < " + rootDir + "test" + nowS + "_" + i2s(i) + ".txt > " + rootDir + "rightOut" + i2s(i) + ".txt";
		system(cmdS.c_str());

		//cout << "correct answer cost " << (steady_clock::now() - startTime).count() << " at test" << i << endl;
		auto timeout =  (steady_clock::now() - startTime) * 15;
		auto timeout2 = seconds(3);
		
		startTime = steady_clock::now();

		cmdS = rootDir + "submitexe.exe < " + rootDir + "test" + nowS + "_" + i2s(i) + ".txt > " + rootDir + "submitOut" + i2s(i) + ".txt";
		system(cmdS.c_str());

		auto currentTime = steady_clock::now();
		//cout << "submit answer cost  " << (steady_clock::now() - startTime).count() << " at test" << i << endl;
		if (currentTime - startTime > timeout || currentTime - startTime > timeout2) {
			cout << "Oh! No! Time Limit Exceeded at test " << i << "!! Stop the testing to prevent time wasted. Orz" << endl;
			return;
		}

		if (!sameTxt(rootDir + "submitOut" + i2s(i) + ".txt", rootDir + "rightOut" + i2s(i) + ".txt")) {
			cout << "Wrong Answer at test " << i << "!" << endl;
			key = 0;
		}
		else {
			cout << "Accept at test " << i << "!" << endl;
		}

	}
	cout << "---------------" << endl;
	if (key) cout << "Wow !! That's an Accept!!!" << endl;
	else cout << "Oops ... that's a Wrong Answer QQ" << endl;
}

inline void judge(string pName,int gen = 1) {
	for (int i = 0; i < (int)pName.size(); i++) {
		if (pName[i] >= 'A' && pName[i] <= 'Z') {
			pName[i] = pName[i] - 'A' + 'a';
		}
	}
	srand(time(NULL));
	if (pName == "p0") {
		if (gen) {
			genP0();
			vs2file("0");
			getAns("correctAns0.cpp", "0",-1);
		}
		else {
			getAns("correctAns0.cpp", "0", 6);
		}
		
	}
	if (pName == "p1") {
		if (gen) {
			genP1(1000000000, 100000);
			vs2file("1");
			getAns("correctAns1.cpp", "1",-1);
		}
		else {
			getAns("correctAns1.cpp", "1", 21);
		}
		
	}
	else if (pName == "p2") {
		if (gen) {
			genP2(100000);
			vs2file("2");
			getAns("correctAns2.cpp", "2",-1);
		}
		else {
			getAns("correctAns2.cpp", "2",10);
		}
	}
	else if (pName == "p3") {
		if (gen) {
			genP3(100000, 100000);
			vs2file("3");
			getAns("correctAns3.cpp", "3",-1);
		}
		else {
			getAns("correctAns3.cpp", "3",56);
		}
		
	}
	else if (pName == "p4") {
		if (gen) {
			genP4(100000);
			vs2file("4");
			getAns("correctAns4.cpp", "4",-1);
		}
		else {
			getAns("correctAns4.cpp", "4",32);
		}
	}
	else if (pName == "p5") {
		if (gen) {
			genP5(100000);
			vs2file("5");
			getAns("correctAns5.cpp", "5",-1);
		}
		else getAns("correctAns5.cpp", "5",30);
	}
	else if (pName == "p6") {
		if (gen) {
			genP6(100000);
			vs2file("6");
			getAns("correctAns6.cpp", "6",-1);
		}
		else {
			getAns("correctAns6.cpp", "6",7);
		}
	}
	else if (pName == "p7") {
		if (gen) {
			genP7(100000, 100000);
			vs2file("7");
			getAns("correctAns7.cpp", "7",-1);
		}
		else {
			getAns("correctAns7.cpp", "7",36);
		}
		
	}
	else if (pName == "p8") {
		if (gen) {
			genP8();
			vs2file("8");
		}
		getAns("correctAns8.cpp", "8",-1);
	}
	else if (pName == "ys") {
		if (gen) {
			genYs();
			vs2file("Ys");
			getAns("correctAnsYs.cpp", "Ys", -1);
		}
		else getAns("correctAnsYs.cpp", "Ys", 5);
	}
	else if (pName == "hw") {
		if (gen) {
			genHw();
			vs2file("Hw");
			getAns("correctAnsHw.cpp", "Hw", -1);
		}
		else getAns("correctAnsHw.cpp", "Hw", 7);
	}
}

int main() {

	string pName;


	while (cin >> pName) {
		if (pName == "new" || pName == "New" || pName == "NEW") {
			cin >> pName;
			judge(pName, 1);
		}
		else judge(pName,0);
	}

	return 0;
}