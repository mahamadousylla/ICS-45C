#include "String.h"


String::String(const char * s) { 
	buf = strdup(s);
}

String::String(const String & s) {
	buf = strdup(s.buf);
}

String String::operator = (const String & s) {
	if (this == & s) {
		return *this;
	}
	delete_char_array(buf);
	buf = strdup(s.buf);
	return *this;
}

char & String::operator [] (int index) {
	String s = "index is out of range";
	if (inBounds(index)) {
		return buf[index];
	} return *s.buf;
}

int String::size() {
	return strlen(buf);
}

String String::reverse() {
	int SIZE_OF_ARRAY = strlen(buf);
	String reverse;
	int index = 0;
	for (int i = SIZE_OF_ARRAY - 1; i >= 0; i--) {
		reverse.buf[index] = buf[i];
		index++;
	} reverse.buf[index] = '\0';
	return reverse;
}

int String::indexOf(const char c) {
	for (int i = 0; buf[i] != '\0'; i++)
    	if ( buf[i] == c ) {
      		return i;	
    } return -1;
}

int String::indexOf(const String pattern) {
	char *p;
	p = strstr(buf, pattern.buf);
	if (p != NULL) {
		int lengthOfbuf = strlen(buf);
		int lengthOfPointer = strlen(p);
		int index = (lengthOfbuf - lengthOfPointer);
		return index;
	} return -1;
}

bool String::operator == (const String s) {
	int result = strcmp(buf, s.buf);
	if (result == 0) {
		return true;
	} return false;
}

bool String::operator != (const String s) {
	int result = strcmp(buf, s.buf);
	if (result != 0) {
		return true;
	} return false;
}

bool String::operator > (const String s) {
	int result = strcmp(buf, s.buf);
	if (result == 1) {
		return true;
	} return false;
}

bool String::operator < (const String s) {
	int result = strcmp(buf, s.buf);
	if (result == -1) {
		return true;
	} return false;
}

bool String::operator <= (const String s) {
	int result = strcmp(buf, s.buf);
	if (result == -1 || result == 0) {
		return true;
	} return false;
}

bool String::operator >= (const String s) {
	int result = strcmp(buf, s.buf);
	if (result == 1 || result == 0) {
		return true;
	} return false;
}

String String::operator + (const String s) {
	// concatenates this and s to return result
	return strcat(buf, s.buf);
}


String String::operator += (const String s) {
	// concatenates s onto end of this
	return strcat(buf, s.buf);
}

void String::print(ostream & out) {
	out << buf;
}

void String::read(istream & in) {
	in >> buf;
}

int String::getAllocations() {
	return allocations;
}

String::~String() {
	delete_char_array(buf);
	buf = NULL;
}


int String::strlen(const char *src) {
	int length = 0;
	for (int i = 0; src[i] != '\0'; i++) {
		length++;
	} return length;
}

char *String::strdup(const char *src) {
	char *dest;
	dest = new_char_array(strlen(src));
	return strcpy(dest, src);
}

char * String::strcpy(char *dest, const char *src) {
	int i;
    for ( i = 0; src[i] != '\0'; i++ ) {
    	dest[i] = src[i];
    } dest[i] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right) {
	int i = 0;
	while ( (left[i] != '\0') || (right[i] != '\0') ) {
		if (left[i] > right[i]) {
			return 1;
		} else if (left[i] < right[i]) {
			return -1;
		} i++;
	} if (strlen(left) == strlen(right)) {
			return 0;
		} else if ( (strlen(left)) < (strlen(right)) ) {
			return -1; 
		} else if ((strlen(left)) > (strlen(right)) ) {
			return 1;
		}
}

char * String::strcat(char *dest, const char *src) {
	int i = 0;
	while (dest[i] != '\0') {
		i++;
	} for (int index = 0; src[index] != '\0'; index++) {
		dest[i] = src[index];
		i++;
	} dest[i] = '\0';
	return dest;
}

char * String::strstr(const char *haystack, const char *needle) {
	char nextValueNeedle;
    char nextValueHay;
    int lengthOfNeedle;

    nextValueNeedle = *needle++;
    lengthOfNeedle = strlen(needle);
    while (strncmp(haystack, needle, lengthOfNeedle) != 0) {
        do {
            nextValueHay = *haystack++;
            if (nextValueHay == '\0') {
            	return NULL;
            }
        } while (nextValueHay != nextValueNeedle);
    } return (char *) (--haystack);
}

int String::strncmp(const char *left, const char *right, int n) {
	int i = 0;
	while ( ((left[i] != '\0') || (right[i]) != '\0') && (i < n) ) {
		if (left[i] > right[i]) {
			return 1;
		} else if (left[i] < right[i]) {
			return -1;
		} i++;
	} if (strlen(left) >= n && strlen(right) >= n) {
			return 0;
		} else if ( (strlen(left)) < (strlen(right)) ) {
			return -1; 
		} else if ((strlen(left)) > (strlen(right)) ) {
			return 1;
		}
}

ostream & operator << (ostream & out, String str) {
	str.print( out );
	return out;
}

istream & operator >> (istream & in, String & str) {
	str.read( in );
	return in;
}

int String::allocations = 0;

char * String::new_char_array( int n_bytes ) {
	++allocations;
	return new char[n_bytes];
}

void String::delete_char_array( char * p ) {
	--allocations;
	delete [] p;
}