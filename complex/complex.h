#ifndef __COMPLEX_H__
#define __COMPLEX_H__

struct Complex {
	int Real;
	int Image;
};

void Add(
	struct Complex *FirstAddend,
	struct Complex *SecondAddend,
	struct Complex **Result
);

void Sub(
	struct Complex *Minuend,
	struct Complex *Deduction,
	struct Complex **Result
);

void Mul(
	struct Complex *Addend,
	struct Complex *Multiplier,
	struct Complex **Result
);

void Div(
	struct Complex *Dividend,
	struct Complex *Divider,
	struct Complex **Result
);
#endif
