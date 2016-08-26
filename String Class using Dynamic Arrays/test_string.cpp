#include "String.h"

void test_constructor() {
	cout << endl << "Testing Constructor" << endl;
	cout << "----------------------------------------------------------------" << endl;
	String s;
	s = "First Test";
	String s1("Second Test");
	String s2 = "Third Test";
	String s5 = String("yoooo");
	String cinTest;
	String cinTest2;
	cout << "Enter a String: ";
	cin >> cinTest;
	cout << "Enter in another String: ";
	cin >> cinTest2;

	cout << "Testing Constructor with cin: " << "Testing \"operator >>\" = " << cinTest << endl;
	cout << "Testing Constructor with cin: " << "Testing \"operator >>\" = " << cinTest2 << endl;
	cout << "Testing Constructor: \"s = First Test\" = " << s << endl;
	cout << "Testing Constructor: \"String s1(\"Second Test\")\" = " << s1 << endl;
	cout << "Testing Constructor: \"String s2 = \"Third Test\" = " << s2 << endl;
	cout << "Testing Constructor: " << "Testing \"s5 = String(yoooo)\" = " << s5 << endl;

	cout << "----------------------------------------------------------------" << endl << endl;
}


void test_operator_assign() {
	String s = "Chicagoooooo";
	String s1 = "Philly";
	String s3 = "NY";
	s = s1;
	s1 = s3;
	cout << "Testing operator =" << endl;
	cout << "----------------------------------" << endl;
	cout << "operator =: s = \"Philly\" = " << s << endl;
	cout << "operator =: s1 = \"NY\" = " << s1 << endl;
	cout << "----------------------------------" << endl << endl;
}


void test_operator_index() {
	cout << "Testing operator [] and reverse()" << endl;
	cout << "--------------------------------------------" << endl;
	String s = "hello";
	String s2 = "good";
	String s3("helloworld");
	String s4("class");

	cout << "operator []: s[1] from \"hello\" = " << s[1] << endl;
	cout << "operator []: s[4] from \"hello\" = " << s[4] << endl;
	
	cout << "Testing reverse(): \"helloworld\" = " << s3.reverse() << endl;
	cout << "Testing reverse(): \"class\" = " << s4.reverse() << endl;
	cout << "--------------------------------------------" << endl << endl;
}


void test_operator_indexOf() {
	cout << "Testing indexOf" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	String s = "helloworld";
	String s1("yessir");
	String s2("This is a test string for testing");
	String s3 = "aaaassssbbbbsir";
	cout << "indexOf(const char c): String s = \"helloworld\" - s.indexOf('o') = " << s.indexOf('o') << endl;
	cout << "indexOf(const char c): String s1 = \"yessir\" - s1.indexOf('r') = " << s1.indexOf('r') << endl;
	cout << "indexOf(const String pattern): String s2 = \"This is a test string for testing\" - s2.indexOf(\"test\") = " << s2.indexOf("test") << endl;
	cout << "indexOf(const String pattern): String s1 = \"yessir\" - s1.indexOf(\"sir\") = " << s1.indexOf("sir") << endl;
	cout << "indexOf(const String pattern): String s3 = \"aaaassssbbbbsir\" - s3.indexOf(\"yoo\") = " << s3.indexOf("yoo") << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl << endl;
}


void test_comparison_operators() {
	cout << "Testing Comparison Operators" << endl;
	cout << "------------------------------------------------------------------" << endl;
	

	String s = "hello";
	String s2 = "world";
	String s3 = "My length should be 22";
	String j("where are");
	String j2(" you going.");
	String j3 = "where are";
	String j4 = " you going.";
	String x = "why";
	String w = "me";
	String y = "good";
	String z = "bad";
	String y1 = "good";
	
	
	cout << "size() function, Size of \"world\" = " << s2.size() << endl;
	cout << "size() function, Size of \"My length should be 22\" = " << s3.size() << endl;

	cout << "operator ==: \"why\" == \"me\" = "  << (x == w) << endl;
	cout << "operator ==: \"good\" ==  \"good\" = " << (y == y1) << endl;

	cout << "operator !=: \"why\" != \"me\" = "  << (x != w) << endl;
	cout << "operator !=: \"good\" !=  \"bad\" = " << (y != z) << endl;

	cout << "operator >: \"why\" > \"me\" = "  << (x > w) << endl;
	cout << "operator >: \"good\" >  \"bad\" = " << (y > z) << endl;

	cout << "operator <: \"why\" < \"me\" = "  << (x < w) << endl;
	cout << "operator <: \"bad\" <  \"good\" = " << (z < y) << endl;

	cout << "operator >=: \"why\" >= \"me\" = "  << (x >= w) << endl;
	cout << "operator >=: \"good\" >=  \"bad\" = " << (y >= z) << endl;

	cout << "operator <=: \"why\" <= \"me\" = "  << (x <= w) << endl;
	cout << "operator <=: \"good\" <=  \"bad\" = " << (y <= z) << endl;

	cout << "operator +: \"hello\" + \"world\" = "  << (s + s2) << endl;
	cout << "operator +: \"where are\" +  \" you going\". = " << (j + j2) << endl;
	

	cout << "operator +=: \"where are\" +=  \" you going\". = " << (j3 += j4) << endl;
	cout << "operator +=: \"why\" += \"you\". = " << (x += "you") << endl;

	
	cout << "------------------------------------------------------------------" << endl << endl;

}


int main() {
	test_constructor();
	test_operator_assign();
	test_comparison_operators();
	test_operator_index();
	test_operator_indexOf();
	cout << endl << "Number of new allocations minus number of delete deallocations is " << String::getAllocations() << endl << endl;
	return 0;
}