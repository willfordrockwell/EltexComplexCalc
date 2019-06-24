#include "complex.h"

void Add(
	struct Complex *FirstAddend,
	struct Complex *SecondAddend,
	struct Complex **Result
)
{
	(*Result)->Real = FirstAddend->Real + SecondAddend->Real;
	(*Result)->Image = FirstAddend->Image + SecondAddend->Image;
	return;
}
