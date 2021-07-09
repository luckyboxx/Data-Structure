#include <iostream>
using namespace std;

class Polynomial; //전방선언
class Term {
	friend Polynomial;
private:
	float coef;   // 계수
	int exp;      // 지수

public:
	Term(void);
	virtual ~Term(void);
};

class Polynomial {
private:
	Term* termArray;
	int capacity;    // 배열의 크기
	int terms;       // 0이 아닌 항의 수
public:
	void Print(void);
	void NewTerm(const float theCoeff, const int theExp);
	Polynomial Add(Polynomial b);
	Polynomial Multi(Polynomial b);

	Polynomial(void);
	~Polynomial(void);
};

Polynomial::Polynomial(void) {
	capacity = 4;
	terms = 0;
	termArray = new Term[capacity];  // 크기 4 로 배열 생성
}

Polynomial::~Polynomial(void) { }

Polynomial Polynomial::Add(Polynomial b) {
// a(x)(*this의 값)와 b(x)를 더한 결과를 반환한다.
	Polynomial c;
	int aPos = 0, bPos = 0;

	while ((aPos < terms) && (bPos < b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}

	// A(x)(*this)의 나머지 항들을 추가한다.
	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);

	// B(x)의 나머지 항들을 추가한다.
	for (; bPos < b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

	return c;
} // Add의 끝

Polynomial Polynomial::Multi(Polynomial b) {
	Polynomial c;   //반환 다항식

	// A 다항식의 Term 처음부터 돌림
	for (int aPos = 0; aPos < terms; aPos++) {
		Polynomial d;	// 각각의 A 다항식의 Term * B다항식을 해줌

		// B Term을 돌려서
		for (int bPos = 0; bPos < b.terms; bPos++)
			d.NewTerm(termArray[aPos].coef * b.termArray[bPos].coef, termArray[aPos].exp + b.termArray[bPos].exp);
		// d 다항식에 넣어주고

		c = c.Add(d);   // c += d 를 해줌
	}
	return c;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp) {
// 새로운 항을 termArray 끝에 첨가한다.
	if (terms == capacity) {
		//termArray의 크기를 두 배로 확장
		capacity *= 2;
		Term* temp = new Term[capacity];           // 새로운 배열
		for (int i = 0; i < terms; i++)
			temp[i] = termArray[i];
		delete[] termArray;                       // 그전 메모리를 반환
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}



void Polynomial::Print() {
	int i;

	cout << "\n";
	if (terms) {
		for (i = 0; i < terms - 1; i++)
			cout << termArray[i].coef << " x^" << termArray[i].exp << " + ";
		// 마지막 항을 출력
		cout << termArray[i].coef << " x^" << termArray[i].exp << "\n";
	}
	else
		cout << " No terms ";

}

Term::Term(void) { }

Term::~Term(void) { }

int main(int argc, char* argv[]) {
	Polynomial A, B, C;
	int i, n, e;
	float c;

	cout << "다항식 A의 항의 수 : ";

	cin >> n;

	for (i = 1; i <= n; i++) {
		cout << "다항식 A의 " << i << " 번째 항의 계수와 지수 : ";
		cin >> c >> e;

		A.NewTerm(c, e);
	}

	cout << "다항식 B의 항의 수 : ";
	cin >> n;

	for (i = 1; i <= n; i++) {
		cout << "다항식 B의 " << i << " 번째 항의 계수와 지수 : ";
		cin >> c >> e;

		B.NewTerm(c, e);
	}

	C = A.Multi(B);
	C.Print();

	return 0;
}