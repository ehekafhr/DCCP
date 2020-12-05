#include "Note.h"


// ���ڿ��� ���� ���̸��� ���ڸ� ���ļ��� �и��� ���� ���̷� ȯ���Ͽ� ��Ʈ ��ü�� �����Ѵ�.
Note::Note(int octave, char pitch, char rhythm) {
	// ���� ó���� ���� �Լ��� �ñ�.

	// ��Ÿ�� ���ؼ� ����
	oct += octave;
	
	// ���� 
	length = rhythmToLength(rhythm) * 300;		//bpm = 200���� ����

	// ���� ��ǥ���  
	if (pitch == '@' || pitch == ',') {
		freq = 0;
		is_rest = true;	// ��ǥ ���� 
	}
	// ��ǥ�� �ƴ϶� ���� ��ǥ���
	else {
		// ���ļ�
		double double_freq = pitchToFreq(pitch);
		// �������� 
		int square = 1;
		for (int i = 1; i < octave; ++i) {
			square *= 2;
		}
		freq = double_freq * square;

		is_rest = false; // ��ǥ ���� 
	}
	is_NULL = false;	// �翬�� �γ�Ʈ �ƴ�
	
	//'0' + a
	pit[1] = '0' + oct;
}

// ������ ������ ��� �ٷ� ���ļ��� ���̿� �����Ѵ�.
Note::Note(int f, int l) {
	freq = f;
	length = l;

	is_NULL = false;
	is_rest = false; // ��ǥ ���� üũ
}

void Note::beep() {
	if (is_NULL == true) {
		// do nothing
	}
	else {
		Beep(freq, length);
	}
}


// pit[0] = ���̸� C~B
// pit[1] =  ��Ÿ��
// pit[2] =  �� ����
// pit[3] = '\0'
double Note::pitchToFreq(char pitch) {
	if (pitch == 'z') { 
		pit[0] = 'C';
		return 32.7032;
	}
	if (pitch == 's') {
		pit[0] = 'C';
		pit[2] = '#';
		return 34.6478;
	}
	if (pitch == 'x') { 
		pit[0] = 'D';
		return 36.7081;
	}
	if (pitch == 'd') {
		pit[0] = 'D'; 
		pit[1] = '#';
		return 38.8909;
	}
	if (pitch == 'c') {
		pit[0] = 'E';
		return 41.2034;
	}
	if (pitch == 'v') { 
		pit[0] = 'F';
		return 43.6535;
	}
	if (pitch == 'g') { 
		pit[0] = 'F'; 
		pit[1] = '#';
		return 46.2493;
	}
	if (pitch == 'b') { 
		pit[0] = 'G';
		return 48.9994;
	}
	if (pitch == 'h') {  
		pit[0] = 'G'; 
		pit[1] = '#';
		return 51.9130;
	}
	if (pitch == 'n') { 
		pit[0] = 'A';
		return 55.0000;
	}
	if (pitch == 'j') {
		pit[0] = 'A';
		pit[1] = '#';
		return 58.2705;
	}
	if (pitch == 'm') { 
		pit[0] = 'B';
		return 61.7354;
	}

	if (pitch == 'q') { 
		oct += 1; 
		pit[0] = 'C';
		return 65.4064;
	}
	if (pitch == '2') { 
		oct += 1; 
		pit[0] = 'C'; 
		pit[2] = '#';
		return 69.2957;
	}
	if (pitch == 'w') { 
		oct += 1; 
		pit[0] = 'D';
		return 73.4162;
	}
	if (pitch == '3') {  
		oct += 1; 
		pit[0] = 'D'; 
		pit[2] = '#';
		return 77.7817;
	}
	if (pitch == 'e') {  
		oct += 1; 
		pit[0] = 'E';
		return 82.4069;
	}
	if (pitch == 'r') {  
		oct += 1; 
		pit[0] = 'F';
		return 87.3071;
	}
	if (pitch == '5') {  
		oct += 1; 
		pit[0] = 'F'; 
		pit[2] = '#';
		return 92.4986;
	}
	if (pitch == 't') { 
		oct += 1; 
		pit[0] = 'G';
		return 97.9989;
	}
	if (pitch == '6') { 
		oct += 1; 
		pit[0] = 'G'; 
		pit[2] = '#';
		return 103.8262;
	}
	if (pitch == 'y') { 
		oct += 1; 
		pit[0] = 'A';
		return 110.0000;
	}
	if (pitch == '7') { 
		oct += 1;
		pit[0] = 'A'; 
		pit[2] = '#';
		return 116.5409;
	}
	if (pitch == 'u') { 
		oct += 1; 
		pit[0] = 'B';
		return 123.4708;
	}


	if (pitch == 'i') { return 130.8128; oct += 2; pit[0] = 'C'; }
	if (pitch == '9') { return 138.5913; oct += 2; pit[0] = 'C'; pit[2] = '#'; }
	if (pitch == 'o') {return 146.8324; oct += 2; pit[0] = 'D';
}
	if (pitch == '0'){return 155.5635; oct += 2; pit[0] = 'D'; pit[2] = '#'; }
	if (pitch == 'p') { return 164.8138; oct += 2; pit[0] = 'E'; }

	return 0;	// exception!
}

int Note::rhythmToLength(char rhythm) {
	if (rhythm == 'z') return 8;
	if (rhythm == 'x') return 4;
	if (rhythm == 'c') return 2;
	if (rhythm == 'v') return 1;	// 300�и���

	return 0;	// exception!
}


const char* Note::getPitch() {

	// �γ�Ʈ���
	if (is_NULL == true) {
		return "NUL\0";
	}
	// ��ǥ��� 
	else if (is_rest == true) {
		return "@\0";
	}
	// ��ǥ�� �ƴ϶��
	else {
		return pit;
	}
}

const char* Note::getLength() {

	// �γ�Ʈ���
	if (is_NULL == true) {
		return "0\0";
	}
	// ��ǥ�� �ƴ϶��
	else {
		if (length == 1) {
			return "1/8\0";
		}
		else if (length == 2) {
			return "1/4\0";
		}
		else if (length == 4) {
			return "1/2\0";
		}
		else if (length == 8) {
			return "1/1\0";
		}
	}
}
