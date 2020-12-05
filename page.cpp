#include "page.h"

//pos는 0부터 29까지 있다.'

//마지막 pos에서 ++ 안됨
void Page::pr() {
    if (pos < 29) pos++;
    else throw(domain_error("error from np"));
}

//첫 pos에서 -- 안됨
void Page::pl() {
    if (pos > 0) pos--;
    else throw(domain_error("error from bp"));
}
//pos 이동(0부터 29 사이)
void Page::pt(int num) {
    if (num <= 29 && num >= 0) pos = num;
    else throw(domain_error("error from pt"));
}
//첫 pos로
void Page::ps() {
    pos = 0;
}

/* 수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요수정필요
pos가 29로 가면 안됨. 현재 마지막 page가 몇페이지인지 저장해 두고, 그걸 가져와야뎀!
*/
void Page::pe() {
    pos = 29;
}

int Page::getPosition() {
    return pos;
}
