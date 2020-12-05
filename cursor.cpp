#include "cursor.h"


void Cursor::cs() {
    pos = 0;
}

void Cursor::ce() {
    pos = 47;
}

void Cursor::ct(int num) {
    if (num >= 0 && num < 48) {
        pos = num;
    }
    else {
        throw(domain_error("error from ct"));
    }
}

void Cursor::cr(int num) {
    if (pos+num >= 0 && pos+num < 48) {
        pos += num;
    }
    else {
        throw(domain_error("error from cr"));
    }
}

void Cursor::cl(int num) {
    if (pos-num >= 0 && pos-num < 48) {
        pos -= num;
    }
    else {
        throw(domain_error("error from cl"));
    }
}

int Cursor::getPosition() {
    return pos;
}

