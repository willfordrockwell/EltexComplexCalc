#include "menu.h"

void Mul_Func ()
{
	struct Complex 
	*Addend = (struct Complex *) malloc (sizeof(struct Complex)),
	*Multiplier = (struct Complex *) malloc (sizeof(struct Complex)),
	*Result = (struct Complex *) malloc (sizeof(struct Complex));

	void *Ext_Library_Mul;
	void *Ext_Library_Get;
	void (*Mul)(struct Complex*, struct Complex*, struct Complex**);
	int (*Get_Input)(char*, char*);

	Ext_Library_Mul = dlopen("./complex/libcustcomplexmul.so", RTLD_LAZY);

	if(!Ext_Library_Mul) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return;
	}

	Mul = dlsym(Ext_Library_Mul, "Mul");

	if (!Mul) {
		fprintf(stderr,"dlsym error: %s\n", dlerror());
		return;
	}

	Ext_Library_Get = dlopen("./menu/libcustmenuget_input.so", RTLD_LAZY);

	if(!Ext_Library_Get) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return;
	}

	Get_Input = dlsym(Ext_Library_Get, "Get_Input");

	if (!Get_Input) {
		fprintf(stderr,"dlsym error: %s\n", dlerror());
		return;
	}

	Addend->Real = Get_Input("real", "addend");
	Addend->Image = Get_Input("image", "addend");

	Multiplier->Real = Get_Input("real", "multiplier");
	Multiplier->Image = Get_Input("image", "multiplier");

	Mul(Addend, Multiplier, &Result);

	printf("(%d ", Addend->Real);
	printf("%s", (Addend->Image >= 0) ? "+ " : "- ");
	printf("%di) * ", abs(Addend->Image));

	printf("(%d ", Multiplier->Real);
	printf("%s", (Multiplier->Image >= 0) ? "+ " : "- ");
	printf("%di) = ", abs(Multiplier->Image));

	printf("(%d ", Result->Real);
	printf("%s", (Result->Image >= 0) ? "+ " : "- ");
	printf("%di)\n", abs(Result->Image));

	dlclose(Ext_Library_Mul);
	dlclose(Ext_Library_Get);

	free(Addend);
	free(Multiplier);
	free(Result);
}
