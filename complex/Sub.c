#include "complex.h"

void Sub(
	struct Complex *Minuend,
	struct Complex *Deduction,
	struct Complex **Result
)
{
	(*Result)->Real = Minuend->Real - Deduction->Real;
	(*Result)->Image = Minuend->Image - Deduction->Image;
	return;
}
