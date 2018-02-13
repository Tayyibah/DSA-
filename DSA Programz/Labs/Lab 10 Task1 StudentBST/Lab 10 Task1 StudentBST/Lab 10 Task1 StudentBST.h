#ifndef CSLINKEDLISTDH_H
#define CSLINKEDLISTDH_H
#include"Node.h"
class CSLinkedListDH
{
private:
	Node  head;
public:
	CSLinkedListDH();
	void display();
	bool remove(int val);
	bool insert(int val);
	CSLinkedListDH(const CSLinkedListDH &orig);
	~CSLinkedListDH();
	CSLinkedListDH operator=(CSLinkedListDH & val);
};
#endif

