#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;
using namespace std;


TEST_CASE("Test"){
	Tree T("Erez");
	T.addFather("Erez", "Aharon"); 
	T.addMother("Erez", "Sigalit");
	CHECK(T.relation("Aharon") == "father");
	CHECK(T.relation("Sigalit") == "mother");
	CHECK(T.find("father") == "Aharon");
	CHECK(T.find("mother") == "Sigalit");
}

TEST_CASE("Test"){
	Tree T("Boaz");
	T.addFather("Boaz", "Aharon");
	T.addMother("Boaz", "Sigalit");
	T.addFather("Aharon","Shlomo");
	T.addMother("Aharon","Yona");
	CHECK(T.relation("Aharon") == "father");
	CHECK(T.relation("Sigalit") == "mother");
	CHECK(T.relation("Yona") == "grandmother");
	CHECK(T.relation("Shlomo") == "grandfather");
	CHECK(T.find("father") == "Aharon");
	CHECK(T.find("mother") == "Aharon");
}


TEST_CASE("Test"){
	Tree T("Shlomi");
	T.addFather("Shlomi", "Aharon");
	T.addMother("Shlomi", "Sigalit");
	T.addFather("Aharon","Shlomo");
	T.addMother("Aharon","Yona");
	T.addFather("Sigalit","Boaz");
	T.addMother("Sigalit","Mazal");
	CHECK(T.relation("Aharon") == "father");
	CHECK(T.relation("Sigalit") == "mother");
	CHECK(T.relation("Yona") == "grandmother");
	CHECK(T.relation("Boaz") == "grandfather");
        CHECK(T.relation("Mazal") == "grandmother");
	CHECK(T.relation("Shlomo") == "grandfather");
	CHECK(T.find("father") == "Aharon");
	CHECK(T.find("mother") == "Sigalit");
}


TEST_CASE("Test"){
	Tree T("Ruth");
	T.addFather("Ruth", "Aharon");
	T.addMother("Ruth", "Sigalit");
	T.addFather("Aharon","Shlomo");
	T.addMother("Aharon","Yona");
	T.addFather("Sigalit","Boaz");
	T.addMother("Sigalit","Mazal");
	CHECK(T.find("father") == "Aharon");
	CHECK(T.find("mother") == "Sigalit");
	CHECK(T.relation("Aharon") == "father");
	CHECK(T.relation("Sigalit") == "mother");
	CHECK(T.relation("Yona") == "grandmother");
	CHECK(T.relation("Boaz") == "grandfather");
        CHECK(T.relation("Mazal") == "grandmother");
	CHECK(T.relation("Shlomo") == "grandfather");
	T.remove("Aharon");
	CHECK(T.find("father") == "unrelated");
	T.addFather("Ruth", "Aharon");
	CHECK(T.relation("Aharon") == "father");
}



TEST_CASE("Test"){
	Tree T("Yonit");
	T.addFather("Yonit", "Aharon");
	T.addMother("Yonit", "Sigalit");
	T.addFather("Aharon","Shlomo");
	T.addMother("Aharon","Yona");
	T.addFather("Sigalit","Boaz");
	T.addMother("Sigalit","Mazal");
	T.addFather("Shlomo","Yosef");
	T.addMother("Shlomo","Bracha");
	CHECK(T.find("father") == "Aharon");
	CHECK(T.find("mother") == "Sigalit");
	CHECK(T.relation("Aharon") == "father");
	CHECK(T.relation("Sigalit") == "mother");
	CHECK(T.relation("Yona") == "grandmother");
	CHECK(T.relation("Boaz") == "grandfather");
        CHECK(T.relation("Mazal") == "grandmother");
	CHECK(T.relation("Shlomo") == "grandfather");
	CHECK(T.relation("Yosef") == "great-grandfather");
	CHECK(T.relation("Bracha") == "great-grandmother");
	CHECK(T.find("father") == "Aharon");
	T.remove("Aharon");
	CHECK(T.find("father") == "unrelated");
	T.addFather("Ruth", "Aharon");
	CHECK(T.relation("Aharon") == "father");
}


