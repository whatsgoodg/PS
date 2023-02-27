class cmp {
public:
	bool operator() (int a, int b) { //a 음수 b 음수
		if (a < 0 && b < 0) {
			return a > b;
		}
		else if (a < 0 && b > 0) {  //a 음수 b 양수
			return -1 * a > b;
		}	
		else if (a > 0 && b < 0) {  //a 양수 b 음수
			b = -1 * b;
			return a >= b;
		}
		else {  //a 양수 b 양수
			return a > b;
		}
	}
};
