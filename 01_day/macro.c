#if 1
#include <stdio.h>

void bar(void)
{
	printf("bar()\n");
}
void foo(void) __attribute__((alias("bar")));

//-------------------------------------------

int main()
{
	foo();
	return 0;
}
#endif



#if 0
#include <stdio.h>

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)
                                           // __UNIQUE_ID_license
                                           // __UNIQUE_ID_license10

#define __MODULE_INFO(tag, info)       \
static const char __UNIQUE_ID(tag)[]  \
    = __stringify(tag) "=" info 

__MODULE_INFO(license, "GPL"); __MODULE_INFO(license, "BSD"); 

int main()
{
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __LINE__)
                                           // __UNIQUE_ID_license
                                           // __UNIQUE_ID_license10

#define __MODULE_INFO(tag, info)       \
static const char __UNIQUE_ID(tag)[]  \
    = __stringify(tag) "=" info 

__MODULE_INFO(license, "GPL"); // __UNIQUE_ID_license18
__MODULE_INFO(license, "BSD"); // __UNIQUE_ID_license19

int main()
{
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

#define __MODULE_INFO(tag, info)     \
static const char tag[]              \
    = __stringify(tag) "=" info 

__MODULE_INFO(license, "GPL");
__MODULE_INFO(license, "BSD");

int main()
{
	printf("license =%s\n", license );
	return 0;
}
#endif

#if 0
#include <stdio.h>

static const char license[] = "license=GPL";

int main()
{
	printf("license =%s\n", license );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	char ch __attribute__((aligned(1)));
	int i __attribute__((aligned(1)));
	printf("&ch=%p\n", &ch );
	printf("&i =%p\n", &i );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	char ch __attribute__((aligned(8)));
	int i __attribute__((aligned(8)));
	printf("&ch=%p\n", &ch );
	printf("&i =%p\n", &i );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int global 
__attribute__((section(".modinfo")))     
	= 0x77777777;
int main()
{
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int local 
		__attribute__((unused))     
		= 0x77777777;
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define __used			__attribute__((__used__))

static int global 
__used
= 0x77777777;

int main()
{
	return 0;
}
#endif

#if 0
#include <stdio.h>

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

char *p = __stringify(__LINE__) "=" "GPL";

int main()
{
	printf("%s\n", p );  // "foo=GPL"
	return 0;
}
#endif
#if 0
#include <stdio.h>

#define foo bar

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

char *p = __stringify(foo) "=" "GPL";

int main()
{
	printf("%s\n", p );  // "foo=GPL"
	return 0;
}
#endif

#if 0
#include <stdio.h>

#define foo bar

#define __stringify_1(x...)	#x
// #define __stringify(x...)	__stringify_1(x)

char *p = __stringify_1(foo) "=" "GPL";

int main()
{
	printf("%s\n", p );  // "foo=GPL"
	return 0;
}
#endif

#if 0
#include <stdio.h>
#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

char *p = __stringify(license) "=" "GPL";

int main()
{
	printf("%s\n", p );  // "license=GPL"
	return 0;
}
#endif
