#include "menu.h"

void Div_Func()
{
	struct Complex
	*Dividend = (struct Complex *) malloc (sizeof(struct Complex)),
	*Divider = (struct Complex *) malloc (sizeof(struct Complex)),
	*Result = (struct Complex *) malloc (sizeof(struct Complex));

	void *Ext_Library_Div;
	void *Ext_Library_Get;
	void (*Div)(struct Complex*, struct Complex*, struct Complex**);
	int (*Get_Input)(char*, char*);

	Ext_Library_Div = dlopen("./complex/libcustcomplexdiv.so", RTLD_LAZY);

	if (!Ext_Library_Div) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return;
	}

	Div = dlsym(Ext_Library_Div, "Div");

	if (!Div) {
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

	Dividend->Real = Get_Input("real", "dividend");
	Dividend->Image = Get_Input("image", "dividend");

	Divider->Real = Get_Input("real", "divider");
	Divider->Image = Get_Input("image", "divider");

	Div(Dividend, Divider, &Result);

	printf("(%d ", Dividend->Real);
	printf("%s", (Dividend->Image >= 0) ? "+ " : "- ");
	printf("%di) / ", abs(Dividend->Image));

	printf("(%d ", Divider->Real);
	printf("%s", (Divider->Image >= 0) ? "+ " : "- ");
	printf("%di) = ", abs(Divider->Image));

	printf("(%d ", Result->Real);
	printf("%s", (Result->Image >= 0) ? "+ " : "- ");
	printf("%di)\n", abs(Result->Image));

	dlclose(Ext_Library_Div);
	dlclose(Ext_Library_Get);

	free(Dividend);
	free(Divider);
	free(Result);
}
