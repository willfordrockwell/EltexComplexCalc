#include "menu.h"

void Sub_Func()
{
	struct Complex
	*Minuend = (struct Complex *) malloc (sizeof(struct Complex)),
	*Deduction = (struct Complex *) malloc (sizeof(struct Complex)),
	*Result = (struct Complex *) malloc (sizeof(struct Complex));

	void *Ext_Library_Sub;
	void *Ext_Library_Get;
	void (*Sub)(struct Complex*, struct Complex*, struct Complex**);
	int (*Get_Input)(char*, char*);

	Ext_Library_Sub = dlopen("./complex/libcustcomplexsub.so", RTLD_LAZY);

	if (!Ext_Library_Sub) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return;
	}

	Sub = dlsym(Ext_Library_Sub, "Sub");

	if (!Add) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return;
	}

	Ext_Library_Get = dlopen("./menu/libcustmenuget_input.so", RTLD_LAZY);

	if (!Ext_Library_Get) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return;
	}

	Get_Input = dlsym(Ext_Library_Get, "Get_Input");

	if (!Get_Input) {
		fprintf(stderr, "dlsym error: %s\n", dlerror());
		return;
	}

	Minuend->Real = Get_Input("real", "minuend");
	Minuend->Image = Get_Input("image", "minuend");

	Deduction->Real = Get_Input("real", "deduction");
	Deduction->Image = Get_Input("image", "deduction");

	Sub(Minuend, Deduction, &Result);

	printf("(%d ", Minuend->Real);
	printf("%s",(Minuend->Image >= 0) ? "+ " : "- ");
	printf("%di) - ",abs(Minuend->Image));

	printf("(%d ", Deduction->Real);
	printf("%s", (Deduction->Image >= 0) ? "+ " : "- ");
	printf("%di) = ", abs(Deduction->Image));

	printf("(%d ", Result->Real);
	printf("%s", (Result->Image >= 0) ? "+ " : "- ");
	printf("%di)\n", abs(Result->Image));

	dlclose(Ext_Library_Sub);
	dlclose(Ext_Library_Get);

	free(Minuend);
	free(Deduction);
	free(Result);
}
