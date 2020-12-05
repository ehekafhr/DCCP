#pragma once
#include <stdexcept>

using namespace std;

class Cursor {
public:
    // Ŀ�� ��ġ ������ cursor end, ce
    void cs();

    // Ŀ�� ��ġ ó������ cursor start, cs
    void ce();

    // Ŀ�� ��ġ p�� ���� cursor to n
    void ct(int num);

    // ������ nĭ �̵� cursor right, cr
    void cr(int num = 1);

    // �������� nĭ �̵� cursor left. cl
    void cl(int num = 1);

    // Ŀ���� ��ġ�� �����Ѵ�.
    int getPosition();

private:
    int pos = 0;
};