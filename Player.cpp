#include "Player.h"

void Player::play(int octave, Cursor& cursor, Page& page, Sheet& sheet, Printer& printer) {

	page.ps();
	int end_page = 1;

	for (int i = 0; i < end_page; ++i) {
		cursor.cs();

		for (int j = 0; j < 48; ++j) {

			system("cls");
			printer.print(octave, cursor, page, sheet);
			sheet.getNote(cursor, page).beep();
			if (j != 47) {
				cursor.cr();
			}
		}

		if (i != end_page) {
			page.pr();
		}
	}

	// 재생이 끝나면 악보의 처음으로 돌아간다.
	page.ps();
	cursor.cs();
	system("cls");
	printer.print(octave, cursor, page, sheet);
}