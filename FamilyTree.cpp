#include "FamilyTree.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>

using namespace std;
using namespace family;

			Tree::Tree ( string text )
			{

			}
			Tree& Tree::addFather( string text, string text2 )
			{
				return *this;
			};

			Tree& Tree::addMother( string text, string text2 )
			{
				return *this;
			};

			string Tree::relation( string text )
			{
				return "relation";
			};

			string Tree::find( string text )
			{
				return "find";
			}

			void Tree::display()
			{
			}

			void Tree::remove( string text )
			{
			}