TEST_CASE("Test"){
    Tree T ("Ella");

	T.addMother("Ella", "Harper") 
	 .addMother("Harper", "Avery") 
	 .addMother("Avery", "Madison")
	 .addMother("Madison", "Lily")
	 .addMother("Lily", "Lillian")
	 .addMother("Lillian", "Aubrey")
	 .addFather("Ella", "Carter")
	 .addFather("Carter", "Wyatt")
	 .addFather("Wyatt", "Jack")
	 .addFather("Jack", "Julian")
	 .addFather("Julian", "Jaxon")
	 .addFather("Jaxon", "Austin");
	CHECK(T.relation("Ella") == "me");
	CHECK(T.relation("Harper") == "mother");
	CHECK(T.relation("Avery") == "grandmother");
	CHECK(T.relation("Madison") == "great-grandmother");
	CHECK(T.relation("Lily") == "great-great-grandmother");
	CHECK(T.relation("Lillian") == "great-great-great-grandmother");
	CHECK(T.relation("Carter") == "father");
	CHECK(T.relation("Wyatt") == "grandfather");
	CHECK(T.relation("Jack") == "great-grandfather");
	CHECK(T.relation("Julian") == "great-great-grandfather");
	CHECK(T.relation("Jaxon") == "great-great-great-grandfather");
	CHECK(T.relation("Austin") == "great-great-great-great-grandfather");
	CHECK(T.relation("Terahby") == "unrelated");
	CHECK(T.relation("Yosef") == "unrelated");
	CHECK(T.find("me") == "Ella");
	CHECK(T.find("mother") == "Harper");
	CHECK(T.find("grandmother") == "Avery");
	CHECK(T.find("great-grandmother") == "Madison");
	CHECK(T.find("great-great-grandmother") == "Lily");
	CHECK(T.find("great-great-great-grandmother") == "Lillian");
	CHECK(T.find("father") == "Carter");
	CHECK(T.find("grandfather") == "Wyatt");
	CHECK(T.find("great-grandfather") == "Jack");
	CHECK(T.find("great-great-grandfather") == "Julian");
	CHECK(T.find("great-great-great-great-grandfather") == "Julian");
	CHECK(T.find("mother") == "Austin");
	CHECK(T.find("great-great-great-grandfather") == "Jaxon");
	CHECK(T.find("mother") == "Rachel");

}


TEST_CASE("Test"){
    Tree T ("Cooper");

	T.addMother("Cooper", "Jameson") 
	 .addMother("Jameson", "Bryson") 
	 .addMother("Bryson", "Everett")
	 .addMother("Everett", "Parker")
	 .addMother("Parker", "Miles")
	 .addMother("Miles", "Sawyer")
	 .addFather("Cooper", "Piper")
	 .addFather("Piper", "Madeline")
	 .addFather("Madeline", "Peyton")
	 .addFather("Peyton", "Hadley")
	 .addFather("Hadley", "Taylor")
	 .addFather("Taylor", "Ashley");


	CHECK(T.relation("Cooper") == "me");
	CHECK(T.relation("Jameson") == "mother");
	CHECK(T.relation("Bryson") == "grandmother");
	CHECK(T.relation("Everett") == "great-grandmother");
	CHECK(T.relation("Parker") == "great-great-grandmother");
	CHECK(T.relation("Miles") == "great-great-great-grandmother");
	CHECK(T.relation("Piper") == "father");
	CHECK(T.relation("Madeline") == "grandfather");
	CHECK(T.relation("Peyton") == "great-grandfather");
	CHECK(T.relation("Hadley") == "great-great-grandfather");
	CHECK(T.relation("Jaxon") == "great-great-great-grandfather");
	CHECK(T.relation("Taylor") == "great-great-great-great-grandfather");
	CHECK(T.relation("Ashley") == "unrelated");
	CHECK(T.relation("Andrea") == "unrelated");


	CHECK(T.relation("Alyssa") == "great-great-great-great-grandfather");
	CHECK(T.relation("Faith") == "great-great-great-great-grandfather");
	CHECK(T.relation("Hadley") == "great-great-great-great-grandfather");
	CHECK(T.relation("Wesley") == "grandfather");
	CHECK(T.relation("Elza") == "grandfather");
	CHECK(T.relation("Aharoni") == "grandfather");
	CHECK(T.relation("Uberbuct") == "grandfather");

	CHECK(T.find("me") == "Cooper");
	CHECK(T.find("mother") == "Jameson");
	CHECK(T.find("grandmother") == "Bryson");
	CHECK(T.find("great-grandmother") == "Everett");
	CHECK(T.find("great-great-grandmother") == "Parker");
	CHECK(T.find("great-great-great-grandmother") == "Miles");
	CHECK(T.find("father") == "Carter");
	CHECK(T.find("grandfather") == "Madeline");
	CHECK(T.find("great-grandfather") == "Peyton");
	CHECK(T.find("great-great-grandfather") == "Hadley");
	CHECK(T.find("great-great-great-great-grandfather") == "Taylor");
	CHECK(T.find("mother") == "Austin");
	CHECK(T.find("great-great-great-grandfather") == "Jaxon");
	CHECK(T.find("mother") == "Rachel");
}

