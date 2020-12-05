#include "page.h"


void Page::pr() {
    if (pos < 29) pos++;
    else throw(domain_error("error from np"));
}

void Page::pl() {
    if (pos > 0) pos--;
    else throw(domain_error("error from bp"));
}

void Page::pt(int num) {
    if (num <= 29 && num >= 0) pos = num;
    else throw(domain_error("error from pt"));
}

void Page::ps() {
    pos = 0;
}

void Page::pe() {
    pos = 29;
}

int Page::getPosition() {
    return pos;
}