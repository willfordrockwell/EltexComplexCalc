#include "menu.h"

void Add_Func ()
{
	struct Complex
	*FirstAddend = (struct Complex *) malloc (sizeof(struct Complex)),
	*SecondAddend = (struct Complex *) malloc (sizeof(struct Complex)),
	*Result = (struct Complex *) malloc (sizeof(struct Complex));

	void *Ext_Library_Add;
	void *Ext_Library_Get;
	void (*Add)(struct Complex*, struct Complex*, struct Complex**);
	int (*Get_Input)(char*, char*);

	Ext_Library_Add = dlopen("./complex/libcustcomplexadd.so", RTLD_LAZY);

	if (!Ext_Library_Add) {
		fprintf(stderr, "dlopen error: %s\n", dlerror());
		return;
	}

	Add = dlsym(Ext_Library_Add, "Add");

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

	FirstAddend->Real = Get_Input("real", "first addend");
	FirstAddend->Image = Get_Input("image", "first addend");

	SecondAddend->Real = Get_Input("real", "second addend");
	SecondAddend->Image = Get_Input("image", "second addend");

	Add(FirstAddend, SecondAddend, &Result);

	printf("(%d ", FirstAddend->Real);
	printf("%s", (FirstAddend->Image >= 0) ? "+ " : "- ");
	printf("%di) + ", abs(FirstAddend->Image));

	printf("(%d ", SecondAddend->Real);
	printf("%s", (SecondAddend->Image >= 0) ? "+ " : "- ");
	printf("%di) = ", abs(SecondAddend->Image));

	printf("(%d ", Result->Real);
	printf("%s", (Result->Image >= 0) ? "+ " : "- ");
	printf("%di)\n", abs(Result->Image));

	dlclose(Ext_Library_Add);
	dlclose(Ext_Library_Get);

	free(FirstAddend);
	free(SecondAddend);
	free(Result);
}
