#include <iostream>
#include <typeinfo>
#include <vector>
#include <cstring>
#include <iterator>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <utility>

using namespace std;

// Compiler version g++ 6.3.0
typedef pair < string, int >spair;
typedef char pchar;

class Instruction
{
  public:
	pchar value;
	int amount;
	  Instruction()
	{
	}
	virtual bool evulate(pchar c) = 0;
};

typedef vector < Instruction * >Ivec;


class InsSymbol:public Instruction
{
  public:
	InsSymbol(pchar _value)
	{
		value = _value;

	}
	bool evulate(pchar c) override
	{
		cout << c << " " << value << endl;
		return value == c ? true : false;
	}
};

class IHolderData
{
  public:
	void *data;
	void *i;
	virtual bool find(Instruction * inst) = 0;

};
class HolderText:public IHolderData
{
  public:
	string * data;
	string::iterator i;
	// InstructionMap im;
	HolderText(string * _data):data(_data), i(_data->begin())
	{

	}
	char getPointedValue()
	{
		return *i;
	}
	bool find(Instruction * inst) override
	{

		while (i != data->end())
		{

			if (inst->evulate(*i))
			{
				return true;
			}
			i++;
		}
		return false;
	}

};

class IPattern
{
  public:
	void *ins;
	void *i;
	virtual Instruction *next() = 0;

};
class Pattern:public IPattern
{
  public:
	Ivec * ins;
	Ivec::iterator i;

	Pattern(Ivec * _ins):ins(_ins), i(_ins->begin())
	{
	}
	Instruction *next() override
	{
		return *i;
	}
};

class Base
{
  public:
	IHolderData * hd;
	IPattern *ipat;
	  Base(HolderText * _hd, IPattern * _ipat):hd(_hd), ipat(_ipat)
	{

	}
	bool search()
	{
		// ---------------
		// .  .
		// .  action . ---------> result -
		// .  .  |true
		// --------------- <------------------

		Instruction *inst = ipat->next();
		bool result = hd->find(inst);
		
		// if(!result){
		// cout<<"not match"<<endl;
		// } 
		result ? cout << "match" : cout << "not match";

		return result;
	}


};

/* 
   class Counter { public:

   vector < spair > vecWordsCounted = vector < spair > (); // set<string>
   wordsChecked = set<string>(); int count; void countWords(vector < string >
   vc) { for (vector < string >::iterator i = vc.begin(); i < vc.end(); ++i) {
   // if(wordsChecked.find(*i)) continue; count = 1; for (vector < string
   >::iterator j = next(i, 1); j < vc.end(); ++j) { //
   if(wordsChecked.find(*j)) continue; if (*i == *j) { count++; vc.erase(j); }
   } vecWordsCounted.push_back(spair(*i, count));

   // wordsChecked.insert(*i); } } };

   class Sorter { public:

   vector < spair > sortVec(vector < spair > vc) {

   sort(vc.begin(), vc.end(),[]( spair a, spair b) { return a.second <
   b.second; } );

   return vc;

   }



   }; 
class Shower
{
  public:
	void showVector(vector < string > vc)
	{
		for (vector < string >::iterator i = vc.begin(); i < vc.end(); ++i)
		{
			cout << *i << endl;

		}


	}
	void showVector(vector < spair > &vc)
	{
		for (vector < spair >::iterator i = vc.begin(); i < vc.end(); i++)
		{
			cout << i->first << " " << i->second << endl;
		}
		// for(pair<string, int> &c: vc){
		// cout<<c.first<<endl;
		// }


	}
	void showMap(map < string, int >mp)
	{
	  for (pair < string, int >element:mp)
		{
			cout << element.first << element.second << endl;
		}


	}
	void showSet(set < spair > st)
	{
	  for (pair < string, int >element:st)
		{
			cout << element.first << element.second << endl;
		}


	}
};
*/
int main()
{

	// cout << "Enter words" << endl;

	// std::string inWords;
	// getline(cin, inWords);
	Ivec ivec = Ivec();
	Instruction *isymb = new InsSymbol('e');
	ivec.push_back(isymb);
	Pattern pat = Pattern(&ivec);
	string text = "some letters to test";
	HolderText hd = HolderText(&text);
	Base base = Base(&hd, &pat);
	base.search();


}
