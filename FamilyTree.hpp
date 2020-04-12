#include<iostream>
using namespace std;

namespace family{
	class Tree {
		public:
			Tree( string text );
		Tree& addFather( string text, string text2 );
		Tree& addMother( string text, string text2 );
		string relation( string text );
		string find( string text );
		void display();
		void remove( string text );
	};
}


