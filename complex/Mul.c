#include "complex.h"

void Mul(
	struct Complex *Addend,
	struct Complex *Multiplier,
	struct Complex **Result
)
{
	(*Result)->Real = (Addend->Real * Multiplier->Real) - (Addend->Image * Multiplier->Image);
	(*Result)->Image = (Addend->Real * Multiplier->Image) + (Addend->Image * Multiplier->Real);
	return;
}
