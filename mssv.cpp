#include "header.h"

int countName(string s){
	int ans = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == ' '){
			ans++;
		}
	}
	return ans + 1;
}

void addHead(PeopleList* &pHead, People* p){
	if (!pHead) {
		pHead = new PeopleList;
		pHead->first = pHead->last = p;
		return;
	}
	
	p->next = pHead->first;
	pHead->first = p;
}

void addTail(PeopleList* &pHead, People* p){
	if (!pHead) {
		pHead = new PeopleList;
		pHead->first = pHead->last = p;
		return;
	}
	
	pHead->last->next = p;
	pHead->last = p;
}

PeopleList* read_file(string input_file){
	// TODO: read input_file
	ifstream fin;
	fin.open(input_file.c_str());
	PeopleList* pHead = nullptr;
	
	while(!fin.eof()){
		string s;
		People* p = new People;
		string tmp;
		p->next = nullptr;
		
		getline(fin, s);
		
		stringstream ss(s);
		getline(ss, p->name, '-');
		getline(ss, tmp, '-');
		p->height = atoi(tmp.c_str());
		getline(ss, tmp);
		p->weight = atoi(tmp.c_str());
		
		if (countName(p->name) <= 3){
			addHead(pHead, p);
		}else{
			addTail(pHead, p);
		}
	}
	return pHead;
	
	fin.close();
	
	return NULL;
}

void remove(PeopleList *&P, int x){
	// TODO: remove people whose height is less than x
	People* cur = P->first;
	if (!cur) return;
	
	while (cur->next){
		if (cur->next->height < x){
			if (cur->next->next){
				delete cur->next;
				cur->next = nullptr;
			}else{
				People* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
		}else{
			cur = cur->next;
		}
	}
	
	if (P->first->height < x){
		if (P->first->next){
			People* tmp = P->first;
			P->first = P->first->next;
			delete tmp;
		}else{
			delete P->first;
			delete P->last;
			delete P;
			P = nullptr;
		}
	}
}


void main_debug(string input_file, int x){
	// YOUR MAIN HERE: do whatever you want here, for example:
	PeopleList* plist = read_file(input_file);
	print_output(plist, x);
	
}






// DO NOT CHANGE ANYTHING FROM HERE
void print_output(PeopleList* plist, int x){
	if (plist){
		for (People *temp = plist->first; temp != NULL; temp = temp->next)
			cout << temp->name << "-" << temp->height << "-" << temp->weight << "\n";
		cout << "----------\n";
		remove(plist, x);
		for (People *temp = plist->first; temp != NULL; temp = temp->next)
			cout << temp->name << "-" << temp->height << "-" << temp->weight << "\n";
	}
}
int main(int argc, char* argv[]){
	string input_file; int x;
	if (argc > 2) {
		input_file = argv[1]; x = atoi(argv[2]);
		if (argc > 3 && atoi(argv[3]) == 1) {
			main_testcases(input_file, x); return 0; }}
	else {
		cout << "Enter input_file:"; cin >> input_file;
	 	cout << "Enter x:"; cin >> x; }
	main_debug(input_file, x);
	if (!system(NULL)) system("pause"); return 0; }

void main_testcases(string input_file, int x){
	PeopleList* plist = read_file(input_file);
	print_output(plist, x); }
