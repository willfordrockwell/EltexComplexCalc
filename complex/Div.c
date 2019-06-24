#include "complex.h"

void Div(
	struct Complex *Dividend,
	struct Complex *Divider,
	struct Complex **Result
)
{
	int DividerUnderscore = Divider->Real * Divider->Real
	+ Divider->Image * Divider->Image;

	(*Result)->Real = Dividend->Real * Divider->Real
	+ Dividend->Image * Divider->Image;

	(*Result)->Real /= DividerUnderscore;

	(*Result)->Image = Dividend->Real * Divider->Image
	- Dividend->Image * Divider->Real;

	(*Result)->Image /= DividerUnderscore;
	return;
}
