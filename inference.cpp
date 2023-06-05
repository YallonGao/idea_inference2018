#include <iostream>
#include <time.h>
using namespace std;

int a[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char option[4] = {'A', 'B', 'C', 'D'};

// Q2，上限题数是5
bool Q2() {
	if (a[2] == 1 && a[5] == 3 || \
	        a[2] == 2 && a[5] == 4 || \
	        a[2] == 3 && a[5] == 1 || \
	        a[2] == 4 && a[5] == 2)
		return true;
	return false;
}

// Q3，上限题数是6
bool Q3() {
	if (a[3] == 1 && a[6] != a[3] && a[6] == a[2] && a[2] == a[4] || \
	        a[3] == 2 && a[6] != a[3] && a[3] == a[2] && a[2] == a[4] || \
	        a[3] == 3 && a[2] != a[3] && a[3] == a[6] && a[6] == a[4] || \
	        a[3] == 4 && a[4] != a[3] && a[3] == a[2] && a[2] == a[6])
		return true;
	return false;
}

// Q4，上限题数是10not
bool Q4() {
	if (a[4] == 1 && a[1] == a[5] || \
	        a[4] == 2 && a[2] == a[7] || \
	        a[4] == 3 && a[1] == a[9] || \
	        a[4] == 4 && a[6] == a[10])
		return true;
	return false;
}

// Q5，上限题数是9
bool Q5() {
	if (a[5] == 1 && a[5] == a[8] || \
	        a[5] == 2 && a[5] == a[4] || \
	        a[5] == 3 && a[5] == a[9] || \
	        a[5] == 4 && a[5] == a[7])
		return true;
	return false;
}

// Q6，上限题数是10
bool Q6() {
	if (a[6] == 1 && a[8] == a[2] && a[8] == a[4] || \
	        a[6] == 2 && a[8] == a[1] && a[8] == a[6] || \
	        a[6] == 3 && a[8] == a[3] && a[8] == a[10] || \
	        a[6] == 4 && a[8] == a[5] && a[8] == a[9])
		return true;
	return false;
}

// Q7，上限题数是10
bool Q7() {
	int count[4] = {0, 0, 0, 0};
	for (int i = 1; i <= 10; i++) {
		count[a[i] - 1]++;
	}
	int min_index = 0;
	int min_count = count[0];
	for (int i = 1; i < 4; i++) {
		if (count[i] < min_count) {
			min_index = i;
			min_count = count[i];
		}

	}
	min_index += 1;
	if ( a[7] == 1 && min_index == 3 || \
	        a[7] == 2 && min_index == 2 || \
	        a[7] == 3 && min_index == 1 || \
	        a[7] == 4 && min_index == 4)
		return true;
	return false;
}

// Q8，上限题数是10
bool Q8() {
	if (a[8] == 1 && (a[7] != a[1] + 1 || a[7] != a[1] - 1) || \
	        a[8] == 2 && (a[5] != a[1] + 1 || a[5] != a[1] - 1) || \
	        a[8] == 3 && (a[2] != a[1] + 1 || a[2] != a[1] - 1) || \
	        a[8] == 4 && (a[10] != a[1] + 1 || a[10] != a[1] - 1))
		return true;
	return false;
}

// Q9，上限题数是10
bool Q9() {
	if (a[9] == 1 && ((a[1] == a[6]) ^ (a[6] == a[5])) || \
	        a[9] == 2 && ((a[1] == a[6]) ^ (a[10] == a[5])) || \
	        a[9] == 3 && ((a[1] == a[6]) ^ (a[2] == a[5])) || \
	        a[9] == 4 && ((a[1] == a[6]) ^ (a[9] == a[5])))
		return true;
	return false;

}

// Q10，上限题数是10
bool Q10() {
	int count[4] = {0, 0, 0, 0};
	for (int i = 1; i <= 10; i++) {
		count[a[i] - 1]++;
	}
	int min_count = 0;
	int max_count = 0;
	for (int i = 1; i < 4; i++) {
		if (count[i] < min_count)
			min_count = count[i];
		if (count[i] > min_count)
			max_count = count[i];
	}
	int dif = max_count - min_count;
	if (a[10] == 1 && dif == 3 || \
	        a[10] == 2 && dif == 2 || \
	        a[10] == 3 && dif == 4 || \
	        a[10] == 4 && dif == 1)
		return true;
	return false;
}

void print_answer() {
	for (int i = 1; i <= 10; i++) {
		printf("%c ", option[a[i] - 1]);
	}
	printf("\n");
}

void violence(int h) {
	if (h > 10)
		return;
	// 极致的优化，极致的享受
	if ( h == 3) {
		if (a[3] == 2 and a[3] != a[2] || \
		        a[3] == 4 and a[3] != a[2])
			return;
	}
	if (h == 4) {
		if (a[3] == 1 and a[2] != a[4] || \
		        a[3] == 2 and !(a[3] == a[2] and a[2] == a[4]) || \
		        a[3] == 4 and a[3] != a[2])
			return;
	}
	// 正常优化
	if (h == 5 && !Q2())
		return;
	if (h == 6 && !Q3())
		return;
	if (h == 9 && !Q5())
		return;
	if (h == 10) {
		if (Q4() && Q6() && Q8() && Q9() && Q7()) {
			print_answer();
			return;
		}
	}
	for (int i = 1; i <= 4; i++) {
		a[h + 1] = i;
		violence(h + 1);
		a[h + 1] = 0;
	}
}

int main() {
	clock_t start, end;
	start = clock();
	violence(0);
	end = clock();
	printf("运行时间: %f秒", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}
