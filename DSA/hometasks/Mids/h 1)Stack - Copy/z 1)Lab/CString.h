#ifndef CSTRING_H
#define CSTRING_H
#include<cstring>
#include<cstdlib>
#include<cctype>
class CString
{
private:
	char * data;
	int size;
	int getLength(  const char * const str)  const;
	void copy(char * const dest,  const char * const source);
	bool isValidIndex(int i)  const;
public:
	CString();
	CString( const char );
	CString( const char * const);
	~CString();
	void input();
	char & at(const int) ;
	const char & at(const int) const;
	void display() const;
	int isEmpty() const;
	int getLength() const;
	int find(const char * const  , const int =0 ) const;
	int find( const char , const int =0 ) const;
	int insert (const int  , const char * const);
	int insert(const int ,const char );
	int remove(const int ,const int=1 );
	int remove(const char );
	void replace(const char );
	int replace(const char , const char );
	int replace(const char * const ,const char * const );
	void rightTrim();
	void leftTrim();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void resize(const int );
	int isEqual(const char * const) const;
	int isEqual(const CString &) const;
	CString( const CString & ) ;
	CString left(const int );
	CString right(const int );
	void concatEqual(const CString & );
	void concatEqual(const char * const );
	CString concat(const CString & )const;
	CString concat(const char * const)const;
	CString tokenize(  char *  );
};
#endif