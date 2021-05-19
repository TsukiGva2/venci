/*
 * Generated from Zimbu file src/out.zu
 */
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#if defined(__MINGW32__) || defined(_MSC_VER)
# define GC_SIG SIGABRT
# include <excpt.h>
#else
# define GC_SIG SIGUSR2
#endif
#include <setjmp.h>
#include <sys/time.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <sys/ioctl.h>
#include "../src/rawmode.h"
#include "../lua/lua.h"
#include "../lua/lualib.h"
#include "../lua/lauxlib.h"

/*
 * TYPEDEFS
 */
#define ZINT_FORMAT "%lld"
#define ZNAT_FORMAT "%llu"
#define ZINT_XFORMAT "%llx"
#define ZFLOAT_FORMAT "%g"
typedef long long Ti; /* int */
typedef short Ti16; /* int16 */
typedef int Ti32; /* int32 */
typedef unsigned long long Tu; /* nat */
typedef unsigned char Tc; /* byte */
typedef unsigned short Tu16; /* nat16 */
typedef unsigned int Tu32; /* nat32 */
typedef double Tf; /* float */
typedef float Tf32; /* float32 */
typedef __INTPTR_TYPE__ Tip; /* int for pointer */
typedef long long Tbb; /* big BITS */

typedef int Tbs; /* small BITS */
typedef int Tb; /* bool */
typedef int Ts; /* status */
typedef int Te; /* enum */
typedef struct Zref__S Tr; /* object ref */
typedef struct Zobj__S To; /* object description */
typedef union {
 Ti ival;
 Tf fval;
 void *ptr;
} Tz; /* dyn value */
typedef struct Ztype__S Tt; /* type */
typedef struct Ztypeo__S Tto; /* type with To pointer */
#define ZOH_OFF 0
typedef struct ZforString__S Tfs; /* FOR in string */
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforRange__S Tfr; /* FOR in range */

typedef struct CArray__S Ta; /* array head */

typedef struct CListHead__S Tl; /* list head */

typedef unsigned long Zhashtype;
typedef struct CDictItem__S CDictItem;
typedef struct CDictHead__S Td;

/* including EModule typedefs */
typedef struct Ytlm__S Ytlm; /* MEModule.Exception */
typedef struct YEro__S YEro; /* MEModule.Exit */
typedef struct YKhn__S YKhn; /* MEModule.OutOfMemory */
typedef struct Y1uN__S Y1uN; /* MEModule.NilAccess */
typedef struct YAxe__S YAxe; /* MEModule.MemoryAccess */
typedef struct YVNj__S YVNj; /* MEModule.Init */
typedef struct Yalz__S Yalz; /* MEModule.BadValue */
typedef struct Yw3O__S Yw3O; /* MEModule.OutOfRange */
typedef struct Y2EX__S Y2EX; /* MEModule.KeyNotFound */
typedef struct YX0i__S YX0i; /* MEModule.KeyExists */
typedef struct YP_P__S YP_P; /* MEModule.IllegalByte */
typedef struct YzSI__S YzSI; /* MEModule.DivideByZero */
typedef struct YXKl__S YXKl; /* MEModule.IOError */
typedef struct YuDC__S YuDC; /* MEModule.WrongType */
typedef struct YrHq__S YrHq; /* MEModule.Internal */
/* EModule done */
/* including TIMEModule typedefs */
typedef struct Y2KX__S Y2KX; /* MTIMEModule.Values */
/* TIMEModule done */
/* including ZModule typedefs */
typedef struct YkxB__S YkxB; /* MZModule.Pos */
/* ZModule done */
/* including IOModule typedefs */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
/* IOModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
typedef struct Ybkz__S Ybkz; /* EditorSyn */
typedef struct Ys45__S Ys45; /* Erow */
typedef struct YQfU__S YQfU; /* EditorConfig */
typedef struct Tcallback__S Tcb;
/*
 * STRUCTS
 */
/* IO.eof */
#define Y3QJ EOF


typedef struct {
 int line;
 int col;
} Tcpos;
typedef struct {
 Ti offset;
 Tc *fileName;
 Tc *methodName;
 Tcpos *table;
} Tcode;

void *Za(size_t size);
void *ZaNm(size_t size);
void *ZaNmi(size_t size);
void *Zran(void *op, size_t osize, size_t nsize);
void *ZranNm(void *op, size_t osize, size_t nsize);
void ZthrowOutOfMemory(Ti size);
char *emergencyAlloc = NULL;
size_t emergencyAllocUsed = 0;
void ZthrowDeadly(int nr);
Tc *ZnewString(Tc *p, Ti len);
void ZthrowCstringNil(char *text);
void ZthrowCstringBadValue(char *msg);
void ZthrowInternal(Tc *t);
char *ZgetCstring(Tc *s);
struct ZforString__S {
 Tc *ptr;
 Ti idx;
 Ti len;
};
struct ZforList__S {
 Tl *l;
 Ti i;
 Ti *keyp;
 void *valp;
};
struct ZforRange__S {
 Ti idx;
 Ti step;
 Ti last;
};

void ZthrowObject(Tr *eo);
void ZthrowIobject(Tr eo);

struct Zref__S {
 void *ptr;
 Tc **table;
 int  type;
};
Tr trZero = {NULL,NULL,0};
struct Zobj__S {
 int off;
 Tt *type;
};

struct Ztype__S {
 int nr;
 Tc *name;
 void *ToString;
};
struct Ztypeo__S {
 int nr;
 Tc *name;
 void *ToString;
 To *to;
};
extern Tt bool__T;
extern Tt byte__T;
extern Tt byteString__T;
extern Tt float128__T;
extern Tt float32__T;
extern Tt float80__T;
extern Tt float__T;
extern Tt int16__T;
extern Tt int32__T;
extern Tt int8__T;
extern Tt int__T;
extern Tt nat16__T;
extern Tt nat32__T;
extern Tt nat__T;
extern Tt status__T;
extern Tt string__T;
extern Tt type__T;
extern Tt array__T;
extern Tt list__T;
extern Tt dict__T;
extern Tt cb__T;
extern Tt iobj__T;

struct CArray__S {
 void *ptr;
 int dim;
 Ti size[3];
 Tt *itemType;
 int itemSize;
 int tosNr;
};
void ZfreeArray(Ta *head);
Ta *ZnewArray(Tt *itemType, int itemSize, Ti size);
struct CListHead__S {
 Tt *itemType;
 void **items;
 Ti empty;
 Ti space;
 Ti itemCount;
 int itemSize;
 int tosNr;
};
Tl *ZLa(Tl *head, Ti after, Tz val);
Tl *ZnewList(Tt *itemType, Ti size);
Tl *ZLap(Tl *head, Tz val);
void *ZListGetPtr(Tl *head, Ti idx);
Tl *ZListClearItem(Tl *head, Ti idx);
#define HT_INIT_SIZE 16
#define PERTURB_SHIFT 5

#define DTYPE_ORDERED 1 /* dict with list to keep order of items */

#define CDI_FLAG_USED 1
#define CDI_FLAG_DEL 2
struct CDictItem__S {
 Zhashtype hash;
 union {
  Tz key;
  Tr iokey;
 };
 union {
  Tz item;
  Tr ioitem;
 };
 CDictItem *lnext;
 CDictItem *lprev;
 int flags;
};

struct CDictHead__S {

 Zhashtype mask;
 Zhashtype used;
 Zhashtype extra;
 Zhashtype filled;
 int tosNr;
 int type;
 CDictItem *array;
 CDictItem smallArray[HT_INIT_SIZE];
 Tt *keyType;
 Tt *itemType;
 int (*eqfunc)(void *i, Tz *v);
 CDictItem *first;
 CDictItem *last;
};
YkxB *MZ__callerPos(void);

Tl *MZ__backtrace(Ti zkip, Ti limit);

YkxB *MZ__posnr2pos(YkxB *t, Ti pos);
typedef struct {
 char text[5];
} Zs5;
/* including EModule structs */
typedef struct {
 char text[4];
} Zs4;
typedef struct {
 char text[13];
} Zs13;
typedef struct {
 char text[11];
} Zs11;
typedef struct {
 char text[39];
} Zs39;
typedef struct {
 char text[12];
} Zs12;
typedef struct {
 char text[3];
} Zs3;
struct Ytlm__S {
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ytlm__T;
typedef struct {
 char text[7];
} Zs7;
struct YEro__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
 Ti Vvalue;
};
extern Tto YEro__T;
typedef struct {
 char text[6];
} Zs6;
typedef struct {
 char text[28];
} Zs28;
typedef struct {
 char text[9];
} Zs9;
struct YKhn__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YKhn__T;
struct Y1uN__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y1uN__T;
struct YAxe__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YAxe__T;
typedef struct {
 char text[14];
} Zs14;
struct YVNj__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YVNj__T;
struct Yalz__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yalz__T;
typedef struct {
 char text[10];
} Zs10;
struct Yw3O__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yw3O__T;
struct Y2EX__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y2EX__T;
typedef struct {
 char text[17];
} Zs17;
typedef struct {
 char text[18];
} Zs18;
struct YX0i__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YX0i__T;
typedef struct {
 char text[22];
} Zs22;
typedef struct {
 char text[23];
} Zs23;
struct YP_P__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YP_P__T;
typedef struct {
 char text[15];
} Zs15;
struct YzSI__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YzSI__T;
struct YXKl__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YXKl__T;
struct YuDC__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YuDC__T;
struct YrHq__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YrHq__T;
/* EModule done */
/* including TIMEModule structs */
struct Y2KX__S {
 Ti Vusec;
 Ti Vsec;
 Ti Vmin;
 Ti Vhour;
 Ti Vday;
 Ti Vmonth;
 Ti Vyear;
 Ti VweekDay;
 Ti VyearDay;
 Te Vdst;
};
extern Tto Y2KX__T;
typedef struct {
 char text[8];
} Zs8;
/* TIMEModule done */
/* including ZModule structs */
typedef struct {
 char text[16];
} Zs16;
struct YkxB__S {
 Tc *Vfilename;
 Ti Vlnum;
 Ti Vcol;
 Tc *Vtext;
};
extern Tto YkxB__T;
/* ZModule done */
/* including IOModule structs */
struct Yw8L__S {
 FILE * Vfd;
 Tc *Vname;
};
extern Tto Yw8L__T;
typedef struct {
 char text[2];
} Zs2;
struct YjUM__S {
 Ti VsLen;
 Ta *Vs;
 Tc *Vx;
};
extern Tto YjUM__T;
/* IOModule done */
/* including LOGModule structs */
typedef struct {
 char text[45];
} Zs45;
typedef struct {
 char text[37];
} Zs37;
/* LOGModule done */
/* including ARGModule structs */
struct YnU5__S {
};
extern Tto YnU5__T;
typedef struct {
 char text[51];
} Zs51;
typedef struct {
 char text[56];
} Zs56;
typedef struct {
 char text[20];
} Zs20;
typedef struct {
 char text[29];
} Zs29;
typedef struct {
 char text[31];
} Zs31;
typedef struct {
 char text[43];
} Zs43;
typedef struct {
 char text[19];
} Zs19;
typedef struct {
 char text[21];
} Zs21;
typedef struct {
 char text[24];
} Zs24;
struct YuMQ__S {
 Tc *Vtext;
};
extern Tto YuMQ__T;
typedef struct {
 char text[42];
} Zs42;
typedef struct {
 char text[50];
} Zs50;
typedef struct {
 char text[52];
} Zs52;
typedef struct {
 char text[32];
} Zs32;
struct Y86c__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tb Vcurrent;
 Tb Vdefault;
};
extern Tto Y86c__T;
struct YJQu__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Ti Vcurrent;
 Ti Vdefault;
 Tl *VtheValueList;
};
extern Tto YJQu__T;
struct YzqH__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tc *Vcurrent;
 Tc *Vdefault;
 Tl *VtheValueList;
};
extern Tto YzqH__T;
struct Y_SI__S {
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tl *Vcurrent;
 Tl *Vdefault;
};
extern Tto Y_SI__T;
/* ARGModule done */
struct Ybkz__S {
 Tc *Vft;
 Tl *Vfpatterns;
 Tc *VicommentStyle;
 Tl *Vkeywords;
 Ti Vflags;
};
extern Tto Ybkz__T;
struct Ys45__S {
 Tc *Vtxt;
 Tc *Vorig;
 Tc *Vrender;
 Tl *Vhl;
 Ti Vts;
 Ybkz *Vsyn;
};
extern Tto Ys45__T;
typedef struct {
 char text[47];
} Zs47;
typedef struct {
 char text[36];
} Zs36;
typedef struct {
 char text[38];
} Zs38;
typedef struct {
 char text[53];
} Zs53;
typedef struct {
 char text[40];
} Zs40;
struct YQfU__S {
 Tu Vcx;
 Tu Vcy;
 Tu Vrx;
 Ti Vrows;
 Ti Vcols;
 Tc Vmode;
 Tl *Verows;
 Ti Vn_erows;
 Ti Vrowoff;
 Tc *Vcopy;
 Ti Vcoloff;
 Ti Vts;
 Tb Vexpand;
 Ti Vfmodified;
 Tc *Vfilename;
 Tc *Vstatusmsg;
 Ti Vstatime;
 Ybkz *Vcsyn;
 struct termios* Vorig_termios;
};
extern Tto YQfU__T;
typedef struct {
 char text[75];
} Zs75;
typedef struct {
 char text[26];
} Zs26;
typedef struct {
 char text[92];
} Zs92;
typedef struct {
 char text[48];
} Zs48;
typedef struct {
 char text[71];
} Zs71;
typedef struct {
 char text[27];
} Zs27;
struct Tcallback__S {
 void *cfunc;
 int toCount;
};
/*
 * DECLARE FUNCTIONS AND GLOBALS
 */
Zs5 ZNilString = {"\003NIL\000"};
/* including EModule declarations */
void YxaJ(Ytlm *t, Tr Aw); /* MEModule__CException.writeTo */
Zs4 YFDa = {"\002: \000"};
Zs13 YHbP = {"\013Exception: \000"};
Zs11 YDGe = {"\011Exception\000"};
Tc *Yoww(Ytlm *t, Tb Averbose); /* MEModule__CException.toString */
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw); /* MEModule__CException.writeTo */
Zs39 Y62e = {"\045\nStack backtrace (last called first):\000"};
Zs12 Yv6_ = {"\012\n(unknown)\000"};
Zs3 Yk = {"\001\n\000"};
To ToYtlm[4];
YEro *YE2c(YEro *t, Ti Avalue); /* MEModule__CExit.NEW */
Zs7 YxJ1 = {"\005EXIT \000"};
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Tc *YEro__Yoww(YEro *t, Tb Averbose); /* MEModule__CExit.toString__p1 */
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw); /* MEModule__CExit.writeTo__p1 */
Tc *YEro__Ytlm_I_imt[14];
To ToYEro[4];
Zs6 YJMo = {"\004Exit\000"};
void YNab(YkxB *Apos, Ti Aval); /* MEModule.throwExit */
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {"\032Out of memory (allocating \000"};
Zs9 YDSH = {"\007 bytes)\000"};
Tc *YKhn__YwtA__Yoww(YKhn *t, Tb Averbose); /* MEModule__COutOfMemory.toString__p2 */
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
Tc *YKhn__Ytlm_I_imt[14];
To ToYKhn[4];
Zs13 Y9Fv = {"\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
Tc *Y1uN__YwtA__Yoww(Y1uN *t, Tb Averbose); /* MEModule__CNilAccess.toString__p2 */
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
Tc *Y1uN__Ytlm_I_imt[14];
To ToY1uN[4];
Zs11 Y4wO = {"\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
Tc *YAxe__YwtA__Yoww(YAxe *t, Tb Averbose); /* MEModule__CMemoryAccess.toString__p2 */
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
Tc *YAxe__Ytlm_I_imt[14];
To ToYAxe[4];
Zs14 Y4QW = {"\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {"\013signal SEGV\000"};
Zs12 YoEx = {"\012signal FPE\000"};
Zs12 YQNH = {"\012signal BUS\000"};
Zs9 YpCZ = {"\007signal \000"};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
Tc *YVNj__YwtA__Yoww(YVNj *t, Tb Averbose); /* MEModule__CInit.toString__p2 */
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw); /* MEModule__CInit.writeTo__p2 */
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw); /* MEModule__CInit.writeTo__p2 */
Tc *YVNj__Ytlm_I_imt[14];
To ToYVNj[4];
Zs6 Ysqt = {"\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
Tc *Yalz__YwtA__Yoww(Yalz *t, Tb Averbose); /* MEModule__CBadValue.toString__p2 */
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
Tc *Yalz__Ytlm_I_imt[14];
To ToYalz[4];
Zs10 YEZq = {"\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
Tc *Yw3O__Yalz__YwtA__Yoww(Yw3O *t, Tb Averbose); /* MEModule__COutOfRange.toString__p3 */
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
Tc *Yw3O__Ytlm_I_imt[14];
To ToYw3O[4];
Zs12 YFK2 = {"\012OutOfRange\000"};
void Y6NT(Ti Aindex, Tc *Amsg); /* MEModule.throwOutOfRange */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
Tc *Y2EX__Yalz__YwtA__Yoww(Y2EX *t, Tb Averbose); /* MEModule__CKeyNotFound.toString__p3 */
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
Tc *Y2EX__Ytlm_I_imt[14];
To ToY2EX[4];
Zs13 YRiW = {"\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {"\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {"\020Key not found: \"\000"};
Zs3 YI = {"\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
Tc *YX0i__Yalz__YwtA__Yoww(YX0i *t, Tb Averbose); /* MEModule__CKeyExists.toString__p3 */
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
Tc *YX0i__Ytlm_I_imt[14];
To ToYX0i[4];
Zs11 Y9_h = {"\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {"\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {"\025Key already exists: \"\000"};
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg); /* MEModule__CIllegalByte.NEW__p3 */
Tc *YP_P__Yalz__YwtA__Yoww(YP_P *t, Tb Averbose); /* MEModule__CIllegalByte.toString__p3 */
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
Tc *YP_P__Ytlm_I_imt[14];
To ToYP_P[4];
Zs13 Ydbm = {"\013IllegalByte\000"};
void YLbE(); /* MEModule.throwIllegalByte */
Zs15 Y4K_ = {"\015invalid UTF-8\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
Tc *YzSI__Ylz1__YwtA__Yoww(YzSI *t, Tb Averbose); /* MEModule__CDivideByZero.toString__p3 */
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
Tc *YzSI__Ytlm_I_imt[14];
To ToYzSI[4];
Zs14 YxFl = {"\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
Tc *YXKl__YwtA__Yoww(YXKl *t, Tb Averbose); /* MEModule__CIOError.toString__p2 */
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
Tc *YXKl__Ytlm_I_imt[14];
To ToYXKl[4];
Zs9 YTj3 = {"\007IOError\000"};
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {"\015Type mismatch\000"};
Tc *YuDC__YwtA__Yoww(YuDC *t, Tb Averbose); /* MEModule__CWrongType.toString__p2 */
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
Tc *YuDC__Ytlm_I_imt[14];
To ToYuDC[4];
Zs11 YCoZ = {"\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
Tc *YrHq__YwtA__Yoww(YrHq *t, Tb Averbose); /* MEModule__CInternal.toString__p2 */
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
Tc *YrHq__Ytlm_I_imt[14];
To ToYrHq[4];
Zs10 YVki = {"\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Tr Ae); /* MEModule.unhandledException */
void YvL0(Tr Ae); /* MEModule.writeToStderr */
void YQar(Tr A0, Tb A1, Tr A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including TIMEModule declarations */
Ti Y9Rj(); /* MTIMEModule.current */
Y2KX *YgaY(Y2KX *t); /* MTIMEModule__CValues.NEW */
Y2KX *YgaYb(Y2KX *t, Ti Ausec); /* MTIMEModule__CValues.NEW */
Tc *YYTs(Y2KX *t); /* MTIMEModule__CValues.ToString */
Zs3 YV = {"\001/\000"};
Zs5 Y6O7 = {"\00302d\000"};
Zs3 YG = {"\001 \000"};
Zs3 Y5 = {"\001:\000"};
To ToY2KX[1];
Zs8 YeCO = {"\006Values\000"};
Tt MTIMEModule__EDst__T = {23, 0, 0};
/* TIMEModule done */
/* including ZModule declarations */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {"\016[unknown file]\000"};
Zs8 YBpY = {"\006 line \000"};
Zs7 Y8ES = {"\005 col \000"};
To ToYkxB[3];
Zs5 YBCs = {"\003Pos\000"};
/* ZModule done */
/* including IOModule declarations */
Ti Y3QJ__NOT = -1 /* MIOModule.eof */;
Tr Y59X = {NULL}; /* MIOModule.stdin */
Tr Yb0q = {NULL}; /* MIOModule.stdout */
Tr YeNQ = {NULL}; /* MIOModule.stderr */
Tr Yd89(); /* MIOModule.newStdin */
Tr Yvyt(); /* MIOModule.newStdout */
Tr YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
Ti YFeQ(Yw8L *t); /* MIOModule__CFile.readByte */
Zs18 YQe8 = {"\020File is not open\000"};
Tc *YaEh(Yw8L *t); /* MIOModule__CFile.readLine */
Tl *YCm1(Yw8L *t); /* MIOModule__CFile.readAllLines */
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Ts YGmp(Yw8L *t); /* MIOModule__CFile.flush */
Ts YrF8(Yw8L *t); /* MIOModule__CFile.close */
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber); /* MIOModule__CFile.write__p1 */
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__Yw8L_I_imt[38];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[2];
Zs6 YtTU = {"\004File\000"};
Tr YsGz(Tc *AfileName); /* MIOModule.fileReader */
Tr YiBk(Tc *AfileName, Tb Atruncate); /* MIOModule.fileWriter */
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Ts Ye7fa(YjUM *t, Ti Abyte); /* MIOModule__CStringWriter.writeByte */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Zs2 Ya = {"\000\000"};
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__YRt7(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.print__p1 */
Tc *YjUM__YdXi_imt[3];
To ToYjUM[3];
Zs14 YE4c = {"\014StringWriter\000"};
int JIOModule(int round);
/* IOModule done */
/* including LOGModule declarations */
Zs3 YLa = {"\001d\000"};
Zs7 YGwH = {"\005debug\000"};
Zs12 YhpM = {"\012Debug mode\000"};
Y86c *YU8T = 0; /* MLOGModule.debugFlag */
Zs3 Y2a = {"\001v\000"};
Zs9 YUsn = {"\007verbose\000"};
Zs45 YSuP = {"\053Verbose messages, repeat for more verbosity\000"};
Y86c *YlUb = 0; /* MLOGModule.verboseFlag */
Tt MLOGModule__ELevel__T = {23, 0, 0};
Zs7 YuXA = {"\005Flags\000"};
Tt MLOGModule__BFlags__T = {25, ((Tc*)&YuXA), 0};
Td *Ytd2 = NULL; /* MLOGModule.counts */
Ti Yrpn = 0; /* MLOGModule.errorCount */
void YFf6(Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.fatal */
Tc *YmaW = ((Tc*)&Ya) /* MLOGModule.extraLead */;
void Ygkj(Te Alevel, Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.log */
Zs11 YJ5p = {"\011INTERNAL \000"};
Zs11 Yyq1 = {"\011Warning: \000"};
Zs9 Y27a = {"\007ERROR: \000"};
Zs16 Y3l3 = {"\016SEVERE ERROR: \000"};
Zs15 YmM8 = {"\015FATAL ERROR: \000"};
Zs3 YU = {"\001.\000"};
Zs5 YwV7 = {"\00306d\000"};
Zs37 YQAha = {"\043/home/tsuki/.zimbu/lib/LOGModule.zu\000"};
void YwlF(Tr Aout); /* MLOGModule.reportStack */
Zs12 YDzC = {"\012Backtrace:\000"};
Ti YvW3 = 0; /* MLOGModule.lastFlush */
Ti YOwl = 300000 /* MLOGModule.flushInterval */;
void Y7LJ(); /* MLOGModule.flush */
Tr Yz2b = {NULL}; /* MLOGModule.logFile */
Tb YiAD = 1 /* MLOGModule.useTimeStamp */;
int JLOGModule(int round);
/* LOGModule done */
/* including ARGModule declarations */
Tc *YzvW = NULL; /* MARGModule.rawName */
Tl *Y1p3 = NULL; /* MARGModule.rawArgs */
Tl *Y6fX = NULL; /* MARGModule.cleanArgs */
Tb YQpY = 0; /* MARGModule.stopFlag */
Tb YUBd = 0; /* MARGModule.disabled */
Tb YhUP = 0; /* MARGModule.disableGiveHelp */
Tb Y_kI = 0; /* MARGModule.disableCompactVal */
Ti YMLU = 1 /* MARGModule.exitVal */;
YuMQ *Yun4 = 0; /* MARGModule.theUsage */
int Ytu___r = 0; /* MARGModule.Ready */
Ts Ytu_(); /* MARGModule.Init */
Ti Y2H3(); /* MARGModule.rawSize */
Tl *YUgp(); /* MARGModule.getRawList */
To ToYnU5[1];
Zs8 Yr32 = {"\006Status\000"};
void YY8i(); /* MARGModule.initCheck */
Zs51 YeBP = {"\061Using command line flag before they are available\000"};
void YZH8(); /* MARGModule.init */
Zs56 Y7T_ = {"\066ARG.disable() used but command line flags were defined\000"};
Zs3 YT = {"\001-\000"};
Zs4 Y1ia = {"\002--\000"};
Zs6 YqzQ = {"\004help\000"};
Zs10 Y3vi = {"\010morehelp\000"};
Zs10 Yll7 = {"\010helpmore\000"};
Zs4 YhZb = {"\002no\000"};
Zs20 YcW8 = {"\022Invalid argument: \000"};
Zs29 Y2hB = {"\033Unknown command line flag: \000"};
Zs31 YcLH = {"\035Duplicate command line flag: \000"};
Zs5 YjK7 = {"\003yes\000"};
Zs6 YsfP = {"\004true\000"};
Zs7 YvpX = {"\005false\000"};
Zs43 YHSJ = {"\051Expected 'yes', 'no', 'true' or 'false': \000"};
Zs19 Y6QK = {"\021Unexpected = in: \000"};
Zs28 Y_ju = {"\032Missing argument for flag \000"};
Zs29 YjTs = {"\033INTERNAL: unknown flag type\000"};
void YSUO(Tc *Amsg); /* MARGModule.error */
Zs22 YkFE = {"\024To list flags use: '\000"};
Zs10 Y15F = {"\010 --help'\000"};
Zs37 Ye5Da = {"\043/home/tsuki/.zimbu/lib/ARGModule.zu\000"};
void Yfj5(Tb Averbose); /* MARGModule.displayHelp */
Zs21 YaBy = {"\023Command line flags:\000"};
Zs13 YwXF = {"\013--morehelp \000"};
Zs24 YEcf = {"\026show more verbose help\000"};
Zs8 Yy2p = {"\006number\000"};
Zs8 YanE = {"\006string\000"};
Zs12 YDci = {"\012string ...\000"};
Zs6 YulU = {"\004 ...\000"};
Zs4 YVZ = {"\002 [\000"};
Zs3 YEa = {"\001]\000"};
Zs4 Yq_ = {"\002 {\000"};
Zs3 Y9a = {"\001}\000"};
Zs5 Y_y2 = {"\003...\000"};
Zs6 Y2yA = {"\004... \000"};
Zs13 Ym4c = {"\013Defined in \000"};
void YTlu(Tc *Alead, Ti AmaxLeadLen); /* MARGModule.writeLead */
Tc *YAMW(YuMQ *t); /* MARGModule__CUsage.get */
Zs5 YMtG = {"\003%0%\000"};
To ToYuMQ[2];
Zs7 Y6qT = {"\005Usage\000"};
Td *Y7be = NULL; /* MARGModule.shortFlags */
Td *YBQy = NULL; /* MARGModule.longFlags */
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc); /* MARGModule__CBool.NEW */
void YEqoa(Y86c *t); /* MARGModule__CBool.setToDefault */
Tb YHoR(Y86c *t); /* MARGModule__CBool.get */
Tb YuOS(Y86c *t); /* MARGModule__CBool.value */
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CBool.NEW__p1 */
Zs42 Yc_h = {"\050Adding command line flag after using one\000"};
Zs50 Y6pY = {"\060Command line flag must have a short or long name\000"};
Zs52 Y9CP = {"\062short command line flag name must be one character\000"};
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CBool.throwDuplicate__p1 */
Zs9 YbbH = {"\007unknown\000"};
Zs32 YtzG = {"\036Duplicate command line flag: '\000"};
Zs17 YDyy = {"\017' also used at \000"};
Ti Y86c__Ye9f(Y86c *t); /* MARGModule__CBool.presentCount__p1 */
Tc *Y86c__YuQR_I_imt[19];
To ToY86c[6];
Zs6 YZ1F = {"\004Bool\000"};
void Y49ga(YJQu *t); /* MARGModule__CInt.setToDefault */
To ToYJQu[7];
Zs5 YzBa = {"\003Int\000"};
void YJaza(YzqH *t); /* MARGModule__CString.setToDefault */
To ToYzqH[9];
Zs8 YDAE = {"\006String\000"};
void YSkKa(Y_SI *t); /* MARGModule__CStringList.setToDefault */
To ToY_SI[8];
Zs12 Ygf5 = {"\012StringList\000"};
int JARGModule(int round);
/* ARGModule done */
Zs7 YcJv = {"\0050.0.1\000"};
Tc *Vvenci_v = ((Tc*)&YcJv);
void YqsW(Tc *As); /* die */
Tc *Ygor(Tc *Af, Tl *Aargs); /* tcalls */
Zs4 YUR = {"\002\033[\000"};
Zs3 Y6 = {"\001;\000"};
void Ywpw(Tc *Af, Tl *Aargs); /* tcall */
Ts YP9u(Ti *Rrows, Ti *Rcols); /* getCursorPosition */
Zs6 YQh8 = {"\004\033[6n\000"};
Zs12 Y_eV = {"\0120123456789\000"};
Ti YZ7l(Ys45 *Ar, Tu Acx, Ti Ats); /* cx2rx */
Tb YjGn(Ti Ach); /* issep */
Ybkz *Yfrg(Ybkz *t, Tc *Aft, Tl *Afp, Ti Aflags, Tc *Aics, Tl *Akw); /* CEditorSyn.NEW */
To ToYbkz[5];
Zs11 Ygt_ = {"\011EditorSyn\000"};
Zs7 Ye5c = {"\005zimbu\000"};
Zs5 YYv4 = {"\003.zu\000"};
Zs3 YJ = {"\001#\000"};
Zs8 Y0Y5 = {"\006SWITCH\000"};
Zs4 YrUa = {"\002DO\000"};
Zs6 YqI4 = {"\004FUNC\000"};
Zs7 YHo2 = {"\005WHILE\000"};
Zs4 Yj1a = {"\002IF\000"};
Zs7 YexT = {"\005UNTIL\000"};
Zs6 Yc7A = {"\004ELSE\000"};
Zs6 Y6T9 = {"\004PROC\000"};
Zs7 YMwW = {"\005CLASS\000"};
Zs8 YGD1 = {"\006RETURN\000"};
Zs5 Yz51 = {"\003FOR\000"};
Zs4 Yr1a = {"\002IN\000"};
Zs6 Y7fW = {"\004TYPE\000"};
Zs8 Y9jU = {"\006ELSEIF\000"};
Zs8 YML6 = {"\006IMPORT\000"};
Zs7 YZzE = {"\005BREAK\000"};
Zs10 Yn3A = {"\010CONTINUE\000"};
Zs6 Y6FU = {"\004CASE\000"};
Zs6 YjG6 = {"\004BITS\000"};
Zs6 YIuk = {"\004int|\000"};
Zs9 Y8Cc = {"\007string|\000"};
Zs8 YBs9 = {"\006float|\000"};
Zs7 YPOy = {"\005nat8|\000"};
Zs8 YcbZ = {"\006nat16|\000"};
Zs6 YF0o = {"\004nat|\000"};
Zs7 YaTa = {"\005list|\000"};
Zs7 YB_5 = {"\005bool|\000"};
Zs8 YyD_ = {"\006array|\000"};
Zs6 YiGa = {"\004dyn|\000"};
Zs8 YDd3 = {"\006nat32|\000"};
Tl *Vfiletypes = NULL;
Tc *Yh7e(Tc *As, Ti Afrom, Ti Alen); /* next */
void YiiI(Ys45 *t); /* CErow.updateRow */
void Yz4M(Ys45 *t, Tu Apos, Ti Ach); /* CErow.insertChar */
void YdbI(Ys45 *t, Tu Apos); /* CErow.shiftl */
void YPEA(Ys45 *t, Tu Apos); /* CErow.preshiftl */
void Yoz2(Ys45 *t); /* CErow.back */
void YhvK(Ys45 *t, Ti Apos); /* CErow.delChar */
Ti YjIv(Ys45 *t, Ti Arx); /* CErow.rx2cx */
void YIV3(Ys45 *t, Tc *As); /* CErow.appendStr */
void YYmf(Ys45 *t); /* CErow.updateSyntax */
Zs3 Y8a = {"\001|\000"};
Ys45 *Yngj(Ys45 *t, Tc *Atext, Ti Ats, Ybkz *Asyn); /* CErow.NEW */
To ToYs45[6];
Zs6 YSv9 = {"\004Erow\000"};
void YouM(YQfU *t, Tc *As, Tc *Ab); /* CEditorConfig.setStatmsg */
void YteW(YQfU *t); /* CEditorConfig.updateSynAllRows */
void YYQw(YQfU *t); /* CEditorConfig.selectSyn */
Ti YB3w(YQfU *t, Ti Ahl); /* CEditorConfig.getSynColor */
void Yc1O(YQfU *t); /* CEditorConfig.find */
Zs37 YUFM = {"\043(=_=) | -ESC to cancel- Find text: \000"};
Tc *YoQj(YQfU *t); /* CEditorConfig.rowsToStr */
void YWKz(YQfU *t); /* CEditorConfig.save */
Zs16 YU14 = {"\016(T.T) | file: \000"};
Zs17 YiHc = {"\017 doesn't exist!\000"};
Zs12 YxQ_ = {"\012(\\^w^/) | \000"};
Zs16 YPwc = {"\016 bytes written\000"};
Zs31 Y7hz = {"\035(o.O?) | Error opening file: \000"};
Zs20 Yjjm = {"\022(o_o)? | Save as: \000"};
Zs47 Ysvx = {"\055(@_@) | so, no saving? Ok that's fine i guess\000"};
void YJA8(YQfU *t); /* CEditorConfig.scroll */
void Yuq0(YQfU *t, Tc *As, Ti Aat); /* CEditorConfig.insertRow */
void YzYj(YQfU *t); /* CEditorConfig.insertNL */
void YcHr(YQfU *t, Ti Ac); /* CEditorConfig.insertChar */
void YneO(YQfU *t); /* CEditorConfig.shiftRowLeft */
void Y7mW(YQfU *t); /* CEditorConfig.delChar */
void YaZr(YQfU *t, Tc *Afname); /* CEditorConfig.open */
void YbQH(YQfU *t); /* CEditorConfig.close */
Zs21 YwGe = {"\023(v.v) | file closed\000"};
void Yeai(YQfU *t, Ti Ak); /* CEditorConfig.moveCursor */
Zs36 YcRO = {"\042(-_O) | undid actions on that line\000"};
Zs42 Y3Gy = {"\050(-_-) | nothing to undo on current line.\000"};
Zs21 YzlG = {"\023(^.^) | line copied\000"};
Zs42 YAc9 = {"\050/(OoO)\\ | sorry, copy buffer is too big.\000"};
Zs38 Y56D = {"\044('V') | line appended to copy buffer\000"};
Zs53 YK3W = {"\063>>.>> | -ESC to cancel- how many lines to advance: \000"};
Zs39 Y7D8 = {"\045(._.) | this is boring, i want to run\000"};
Zs53 YMbE = {"\063<<.<< | -ESC to cancel- how many lines to go back: \000"};
Zs39 YKoD = {"\045('-') | this is boring, i want to run\000"};
Zs10 Y9At = {"\010(Owo) | \000"};
Zs40 Ye_A = {"\046<!--i regret adding this ascii face-->\000"};
Zs17 Y6Hv = {"\017-ESC to cancel-\000"};
Zs21 YNTX = {"\023 String to insert: \000"};
Zs43 YZj2 = {"\051(.o.) | why tho? this command is so cool!\000"};
Ts YLNB(YQfU *t); /* CEditorConfig.getWindowSize */
Zs14 Yd1d = {"\014\033[999C\033[999B\000"};
void YEDW(YQfU *t); /* CEditorConfig.reset */
YQfU *Yek3(YQfU *t); /* CEditorConfig.NEW */
To ToYQfU[6];
Zs14 YT6N = {"\014EditorConfig\000"};
YQfU *Vec = 0;
void YYfE(Tc *Aquery, Ti Ak); /* findCb */
Ti YHqw = -1 /* YYfE.last */;
Ti Ynxs = 1 /* YYfE.dir */;
Ti Yr0N = 0 /* YYfE.shl_index */;
Tl *Yu33; /* YYfE.shl */
Zs75 YRuz = {"\111('.') | i was trying to find something, but you just canceled the search.\000"};
Zs29 YAGa = {"\033(^_-) | didn't find string \000"};
Zs26 Ytas = {"\030(^O^) | Yay! i found it!\000"};
Zs17 Ykqx = {"\017tcsetattr error\000"};
void YDKA(); /* enableRawMode */
void YdnK(); /* clrscr */
Zs3 Yla = {"\001J\000"};
Zs3 YY = {"\0012\000"};
void YNEj(Ti Ax, Ti Ay); /* gotoxy */
Zs3 Yja = {"\001H\000"};
Tc *YcnF(Ti Ax, Ti Ay); /* gotoxy_s */
void YyP1(); /* warnUnsaved */
Zs92 Yeix = {"\132WAIT! (O__O!) | you have unsaved changes, press CTRL-S to save or try again to quit anyway\000"};
void YLzL(); /* processKeypress */
Ti Y1kq = 1 /* YLzL.didquit */;
Zs12 Ya_Da = {"\012src/out.zu\000"};
Zs43 Yq1o = {"\051/>.</ | -ESC to cancel- type a filename: \000"};
Zs36 Y38M = {"\042@.@ | ok, i get it, no file for me\000"};
Zs7 Yp3l = {"\005hjlk+\000"};
Zs37 Yq_k = {"\043(o_O) | -ESC to cancel- Goto line: \000"};
Zs40 YKlk = {"\046(~____~) | nooooo, i want to teleport!\000"};
Zs48 Ykz0 = {"\056(X-x) | man... you cant go to that line, it's \000"};
Zs8 YSd9 = {"\006waayyy\000"};
Zs9 YU30 = {"\007like...\000"};
Zs22 YW0q = {"\024 outside of the file\000"};
Zs71 YNJx = {"\105(*_*) | unlike vim, there's actually a NORMAL way to exit, try CTRL-Q\000"};
Tc *YZeI(); /* drawRows */
Zs22 Y1ky = {"\024Venci test, version \000"};
Zs3 Yab = {"\001~\000"};
Zs3 YUa = {"\001m\000"};
Zs4 YQsa = {"\00239\000"};
Zs5 Y6Sh = {"\003\033[K\000"};
Zs4 Yau = {"\002\r\n\000"};
Tc *Y4Sa(); /* drawStatusBar */
Zs11 YsQ7 = {"\011[No Name]\000"};
Zs3 YQ = {"\001*\000"};
Zs5 Yhyt = {"\003 - \000"};
Zs8 YVqY = {"\006 lines\000"};
Zs3 Y7 = {"\001<\000"};
Zs8 YsAp = {"\006> ft: \000"};
Zs6 YzQY = {"\004none\000"};
Zs8 Y3dz = {"\006 LINE:\000"};
Zs12 YJ7Q = {"\012 | COLUMN:\000"};
Zs11 YZAu = {"\011 (^_^)/ |\000"};
Zs3 Y2 = {"\0017\000"};
Tc *YTEZ(); /* drawMsgBar */
Zs3 Yma = {"\001K\000"};
void Y9Dc(); /* refreshScreen */
Zs3 YTa = {"\001l\000"};
Zs5 YamK = {"\003?25\000"};
Zs3 YPa = {"\001h\000"};
Tc *Y1GC(Tc *Amsg, Tcb *Afn); /* prompt */
Ti Y8Q5(); /* readKey */
Zs12 Y9Ri = {"\012read error\000"};
Zs27 Yt7s = {"\031error getting window size\000"};
Zs56 YmOu = {"\066info: press Ctrl-Q to quit venci, press Ctrl-S to save\000"};
/*** callbacks for methods invoked directly ***/
void ZcbYYfE(Tcb *cb, Tc *arg0, Ti arg1);
Tcb ZCB_YYfE = {ZcbYYfE, -1};

Tt bool__T  = {21, 0, 0};
Tt byte__T  = {11, 0, 0};
Tt byteString__T = {201, 0, 0};
Tt float128__T  = {83, 0, 0};
Tt float32__T  = {81, 0, 0};
Tt float80__T  = {82, 0, 0};
Tt float__T  = {80, 0, 0};
Tt int16__T  = {2, 0, 0};
Tt int32__T  = {3, 0, 0};
Tt int8__T  = {1, 0, 0};
Tt int__T  = {0, 0, 0};
Tt nat16__T  = {12, 0, 0};
Tt nat32__T  = {13, 0, 0};
Tt nat__T  = {10, 0, 0};
Tt status__T  = {22, 0, 0};
Tt string__T = {200, 0, 0};
Tt type__T  = {101, 0, 0};
Tt array__T = {300, 0, 0};
Tt list__T = {301, 0, 0};
Tt dict__T = {302, 0, 0};
Tt cb__T  = {330, 0, 0};
Tt iobj__T = {391, 0, 0};
int ZglobInit(int round);

typedef struct Zfo__S {
 int off;
 Tt  *type;
} Zfo;
typedef struct Zsf__S {
 volatile int pos;
 struct Zsf__S *prev;
 Zfo *frof;
} Zsf;
#define POS_MASK 0x3fffffff
typedef struct StryCtx__S {
 jmp_buf jmpBuf;
 Zsf *sf;
} Ttc;
typedef struct Senv__S {
 Ttc  *tryCtx;
 int  tryCtxSize;
 int  tryCtxUsed;
 Tr   *thrown;
 int  thrownSize;
 int  thrownUsed;
 int tosNr;
} Tn; /* per-thread environemnt */

Zsf *topFrame = NULL;
int inZa = 0;
int ZaEntered = 0;

Tn Zenv = {NULL, 0, 0, NULL, 0, 0, 0};

void beforeExit() {
}


Tc *Zstr(char *s) {
 return ZnewString((Tc*)s, strlen(s));
}

/* allocate memory */
void *Za(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (Za)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

/* allocate memory with offset */
#define ZaOff(size) (Za((size) + ZOH_OFF) + ZOH_OFF)
#define ZranOff(ptr, osize, nsize) (Zran((ptr) ? (void*)(ptr) - ZOH_OFF : NULL, (osize) + ZOH_OFF, (nsize) + ZOH_OFF) + ZOH_OFF)

/* allocate memory */
void *ZaNm(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNm)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

void *ZaNmi(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNmi)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

/* reallocate memory */
void *Zran(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 if (!inZa && !ZaEntered) {
  inZa = 1;
  p = realloc(op, nsize);
  inZa = 0;
  if (p == NULL) {
    ++ZaEntered;
    ZthrowOutOfMemory(nsize);
  }
  ZaEntered = 0;
  if (nsize > osize) memset(p + osize, 0, nsize - osize);
  return p;
 }
 p = Za(nsize);
 if (op)
  memmove(p + ZOH_OFF, op + ZOH_OFF, nsize > osize ? osize - ZOH_OFF : nsize - ZOH_OFF);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

void *ZranNm(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 if (!inZa && !ZaEntered) {
  inZa = 1;
  p = realloc(op, nsize);
  inZa = 0;
  if (p == NULL) {
   ++ZaEntered;
   ZthrowOutOfMemory(nsize);
  }
  if (nsize > osize) memset(p + osize, 0, nsize - osize);
  return p;
 }
 p = ZaNm(nsize);
 if (op) memmove(p, op, nsize > osize ? osize : nsize);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

void Zfree(void *p) {
 if (p) free(p);
}

Tc *ZnewStringInit(Ti len, Tc **pp) {
 Ti rlen = len;
 int i;
 int n = ZOH_OFF;
 Tc buf[20];
 Tc *res;
 buf[0] = (rlen & 127);
 rlen >>= 7;
 for (i = 1; rlen > 0; ++i)
 {
  buf[i] = (rlen & 127) + 128;
  rlen >>= 7;
 }
 res = Za(ZOH_OFF + len + i + 1);
 while (i > 0) res[n++] = buf[--i];
 *pp = res + n;
 return res;
}

Tc *ZnewString(Tc *p, Ti len) {
 Tc *pp;
 Tc *res = ZnewStringInit(len, &pp);
 memmove(pp, p, len);
 return res;
}
Tc Ye5D[]="/home/tsuki/.zimbu/lib/ARGModule.zu";
Tc Y6mX[]="/home/tsuki/.zimbu/lib/EModule.zu";
Tc Yusm[]="/home/tsuki/.zimbu/lib/IOModule.zu";
Tc YQAh[]="/home/tsuki/.zimbu/lib/LOGModule.zu";
Tc YTAg[]="/home/tsuki/.zimbu/lib/TIMEModule.zu";
Tc YHVP[]="/home/tsuki/.zimbu/lib/ZModule.zu";
Tc Ya_D[]="src/out.zu";
Tc Yaa[]="";
Tcpos ZcTbl0[]={
{137,17},
{650,14},
};
Tc Y_VO[]="ARG.Bool.NEW/1()";
Tcpos ZcTbl3273[]={
{791,5},
{2,7},
{3,16},
{4,16},
{5,18},
};
Tc YImf[]="ARG.Bool.NEW__p1/1()";
Tcpos ZcTbl76644[]={
{637,5},
{1,7},
{2,9},
{4,7},
{6,9},
{8,7},
{9,20},
{11,7},
{12,19},
{14,12},
{18,7},
{19,20},
{20,19},
{23,7},
{24,9},
{25,11},
{27,9},
{29,7},
{30,9},
{31,11},
{33,9},
{34,11},
{36,9},
{38,12},
};
Tc YM2k[]="ARG.Bool.setToDefault/1()";
Tcpos ZcTbl38911[]={
{800,11},
{1,16},
};
Tc YgDO[]="ARG.Bool.throwDuplicate__p1/1()";
Tcpos ZcTbl75697[]={
{679,11},
{1,44},
{2,18},
{4,7},
};
Tc Y2cg[]="ARG.Bool.value()";
Tcpos ZcTbl61284[]={
{830,11},
{1,15},
};
Tc YPPv[]="ARG.Init()";
Tcpos ZcTbl66501[]={
{78,29},
};
Tc Ygzb[]="ARG.Int.setToDefault/1()";
Tcpos ZcTbl16350[]={
{865,11},
{1,16},
};
Tc YZNA[]="ARG.String.setToDefault/1()";
Tcpos ZcTbl86206[]={
{953,11},
{1,16},
};
Tc YRbs[]="ARG.StringList.setToDefault/1()";
Tcpos ZcTbl64478[]={
{1046,11},
{1,16},
};
Tc YEFE[]="ARG.Usage.get()";
Tcpos ZcTbl43000[]={
{600,11},
{1,23},
{2,7},
{3,17},
{5,49},
};
Tc YzK9[]="ARG.displayHelp()";
Tcpos ZcTbl29560[]={
{461,5},
{1,7},
{3,5},
{6,35},
{7,5},
{8,19},
{9,7},
{10,33},
{7,5},
{17,5},
{18,7},
{19,9},
{20,9},
{23,7},
{24,21},
{26,26},
{28,9},
{29,11},
{30,21},
{32,21},
{34,15},
{35,21},
{36,11},
{37,21},
{39,21},
{41,15},
{42,21},
{43,11},
{44,21},
{46,21},
{48,15},
{50,9},
{51,11},
{52,21},
{54,21},
{58,23},
{59,9},
{60,16},
{62,9},
{63,11},
{65,13},
{66,15},
{67,22},
{69,15},
{71,18},
{73,16},
{76,9},
{77,16},
{80,9},
{81,11},
{82,13},
{83,13},
{85,13},
{87,11},
{88,13},
{89,13},
{92,11},
{93,24},
{95,11},
{96,24},
{23,7},
{17,5},
{103,10},
};
Tc Yza4[]="ARG.error()";
Tcpos ZcTbl85295[]={
{449,5},
{1,5},
{2,7},
{4,5},
{5,7},
{7,10},
};
Tc YXkl[]="ARG.getRawList()";
Tcpos ZcTbl25227[]={
{120,12},
};
Tc Yh2v[]="ARG.init()";
Tcpos ZcTbl82533[]={
{259,5},
{1,7},
{3,20},
{4,19},
{6,7},
{7,9},
{9,7},
{10,9},
{9,7},
{12,7},
{13,9},
{12,7},
{16,17},
{17,22},
{19,7},
{20,9},
{22,16},
{26,22},
{27,9},
{28,11},
{29,11},
{30,21},
{33,11},
{34,21},
{39,13},
{40,37},
{41,15},
{44,17},
{48,34},
{49,15},
{50,23},
{51,26},
{54,20},
{57,15},
{58,22},
{59,17},
{60,19},
{62,30},
{63,27},
{66,26},
{72,37},
{75,34},
{76,15},
{77,23},
{78,26},
{80,17},
{82,24},
{83,19},
{86,21},
{88,23},
{89,36},
{89,36},
{90,37},
{91,32},
{92,28},
{93,33},
{96,47},
{98,29},
{99,32},
{80,17},
{105,15},
{106,17},
{107,27},
{108,22},
{111,13},
{112,15},
{113,17},
{116,15},
{117,17},
{119,15},
{120,15},
{121,30},
{121,30},
{122,17},
{123,19},
{124,35},
{125,40},
{126,35},
{128,21},
{131,33},
{133,27},
{134,17},
{135,19},
{137,36},
{137,36},
{138,31},
{139,17},
{140,19},
{139,17},
{144,17},
{146,24},
{147,19},
{148,21},
{150,25},
{152,17},
{153,31},
{153,31},
{154,19},
{156,35},
{157,21},
};
Tcpos ZcTbl82534[]={
{422,40},
{1,35},
{2,21},
{4,29},
{5,34},
{5,34},
{6,19},
{8,35},
{9,21},
{11,35},
{12,21},
{15,19},
{-144,7},
};
Tc Y8iP[]="ARG.rawSize()";
Tcpos ZcTbl41830[]={
{115,20},
};
Tc YMnk[]="ARG.writeLead()";
Tcpos ZcTbl81798[]={
{569,5},
{2,5},
{3,7},
{2,5},
};
Tc Y5LR[]="E.BadValue.NEW__p2/2()";
Tcpos ZcTbl60593[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YO_6[]="E.BadValue.toString__p2/2()";
Tcpos ZcTbl56573[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y9VX[]="E.BadValue.writeTo__p2/4()";
Tcpos ZcTbl46171[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y4u_[]="E.BadValue.writeTo__p2/5()";
Tcpos ZcTbl56372[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y_Qs[]="E.DivideByZero.NEW__p3/3()";
Tcpos ZcTbl73471[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YNLE[]="E.DivideByZero.toString__p3/3()";
Tcpos ZcTbl69435[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YG80[]="E.DivideByZero.writeTo__p3/6()";
Tcpos ZcTbl44130[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YLzZ[]="E.DivideByZero.writeTo__p3/7()";
Tcpos ZcTbl54331[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y3yN[]="E.Exception.toString()";
Tcpos ZcTbl97135[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YgcH[]="E.Exception.writeTo()";
Tcpos ZcTbl49183[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YYT9[]="E.Exception.writeTo/1()";
Tcpos ZcTbl36491[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YwZj[]="E.Exit.NEW/1()";
Tcpos ZcTbl31890[]={
{171,5},
{1,14},
{2,16},
{4,20},
{4,24},
};
Tc Ywpu[]="E.Exit.toString__p1/1()";
Tcpos ZcTbl94689[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YTjU[]="E.Exit.writeTo/2()";
Tcpos ZcTbl92163[]={
{191,11},
{1,7},
{2,9},
{3,9},
{5,7},
{6,7},
{7,7},
{8,9},
{9,9},
};
Tc Y9aV[]="E.Exit.writeTo__p1/3()";
Tcpos ZcTbl42983[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y9Cv[]="E.IOError.NEW__p2/2()";
Tcpos ZcTbl48299[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yc7B[]="E.IOError.toString__p2/2()";
Tcpos ZcTbl32191[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y59h[]="E.IOError.writeTo__p2/4()";
Tcpos ZcTbl89685[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y0Jk[]="E.IOError.writeTo__p2/5()";
Tcpos ZcTbl99886[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y2NH[]="E.IllegalByte.NEW__p3/3()";
Tcpos ZcTbl45209[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YPGE[]="E.IllegalByte.toString__p3/3()";
Tcpos ZcTbl13917[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YALK[]="E.IllegalByte.writeTo__p3/6()";
Tcpos ZcTbl9948[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YFbI[]="E.IllegalByte.writeTo__p3/7()";
Tcpos ZcTbl20149[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Yp81[]="E.Init.NEW__p2/2()";
Tcpos ZcTbl53377[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yuz_[]="E.Init.NEW__p2/3()";
Tcpos ZcTbl63578[]={
{69,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YeMI[]="E.Init.toString__p2/2()";
Tcpos ZcTbl93453[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YMF2[]="E.Init.writeTo__p2/4()";
Tcpos ZcTbl96107[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YR5_[]="E.Init.writeTo__p2/5()";
Tcpos ZcTbl6308[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YbzA[]="E.Internal.NEW__p2/2()";
Tcpos ZcTbl78082[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YFnU[]="E.Internal.toString__p2/2()";
Tcpos ZcTbl79874[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YxLq[]="E.Internal.writeTo__p2/4()";
Tcpos ZcTbl412[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YCbo[]="E.Internal.writeTo__p2/5()";
Tcpos ZcTbl10613[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ycb9[]="E.KeyExists.NEW__p3/3()";
Tcpos ZcTbl85000[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YJyB[]="E.KeyExists.toString__p3/3()";
Tcpos ZcTbl4984[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y4SL[]="E.KeyExists.writeTo__p3/6()";
Tcpos ZcTbl14715[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y9iJ[]="E.KeyExists.writeTo__p3/7()";
Tcpos ZcTbl24916[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YAVe[]="E.KeyNotFound.NEW__p3/3()";
Tcpos ZcTbl29585[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YlfT[]="E.KeyNotFound.toString__p3/3()";
Tcpos ZcTbl67925[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Ygil[]="E.KeyNotFound.writeTo__p3/6()";
Tcpos ZcTbl43124[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YlJi[]="E.KeyNotFound.writeTo__p3/7()";
Tcpos ZcTbl53325[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YF6S[]="E.MemoryAccess.NEW__p2/2()";
Tcpos ZcTbl73580[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yh7q[]="E.MemoryAccess.toString__p2/2()";
Tcpos ZcTbl18292[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y4vu[]="E.MemoryAccess.writeTo__p2/4()";
Tcpos ZcTbl25958[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y_4w[]="E.MemoryAccess.writeTo__p2/5()";
Tcpos ZcTbl36159[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y1As[]="E.NilAccess.NEW__p2/2()";
Tcpos ZcTbl32086[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YkLW[]="E.NilAccess.toString__p2/2()";
Tcpos ZcTbl79110[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YcIS[]="E.NilAccess.writeTo__p2/4()";
Tcpos ZcTbl35088[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y7gV[]="E.NilAccess.writeTo__p2/5()";
Tcpos ZcTbl45289[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YobA[]="E.OutOfMemory.NEW/3()";
Tcpos ZcTbl80644[]={
{262,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Ys9t[]="E.OutOfMemory.toString__p2/2()";
Tcpos ZcTbl90571[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YoZS[]="E.OutOfMemory.writeTo__p2/4()";
Tcpos ZcTbl11217[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YtpQ[]="E.OutOfMemory.writeTo__p2/5()";
Tcpos ZcTbl21418[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y99g[]="E.OutOfRange.NEW__p3/3()";
Tcpos ZcTbl56381[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y6co[]="E.OutOfRange.toString__p3/3()";
Tcpos ZcTbl83985[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YqK0[]="E.OutOfRange.writeTo__p3/6()";
Tcpos ZcTbl52608[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ylj3[]="E.OutOfRange.writeTo__p3/7()";
Tcpos ZcTbl62809[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YR5m[]="E.WrongType.NEW/1()";
Tcpos ZcTbl87235[]={
{514,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YOoP[]="E.WrongType.toString__p2/2()";
Tcpos ZcTbl16768[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YlgI[]="E.WrongType.writeTo__p2/4()";
Tcpos ZcTbl86818[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YgQK[]="E.WrongType.writeTo__p2/5()";
Tcpos ZcTbl97019[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YEFs[]="E.unhandledException()";
Tcpos ZcTbl15718[]={
{609,23},
{0,23},
{0,23},
};
Tc YgcM[]="E.writeToStderr()";
Tcpos ZcTbl52386[]={
{629,5},
{1,5},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{2,5},
};
Tc YTMY[]="EditorConfig.NEW()";
Tcpos ZcTbl14774[]={
{779,3},
{1,5},
{2,11},
{3,11},
{4,19},
};
Tc YLWi[]="EditorConfig.close()";
Tcpos ZcTbl98266[]={
{594,9},
{1,5},
{2,5},
};
Tc Yjur[]="EditorConfig.delChar()";
Tcpos ZcTbl92863[]={
{555,9},
{1,5},
{2,17},
{3,7},
{4,9},
{5,12},
{6,18},
{7,13},
{8,9},
{10,9},
{11,17},
{13,12},
};
Tc YdpR[]="EditorConfig.find()";
Tcpos ZcTbl6661[]={
{429,9},
{1,16},
{2,16},
{3,20},
{4,20},
{6,20},
{8,5},
{9,11},
{10,11},
{11,15},
{12,15},
};
Tc YX43[]="EditorConfig.getSynColor()";
Tcpos ZcTbl74713[]={
{417,9},
{1,5},
{2,33},
{3,34},
{4,31},
{5,32},
{6,33},
{7,34},
{8,23},
};
Tc YM6u[]="EditorConfig.getWindowSize()";
Tcpos ZcTbl70635[]={
{744,9},
{1,4},
{4,5},
{5,7},
{6,16},
{8,14},
{10,13},
{11,13},
{12,14},
};
Tc YiHr[]="EditorConfig.insertChar()";
Tcpos ZcTbl37527[]={
{541,9},
{1,5},
{2,7},
{3,17},
{5,5},
{6,8},
{7,15},
};
Tc YRIX[]="EditorConfig.insertNL()";
Tcpos ZcTbl15699[]={
{524,9},
{1,5},
{2,7},
{4,17},
{5,7},
{6,7},
{7,15},
{9,15},
{11,7},
{13,8},
{14,9},
};
Tc YNwb[]="EditorConfig.insertRow()";
Tcpos ZcTbl35189[]={
{508,9},
{1,5},
{2,16},
{4,7},
{6,7},
{7,9},
{9,9},
{11,15},
{12,17},
};
Tc YnTk[]="EditorConfig.moveCursor()";
Tcpos ZcTbl15045[]={
{599,9},
{3,5},
{4,35},
{8,7},
{9,13},
{11,13},
{14,11},
{17,32},
{19,5},
{21,9},
{22,14},
{23,20},
{24,14},
{25,11},
{26,17},
{30,9},
{31,14},
{34,9},
{35,14},
{38,9},
{39,14},
{42,9},
{43,11},
{44,21},
{47,9},
{48,11},
{49,21},
{52,9},
{53,11},
{54,13},
{55,15},
{56,27},
{54,13},
{59,13},
{60,13},
{62,13},
{66,9},
{67,11},
{68,19},
{69,21},
{72,9},
{73,17},
{74,11},
{77,9},
{78,11},
{79,13},
{80,16},
{78,11},
{84,9},
{85,17},
{86,11},
{87,13},
{88,19},
{90,13},
{93,17},
{94,11},
{97,24},
{99,9},
{100,11},
{104,9},
{105,11},
{104,9},
{108,24},
{110,9},
{111,11},
{115,9},
{116,11},
{115,9},
{119,20},
{120,9},
{121,11},
{124,9},
{125,11},
{124,9},
{127,9},
{128,11},
{127,9},
{131,9},
{132,15},
{135,13},
{138,33},
{139,24},
{140,5},
{141,11},
};
Tc Y3iP[]="EditorConfig.open()";
Tcpos ZcTbl63278[]={
{573,9},
{1,5},
{1,5},
{2,22},
{6,7},
{7,9},
{9,19},
{10,32},
{11,9},
{12,11},
{11,9},
{14,20},
{15,9},
{16,9},
{4,7},
};
Tc Y3mJ[]="EditorConfig.reset()";
Tcpos ZcTbl24179[]={
{760,9},
{1,13},
{2,13},
{3,12},
{4,11},
{5,9},
{6,16},
{7,14},
{8,14},
{9,15},
{10,16},
{11,9},
{12,13},
{13,11},
{14,9},
{15,9},
{16,11},
};
Tc YZoA[]="EditorConfig.rowsToStr()";
Tcpos ZcTbl81219[]={
{445,9},
{1,18},
{2,5},
{3,11},
{2,5},
{5,12},
};
Tc YSK2[]="EditorConfig.save()";
Tcpos ZcTbl82575[]={
{453,9},
{1,5},
{2,23},
{4,7},
{4,7},
{5,24},
{9,9},
{10,11},
{12,11},
{13,11},
{14,11},
{15,28},
{14,11},
{17,22},
{18,11},
{7,9},
{22,17},
{23,7},
{24,9},
{26,9},
{29,5},
};
Tc YK_C[]="EditorConfig.scroll()";
Tcpos ZcTbl77103[]={
{485,9},
{1,9},
{2,5},
{3,11},
{6,5},
{7,15},
{10,5},
{11,15},
{14,5},
{15,15},
{18,5},
{19,15},
};
Tc YXEW[]="EditorConfig.selectSyn()";
Tcpos ZcTbl47110[]={
{400,9},
{1,11},
{2,5},
{3,7},
{6,5},
{7,7},
{8,9},
{9,17},
{10,11},
{11,11},
{7,7},
{6,5},
};
Tc YLfe[]="EditorConfig.setStatmsg()";
Tcpos ZcTbl77835[]={
{388,9},
{1,16},
{2,14},
};
Tc YVSL[]="EditorConfig.shiftRowLeft()";
Tcpos ZcTbl19937[]={
{551,9},
{1,5},
};
Tc YXnE[]="EditorConfig.updateSynAllRows()";
Tcpos ZcTbl12969[]={
{393,9},
{1,5},
{2,13},
{3,7},
{1,5},
};
Tc Y1IG[]="EditorSyn.NEW()";
Tcpos ZcTbl82619[]={
{126,3},
{1,9},
{2,16},
{3,12},
{4,20},
{5,15},
};
Tc YegA[]="Erow.NEW()";
Tcpos ZcTbl33010[]={
{359,3},
{1,10},
{2,9},
{3,11},
{4,9},
{5,13},
{6,10},
};
Tc Y4rW[]="Erow.appendStr()";
Tcpos ZcTbl33249[]={
{245,9},
{1,10},
{2,5},
};
Tc YL2R[]="Erow.back()";
Tcpos ZcTbl56421[]={
{212,9},
{1,10},
{2,5},
};
Tc YG9f[]="Erow.delChar()";
Tcpos ZcTbl87451[]={
{217,9},
{1,5},
{2,20},
{3,7},
{4,13},
{6,11},
{7,12},
{9,5},
};
Tc YrH_[]="Erow.insertChar()";
Tcpos ZcTbl59651[]={
{178,9},
{1,14},
{2,5},
{3,12},
{5,5},
{6,10},
{9,18},
{10,5},
{11,11},
{13,9},
{14,9},
{16,10},
{17,5},
};
Tc YMaL[]="Erow.preshiftl()";
Tcpos ZcTbl20941[]={
{203,9},
{1,18},
{2,5},
{3,11},
{5,10},
{6,5},
};
Tc YEP0[]="Erow.rx2cx()";
Tcpos ZcTbl33623[]={
{229,9},
{1,15},
{2,14},
{3,5},
{4,7},
{5,13},
{7,10},
{9,7},
{10,16},
{3,5},
{13,12},
};
Tc YQuU[]="Erow.shiftl()";
Tcpos ZcTbl90810[]={
{198,9},
{1,10},
{2,5},
};
Tc YxWc[]="Erow.updateRow()";
Tcpos ZcTbl90139[]={
{164,9},
{1,13},
{2,5},
{3,7},
{4,9},
{5,19},
{4,9},
{8,17},
{2,5},
{11,5},
};
Tc YHhk[]="Erow.updateSyntax()";
Tcpos ZcTbl87078[]={
{250,9},
{1,5},
{2,11},
{3,7},
{4,9},
{3,7},
{6,7},
{9,13},
{11,23},
{13,9},
{15,17},
{16,17},
{18,28},
{20,5},
{21,16},
{24,4},
{27,11},
{29,7},
{31,7},
{32,9},
{33,18},
{34,11},
{35,13},
{34,11},
{41,7},
{42,9},
{43,18},
{44,11},
{45,13},
{46,15},
{49,11},
{50,19},
{52,12},
{53,16},
{56,11},
{57,19},
{58,20},
{59,14},
{65,7},
{66,9},
{68,18},
{69,12},
{70,16},
{75,7},
{76,23},
{77,9},
{79,22},
{80,30},
{81,23},
{82,11},
{83,16},
{84,15},
{86,11},
{88,26},
{89,20},
{90,13},
{91,15},
{90,13},
{93,15},
{94,20},
{77,9},
{98,9},
{99,16},
{104,12},
{105,8},
{20,5},
};
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
};
Tc YEgn[]="IO.File.close()";
Tcpos ZcTbl15755[]={
{582,11},
{1,20},
{2,7},
{6,4},
{9,4},
{12,15},
{15,14},
};
Tc YskO[]="IO.File.flush()";
Tcpos ZcTbl60567[]={
{564,11},
{1,20},
{2,7},
{4,4},
{12,14},
};
Tc Yxlj[]="IO.File.print__p1/15()";
Tcpos ZcTbl82618[]={
{230,11},
{1,15},
};
Tc YJ7z[]="IO.File.print__p1/8()";
Tcpos ZcTbl66188[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc YHIM[]="IO.File.readAllLines()";
Tcpos ZcTbl87025[]={
{420,11},
{1,29},
{2,7},
{3,24},
{4,9},
{7,9},
{2,7},
{9,14},
};
Tc Y5P_[]="IO.File.readByte()";
Tcpos ZcTbl16053[]={
{253,11},
{1,7},
{2,9},
{6,4},
{17,14},
};
Tc YDzF[]="IO.File.readLine()";
Tcpos ZcTbl72841[]={
{374,11},
{1,16},
{2,7},
{3,16},
{5,24},
{7,7},
{8,9},
{10,11},
{12,11},
{13,13},
{14,13},
{12,11},
{16,11},
{18,11},
{7,7},
{20,16},
};
Tc Yj_J[]="IO.File.write/8()";
Tcpos ZcTbl94823[]={
{483,11},
{3,9},
{4,11},
{6,4},
{31,14},
};
Tc YGQL[]="IO.File.write__p1/9()";
Tcpos ZcTbl59819[]={
{129,11},
{1,15},
};
Tc YrJP[]="IO.StringWriter.ToString()";
Tcpos ZcTbl64531[]={
{1431,11},
{3,9},
{4,13},
{6,4},
{17,14},
};
Tc YYk7[]="IO.StringWriter.print__p1/8()";
Tcpos ZcTbl26760[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc YCbR[]="IO.StringWriter.write/8()";
Tcpos ZcTbl89987[]={
{1359,11},
{1,37},
{3,9},
{4,14},
{5,11},
{6,17},
{8,11},
{10,13},
{12,11},
{13,17},
{24,14},
};
Tc Y35R[]="IO.StringWriter.writeByte/1()";
Tcpos ZcTbl38552[]={
{1388,11},
{2,9},
{3,14},
{4,26},
{6,11},
{8,21},
{9,19},
{19,14},
};
Tc YzQB[]="IO.StringWriter.write__p1/9()";
Tcpos ZcTbl72007[]={
{129,11},
{1,15},
};
Tc YTE3[]="IO.fileReader()";
Tcpos ZcTbl99838[]={
{926,4},
{5,9},
{6,4},
{16,12},
};
Tc Y5X7[]="IO.fileWriter()";
Tcpos ZcTbl81580[]={
{956,4},
{8,9},
{9,4},
{19,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1337,4},
{9,12},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1227,37},
{1,4},
{13,12},
};
Tc Y_pS[]="IO.write()";
Tcpos ZcTbl84870[]={
{1168,4},
{13,12},
};
Tc YVvh[]="LOG";
Tcpos ZcTbl83326[]={
{21,14},
{2,14},
{50,20},
};
Tc YFIR[]="LOG.flush()";
Tcpos ZcTbl56555[]={
{226,5},
{1,5},
{2,7},
{4,15},
};
Tc Y8w5[]="LOG.reportStack()";
Tcpos ZcTbl84899[]={
{213,7},
{1,7},
{2,18},
{2,7},
{2,18},
{3,9},
{2,7},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{1282,3},
{1,3},
{2,5},
{5,3},
{7,3},
{8,5},
{11,3},
{12,5},
{13,5},
{11,3},
{16,10},
};
Tc YQE_[]="TIME.Values.NEW()";
Tcpos ZcTbl5342[]={
{50,5},
{1,7},
};
Tc Y0DO[]="TIME.Values.NEW/2()";
Tcpos ZcTbl32939[]={
{64,5},
{2,4},
{23,13},
};
Tc YHWY[]="TIME.Values.ToString()";
Tcpos ZcTbl34818[]={
{111,11},
{1,27},
{2,7},
{3,7},
{4,7},
{5,7},
{6,7},
{7,7},
{8,7},
{9,7},
{10,7},
{11,7},
{12,7},
{13,16},
};
Tc YLwM[]="TIME.current()";
Tcpos ZcTbl50841[]={
{22,4},
{5,12},
};
Tc Ym1t[]="Z.Pos.ToString()";
Tcpos ZcTbl18187[]={
{83,11},
{1,27},
{2,7},
{3,9},
{5,9},
{7,7},
{8,7},
{9,7},
{10,7},
{11,16},
};
Tc YrXP[]="clrscr()";
Tcpos ZcTbl94330[]={
{898,3},
{1,3},
};
Tc Yy3n[]="cx2rx()";
Tcpos ZcTbl72184[]={
{94,12},
{1,11},
{2,3},
{3,5},
{6,5},
{7,10},
{9,7},
{10,6},
{2,3},
{12,10},
};
Tc YXBg[]="die()";
Tcpos ZcTbl56087[]={
{17,3},
};
Tc Y8aB[]="drawMsgBar()";
Tcpos ZcTbl86795[]={
{1129,15},
{1,6},
{2,29},
{3,3},
{4,8},
{6,10},
};
Tc YCgG[]="drawRows()";
Tcpos ZcTbl31458[]={
{1037,15},
{1,3},
{2,15},
{3,5},
{4,7},
{5,43},
{6,44},
{7,9},
{8,14},
{9,18},
{11,9},
{12,14},
{13,18},
{11,9},
{15,12},
{17,12},
{20,42},
{21,20},
{22,7},
{23,13},
{25,7},
{26,13},
{29,15},
{30,21},
{31,7},
{33,4},
{36,15},
{37,9},
{38,11},
{39,16},
{40,20},
{42,14},
{44,26},
{45,11},
{46,20},
{47,16},
{49,14},
{51,10},
{31,7},
{53,10},
{56,8},
{57,8},
{1,3},
{59,10},
};
Tc Y5xc[]="drawStatusBar()";
Tcpos ZcTbl25708[]={
{1100,15},
{2,138},
{4,124},
{5,26},
{7,20},
{8,3},
{9,13},
{12,6},
{14,6},
{16,3},
{17,5},
{18,10},
{21,8},
{16,3},
{23,6},
{24,6},
{25,10},
};
Tc YdWL[]="enableRawMode()";
Tcpos ZcTbl25411[]={
{878,4},
};
Tc YInF[]="findCb()";
Tcpos ZcTbl33763[]={
{794,21},
{2,3},
{3,28},
{4,9},
{8,4},
{11,7},
{13,3},
{14,5},
{15,10},
{16,9},
{17,5},
{18,11},
{19,9},
{20,11},
{21,9},
{22,11},
{23,5},
{24,7},
{25,11},
{26,7},
{28,7},
{29,12},
{30,11},
{31,7},
{34,10},
{35,9},
{38,3},
{39,9},
{42,17},
{44,3},
{45,13},
{46,5},
{47,15},
{48,20},
{49,15},
{52,17},
{53,26},
{55,5},
{56,12},
{57,13},
{58,13},
{59,17},
{61,17},
{62,11},
{64,7},
{65,9},
{66,19},
{64,7},
{44,3},
};
Tc YetL[]="getCursorPosition()";
Tcpos ZcTbl15576[]={
{43,3},
{1,12},
{4,14},
{5,3},
{6,23},
{7,5},
{10,7},
{11,5},
{5,3},
{16,3},
{17,12},
{20,15},
{21,15},
{22,15},
{23,38},
{25,3},
{26,22},
{27,5},
{28,10},
{29,14},
{32,6},
{25,3},
{35,3},
{36,22},
{37,5},
{38,10},
{39,14},
{35,3},
{44,8},
{45,8},
{47,10},
};
Tc YA77[]="gotoxy()";
Tcpos ZcTbl56063[]={
{903,3},
};
Tc YCn_[]="gotoxy_s()";
Tcpos ZcTbl14477[]={
{907,10},
};
Tc YTky[]="issep()";
Tcpos ZcTbl23829[]={
{111,4},
{3,5},
{5,11},
};
Tc YEwQ[]="next()";
Tcpos ZcTbl79128[]={
{153,12},
};
Tc YQ8H[]="processKeypress()";
Tcpos ZcTbl40266[]={
{917,4},
{3,5},
{4,3},
{5,5},
{6,7},
{7,14},
{9,7},
{10,12},
{12,11},
{13,20},
{15,5},
{16,7},
{17,7},
{20,5},
{21,7},
{22,14},
{24,7},
{25,7},
{28,11},
{29,5},
{30,7},
{31,14},
{33,7},
{36,37},
{37,13},
{38,5},
{40,9},
{43,9},
{46,21},
{47,9},
{48,11},
{50,22},
{51,9},
{52,17},
{54,11},
{58,9},
{61,17},
{63,27},
{65,9},
{66,17},
{72,9},
{75,9},
{79,9},
{80,17},
{81,17},
{82,17},
{83,11},
{83,37},
{85,9},
{86,22},
{87,11},
{85,9},
{94,9},
{97,9},
{98,11},
{99,13},
{98,11},
{110,9},
{111,11},
{113,11},
};
Tc Yown[]="prompt()";
Tcpos ZcTbl87455[]={
{1161,16},
{1,3},
{2,5},
{3,5},
{6,4},
{9,7},
{11,5},
{12,7},
{13,13},
{15,13},
{19,5},
{20,7},
{21,7},
{22,9},
{24,14},
{27,5},
{28,7},
{29,9},
{30,9},
{31,11},
{35,13},
{36,11},
{39,5},
{40,7},
{1,3},
{43,10},
};
Tc YRKs[]="readKey()";
Tcpos ZcTbl79390[]={
{1209,4},
{4,4},
{8,4},
{11,3},
{12,5},
{13,7},
{11,3},
{17,3},
{18,4},
{21,5},
{22,15},
{26,5},
{27,15},
{30,5},
{31,7},
{32,9},
{33,19},
{35,9},
{36,24},
{37,11},
{38,34},
{39,34},
{40,34},
{41,34},
{42,34},
{43,34},
{44,34},
{48,22},
{49,9},
{50,29},
{51,29},
{52,29},
{53,29},
{54,29},
{55,29},
{58,13},
{59,20},
{60,7},
{61,27},
{62,27},
{66,13},
{68,12},
};
Tc YClS[]="refreshScreen()";
Tcpos ZcTbl56800[]={
{1139,3},
{2,3},
{4,15},
{6,6},
{7,6},
{9,6},
{10,6},
{11,6},
{13,6},
{14,6},
{16,4},
};
Tc YR5F[]="tcall()";
Tcpos ZcTbl56509[]={
{38,16},
{1,3},
};
Tc YcA1[]="tcalls()";
Tcpos ZcTbl72424[]={
{21,16},
{1,3},
{2,13},
{3,5},
{4,7},
{5,13},
{7,13},
{9,8},
{3,5},
{12,7},
{13,10},
};
Tc Y14F[]="warnUnsaved()";
Tcpos ZcTbl12051[]={
{911,3},
};
Tcode ZcodeTable[]={
{0,Ya_D,Yaa,ZcTbl0},
{412,Y6mX,YxLq,ZcTbl412},
{1872,Yusm,YNFk,ZcTbl1872},
{3273,Ye5D,Y_VO,ZcTbl3273},
{4984,Y6mX,YJyB,ZcTbl4984},
{5270,Ya_D,Y9QD,ZcTbl5270},
{5342,YTAg,YQE_,ZcTbl5342},
{6308,Y6mX,YR5_,ZcTbl6308},
{6661,Ya_D,YdpR,ZcTbl6661},
{7452,Yusm,Ys1a,ZcTbl7452},
{9948,Y6mX,YALK,ZcTbl9948},
{10613,Y6mX,YCbo,ZcTbl10613},
{11217,Y6mX,YoZS,ZcTbl11217},
{12051,Ya_D,Y14F,ZcTbl12051},
{12969,Ya_D,YXnE,ZcTbl12969},
{13917,Y6mX,YPGE,ZcTbl13917},
{14477,Ya_D,YCn_,ZcTbl14477},
{14715,Y6mX,Y4SL,ZcTbl14715},
{14774,Ya_D,YTMY,ZcTbl14774},
{15045,Ya_D,YnTk,ZcTbl15045},
{15576,Ya_D,YetL,ZcTbl15576},
{15699,Ya_D,YRIX,ZcTbl15699},
{15718,Y6mX,YEFs,ZcTbl15718},
{15755,Yusm,YEgn,ZcTbl15755},
{16053,Yusm,Y5P_,ZcTbl16053},
{16350,Ye5D,Ygzb,ZcTbl16350},
{16768,Y6mX,YOoP,ZcTbl16768},
{18187,YHVP,Ym1t,ZcTbl18187},
{18292,Y6mX,Yh7q,ZcTbl18292},
{19937,Ya_D,YVSL,ZcTbl19937},
{20149,Y6mX,YFbI,ZcTbl20149},
{20941,Ya_D,YMaL,ZcTbl20941},
{21418,Y6mX,YtpQ,ZcTbl21418},
{23829,Ya_D,YTky,ZcTbl23829},
{24179,Ya_D,Y3mJ,ZcTbl24179},
{24916,Y6mX,Y9iJ,ZcTbl24916},
{25227,Ye5D,YXkl,ZcTbl25227},
{25411,Ya_D,YdWL,ZcTbl25411},
{25708,Ya_D,Y5xc,ZcTbl25708},
{25958,Y6mX,Y4vu,ZcTbl25958},
{26760,Yusm,YYk7,ZcTbl26760},
{29560,Ye5D,YzK9,ZcTbl29560},
{29585,Y6mX,YAVe,ZcTbl29585},
{31458,Ya_D,YCgG,ZcTbl31458},
{31890,Y6mX,YwZj,ZcTbl31890},
{32086,Y6mX,Y1As,ZcTbl32086},
{32191,Y6mX,Yc7B,ZcTbl32191},
{32939,YTAg,Y0DO,ZcTbl32939},
{33010,Ya_D,YegA,ZcTbl33010},
{33249,Ya_D,Y4rW,ZcTbl33249},
{33623,Ya_D,YEP0,ZcTbl33623},
{33763,Ya_D,YInF,ZcTbl33763},
{34818,YTAg,YHWY,ZcTbl34818},
{35088,Y6mX,YcIS,ZcTbl35088},
{35189,Ya_D,YNwb,ZcTbl35189},
{36159,Y6mX,Y_4w,ZcTbl36159},
{36491,Y6mX,YYT9,ZcTbl36491},
{37527,Ya_D,YiHr,ZcTbl37527},
{38552,Yusm,Y35R,ZcTbl38552},
{38911,Ye5D,YM2k,ZcTbl38911},
{40266,Ya_D,YQ8H,ZcTbl40266},
{41830,Ye5D,Y8iP,ZcTbl41830},
{42983,Y6mX,Y9aV,ZcTbl42983},
{43000,Ye5D,YEFE,ZcTbl43000},
{43124,Y6mX,Ygil,ZcTbl43124},
{44130,Y6mX,YG80,ZcTbl44130},
{45209,Y6mX,Y2NH,ZcTbl45209},
{45289,Y6mX,Y7gV,ZcTbl45289},
{46171,Y6mX,Y9VX,ZcTbl46171},
{46761,Yusm,YN2v,ZcTbl46761},
{47110,Ya_D,YXEW,ZcTbl47110},
{48299,Y6mX,Y9Cv,ZcTbl48299},
{49183,Y6mX,YgcH,ZcTbl49183},
{50841,YTAg,YLwM,ZcTbl50841},
{52386,Y6mX,YgcM,ZcTbl52386},
{52608,Y6mX,YqK0,ZcTbl52608},
{53325,Y6mX,YlJi,ZcTbl53325},
{53377,Y6mX,Yp81,ZcTbl53377},
{54331,Y6mX,YLzZ,ZcTbl54331},
{56063,Ya_D,YA77,ZcTbl56063},
{56087,Ya_D,YXBg,ZcTbl56087},
{56372,Y6mX,Y4u_,ZcTbl56372},
{56381,Y6mX,Y99g,ZcTbl56381},
{56421,Ya_D,YL2R,ZcTbl56421},
{56509,Ya_D,YR5F,ZcTbl56509},
{56555,YQAh,YFIR,ZcTbl56555},
{56573,Y6mX,YO_6,ZcTbl56573},
{56800,Ya_D,YClS,ZcTbl56800},
{59651,Ya_D,YrH_,ZcTbl59651},
{59819,Yusm,YGQL,ZcTbl59819},
{60567,Yusm,YskO,ZcTbl60567},
{60593,Y6mX,Y5LR,ZcTbl60593},
{61284,Ye5D,Y2cg,ZcTbl61284},
{62809,Y6mX,Ylj3,ZcTbl62809},
{63278,Ya_D,Y3iP,ZcTbl63278},
{63578,Y6mX,Yuz_,ZcTbl63578},
{64478,Ye5D,YRbs,ZcTbl64478},
{64531,Yusm,YrJP,ZcTbl64531},
{66188,Yusm,YJ7z,ZcTbl66188},
{66501,Ye5D,YPPv,ZcTbl66501},
{67925,Y6mX,YlfT,ZcTbl67925},
{69435,Y6mX,YNLE,ZcTbl69435},
{70635,Ya_D,YM6u,ZcTbl70635},
{72007,Yusm,YzQB,ZcTbl72007},
{72184,Ya_D,Yy3n,ZcTbl72184},
{72424,Ya_D,YcA1,ZcTbl72424},
{72841,Yusm,YDzF,ZcTbl72841},
{73471,Y6mX,Y_Qs,ZcTbl73471},
{73580,Y6mX,YF6S,ZcTbl73580},
{74713,Ya_D,YX43,ZcTbl74713},
{75697,Ye5D,YgDO,ZcTbl75697},
{76644,Ye5D,YImf,ZcTbl76644},
{77103,Ya_D,YK_C,ZcTbl77103},
{77835,Ya_D,YLfe,ZcTbl77835},
{78082,Y6mX,YbzA,ZcTbl78082},
{79110,Y6mX,YkLW,ZcTbl79110},
{79128,Ya_D,YEwQ,ZcTbl79128},
{79390,Ya_D,YRKs,ZcTbl79390},
{79874,Y6mX,YFnU,ZcTbl79874},
{80644,Y6mX,YobA,ZcTbl80644},
{81219,Ya_D,YZoA,ZcTbl81219},
{81580,Yusm,Y5X7,ZcTbl81580},
{81798,Ye5D,YMnk,ZcTbl81798},
{82533,Ye5D,Yh2v,ZcTbl82533},
{82534,Ye5D,Yh2v,ZcTbl82534},
{82575,Ya_D,YSK2,ZcTbl82575},
{82618,Yusm,Yxlj,ZcTbl82618},
{82619,Ya_D,Y1IG,ZcTbl82619},
{83326,YQAh,YVvh,ZcTbl83326},
{83985,Y6mX,Y6co,ZcTbl83985},
{84870,Yusm,Y_pS,ZcTbl84870},
{84899,YQAh,Y8w5,ZcTbl84899},
{85000,Y6mX,Ycb9,ZcTbl85000},
{85295,Ye5D,Yza4,ZcTbl85295},
{86206,Ye5D,YZNA,ZcTbl86206},
{86795,Ya_D,Y8aB,ZcTbl86795},
{86818,Y6mX,YlgI,ZcTbl86818},
{87025,Yusm,YHIM,ZcTbl87025},
{87078,Ya_D,YHhk,ZcTbl87078},
{87235,Y6mX,YR5m,ZcTbl87235},
{87451,Ya_D,YG9f,ZcTbl87451},
{87455,Ya_D,Yown,ZcTbl87455},
{89685,Y6mX,Y59h,ZcTbl89685},
{89987,Yusm,YCbR,ZcTbl89987},
{90139,Ya_D,YxWc,ZcTbl90139},
{90571,Y6mX,Ys9t,ZcTbl90571},
{90810,Ya_D,YQuU,ZcTbl90810},
{92163,Y6mX,YTjU,ZcTbl92163},
{92863,Ya_D,Yjur,ZcTbl92863},
{93453,Y6mX,YeMI,ZcTbl93453},
{94330,Ya_D,YrXP,ZcTbl94330},
{94689,Y6mX,Ywpu,ZcTbl94689},
{94823,Yusm,Yj_J,ZcTbl94823},
{96107,Y6mX,YMF2,ZcTbl96107},
{97019,Y6mX,YgQK,ZcTbl97019},
{97135,Y6mX,Y3yN,ZcTbl97135},
{98266,Ya_D,YLWi,ZcTbl98266},
{99838,Yusm,YTE3,ZcTbl99838},
{99886,Y6mX,Y0Jk,ZcTbl99886},
};

#ifdef SIGSEGV
void Zdeadly(int nr) {
 ZthrowDeadly(nr);
}
#endif

void ZthreadGC() {
}
Ti ZstringSizePtr(Tc *s, Tc **dp) {
 Tc *p;
 Ti len;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {  /* be quick for short string */
  *dp = p + 1;
  return *p;
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 *dp = p + 1;
 return (len << 7) + *p;
}

void ZthrowCstringNil(char *text) {
 YvdV(NULL, Zstr(text));
}

void ZthrowThisNil() {
 YvdV(NULL, Zstr("THIS is NIL"));
}

void ZthrowCstringInit(char *text) {
 Y3w6(Zstr(text));
}

void ZthrowOutOfMemory(Ti size) {
 Y1KV(size);
}

void ZthrowCstringOutOfRange(Ti i, char *text) {
 Y6NT(i, Zstr(text));
}

void ZthrowCstringBadValue(char *msg) {
 Yaez(Zstr(msg));
}

void ZthrowDeadly(int nr) {
 YE93((Ti)nr);
}

void ZthrowInternal(Tc *text) {
 YUSH(NULL, text);
}

Tc *ZintAsString(Ti n) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  Tc *p = Za(ZOH_OFF + 3);
  p[ZOH_OFF] = 1;
  p[ZOH_OFF + 1] = n;
  p[ZOH_OFF + 2] = 0;
  return p;
 }
 if (n <= 0x7ff) {
  Tc *p = Za(ZOH_OFF + 4);
  p[ZOH_OFF] = 2;
  p[ZOH_OFF + 1] = 0xc0 + ((unsigned)n >> 6);
  p[ZOH_OFF + 2] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 3] = 0;
  return p;
 }
 if (n <= 0xffff) {
  Tc *p = Za(ZOH_OFF + 5);
  p[ZOH_OFF] = 3;
  p[ZOH_OFF + 1] = 0xe0 + ((unsigned)n >> 12);
  p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  p[ZOH_OFF + 3] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 4] = 0;
  return p;
 }
 Tc *p = Za(ZOH_OFF + 6);
 p[ZOH_OFF] = 4;
 p[ZOH_OFF + 1] = 0xf0 + ((unsigned)n >> 18);
 p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 p[ZOH_OFF + 3] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 p[ZOH_OFF + 4] = 0x80 + (n & 0xef);
 p[ZOH_OFF + 5] = 0;
 return p;
}

int Zchar2stringBuf(Ti n, Tc *buf) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  buf[0] = n;
  buf[1] = 0;
  return 1;
 }
 if (n <= 0x7ff) {
  buf[0] = 0xc0 + ((unsigned)n >> 6);
  buf[1] = 0x80 + (n & 0x3f);
  buf[2] = 0;
  return 2;
 }
 if (n <= 0xffff) {
  buf[0] = 0xe0 + ((unsigned)n >> 12);
  buf[1] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  buf[2] = 0x80 + (n & 0x3f);
  buf[3] = 0;
  return 3;
 }
 buf[0] = 0xf0 + ((unsigned)n >> 18);
 buf[1] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 buf[2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 buf[3] = 0x80 + (n & 0xef);
 buf[4] = 0;
 return 4;
}

/* concat string */
Tc *ZcS(Tc *l, Tc *ri) {
 Tc *l_p;
 Ti l_len;
 Tc *r_p;
 Ti r_len;
 Ti len;
 Tc *pp;
 Tc *r;
 if (l == NULL) {l_len = 3; l_p = (Tc*)"NIL";}
 else l_len = ZstringSizePtr(l, &l_p);
 if (ri == NULL) {r_len = 3; r_p = (Tc*)"NIL";}
 else r_len = ZstringSizePtr(ri, &r_p);
 len = l_len + r_len;
 r = ZnewStringInit(len, &pp);
 memmove(pp, l_p, l_len);
 memmove(pp + l_len, r_p, r_len);
 return r;
}

/* concat string */
Tc *ZcS3(Tc *s1, Tc *s2, Tc *s3) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 len = len1 + len2 + len3;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 return r;
}

/* concat string */
Tc *ZcS5(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Tc *p4;
 Ti len4;
 Tc *p5;
 Ti len5;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 if (s4 == NULL) {len4 = 3; p4 = (Tc*)"NIL";}
 else len4 = ZstringSizePtr(s4, &p4);
 if (s5 == (Tc*)1) len5 = 0;
 else if (s5 == NULL) {len5 = 3; p5 = (Tc*)"NIL";}
 else len5 = ZstringSizePtr(s5, &p5);
 len = len1 + len2 + len3 + len4 + len5;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 memmove(pp + len1 + len2 + len3, p4, len4);
 if (s5 != (Tc*)1) memmove(pp + len1 + len2 + len3 + len4, p5, len5);
 return r;
}

/* concat string */
Tc *ZcS8(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5, Tc *s6, Tc *s7, Tc *s8) {
 Tc *p[8];
 Ti len[8];
 Ti totlen = 0;
 Tc *pp;
 Tc *r;
 int i;
 if (s1 == NULL) {len[0] = 3; p[0] = (Tc*)"NIL";}
 else len[0] = ZstringSizePtr(s1, &p[0]);
 if (s2 == NULL) {len[1] = 3; p[1] = (Tc*)"NIL";}
 else len[1] = ZstringSizePtr(s2, &p[1]);
 if (s3 == NULL) {len[2] = 3; p[2] = (Tc*)"NIL";}
 else len[2] = ZstringSizePtr(s3, &p[2]);
 if (s4 == NULL) {len[3] = 3; p[3] = (Tc*)"NIL";}
 else len[3] = ZstringSizePtr(s4, &p[3]);
 if (s5 == NULL) {len[4] = 3; p[4] = (Tc*)"NIL";}
 else len[4] = ZstringSizePtr(s5, &p[4]);
 if (s6 == NULL) {len[5] = 3; p[5] = (Tc*)"NIL";}
 else len[5] = ZstringSizePtr(s6, &p[5]);
 if (s7 == (Tc*)1) len[6] = 0;
 else if (s7 == NULL) {len[6] = 3; p[6] = (Tc*)"NIL";}
 else len[6] = ZstringSizePtr(s7, &p[6]);
 if (s8 == (Tc*)1) len[7] = 0;
 else if (s8 == NULL) {len[7] = 3; p[7] = (Tc*)"NIL";}
 else len[7] = ZstringSizePtr(s8, &p[7]);
 for (i = 0; i < 8; ++i) totlen += len[i];
 r = ZnewStringInit(totlen, &pp);
 totlen = 0;
 for (i = 0; i < 8; ++i) {
  memmove(pp + totlen, p[i], len[i]);
  totlen += len[i];
 }
 return r;
}

/* concat string */
Tc *ZcS12(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5, Tc *s6, Tc *s7, Tc *s8, Tc *s9, Tc *s10, Tc *s11, Tc *s12) {
 Tc *p[12];
 Ti len[12];
 Ti totlen = 0;
 Tc *pp;
 Tc *r;
 int i;
 if (s1 == NULL) {len[0] = 3; p[0] = (Tc*)"NIL";}
 else len[0] = ZstringSizePtr(s1, &p[0]);
 if (s2 == NULL) {len[1] = 3; p[1] = (Tc*)"NIL";}
 else len[1] = ZstringSizePtr(s2, &p[1]);
 if (s3 == NULL) {len[2] = 3; p[2] = (Tc*)"NIL";}
 else len[2] = ZstringSizePtr(s3, &p[2]);
 if (s4 == NULL) {len[3] = 3; p[3] = (Tc*)"NIL";}
 else len[3] = ZstringSizePtr(s4, &p[3]);
 if (s5 == NULL) {len[4] = 3; p[4] = (Tc*)"NIL";}
 else len[4] = ZstringSizePtr(s5, &p[4]);
 if (s6 == NULL) {len[5] = 3; p[5] = (Tc*)"NIL";}
 else len[5] = ZstringSizePtr(s6, &p[5]);
 if (s7 == NULL) {len[6] = 3; p[6] = (Tc*)"NIL";}
 else len[6] = ZstringSizePtr(s7, &p[6]);
 if (s8 == NULL) {len[7] = 3; p[7] = (Tc*)"NIL";}
 else len[7] = ZstringSizePtr(s8, &p[7]);
 if (s9 == NULL) {len[8] = 3; p[8] = (Tc*)"NIL";}
 else len[8] = ZstringSizePtr(s9, &p[8]);
 if (s10 == (Tc*)1) len[9] = 0;
 else if (s10 == NULL) {len[9] = 3; p[9] = (Tc*)"NIL";}
 else len[9] = ZstringSizePtr(s10, &p[9]);
 if (s11 == (Tc*)1) len[10] = 0;
 else if (s11 == NULL) {len[10] = 3; p[10] = (Tc*)"NIL";}
 else len[10] = ZstringSizePtr(s11, &p[10]);
 if (s12 == (Tc*)1) len[11] = 0;
 else if (s12 == NULL) {len[11] = 3; p[11] = (Tc*)"NIL";}
 else len[11] = ZstringSizePtr(s12, &p[11]);
 for (i = 0; i < 12; ++i) totlen += len[i];
 r = ZnewStringInit(totlen, &pp);
 totlen = 0;
 for (i = 0; i < 12; ++i) {
  memmove(pp + totlen, p[i], len[i]);
  totlen += len[i];
 }
 return r;
}

Tr Zao(void *ptr, Tc **table, Ti type) {
 Tr tr;
 tr.ptr = ptr;
 tr.table = table;
 tr.type = type;
 return tr;
}

/* fill not-allocated object reference */
Tr *Znao(Tr *p, void *ptr, Tc **table, Ti type) {
 p->ptr = ptr;
 p->table = table;
 p->type = type;
 return p;
}

Tr ZconvertZioref(Tr orig, Tc ***table, int type, int maxType, Ti pos) {
 Tr p;
 if (orig.ptr == NULL) p.ptr = NULL;
 else {
  if (orig.type < type || orig.type >= maxType) YTuG(pos);
  p.ptr = orig.ptr;
  p.type = orig.type - type;
  p.table = table[p.type];
 }
 return p;
}

void *Zio(int type, Ti pos, Tr *p) {
 void *r;
 if (p == NULL || p->ptr == NULL) r = NULL;
 else {
  if (p->type != type) YTuG(pos);
  r = p->ptr;
 }
 return r;
}

void *Znio(int type, Ti pos, Tr tr) {
 void *r;
 if (tr.ptr == NULL) r = NULL;
 else {
  if (tr.type != type) YTuG(pos);
  r = tr.ptr;
 }
 return r;
}

void Zexit(YkxB *pos, Ti val) {
 YNab(pos, val);
}

Ti ZChar2ByteIdx(Tc *p, Ti len, Ti charIdx) {
 Ti idx = 0;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == len) break;
  ++idx;
  if ((p[idx - 1] & 0x80) != 0) {
    while ((p[idx] & 0xc0) == 0x80)
      ++idx;
  }
  ++count;
 }
 return idx;
}

Ti ZfromChar(Tc *p) {
 if (*p <= 0x7f)
  return *p;
 if ((*p & 0xe0) == 0xc0)
  return ((p[0] & 0x1f) << 6) + (p[1] & 0x3f);
 if  ((*p & 0xf0) == 0xe0)
  return ((p[0] & 0x0f) << 12) + ((p[1] & 0x3f) << 6) + (p[2] & 0x3f);
 return ((p[0] & 0x07) << 18) + ((p[1] & 0x3f) << 12) + ((p[2] & 0x3f) << 6) + (p[3] & 0x3f);
}

Ti ZstringGetChar(Tc *sv, Ti idx) {
 Ti i;
 Tc *p;
 Ti len;
 Ti r;
 if (sv == NULL) ZthrowCstringNil("using [] on NIL");
 if (idx < 0) ZthrowCstringOutOfRange(idx, "using negative index");
 len = ZstringSizePtr(sv, &p);
 i = ZChar2ByteIdx(p, len, idx);
 if (i >= len) ZthrowCstringOutOfRange(idx, "index too big");
 r = ZfromChar(p + i);
 return r;
}

Ti Zutf8size(Tc *sp, Ti len) {
 Tc *p = (Tc*)sp;
 Tc *pend = p + len;
 Ti clen = 0;
 while (p < pend) {
  if ((*p & 0xc0) != 0x80) ++clen;
  ++p;
 }
 return clen;
}

Ti ZstringSize(Tc *s) {
 Tc *p;
 Ti r;
 Ti len;
 if (s == NULL) return 0;
 len = ZstringSizePtr(s, &p);
 r = Zutf8size(p, len);
 return r;
}

Ti ZbyteStringSize(Tc *s) {
 Tc *p;
 Ti len;
 if (s == NULL) return 0;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {
  return *p;  /* be quick for short string */
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 return (len << 7) + *p;
}

Tc *Zint2string(Ti n) {
 char buf[30];
 char *p;
 int len;
 sprintf(buf, ZINT_FORMAT, n);
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

Tc *ZintFormat(Tc *fmt, Ti n) {
 char fmtbuf[100];
 char buf[100];
 char *p;
 int len;
 int c;
 Tc *fmtp;
 if (fmt == NULL) ZthrowCstringNil("ToString(): format is NIL");
 if (ZstringSizePtr(fmt, &fmtp) > 90) {
  ZthrowCstringBadValue("ToString(): format too long");
 }
 c = fmtp[strlen((char*)fmtp) - 1];
 if (c != 'd' && c != 'x') {
  ZthrowCstringBadValue("ToString(): format must end in 'd' or 'x'");
 }
 sprintf(fmtbuf, "%%%s", fmtp);
 strcpy(fmtbuf + strlen(fmtbuf) - 1, (c == 'd' ? ZINT_FORMAT : ZINT_XFORMAT) + 1);
 sprintf(buf, fmtbuf, n);
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

char *ZgetCstring(Tc *s) {
 Tc *p;
 if (s == NULL) return NULL;
 p = s + ZOH_OFF;
 while ((*p & 0x80) != 0) ++p;
 return (char *)p + 1;
}

Ta *ZStringToArray(Tc *ss) {
 Ti blen;
 Ti clen;
 Ti i;
 Tc *s;
 Tc *end;
 Ta *r;
 Tu32 c;
 if (ss == NULL) return NULL;
 blen = ZstringSizePtr(ss, &s);
 end = s + blen;
 clen = Zutf8size(s, blen);
 r = ZnewArray(&nat32__T, sizeof(Tu32), clen);
 for (i = 0; i < clen; ++i) {
  if (*s <= 0x7f) {
   c = *s;
   ++s;
  } else if ((*s & 0xe0) == 0xc0) {
   if (s + 1 >= end) YLbE();
   c = ((s[0] & 0x1f) << 6) + (s[1] & 0x3f);
   s += 2;
  } else if ((*s & 0xf0) == 0xe0) {
   if (s + 2 >= end) YLbE();
   c = ((s[0] & 0x0f) << 12) + ((s[1] & 0x3f) << 6) + (s[2] & 0x3f);
   s += 3;
  } else if ((*s & 0xf8) == 0xf0) {
   if (s + 3 >= end) YLbE();
   c = ((s[0] & 0x07) << 18) + ((s[1] & 0x3f) << 12) + ((s[2] & 0x3f) << 6) + (s[3] & 0x3f);
   s += 4;
  } else YLbE();
  ((Tu32*)r->ptr)[i] = c;
 }
 return r;
}

void ZforStringNew(Tc *p, Tfs *s) {
 s->len = p == NULL ? 0 : ZstringSizePtr(p, &(s->ptr));
 s->idx = 0;
}
void ZforStringGetInt(Tfs *s, Ti *p) {
 if (s->idx >= s->len) *p = 0;
 else *p = ZfromChar(s->ptr + s->idx);
}
int ZforStringContInt(Tfs *s) {
return s->idx < s->len;
}
void ZforStringNextInt(Tfs *s, Ti *p) {
 if (s->idx < s->len) {
  ++(s->idx);
  while ((s->ptr[s->idx] & 0xc0) == 0x80) ++(s->idx);
 }
 ZforStringGetInt(s, p);
}

void ZforRangeNew(Ti start, Ti last, int until, Ti step, Tfr *s) {
 s->idx = start;
 if (until)
  s->last = last - (step > 0 ? 1 : -1);
 else
  s->last = last;
 s->step = step;
}
void ZforRangeGetInt(Tfr *s, Ti *p) {
 *p = s->idx;
}
int ZforRangeContInt(Tfr *s) {
 return s->step > 0 ? (s->idx <= s->last) : (s->idx >= s->last);
}
void ZforRangeNextInt(Tfr *s, Ti *p) {
 s->idx += s->step;
 ZforRangeGetInt(s, p);
}

void ZtryDeeper(Tn *e, Zsf *sf) {
 if (e->tryCtx == NULL) {
  e->tryCtxSize = 20;
  e->tryCtx = ZaNm(sizeof(Ttc) * e->tryCtxSize);
  e->tryCtxUsed = 1;
 } else if (++e->tryCtxUsed > e->tryCtxSize) {
  e->tryCtxSize += 20;
  e->tryCtx = ZranNm(e->tryCtx, sizeof(Ttc) * (e->tryCtxSize - 20), sizeof(Ttc) * e->tryCtxSize);
 }
 e->tryCtx[e->tryCtxUsed - 1].sf = sf;
}
void Zrethrow() {
 Tn *e = (&Zenv);
   ZthrowIobject(e->thrown[--e->thrownUsed]);
}

void ZthrowIobject(Tr eo) {
 Tn *e = (&Zenv);
 Ttc *ctx = &e->tryCtx[e->tryCtxUsed - 1];
 if (e->tryCtxUsed > 0) {
  if (e->thrown == NULL) {
   e->thrownSize = 10;
   e->thrown = ZaNmi(sizeof(Tr) * e->thrownSize);
   e->thrownUsed = 1;
  } else if (++e->thrownUsed > e->thrownSize) {
   e->thrownSize += 20;
   e->thrown = ZranNm(e->thrown, sizeof(Tr) * (e->thrownSize - 20), sizeof(Tr *) * e->thrownSize);
  }
  e->thrown[e->thrownUsed - 1] = eo;
  longjmp(ctx->jmpBuf, 42);
 } else
 YxIS(eo);
}
int ZstringCmp(Tc *s1, Tc *s2) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 int r;
 if (s1 == NULL || s2 == NULL) {
  if (s1 == NULL && s2 == NULL) r = 0;
  else r = 1;
  goto end;
 }
 if (s1[ZOH_OFF] != s2[ZOH_OFF]) {
  r = 1;
  goto end;
 }
 len1 = ZstringSizePtr(s1, &p1);
 len2 = ZstringSizePtr(s2, &p2);
 if (len1 == len2) {
  r = memcmp(p1, p2, len1);
  goto end;
 }
 r = 1;
end:
 return r;
}

Ti ZChar2ByteIdxEnd(Tc *p, Ti len, Ti charIdx) {
 Ti idx = len;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == 0) return -1;
  --idx;
  while (idx > 0 && (p[idx] & 0xc0) == 0x80)
    --idx;
  ++count;
 }
 return idx;
}

Ti ZstringFindLen(Tc *big, Ti biglen, Tc *small, Ti smalllen) {
 Ti i;
 Ti ci = 0;
 for (i = 0; i <= biglen - smalllen; ++ci) {
  if (memcmp(big + i, small, smalllen) == 0)
   return ci;
  ++i;
  while ((big[i] & 0xc0) == 0x80 && i < biglen)
   ++i;
 }
 return -1;
}

Ti ZstringFind(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Ti r;
 if (big == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  if (small == NULL) ZthrowCstringNil("using find() with NIL argument");
  biglen = ZstringSizePtr(big, &bigp);
  smalllen = ZstringSizePtr(small, &smallp);
  r = ZstringFindLen(bigp, biglen, smallp, smalllen);
 }
 return r;
}

Ti ZptrFindChar2(Tc *s, Ti slen, Ti c, Ti low) {
 Tc *p = s;
 Ti idx = 0;
 Ti len;
 Tc buf[5];
 int charlen;
 int clen = Zchar2stringBuf(c, buf);
 for (len = slen; len > 0; len -= charlen) {
  for (charlen = 1; (p[charlen] & 0xc0) == 0x80; ++charlen)
   ;
  if (charlen == clen && memcmp(buf, p, charlen) == 0 && idx >= low) {
   return idx;
  }
  p += charlen;
  ++idx;
 }
 return -1;
}

Ti ZstringFindChar2(Tc *s, Ti c, Ti low, int dn) {
 Tc *p;
 int len;
 Ti r;
 if (s == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  len = ZstringSizePtr(s, &p);
  r = ZptrFindChar2(p, len, c, low);
 }
 return r;
}

Ti ZstringFindChar(Tc *s, Ti c, int dn) {
 return ZstringFindChar2(s, c, 0, dn);
}

Tb ZstringEndsWith(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Tb r = 0;
 if (big == NULL) {
  if (dn) goto end;
  ZthrowCstringNil("using endsWith() on NIL");
 }
 if (small == NULL) ZthrowCstringNil("using endsWith() with NIL argument");
 biglen = ZstringSizePtr(big, &bigp);
 smalllen = ZstringSizePtr(small, &smallp);
 if (smalllen <= biglen) r = memcmp(bigp + biglen - smalllen, smallp, smalllen) == 0;
end:
 return r;
}

Tl *ZstringSplitLen(Tc *pss, Ti len, Tc *m) {
 Tl *head = ZnewList(&string__T, 0);
 if (len > 0) {
  Tc *mp;
  Ti mlen = ZstringSizePtr(m, &mp);
  Tc *ps;
  Tc *pe;

  for (ps = pss; ; ps = pe + mlen) {
   int nlen;
   /* TODO: handle NULL byteString */
   pe = (Tc*)strstr((char *)ps, (char *)mp);
   if (pe == NULL) {
    nlen = len - (ps - pss);
   } else {
    nlen = pe - ps;
   }
   ZLa(head, -1, (Tz)(void*)ZnewString(ps, nlen));
   if (pe == NULL) break;
  }
 }
 return head;
}

Tl *ZstringSplit(Tc *b, Tc *m, int dn) {
 Tc *p;
 Ti len;
 Tl *r;
 if (b == NULL) {
  if (!dn) ZthrowCstringNil("using split() on NIL");
  r = NULL;
 } else {
  if (m == NULL) ZthrowCstringNil("split() argument is NIL");
  len = ZstringSizePtr(b, &p);
  r = ZstringSplitLen(p, len, m);
 }
 return r;
}

Tc *ZstringSlice(Tc *sv, Ti start, Ti end, int dn) {
 Ti is;
 Ti ie;
 Tc *p;
 Ti len;
 Tc *r;
 if (sv == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("using slice() on NIL");
 }
 len = ZstringSizePtr(sv, &p);
 is = start < 0 ? ZChar2ByteIdxEnd(p, len, -start) : ZChar2ByteIdx(p, len, start);
 ie = end < 0 ? ZChar2ByteIdxEnd(p, len, -end - 1) - 1 : ZChar2ByteIdx(p, len, end + 1) - 1;
 if (is < 0)
  is = 0;
 if (ie < 0 || ie < is) r = ZnewString((Tc*)"", 0);
 else r = ZnewString(p + is,  ie - is + 1);
 return r;
}

Ti ZptrToInt(Tc *s, int t, Ti def) {
 Ti r;
 char *p = (char*)s;
 if ((*p < '0' || *p > '9') && *p != '-') {
  if (t == 1) ZthrowCstringBadValue("toInt(): argument does not start with a digit or -");
  return def;
 }
 sscanf(p, ZINT_FORMAT, &r);
 return r;
}

Ti ZstringToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using toInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrToInt(s, t, def);
 return r;
}

int ZcopyItems(Tt *toType, int toSize, void *toPtr, Ti toOff, Tt *fromType, int fromSize, void *fromPtr, Ti fromOff, Ti len) {
 Ti i;
 if (toType == fromType || (toType->nr >= 100 && fromType->nr >= 100)) {
  memmove((char*)toPtr + toOff * toSize, (char*)fromPtr + fromOff * fromSize, len * toSize);
  return 1;
 }
 if (fromType->nr >= 100 || toType->nr >= 100) return 0;
 for (i = 0; i < len; ++i) {
  Ti iv;
  Tf fv;
  switch (fromType->nr) {
   case 0:
   case 24:
   case 25:
    iv = ((Ti*)fromPtr)[fromOff + i]; fv = iv; break;
   case 1:
    iv = ((char*)fromPtr)[fromOff + i]; fv = iv; break;
   case 2:
    iv = ((Ti16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 3:
    iv = ((Ti32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 10:
    iv = ((Tu*)fromPtr)[fromOff + i]; fv = iv; break;
   case 11:
    iv = ((Tc*)fromPtr)[fromOff + i]; fv = iv; break;
   case 12:
    iv = ((Tu16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 13:
    iv = ((Tu32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 21:
   case 22:
   case 23:
    iv = ((int*)fromPtr)[fromOff + i]; fv = iv; break;
   case 80:
   case 82:
   case 83:
    fv = ((Tf*)fromPtr)[fromOff + i]; iv = fv; break;
   case 81:
    fv = ((Tf32*)fromPtr)[fromOff + i]; iv = fv; break;
  }
  switch (toType->nr) {
   case 0:
   case 10:
   case 24:
   case 25:
    ((Ti*)toPtr)[toOff + i] = iv; break;
   case 1:
   case 11:
    ((char*)toPtr)[toOff + i] = iv; break;
   case 2:
   case 12:
    ((Ti16*)toPtr)[toOff + i] = iv; break;
   case 3:
   case 13:
    ((Ti32*)toPtr)[toOff + i] = iv; break;
   case 21:
   case 22:
   case 23:
    ((int*)toPtr)[toOff + i] = iv; break;
   case 80:
   case 82:
   case 83:
    ((Tf*)toPtr)[toOff + i] = fv; break;
   case 81:
    ((Tf32*)toPtr)[toOff + i] = fv; break;
  }
 }
 return 1;
}
void ZfreeArray(Ta *head) {
 Ti i;
 Ti d;
 if (head == NULL) return;
 if (head->ptr && head->ptr != head + 1) {
  Zfree(head->ptr - ZOH_OFF);
 }
 Zfree(head);
}

Ta *ZArrayInit(Ta *head, Tt *itemType, int itemSize, Ti size) {
 head->ptr = ZaOff(itemSize * size);
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ta *ZnewArray(Tt *itemType, int itemSize, Ti size) {
 Ta *head;
 size_t extra = size * itemSize;
 if (extra > 100) extra = 0;
 head = Za(sizeof(Ta) + extra);
 if (extra == 0) {
  head->ptr = ZaOff(itemSize * size);
 } else head->ptr = head + 1;
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ti ZArraySize(Ta *head) {
 Ti r;
 if (head == NULL) r = 0;
 else r = head->size[0];
 return r;
}

void *ZarrayPtr(Ta *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("using [] on NIL array");
 if (idx < 0 || idx >= head->size[0]) ZthrowCstringOutOfRange(idx, "array index out of bounds");
 return head->ptr + idx * head->itemSize;
}

Ta *Zas(Ta *head, void *vals, int type, Ti offset) {
 int len;
 int i;
 if (head == NULL) ZthrowCstringNil("Invoking set() on NIL array");
 if (type == 0) {
  /* vals is a byteString */
  Tc *p;
  len = ZstringSizePtr(vals, &p);
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  if (head->itemSize == 1) {
   memmove(((Tc*)head->ptr) + offset, p, len);
  } else if (head->itemSize == sizeof(Te)) {
   for (i = 0; i < len; ++i) ((Te*)head->ptr)[i + offset] = p[i];
  } else {
   for (i = 0; i < len; ++i) ((Ti*)head->ptr)[i + offset] = p[i];
  }
 } else if (type == 1) {
  /* vals is an array */
  Ta *from = vals;
  len = from->size[0];
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->ptr, 0, len);

 } else {
  /* vals is a list */
  Tl *from = (Tl*)vals;
  Ti count = from->itemCount;
  if (count > offset + head->size[0]) count = offset + head->size[0];
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->items, from->empty, count);
 }
 return head;
}

Ta *ZarrayResize(Ta *head, int bytes, Ti size) {
 if (head == NULL) ZthrowCstringNil("Invoking resize() on NIL array");
 if (head->ptr == head + 1) {
  head->ptr = ZaOff(bytes * size);
  memmove(head->ptr, head + 1, size > head->size[0] ? bytes * head->size[0] : bytes * size);
 } else head->ptr = ZranOff(head->ptr, bytes * head->size[0], bytes * size);
 head->size[0] = size;
 return head;
}

Ti ZArrayFind(Ta *head, Tz val) {
 Ti n;
 Ti tot;
 if (head == NULL) ZthrowCstringNil("Attempt to find in NIL array");
 tot = head->size[0];
 for (n = 0; n < tot ; ++n)
  switch (head->itemType->nr) {
   case 0:
   case 24:
   case 25:
    if (((Ti*)head->ptr)[n] == val.ival) return n;
    break;
   case 10:
    if ((Ti)((Tu*)head->ptr)[n] == val.ival) return n;
    break;
   case 1:
    if (((char*)head->ptr)[n] == val.ival) return n;
    break;
   case 11:
    if ((Ti)((Tc*)head->ptr)[n] == val.ival) return n;
    break;
   case 2:
    if (((Ti16*)head->ptr)[n] == val.ival) return n;
    break;
   case 12:
    if ((Ti)((Tu16*)head->ptr)[n] == val.ival) return n;
    break;
   case 3:
   case 13:
    if (((Ti32*)head->ptr)[n] == val.ival) return n;
    break;
   case 21:
   case 22:
   case 23:
    if (((int*)head->ptr)[n] == val.ival) return n;
    break;
   case 80:
   case 82:
   case 83:
    if (((Tf*)head->ptr)[n] == val.fval) return n;
    break;
   case 81:
    if (((Tf32*)head->ptr)[n] == (Tf32)val.fval) return n;
    break;
   case 200:
   case 201:
    if (ZstringCmp(((void**)head->ptr)[n], val.ptr) == 0) return n;
    break;
   case 391:
    ZthrowCstringNil("Invoking find() on iobject array");
    break;
   default:
    if (((void**)head->ptr)[n] == val.ptr) return n;
    break;
  }
 return -1;
}

Ti ZListFindIdx(Tl *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("Accessing NIL list");
 if (idx < 0) {
  Ti n = head->itemCount + idx;
  if (n < 0) return n;
  return n + head->empty;
 }
 if (idx >= head->itemCount) return -1;
 return idx + head->empty;
}

void ZListSetType(Tl* head, Tt *itemType) {
 head->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating list without type");
 switch (itemType->nr) {
  case 0:
  case 10:
  case 80:
  case 82:
  case 83:
  case 24:
  case 25:
   head->itemSize = 8; break;
  case 1:
  case 11:
   head->itemSize = 1; break;
  case 12:
  case 2:
   head->itemSize = 2; break;
  case 3:
  case 13:
  case 81:
   head->itemSize = 4; break;
  case 21:
  case 22:
  case 23:
   head->itemSize = sizeof(int); break;
  case 391:
   head->itemSize = sizeof(Tr); break;
  default:
   head->itemSize = sizeof(void*); break;
 }
}

Tl *ZnewList(Tt *itemType, Ti size) {
 int alloc = size > ((itemType->nr == 1 || itemType->nr == 11) ? 64 : 8);
 int extraSize = itemType != NULL && itemType->nr == 391 ? 8 * sizeof(Tr) : 64;
 Tl *head = Za(sizeof(Tl) + (alloc ? 0 : extraSize));
 ZListSetType(head, itemType);
 if (alloc) {
  head->items = ZaOff(head->itemSize * size);
  head->space = size;
 } else {
  head->items = (void**)(head + 1);
  head->space = extraSize / head->itemSize;
 }
 return head;
}
void ZListGrow(Tl *head, Ti count) {
 Ti newsize = head->empty + head->itemCount + count;
 if (newsize <= head->space) return;
 if (newsize < 100) {
  newsize += (newsize >> 2) + 7;
 } else {
  newsize += newsize >> 3;
 }
 if (head->items == (void**)(head + 1)) {
  head->items = ZaOff(head->itemSize * newsize);
  memmove(head->items, head + 1, head->itemSize * head->itemCount);
 } else {
  head->items = ZranOff(head->items, head->itemSize * head->space, head->itemSize * newsize);
 }
 head->space = newsize;
}

Tl *ZLa(Tl *head, Ti after, Tz val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 switch (head->itemType->nr) {
  case 0:
  case 10:
  case 24:
  case 25:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti*)head->items) + idx + 1, ((Ti*)head->items) + idx, head->itemSize * len);
   ((Ti*)head->items)[idx] = val.ival;
   break;
  case 1:
  case 11:
   if (len > 0 && idx >= head->empty)
    memmove(((char*)head->items) + idx + 1, ((char*)head->items) + idx, head->itemSize * len);
   ((char*)head->items)[idx] = val.ival;
   break;
  case 12:
  case 2:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti16*)head->items) + idx + 1, ((Ti16*)head->items) + idx, head->itemSize * len);
   ((Ti16*)head->items)[idx] = val.ival;
   break;
  case 3:
  case 13:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti32*)head->items) + idx + 1, ((Ti32*)head->items) + idx, head->itemSize * len);
   ((Ti32*)head->items)[idx] = val.ival;
   break;
  case 21:
  case 22:
  case 23:
   if (len > 0 && idx >= head->empty)
    memmove(((int*)head->items) + idx + 1, ((int*)head->items) + idx, head->itemSize * len);
   ((int*)head->items)[idx] = val.ival;
   break;
  case 80:
  case 82:
  case 83:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf*)head->items) + idx + 1, ((Tf*)head->items) + idx, head->itemSize * len);
   ((Tf*)head->items)[idx] = val.fval;
   break;
  case 81:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf32*)head->items) + idx + 1, ((Tf32*)head->items) + idx, head->itemSize * len);
   ((Tf32*)head->items)[idx] = val.fval;
   break;
  default:
   if (len > 0 && idx >= head->empty)
    memmove(head->items + idx + 1, head->items + idx, head->itemSize * len);
   head->items[idx] = val.ptr;
   break;
 }
 ++head->itemCount;
 return head;
}
Tl *ZLap(Tl *head, Tz val) {
 return ZLa(head, -1, val);
}

Tl *ZLaIobj(Tl *head, Ti after, Tr val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 if (len > 0 && idx >= head->empty)
  memmove((Tr*)head->items + idx + 1, (Tr*)head->items + idx, head->itemSize * len);
 ((Tr*)head->items)[idx] = val;
 ++head->itemCount;
 return head;
}
Tl *ZLapIobj(Tl *head, Tr val) {
 return ZLaIobj(head, -1, val);
}
Tl *ZListInsert(Tl *head, Ti before, Tz val) {
 Ti nBefore;
 Ti idx;
 if (head == NULL) ZthrowCstringNil("Invoking insert() on NIL list");
 if (head->itemCount == 0 || before >= head->itemCount) return ZLa(head, -1, val);
 if (before < 0) {
  nBefore = head->itemCount + before;
 } else {
  nBefore = before;
 }
 if (nBefore <= 0) nBefore = -head->itemCount;
 return ZLa(head, nBefore - 1, val);
}

Tl *ZListCopy(Tl *head) {
 Tl *newhead;
 Ti len;
 Ti n;
 if (head == NULL) ZthrowCstringNil("Invoking copy() on NIL list");
 len = head->itemCount;
 newhead = Za(sizeof(Tl));
 newhead->itemType = head->itemType;
 newhead->itemSize = head->itemSize;
 newhead->items = ZaOff(head->itemSize * len);
 memmove(newhead->items, (char*)head->items + head->empty * head->itemSize, len * head->itemSize);
 newhead->space = len;
 newhead->itemCount = len;
 return newhead;
}

Ti ZListSize(Tl *head) {
 if (head == NULL) return 0;
 return head->itemCount;
}

Ti ZListGetInt(Tl *head, Ti idx) {
 Ti r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 0:
   case 24:
   case 25:
    r = ((Ti*)head->items)[n]; break;
   case 10:
    r = (Ti)((Tu*)head->items)[n]; break;
   case 1:
    r = ((char*)head->items)[n]; break;
   case 11:
    r = (Ti)((Tc*)head->items)[n]; break;
   case 2:
    r = ((Ti16*)head->items)[n]; break;
   case 12:
    r = (Ti)((Tu16*)head->items)[n]; break;
   case 3:
    r = ((Ti32*)head->items)[n]; break;
   case 13:
    r = (Ti)((Tu32*)head->items)[n]; break;
   case 21:
   case 22:
   case 23:
    r = ((int*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

void *ZListGetIntP(Tl *head, Ti idx) {
 Ti *r;
 Ti n = ZListFindIdx(head, idx);
 if (n < 0) ZthrowCstringOutOfRange(idx, "index out of range");
 return (void*)head->items + n * head->itemSize;
}

Tf ZListGetFloat(Tl *head, Ti idx) {
 Tf r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 80:
   case 82:
   case 83:
    r = ((Tf*)head->items)[n]; break;
   case 81:
    r = (Tf)((Tf32*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

void *ZListGetPtr(Tl *head, Ti idx) {
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) return head->items[n];
 return NULL;
}

Tl *ZListClearItem(Tl *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("Invoking remove() on NIL list");
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  Ti len = head->itemCount - (n - head->empty) - 1;
  if (len > 0)
   memmove(((char*)head->items) + n * head->itemSize, ((char*)head->items) + (n + 1) * head->itemSize, len * head->itemSize);
  head->itemCount--;
  // ZListShrink(head);
 }
 return head;
}

static int stringCmp(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p1p, p2p, len);
 if (r == 0) return len1 - len2;
 return r;
}
static int stringCmpR(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p2p, p1p, len);
 if (r == 0) return len2 - len1;
 return r;
}
Tl *ZstringListSort(Tl *head, int asc) {
 int i = 0;
 if (head == NULL) ZthrowCstringNil("Invoking sort() on NIL list");
 qsort(head->items + head->empty, head->itemCount, sizeof(Tc*), asc ? stringCmp : stringCmpR);
 return head;
}

int ZforListIntCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(Ti*)tfl->valp = ZListGetInt(l, i);
 ++tfl->i;
 return 1;
}

int ZforListPtrCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(char**)tfl->valp = l->items[i + l->empty];
 ++tfl->i;
 return 1;
}

int ZDeqNr(Tz *l, Tz *r) {
 return l->ival == r->ival;
}
int ZDeqFloat(Tz *l, Tz *r) {
 return l->fval == r->fval;
}
int ZDeqStr(Tz *l, Tz *r) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 if (r->ptr != NULL) {
  len1 = ZstringSizePtr(l->ptr, &p1);
  len2 = ZstringSizePtr(r->ptr, &p2);
  if (len1 == len2) return memcmp(p1, p2, len1) == 0;
 }
 return 0;
}
int ZDeqRef(Tz *l, Tz *r) {
 return l->ptr == r->ptr;
}
int ZDeqIobj(Tr *l, Tz *r) {
 return l->ptr == ((Tr*)r->ptr)->ptr;
}

Td *ZDictHead(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 d->array = d->smallArray;
 d->mask = HT_INIT_SIZE - 1;
 d->keyType = keyType;
 d->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating dict without item type");
 if (keyType == NULL) ZthrowCstringNil("Creating dict without key type");
 if (ordered) d->type = DTYPE_ORDERED;
 if (keyType->nr < 80) d->eqfunc = (int (*)(void*, Tz*))ZDeqNr;
 else if (keyType->nr < 100) d->eqfunc = (int (*)(void*, Tz*))ZDeqFloat;
 else if (keyType == &iobj__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqIobj;
 else if (keyType == &string__T || keyType == &byteString__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqStr;
 else d->eqfunc = (int (*)(void*, Tz*))ZDeqRef;
 return d;
}
Td *ZDictInit(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 memset(d, 0, sizeof(Td));
 ZDictHead(d, keyType, itemType, ordered);
 return d;
}
Td *ZnewDict(Tt *keyType, Tt *itemType, Tb ordered) {
 return ZDictHead(Za(sizeof(Td)), keyType, itemType, ordered);
}

Zhashtype ZDictHash(Tt *keyType, Tz key) {
 Zhashtype hash;
 void *ptr;
 if (keyType->nr < 80) return (Zhashtype)key.ival;
 if (keyType->nr < 100) return (Zhashtype)key.fval;
 if (keyType == &iobj__T) {
  ptr = ((Tr*)key.ptr)->ptr;
 } else {
  ptr = key.ptr;
 }
 if (ptr == NULL) ZthrowCstringNil("dict key is NIL");
 if (keyType == &string__T || keyType == &byteString__T) {
  Tc *p;
  int l = ZstringSizePtr(key.ptr, &p);
  if (l == 0) {
   hash = 0;
  } else {
   hash = *p;
   while (--l > 0) {
    hash = hash * 101 + *++p;
   }
  }
 } else {
  Tip k = (Tip)ptr;
  int l = sizeof(Tc*);
  hash = k & 0xff;
  while (--l > 0) {
   k >>= 8;
   hash = hash * 101 + (k & 0xff);
  }
 }
 return hash;
}

void ZthrowIntKeyNotFound(Tz key, Tc *msg) {
  Yxmk(key.ival, msg);
}

void ZthrowStringKeyNotFound(Tz key, Tc *msg) {
  Y5LT(key.ptr, msg);
}

void ZthrowIntKeyExists(Tz key, Tc *msg) {
  YL9Z(key.ival, msg);
}
void ZthrowStringKeyExists(Tz key, Tc *msg) {
  YEeX(key.ptr, msg);
}

/* #define DICT_DEBUG 1 */

CDictItem *ZDictLookup(Td *d, Tz key, Zhashtype hash)
{
 Zhashtype  perturb;
 CDictItem  *freeitem;
 int        idx = (int)(hash & d->mask);
 CDictItem  *di = &d->array[idx];
 if (di->flags == 0) return di;
 if (di->flags == CDI_FLAG_DEL) freeitem = di;
 else if (di->hash == hash && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) {
  return di;
 } else {
  freeitem = NULL;
 }

 for (perturb = hash; ; perturb >>= PERTURB_SHIFT)
 {
  idx = (int)((idx << 2) + idx + perturb + 1);
  di = &d->array[idx & d->mask];
  if (di->flags == 0) return freeitem == NULL ? di : freeitem;
  if (di->hash == hash && di->flags != CDI_FLAG_DEL && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) return di;
  if (di->flags == CDI_FLAG_DEL && freeitem == NULL) freeitem = di;
 }
}

void ZDictResize(Td *d, int minitems) {
 CDictItem temparray[HT_INIT_SIZE];
 CDictItem *oldarray, *newarray;
 CDictItem *olditem, *newitem, *nextitem;
 int newi;
 int todo;
 Zhashtype oldsize, newsize;
 Zhashtype minsize;
 Zhashtype newmask;
 Zhashtype perturb;

#ifdef DICT_DEBUG
 printf("size: %lu, filled: %lu, used: %lu\n",
           d->mask + 1, d->filled, d->used);
#endif

 if (minitems == 0) {
  if (d->filled < HT_INIT_SIZE - 1 && d->array == d->smallArray) {
#ifdef DICT_DEBUG
   printf("small array not full\n");
#endif
   return;
  }
  oldsize = d->mask + 1;
  if (d->filled * 3 < oldsize * 2 && d->used > oldsize / 5) {
#ifdef DICT_DEBUG
   printf("size OK\n");
#endif
   return;
  }
  if (d->used > 1000) minsize = d->used * 2;
  else minsize = d->used * 4;
 } else {
  if ((Zhashtype)minitems < d->used) minitems = (int)d->used;
  minsize = minitems * 3 / 2;
 }

 newsize = HT_INIT_SIZE;
 while (newsize < minsize) {
  newsize <<= 1;
  if (newsize == 0) {
   ZthrowInternal(Zstr("ZDictResize"));
   return;
  }
 }

#ifdef DICT_DEBUG
 printf("resizing from %lu to %lu\n", d->mask + 1, newsize);
#endif

 if (newsize == HT_INIT_SIZE) {
  newarray = d->smallArray;
  if (d->array == newarray) {
   memmove(temparray, newarray, sizeof(temparray));
   oldarray = temparray;
  } else
   oldarray = d->array;
  memset(newarray, 0, (size_t)(sizeof(CDictItem) * newsize));
 } else {
  newarray = (CDictItem *)ZaOff((sizeof(CDictItem) * newsize));
  oldarray = d->array;
 }

 newmask = newsize - 1;
 todo = (int)d->used;
 for (olditem = oldarray; todo > 0; ++olditem)
  if (olditem->flags & CDI_FLAG_USED) {
   newi = (int)(olditem->hash & newmask);
   newitem = &newarray[newi];
   if (newitem->flags != 0)
    for (perturb = olditem->hash; ; perturb >>= PERTURB_SHIFT) {
     newi = (int)((newi << 2) + newi + perturb + 1);
     newitem = &newarray[newi & newmask];
     if (newitem->flags == 0) break;
    }
   *newitem = *olditem;
   if (d->type & DTYPE_ORDERED) {
    olditem->lprev = newitem;
   }
   --todo;
  }
 if ((d->type & DTYPE_ORDERED) && d->first) {
  olditem = d->first;
  newitem = olditem->lprev;
  newitem->lprev = NULL;
  d->first = newitem;
  while (olditem->lnext) {
   olditem = olditem->lnext;
   nextitem = olditem->lprev;
   newitem->lnext = nextitem;
   newitem->lnext->lprev = newitem;
   newitem = nextitem;
  }
  newitem->lnext = NULL;
  d->last = newitem;
 }

 if (d->array != d->smallArray) Zfree((void*)d->array - ZOH_OFF);
 d->array = newarray;
 d->mask = newmask;
 d->filled = d->used;
}

/* "ow" is the overwrite flag.  When zero it's not allowed to overwrite an
 * existing entry. */
Td *ZDictAdd(int ow, Td *d, Tz key, Tz value) {
 Zhashtype hash = ZDictHash(d->keyType, key);
 CDictItem *di = ZDictLookup(d, key, hash);
#ifdef DICT_DEBUG
 if (d->keyType->nr >= 100)
   printf("Adding item %s\n", (Tc*)key.ptr);
 else
   printf("Adding item %lld\n", key.ival);
 if (key.ptr != NULL
     && (strcmp(key.ptr, "ENUM") == 0
         || strcmp(key.ptr, "Equal") == 0
         || strcmp(key.ptr, "EXIT") == 0))
   dumpdict(d);
#endif
 if (di->flags == 0 || di->flags == CDI_FLAG_DEL || ow) {
  if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
   ++d->used;
   if (di->flags == 0)
    ++d->filled;
  }
  di->hash = hash;
  if (d->keyType->nr == 391) {
   di->iokey = *(Tr*)key.ptr;
  } else if (d->keyType->nr >= 100) {
   if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
    di->key = key;
   }
  } else di->key = key;
  if (d->itemType->nr == 391)
   di->ioitem = *(Tr*)value.ptr;
  else
   di->item = value;
  di->flags = CDI_FLAG_USED;
  if (d->type & DTYPE_ORDERED) {
   di->lprev = d->last;
   if (d->last) d->last->lnext = di;
   else d->first = di;
   d->last = di;
   di->lnext = NULL;
  }

  ZDictResize(d, 0);
 } else {
  if (d->keyType->nr >= 100) ZthrowStringKeyExists(key, Zstr("dict.add(): "));
  ZthrowIntKeyExists(key, Zstr("dict.add(): "));
 }
 return d;
}
Td *ZDictAddIobjTz(int ow, Td *d, Tr key, Tz value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, value);
}
Td *ZDictAddTzIobj(int ow, Td *d, Tz key, Tr value) {
 return ZDictAdd(ow, d, key, (Tz)(void*)&value);
}
Td *ZDictAddIobjIobj(int ow, Td *d, Tr key, Tr value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, (Tz)(void*)&value);
}

#ifdef DICT_DEBUG
dumpdict(Td *d)
{
 int        todo = (int)d->used;
 CDictItem  *item;
 int        idx = 0;

 for (item = d->array; todo > 0; ++item) {
  if (item->flags & CDI_FLAG_USED) {
   printf("%2d: %s\n", idx, (Tc*)item->key.ptr);
   --todo;
  } else if (item->flags == 0) {
   printf("%2d: unused\n", idx);
  } else if (item->flags == CDI_FLAG_DEL) {
   printf("%2d: deleted\n", idx);
  } else {
   printf("%2d: invalid flags: %d\n", idx, item->flags);
  }
  ++idx;
 }
}
#endif


CDictItem *ZDictFind(Td *d, Tz key) {
 Zhashtype  hash = ZDictHash(d->keyType, key);
 CDictItem  *di = ZDictLookup(d, key, hash);
 if (di->flags & CDI_FLAG_USED) return di;
 return NULL;
}

Tr *ZDictGetIobjP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  static Tr dummy = {0, 0, 0};
  ZDictAdd(1, d, key, (Tz)(void*)&dummy);
  di = ZDictFind(d, key);
 }
 return &di->ioitem;
}

Tr ZDictGetIobj(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->ioitem;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return trZero;
}

Tr ZDictGetIobjDef(Td *d, Tz key, Tr def) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) return di->ioitem;
 return def;
}

Ti *ZDictGetIntP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  ZDictAdd(1, d, key, (Tz)(Ti)0);
  di = ZDictFind(d, key);
 }
 return &di->item.ival;
}

Ti ZDictGetInt(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->item.ival;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return 0;
}

Tb ZDictHas(Td *d, Tz key) {
 return (ZDictFind(d, key) != NULL);
}
Tb ZDictHasIobj(Td *d, Tr key) {
 return (ZDictFind(d, (Tz)(void*)&key) != NULL);
}
Tl *ZDictKeys(Td *d, int dn) {
 Tl *l;
 int todo;
 CDictItem *di;
 if (d == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("Invoking keys() on NIL dict");
 }
 l = ZnewList(d->keyType, d->used);
 if (d->type & DTYPE_ORDERED) {
  if (d->keyType == &iobj__T)
   for (di = d->first; di; di = di->lnext) {
    ZLaIobj(l, -1, di->iokey);
   }
  else
   for (di = d->first; di; di = di->lnext) {
    ZLa(l, -1, di->key);
   }
 } else {
  todo = d->used;
  for (di = d->array; todo > 0; ++di) {
   if (di->flags & CDI_FLAG_USED) {
    --todo;
    if (d->keyType == &iobj__T)
     ZLaIobj(l, -1, di->iokey);
    else
     ZLa(l, -1, di->key);
   }
  }
 }
 return l;
}

Ti ZDictSize(Td *d) {
 if (d == NULL) return 0;
 return d->used;
}

Tcode *ZtableIndex(Ti pos100) {
 Ti pos = pos100 / 100;
 int l = 0;
 int h = sizeof(ZcodeTable)/sizeof(Tcode) - 1;
 int m;
 while (l <= h) {
  m = (l + h) / 2;
  if (ZcodeTable[m].offset == pos) break;
  if (ZcodeTable[m].offset < pos) l = m + 1;
  else h = m - 1;
 }
 return &ZcodeTable[m];
}
YkxB *MZ__callerPos(void) {
 Tcode *p;
 Zsf *tf = topFrame;
 if (tf == NULL) return NULL;
 tf = tf->prev == NULL ? tf : tf->prev;
 while (1) {
  if (tf == NULL) return NULL;
  if (tf->pos & POS_MASK) {
   p = ZtableIndex(tf->pos & POS_MASK);
   if (p->fileName) {
    return MZ__posnr2pos(NULL, tf->pos & POS_MASK);
   }
  }
  tf = tf->prev;
 }
}

Tl *MZ__backtrace(Ti skip, Ti limit) {
 Tl *head = ZnewList((Tt*)&YkxB__T, 0);
 int done = 0;
 Zsf *tf = topFrame;
 if (skip > 0) {
  int i;
  for (i = 0; i < skip && tf != NULL; ++i) tf = tf->prev;
 }
 while (tf != NULL) {
  if (tf->pos & POS_MASK) {
   YkxB *item = Za(sizeof(YkxB));
   if (limit >= 0 && done >= limit) {
    item->Vfilename = Zstr("truncated");
    ZLa(head, -1, (Tz)(void*)item);
    break;
   }
   MZ__posnr2pos(item, tf->pos & POS_MASK);
   ZLa(head, -1, (Tz)(void*)item);
   ++done;
  }
  tf = tf->prev;
 }
 return head;
}

YkxB *MZ__posnr2pos(YkxB *t, Ti pos) {
 int i;
 Tcode *p;
 Tcpos *pp;
 if (t == NULL) t = Za(sizeof(YkxB));
 p = ZtableIndex(pos);
 i = pos - p->offset * 100;
 pp = &p->table[i];
 t->Vfilename = Zstr((char*)p->fileName);
 t->Vtext = Zstr((char*)p->methodName);
 t->Vlnum = pp->line;
 if (i) t->Vlnum += p->table[0].line;
 t->Vcol = pp->col;
 return t;
}
/*
 * FUNCTION BODIES
 */
/* including EModule bodies */
void YxaJ(Ytlm *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4918300;
  ZthrowThisNil();
 }
 sf.pos=4918301;
 if ((t->Vpos != NULL))
 {
  sf.pos=4918302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4918303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4918304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4918305;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4918306;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4918307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Yoww(Ytlm *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9713500;
  ZthrowThisNil();
 }
 sf.pos=9713501;
 Vw = Za(sizeof(YjUM));
 sf.pos=9713502;
 YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9713503;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3649100;
  ZthrowThisNil();
 }
 sf.pos=3649101;
 YxaJ(t, Aw);
 sf.pos=3649102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3649103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3649104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3649105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3649106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3649107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3649108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3649109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3649110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3649111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3649112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYtlm[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Ytlm__T = {390, (Tc*)&YDGe, 0, ToYtlm};
YEro *YE2c(YEro *t, Ti Avalue) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3189000; t = Za(sizeof(YEro));}
 sf.pos=3189001;
 t->Vvalue = Avalue;
 sf.pos=3189002;
 t->Vmessage = ZcS(((Tc*)&YxJ1), Zint2string(Avalue));
 sf.pos=3189003;
 t->Vbacktrace = (sf.pos=3189004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YXHSa(YEro *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9216300;
  ZthrowThisNil();
 }
 sf.pos=9216301;
 if ((t->Vpos != NULL))
 {
  sf.pos=9216302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9216303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9216304;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YxJ1));
 sf.pos=9216305;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Zint2string(t->Vvalue));
 sf.pos=9216306;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9216307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
  sf.pos=9216308;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 topFrame = sf.prev;
 return;
}
Tc *YEro__Yoww(YEro *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9468900;
  ZthrowThisNil();
 }
 sf.pos=9468901;
 Vw = Za(sizeof(YjUM));
 sf.pos=9468902;
 YEro__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9468903;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4298300;
  ZthrowThisNil();
 }
 sf.pos=4298301;
 YXHSa(t, Aw);
 sf.pos=4298302;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=4298303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4298304;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4298305;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=4298306;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=4298307;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=4298308;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4298309;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=4298310;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=4298311;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4298312;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YEro__Ytlm_I_imt[] = {
 (Tc*)&YEro__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CExit.NEW - YEro__YRHRa */
 (Tc*)0, /* MEModule__CExit.NEW - YEro__YRHR */
 (Tc*)0, /* MEModule__CExit.ToString - Ydtua */
 (Tc*)YEro__YxaJa, /* MEModule__CExit.writeTo - YEro__YxaJa */
 (Tc*)YXHSa, /* MEModule__CExit.writeTo - YXHSa */
 (Tc*)YEro__Yoww, /* MEModule__CExit.toString - YEro__Yoww */
 (Tc*)0, /* MEModule__CExit.getMessage - YEro__YCzX */
 (Tc*)0, /* MEModule__CExit.getPos - YEro__YvCK */
 (Tc*)0, /* MEModule__CExit.getBacktrace - YEro__Y4bq */
 (Tc*)0, /* Init - YEroa */
};
To ToYEro[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YEro__T = {390, (Tc*)&YJMo, 0, ToYEro};
void YNab(YkxB *Apos, Ti Aval) {
 Tr ex;
 YEro *Ve = 0;
 Tr t0 = {NULL};
 Ve = YE2c(NULL, Aval);
 Ve->Vpos = Apos;
 *Znao(&ex, Ve, YEro__Ytlm_I_imt, 1);
 ZthrowIobject(ex);
}
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8064400; t = Za(sizeof(YKhn));}
 sf.pos=8064401;
 t->Vmessage = ZcS3(((Tc*)&YIBz), Zint2string(Asize), ((Tc*)&YDSH));
 sf.pos=8064402;
 t->Vpos = MZ__callerPos();
 sf.pos=8064403;
 t->Vbacktrace = (sf.pos=8064404, MZ__backtrace(1, Alimit));
 topFrame = sf.prev;
 return t;
}
Tc *YKhn__YwtA__Yoww(YKhn *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9057100;
  ZthrowThisNil();
 }
 sf.pos=9057101;
 Vw = Za(sizeof(YjUM));
 sf.pos=9057102;
 YKhn__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9057103;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1121700;
  ZthrowThisNil();
 }
 sf.pos=1121701;
 YKhn__YwtA__YxaJ(t, Aw);
 sf.pos=1121702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1121703;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=1121704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1121705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1121706;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1121707;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1121708;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=1121709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1121710;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1121711;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=1121712;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2141800;
  ZthrowThisNil();
 }
 sf.pos=2141801;
 if ((t->Vpos != NULL))
 {
  sf.pos=2141802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=2141803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=2141804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=2141805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=2141806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=2141807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YKhn__Ytlm_I_imt[] = {
 (Tc*)&YKhn__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHRa */
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHR */
 (Tc*)0, /* MEModule__COutOfMemory.ToString - YKhn__YwtA__YH0V */
 (Tc*)YKhn__YwtA__YxaJa, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJa */
 (Tc*)YKhn__YwtA__YxaJ, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJ */
 (Tc*)YKhn__YwtA__Yoww, /* MEModule__COutOfMemory.toString - YKhn__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfMemory.getMessage - YKhn__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfMemory.getPos - YKhn__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfMemory.getBacktrace - YKhn__YwtA__Y4bq */
 (Tc*)0, /* Init - YKhna */
};
To ToYKhn[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YKhn__T = {390, (Tc*)&Y9Fv, 0, ToYKhn};
void Y1KV(Ti Asize) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YDNob(NULL, Asize, 30), YKhn__Ytlm_I_imt, 4);
 ZthrowIobject(ex);
}
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3208600; t = Za(sizeof(Y1uN));}
 sf.pos=3208601;
 t->Vmessage = Amsg;
 sf.pos=3208602;
 t->Vpos = MZ__callerPos();
 sf.pos=3208603;
 t->Vbacktrace = (sf.pos=3208604, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Y1uN__YwtA__Yoww(Y1uN *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7911000;
  ZthrowThisNil();
 }
 sf.pos=7911001;
 Vw = Za(sizeof(YjUM));
 sf.pos=7911002;
 Y1uN__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7911003;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3508800;
  ZthrowThisNil();
 }
 sf.pos=3508801;
 Y1uN__YwtA__YxaJ(t, Aw);
 sf.pos=3508802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3508803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3508804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3508805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3508806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3508807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3508808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3508809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3508810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3508811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3508812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4528900;
  ZthrowThisNil();
 }
 sf.pos=4528901;
 if ((t->Vpos != NULL))
 {
  sf.pos=4528902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4528903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4528904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4528905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4528906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4528907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Y1uN__Ytlm_I_imt[] = {
 (Tc*)&Y1uN__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHRa */
 (Tc*)Y1uN__YwtA__YRHR, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHR */
 (Tc*)0, /* MEModule__CNilAccess.ToString - Y1uN__YwtA__YH0V */
 (Tc*)Y1uN__YwtA__YxaJa, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJa */
 (Tc*)Y1uN__YwtA__YxaJ, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJ */
 (Tc*)Y1uN__YwtA__Yoww, /* MEModule__CNilAccess.toString - Y1uN__YwtA__Yoww */
 (Tc*)0, /* MEModule__CNilAccess.getMessage - Y1uN__YwtA__YCzX */
 (Tc*)0, /* MEModule__CNilAccess.getPos - Y1uN__YwtA__YvCK */
 (Tc*)0, /* MEModule__CNilAccess.getBacktrace - Y1uN__YwtA__Y4bq */
 (Tc*)0, /* Init - Y1uNa */
};
To ToY1uN[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Y1uN__T = {390, (Tc*)&Y4wO, 0, ToY1uN};
void YvdV(YkxB *Apos, Tc *Atext) {
 Tr ex;
 Y1uN *Ve = 0;
 Tr t0 = {NULL};
 Ve = Y1uN__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, Y1uN__Ytlm_I_imt, 5);
 ZthrowIobject(ex);
}
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7358000; t = Za(sizeof(YAxe));}
 sf.pos=7358001;
 t->Vmessage = Amsg;
 sf.pos=7358002;
 t->Vpos = MZ__callerPos();
 sf.pos=7358003;
 t->Vbacktrace = (sf.pos=7358004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YAxe__YwtA__Yoww(YAxe *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1829200;
  ZthrowThisNil();
 }
 sf.pos=1829201;
 Vw = Za(sizeof(YjUM));
 sf.pos=1829202;
 YAxe__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1829203;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2595800;
  ZthrowThisNil();
 }
 sf.pos=2595801;
 YAxe__YwtA__YxaJ(t, Aw);
 sf.pos=2595802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2595803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2595804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2595805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2595806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2595807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2595808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2595809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2595810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2595811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2595812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3615900;
  ZthrowThisNil();
 }
 sf.pos=3615901;
 if ((t->Vpos != NULL))
 {
  sf.pos=3615902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=3615903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=3615904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=3615905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=3615906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=3615907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YAxe__Ytlm_I_imt[] = {
 (Tc*)&YAxe__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHRa */
 (Tc*)YAxe__YwtA__YRHR, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHR */
 (Tc*)0, /* MEModule__CMemoryAccess.ToString - YAxe__YwtA__YH0V */
 (Tc*)YAxe__YwtA__YxaJa, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJa */
 (Tc*)YAxe__YwtA__YxaJ, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJ */
 (Tc*)YAxe__YwtA__Yoww, /* MEModule__CMemoryAccess.toString - YAxe__YwtA__Yoww */
 (Tc*)0, /* MEModule__CMemoryAccess.getMessage - YAxe__YwtA__YCzX */
 (Tc*)0, /* MEModule__CMemoryAccess.getPos - YAxe__YwtA__YvCK */
 (Tc*)0, /* MEModule__CMemoryAccess.getBacktrace - YAxe__YwtA__Y4bq */
 (Tc*)0, /* Init - YAxea */
};
To ToYAxe[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YAxe__T = {390, (Tc*)&Y4QW, 0, ToYAxe};
void YE93(Ti Anr) {
 Tr ex;
 Tr t0 = {NULL};
 if ((Anr == 11))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YkfG)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 if ((Anr == 8))
 {
  Tr ex;
  *Znao(&ex, YzSI__Ylz1__YwtA__YRHR(NULL, ((Tc*)&YoEx)), YzSI__Ytlm_I_imt, 17);
  ZthrowIobject(ex);
 }
 if ((Anr == 7))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YQNH)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 *Znao(&ex, YAxe__YwtA__YRHR(NULL, ZcS(((Tc*)&YpCZ), Zint2string(Anr))), YAxe__Ytlm_I_imt, 6);
 ZthrowIobject(ex);
}
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6357800; t = Za(sizeof(YVNj));}
 sf.pos=6357801;
 t->Vmessage = Amsg;
 sf.pos=6357802;
 t->Vpos = Apos;
 sf.pos=6357803;
 t->Vbacktrace = (sf.pos=6357804, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=5337700; t = Za(sizeof(YVNj));}
 sf.pos=5337701;
 t->Vmessage = Amsg;
 sf.pos=5337702;
 t->Vpos = MZ__callerPos();
 sf.pos=5337703;
 t->Vbacktrace = (sf.pos=5337704, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YVNj__YwtA__Yoww(YVNj *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9345300;
  ZthrowThisNil();
 }
 sf.pos=9345301;
 Vw = Za(sizeof(YjUM));
 sf.pos=9345302;
 YVNj__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9345303;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9610700;
  ZthrowThisNil();
 }
 sf.pos=9610701;
 YVNj__YwtA__YxaJ(t, Aw);
 sf.pos=9610702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=9610703;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=9610704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=9610705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=9610706;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=9610707;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=9610708;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=9610709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=9610710;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=9610711;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=9610712;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=630800;
  ZthrowThisNil();
 }
 sf.pos=630801;
 if ((t->Vpos != NULL))
 {
  sf.pos=630802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=630803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=630804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=630805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=630806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=630807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YVNj__Ytlm_I_imt[] = {
 (Tc*)&YVNj__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YVNj__YwtA__YRHRa, /* MEModule__CInit.NEW - YVNj__YwtA__YRHRa */
 (Tc*)YVNj__YwtA__YRHR, /* MEModule__CInit.NEW - YVNj__YwtA__YRHR */
 (Tc*)0, /* MEModule__CInit.ToString - YVNj__YwtA__YH0V */
 (Tc*)YVNj__YwtA__YxaJa, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJa */
 (Tc*)YVNj__YwtA__YxaJ, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJ */
 (Tc*)YVNj__YwtA__Yoww, /* MEModule__CInit.toString - YVNj__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInit.getMessage - YVNj__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInit.getPos - YVNj__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInit.getBacktrace - YVNj__YwtA__Y4bq */
 (Tc*)0, /* Init - YVNja */
};
To ToYVNj[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YVNj__T = {390, (Tc*)&Ysqt, 0, ToYVNj};
void Y3w6(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YVNj__YwtA__YRHR(NULL, Atext), YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6059300; t = Za(sizeof(Yalz));}
 sf.pos=6059301;
 t->Vmessage = Amsg;
 sf.pos=6059302;
 t->Vpos = MZ__callerPos();
 sf.pos=6059303;
 t->Vbacktrace = (sf.pos=6059304, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Yalz__YwtA__Yoww(Yalz *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5657300;
  ZthrowThisNil();
 }
 sf.pos=5657301;
 Vw = Za(sizeof(YjUM));
 sf.pos=5657302;
 Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5657303;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4617100;
  ZthrowThisNil();
 }
 sf.pos=4617101;
 Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=4617102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=4617103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4617104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4617105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=4617106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=4617107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=4617108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4617109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=4617110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=4617111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4617112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5637200;
  ZthrowThisNil();
 }
 sf.pos=5637201;
 if ((t->Vpos != NULL))
 {
  sf.pos=5637202;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=5637203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5637204;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=5637205;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=5637206;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=5637207;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Yalz__Ytlm_I_imt[] = {
 (Tc*)&Yalz__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHRa */
 (Tc*)Yalz__YwtA__YRHR, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CBadValue.ToString - Yalz__YwtA__YH0V */
 (Tc*)Yalz__YwtA__YxaJa, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJa */
 (Tc*)Yalz__YwtA__YxaJ, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJ */
 (Tc*)Yalz__YwtA__Yoww, /* MEModule__CBadValue.toString - Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CBadValue.getMessage - Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CBadValue.getPos - Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CBadValue.getBacktrace - Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yalza */
};
To ToYalz[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Yalz__T = {390, (Tc*)&YEZq, 0, ToYalz};
void Yaez(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yalz__YwtA__YRHR(NULL, Atext), Yalz__Ytlm_I_imt, 10);
 ZthrowIobject(ex);
}
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=5638100; t = Za(sizeof(Yw3O));}
 sf.pos=5638101;
 t->Vmessage = Amsg;
 sf.pos=5638102;
 t->Vpos = MZ__callerPos();
 sf.pos=5638103;
 t->Vbacktrace = (sf.pos=5638104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Yw3O__Yalz__YwtA__Yoww(Yw3O *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8398500;
  ZthrowThisNil();
 }
 sf.pos=8398501;
 Vw = Za(sizeof(YjUM));
 sf.pos=8398502;
 Yw3O__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8398503;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5260800;
  ZthrowThisNil();
 }
 sf.pos=5260801;
 if ((t->Vpos != NULL))
 {
  sf.pos=5260802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=5260803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5260804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=5260805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=5260806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=5260807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6280900;
  ZthrowThisNil();
 }
 sf.pos=6280901;
 Yw3O__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=6280902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=6280903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=6280904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6280905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=6280906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=6280907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=6280908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=6280909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=6280910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=6280911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=6280912;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *Yw3O__Ytlm_I_imt[] = {
 (Tc*)&Yw3O__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHRa */
 (Tc*)Yw3O__Yalz__YwtA__YRHR, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__COutOfRange.ToString - Yw3O__Yalz__YwtA__YH0V */
 (Tc*)Yw3O__Yalz__YwtA__YxaJa, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJa */
 (Tc*)Yw3O__Yalz__YwtA__YxaJ, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJ */
 (Tc*)Yw3O__Yalz__YwtA__Yoww, /* MEModule__COutOfRange.toString - Yw3O__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - Yw3O__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getPos - Yw3O__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Yw3O__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
};
To ToYw3O[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Yw3O__T = {390, (Tc*)&YFK2, 0, ToYw3O};
void Y6NT(Ti Aindex, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&YFDa), Zint2string(Aindex))), Yw3O__Ytlm_I_imt, 11);
 ZthrowIobject(ex);
}
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2958500; t = Za(sizeof(Y2EX));}
 sf.pos=2958501;
 t->Vmessage = Amsg;
 sf.pos=2958502;
 t->Vpos = MZ__callerPos();
 sf.pos=2958503;
 t->Vbacktrace = (sf.pos=2958504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *Y2EX__Yalz__YwtA__Yoww(Y2EX *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6792500;
  ZthrowThisNil();
 }
 sf.pos=6792501;
 Vw = Za(sizeof(YjUM));
 sf.pos=6792502;
 Y2EX__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6792503;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4312400;
  ZthrowThisNil();
 }
 sf.pos=4312401;
 if ((t->Vpos != NULL))
 {
  sf.pos=4312402;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4312403;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4312404;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4312405;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4312406;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4312407;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5332500;
  ZthrowThisNil();
 }
 sf.pos=5332501;
 Y2EX__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=5332502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=5332503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5332504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5332505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=5332506;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=5332507;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=5332508;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5332509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=5332510;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=5332511;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5332512;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *Y2EX__Ytlm_I_imt[] = {
 (Tc*)&Y2EX__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHRa */
 (Tc*)Y2EX__Yalz__YwtA__YRHR, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - Y2EX__Yalz__YwtA__YH0V */
 (Tc*)Y2EX__Yalz__YwtA__YxaJa, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJa */
 (Tc*)Y2EX__Yalz__YwtA__YxaJ, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJ */
 (Tc*)Y2EX__Yalz__YwtA__Yoww, /* MEModule__CKeyNotFound.toString - Y2EX__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - Y2EX__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - Y2EX__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y2EX__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Y2EXa */
};
To ToY2EX[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Y2EX__T = {390, (Tc*)&YRiW, 0, ToY2EX};
void Yxmk(Ti Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Ym6C), Zint2string(Akey))), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
void Y5LT(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YJ3Y), Akey, ((Tc*)&YI), (Tc*)1)), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8500000; t = Za(sizeof(YX0i));}
 sf.pos=8500001;
 t->Vmessage = Amsg;
 sf.pos=8500002;
 t->Vpos = MZ__callerPos();
 sf.pos=8500003;
 t->Vbacktrace = (sf.pos=8500004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YX0i__Yalz__YwtA__Yoww(YX0i *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=498400;
  ZthrowThisNil();
 }
 sf.pos=498401;
 Vw = Za(sizeof(YjUM));
 sf.pos=498402;
 YX0i__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=498403;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1471500;
  ZthrowThisNil();
 }
 sf.pos=1471501;
 if ((t->Vpos != NULL))
 {
  sf.pos=1471502;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1471503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1471504;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1471505;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1471506;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1471507;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2491600;
  ZthrowThisNil();
 }
 sf.pos=2491601;
 YX0i__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=2491602;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2491603;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2491604;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2491605;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2491606;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2491607;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2491608;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2491609;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2491610;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2491611;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2491612;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YX0i__Ytlm_I_imt[] = {
 (Tc*)&YX0i__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHRa */
 (Tc*)YX0i__Yalz__YwtA__YRHR, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CKeyExists.ToString - YX0i__Yalz__YwtA__YH0V */
 (Tc*)YX0i__Yalz__YwtA__YxaJa, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJa */
 (Tc*)YX0i__Yalz__YwtA__YxaJ, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJ */
 (Tc*)YX0i__Yalz__YwtA__Yoww, /* MEModule__CKeyExists.toString - YX0i__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YX0i__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YX0i__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - YX0i__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - YX0ia */
};
To ToYX0i[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YX0i__T = {390, (Tc*)&Y9_h, 0, ToYX0i};
void YL9Z(Ti Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Y9qa), Zint2string(Akey))), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
void YEeX(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YMKM), Akey, ((Tc*)&YI), (Tc*)1)), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4520900; t = Za(sizeof(YP_P));}
 sf.pos=4520901;
 t->Vmessage = Amsg;
 sf.pos=4520902;
 t->Vpos = MZ__callerPos();
 sf.pos=4520903;
 t->Vbacktrace = (sf.pos=4520904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YP_P__Yalz__YwtA__Yoww(YP_P *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1391700;
  ZthrowThisNil();
 }
 sf.pos=1391701;
 Vw = Za(sizeof(YjUM));
 sf.pos=1391702;
 YP_P__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1391703;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=994800;
  ZthrowThisNil();
 }
 sf.pos=994801;
 if ((t->Vpos != NULL))
 {
  sf.pos=994802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=994803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=994804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=994805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=994806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=994807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2014900;
  ZthrowThisNil();
 }
 sf.pos=2014901;
 YP_P__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=2014902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2014903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2014904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2014905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2014906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2014907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2014908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2014909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2014910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2014911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2014912;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YP_P__Ytlm_I_imt[] = {
 (Tc*)&YP_P__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIllegalByte.NEW - YP_P__Yalz__YwtA__YRHRa */
 (Tc*)YP_P__Yalz__YwtA__YRHR, /* MEModule__CIllegalByte.NEW - YP_P__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CIllegalByte.ToString - YP_P__Yalz__YwtA__YH0V */
 (Tc*)YP_P__Yalz__YwtA__YxaJa, /* MEModule__CIllegalByte.writeTo - YP_P__Yalz__YwtA__YxaJa */
 (Tc*)YP_P__Yalz__YwtA__YxaJ, /* MEModule__CIllegalByte.writeTo - YP_P__Yalz__YwtA__YxaJ */
 (Tc*)YP_P__Yalz__YwtA__Yoww, /* MEModule__CIllegalByte.toString - YP_P__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CIllegalByte.getMessage - YP_P__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CIllegalByte.getPos - YP_P__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CIllegalByte.getBacktrace - YP_P__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - YP_Pa */
};
To ToYP_P[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YP_P__T = {390, (Tc*)&Ydbm, 0, ToYP_P};
void YLbE() {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y4K_)), YP_P__Ytlm_I_imt, 15);
 ZthrowIobject(ex);
}
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7347100; t = Za(sizeof(YzSI));}
 sf.pos=7347101;
 t->Vmessage = Amsg;
 sf.pos=7347102;
 t->Vpos = MZ__callerPos();
 sf.pos=7347103;
 t->Vbacktrace = (sf.pos=7347104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YzSI__Ylz1__YwtA__Yoww(YzSI *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6943500;
  ZthrowThisNil();
 }
 sf.pos=6943501;
 Vw = Za(sizeof(YjUM));
 sf.pos=6943502;
 YzSI__Ylz1__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6943503;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4413000;
  ZthrowThisNil();
 }
 sf.pos=4413001;
 if ((t->Vpos != NULL))
 {
  sf.pos=4413002;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4413003;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4413004;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4413005;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4413006;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4413007;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5433100;
  ZthrowThisNil();
 }
 sf.pos=5433101;
 YzSI__Ylz1__YwtA__YxaJ(t, Aw);
 sf.pos=5433102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=5433103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5433104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5433105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=5433106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=5433107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=5433108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5433109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=5433110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=5433111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5433112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YzSI__Ytlm_I_imt[] = {
 (Tc*)&YzSI__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHRa */
 (Tc*)YzSI__Ylz1__YwtA__YRHR, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHR */
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YzSI__Ylz1__YwtA__YH0V */
 (Tc*)YzSI__Ylz1__YwtA__YxaJa, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJa */
 (Tc*)YzSI__Ylz1__YwtA__YxaJ, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJ */
 (Tc*)YzSI__Ylz1__YwtA__Yoww, /* MEModule__CDivideByZero.toString - YzSI__Ylz1__YwtA__Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YzSI__Ylz1__YwtA__YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YzSI__Ylz1__YwtA__YvCK */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - YzSI__Ylz1__YwtA__Y4bq */
 (Tc*)0, /* Init - YzSIa */
};
To ToYzSI[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YzSI__T = {390, (Tc*)&YxFl, 0, ToYzSI};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4829900; t = Za(sizeof(YXKl));}
 sf.pos=4829901;
 t->Vmessage = Amsg;
 sf.pos=4829902;
 t->Vpos = MZ__callerPos();
 sf.pos=4829903;
 t->Vbacktrace = (sf.pos=4829904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YXKl__YwtA__Yoww(YXKl *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3219100;
  ZthrowThisNil();
 }
 sf.pos=3219101;
 Vw = Za(sizeof(YjUM));
 sf.pos=3219102;
 YXKl__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3219103;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8968500;
  ZthrowThisNil();
 }
 sf.pos=8968501;
 YXKl__YwtA__YxaJ(t, Aw);
 sf.pos=8968502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=8968503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8968504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8968505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=8968506;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=8968507;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=8968508;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8968509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=8968510;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=8968511;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8968512;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9988600;
  ZthrowThisNil();
 }
 sf.pos=9988601;
 if ((t->Vpos != NULL))
 {
  sf.pos=9988602;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9988603;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9988604;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9988605;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=9988606;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=9988607;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YXKl__Ytlm_I_imt[] = {
 (Tc*)&YXKl__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHRa */
 (Tc*)YXKl__YwtA__YRHR, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHR */
 (Tc*)0, /* MEModule__CIOError.ToString - YXKl__YwtA__YH0V */
 (Tc*)YXKl__YwtA__YxaJa, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJa */
 (Tc*)YXKl__YwtA__YxaJ, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJ */
 (Tc*)YXKl__YwtA__Yoww, /* MEModule__CIOError.toString - YXKl__YwtA__Yoww */
 (Tc*)0, /* MEModule__CIOError.getMessage - YXKl__YwtA__YCzX */
 (Tc*)0, /* MEModule__CIOError.getPos - YXKl__YwtA__YvCK */
 (Tc*)0, /* MEModule__CIOError.getBacktrace - YXKl__YwtA__Y4bq */
 (Tc*)0, /* Init - YXKla */
};
To ToYXKl[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YXKl__T = {390, (Tc*)&YTj3, 0, ToYXKl};
YuDC *YdhH(YuDC *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8723500; t = Za(sizeof(YuDC));}
 sf.pos=8723501;
 t->Vmessage = ((Tc*)&Ynjz);
 sf.pos=8723502;
 t->Vpos = MZ__callerPos();
 sf.pos=8723503;
 t->Vbacktrace = (sf.pos=8723504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YuDC__YwtA__Yoww(YuDC *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1676800;
  ZthrowThisNil();
 }
 sf.pos=1676801;
 Vw = Za(sizeof(YjUM));
 sf.pos=1676802;
 YuDC__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1676803;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8681800;
  ZthrowThisNil();
 }
 sf.pos=8681801;
 YuDC__YwtA__YxaJ(t, Aw);
 sf.pos=8681802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=8681803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8681804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8681805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=8681806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=8681807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=8681808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8681809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=8681810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=8681811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8681812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9701900;
  ZthrowThisNil();
 }
 sf.pos=9701901;
 if ((t->Vpos != NULL))
 {
  sf.pos=9701902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9701903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9701904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9701905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=9701906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=9701907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YuDC__Ytlm_I_imt[] = {
 (Tc*)&YuDC__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHRa */
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHR */
 (Tc*)0, /* MEModule__CWrongType.ToString - YuDC__YwtA__YH0V */
 (Tc*)YuDC__YwtA__YxaJa, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJa */
 (Tc*)YuDC__YwtA__YxaJ, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJ */
 (Tc*)YuDC__YwtA__Yoww, /* MEModule__CWrongType.toString - YuDC__YwtA__Yoww */
 (Tc*)0, /* MEModule__CWrongType.getMessage - YuDC__YwtA__YCzX */
 (Tc*)0, /* MEModule__CWrongType.getPos - YuDC__YwtA__YvCK */
 (Tc*)0, /* MEModule__CWrongType.getBacktrace - YuDC__YwtA__Y4bq */
 (Tc*)0, /* Init - YuDCa */
};
To ToYuDC[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YuDC__T = {390, (Tc*)&YCoZ, 0, ToYuDC};
void YTuG(Ti Apos) {
 Tr ex;
 YuDC *Ve = 0;
 Tr t0 = {NULL};
 Ve = YdhH(NULL);
 Ve->Vpos = MZ__posnr2pos(NULL, Apos);
 *Znao(&ex, Ve, YuDC__Ytlm_I_imt, 24);
 ZthrowIobject(ex);
}
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7808200; t = Za(sizeof(YrHq));}
 sf.pos=7808201;
 t->Vmessage = Amsg;
 sf.pos=7808202;
 t->Vpos = MZ__callerPos();
 sf.pos=7808203;
 t->Vbacktrace = (sf.pos=7808204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Tc *YrHq__YwtA__Yoww(YrHq *t, Tb Averbose) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7987400;
  ZthrowThisNil();
 }
 sf.pos=7987401;
 Vw = Za(sizeof(YjUM));
 sf.pos=7987402;
 YrHq__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7987403;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=41200;
  ZthrowThisNil();
 }
 sf.pos=41201;
 YrHq__YwtA__YxaJ(t, Aw);
 sf.pos=41202;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=41203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=41204;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=41205;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=41206;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=41207;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=41208;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=41209;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=41210;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=41211;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=41212;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1061300;
  ZthrowThisNil();
 }
 sf.pos=1061301;
 if ((t->Vpos != NULL))
 {
  sf.pos=1061302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1061303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1061304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1061305;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1061306;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1061307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YrHq__Ytlm_I_imt[] = {
 (Tc*)&YrHq__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHRa */
 (Tc*)YrHq__YwtA__YRHR, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHR */
 (Tc*)0, /* MEModule__CInternal.ToString - YrHq__YwtA__YH0V */
 (Tc*)YrHq__YwtA__YxaJa, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJa */
 (Tc*)YrHq__YwtA__YxaJ, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJ */
 (Tc*)YrHq__YwtA__Yoww, /* MEModule__CInternal.toString - YrHq__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInternal.getMessage - YrHq__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInternal.getPos - YrHq__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInternal.getBacktrace - YrHq__YwtA__Y4bq */
 (Tc*)0, /* Init - YrHqa */
};
To ToYrHq[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YrHq__T = {390, (Tc*)&YVki, 0, ToYrHq};
void YUSH(YkxB *Apos, Tc *Atext) {
 Tr ex;
 YrHq *Ve = 0;
 Tr t0 = {NULL};
 Ve = YrHq__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, YrHq__Ytlm_I_imt, 26);
 ZthrowIobject(ex);
}
void YxIS(Tr Ae) {
      static int entered = 0;
      int didEnter = entered;
      entered = 1;
 if ((Ae).type == 1)
 {
  Ti VexitVal;
  VexitVal = ((YEro *)Znio(1, 1571802, (Ae)))->Vvalue;
  if (!didEnter) beforeExit();
  exit(VexitVal);
 }
 else
 {
  YvL0(Ae);
  if (!didEnter) beforeExit();
  exit(1);
 }
 return;
}
void YvL0(Tr Ae) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5238600;
 Ylxt();
 sf.pos=5238601;
 YQar(Ae, 1, YeNQ);
 sf.pos=5238617;
 ((Ts (*)(void*))(YeNQ.table[18]))(YeNQ.ptr);
 topFrame = sf.prev;
 return;
}
void YQar(Tr A0, Tb A1, Tr A2) {
 if (A0.ptr == NULL) ZthrowCstringNil("writeTo: object is NIL, cannot select method to invoke");
 if (A2.ptr == NULL) ZthrowCstringNil("writeTo: argument 2 is NIL, cannot select method to invoke");
 switch (A0.type) {
  case 0:
   YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238602)); return;
  case 1:
   YEro__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238603)); return;
  case 2:
   return;
  case 3:
   return;
  case 4:
   YKhn__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238604)); return;
  case 5:
   Y1uN__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238605)); return;
  case 6:
   YAxe__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238606)); return;
  case 7:
   YVNj__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238607)); return;
  case 8:
   return;
  case 9:
   return;
  case 10:
   Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238608)); return;
  case 11:
   Yw3O__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238609)); return;
  case 12:
   Y2EX__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238610)); return;
  case 13:
   return;
  case 14:
   YX0i__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238611)); return;
  case 15:
   YP_P__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238612)); return;
  case 16:
   return;
  case 17:
   YzSI__Ylz1__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238613)); return;
  case 18:
   return;
  case 19:
   YXKl__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238614)); return;
  case 20:
   return;
  case 21:
   return;
  case 22:
   return;
  case 23:
   return;
  case 24:
   YuDC__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238615)); return;
  case 25:
   return;
  case 26:
   YrHq__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238616)); return;
  case 27:
   return;
  case 28:
   return;
 }
 ZthrowCstringBadValue("writeTo: cannot select method to invoke");
 return;
}
/* EModule done */
/* including TIMEModule bodies */
Ti Y9Rj() {
 Ti Vusec;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vusec = 0;
 sf.pos=5084100;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    Vusec = (Ti)tv.tv_sec * 1000000 + (Ti)tv.tv_usec;
 sf.pos=5084101;
 r = Vusec;
 topFrame = sf.prev;
 return r;
}
Y2KX *YgaY(Y2KX *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=534200; t = Za(sizeof(Y2KX));}
 sf.pos=534201;
 YgaYb(t, Y9Rj());
 topFrame = sf.prev;
 return t;
}
Y2KX *YgaYb(Y2KX *t, Ti Ausec) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3293900; t = Za(sizeof(Y2KX));}
 sf.pos=3293901;
  time_t tt = Ausec / 1000000;
  struct tm tms;
  struct tm *tmsp;
#ifdef __MINGW32__
  tmsp = localtime(&tt);
  if (tmsp) tms = *tmsp;
#else
  localtime_r(&tt, &tms);
#endif
  t->Vsec = tms.tm_sec;
  t->Vmin = tms.tm_min;
  t->Vhour = tms.tm_hour;
  t->Vday = tms.tm_mday;
  t->Vmonth = tms.tm_mon + 1;
  t->Vyear = tms.tm_year + 1900;
  t->VweekDay = tms.tm_wday + 1;
  t->VyearDay = tms.tm_yday + 1;
  if (tms.tm_isdst > 0) t->Vdst = 2;
  else if (tms.tm_isdst == 0) t->Vdst = 1;
 sf.pos=3293902;
 t->Vusec = (Ausec % 1000000);
 topFrame = sf.prev;
 return t;
}
Tc *YYTs(Y2KX *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3481800;
  ZthrowThisNil();
 }
 sf.pos=3481801;
 Vw = Za(sizeof(YjUM));
 sf.pos=3481802;
 YjUM__YHhZb(Vw, t->Vyear);
 sf.pos=3481803;
 YJqza(Vw, ((Tc*)&YV));
 sf.pos=3481804;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vmonth));
 sf.pos=3481805;
 YJqza(Vw, ((Tc*)&YV));
 sf.pos=3481806;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vday));
 sf.pos=3481807;
 YJqza(Vw, ((Tc*)&YG));
 sf.pos=3481808;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vhour));
 sf.pos=3481809;
 YJqza(Vw, ((Tc*)&Y5));
 sf.pos=3481810;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vmin));
 sf.pos=3481811;
 YJqza(Vw, ((Tc*)&Y5));
 sf.pos=3481812;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vsec));
 sf.pos=3481813;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
To ToY2KX[] = {
 {0, 0},
};
Tto Y2KX__T = {390, (Tc*)&YeCO, 0, ToY2KX};
/* TIMEModule done */
/* including ZModule bodies */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
}
Tc *YpI_(YkxB *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1818700;
  ZthrowThisNil();
 }
 sf.pos=1818701;
 Vw = Za(sizeof(YjUM));
 sf.pos=1818702;
 if ((t->Vfilename == NULL))
 {
  sf.pos=1818703;
  YJqza(Vw, ((Tc*)&YKo1));
 }
 else
 {
  sf.pos=1818704;
  YJqza(Vw, t->Vfilename);
 }
 sf.pos=1818705;
 YJqza(Vw, ((Tc*)&YBpY));
 sf.pos=1818706;
 YjUM__YHhZb(Vw, t->Vlnum);
 sf.pos=1818707;
 YJqza(Vw, ((Tc*)&Y8ES));
 sf.pos=1818708;
 YjUM__YHhZb(Vw, t->Vcol);
 sf.pos=1818709;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
To ToYkxB[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* filename */
 {0, (Tt*)&string__T}, /* text */
};
Tto YkxB__T = {390, (Tc*)&YBCs, 0, ToYkxB};
/* ZModule done */
/* including IOModule bodies */
Tr Yd89() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdin;
 r = Vfile;
 return r;
}
Tr Yvyt() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdout;
 r = Vfile;
 return r;
}
Tr YsM3() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stderr;
 r = Vfile;
 return r;
}
Tc **YdXi__imtt[] = {
  Yw8L__YdXi_imt,
    0,
  YjUM__YdXi_imt,
    0,
};
Ti YFeQ(Yw8L *t) {
 Ti Vb;
 Zsf sf;
 Ti r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1605300;
  ZthrowThisNil();
 }
 sf.pos=1605301;
 if ((t->Vfd == NULL))
 {
  Tr ex;
  sf.pos=1605302;
  *Znao(&ex, YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8)), YXKl__Ytlm_I_imt, 19);
  ZthrowIobject(ex);
 }
 Vb = 0;
 sf.pos=1605303;
 Vb = fgetc(t->Vfd);
 sf.pos=1605304;
 r = Vb;
 topFrame = sf.prev;
 return r;
}
Tc *YaEh(Yw8L *t) {
 Ti Vb;
 Ti VcrCount;
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7284100;
  ZthrowThisNil();
 }
 sf.pos=7284101;
 Vb = YFeQ(t);
 sf.pos=7284102;
 if ((Vb == Y3QJ))
 {
  sf.pos=7284103;
  r = NULL;
  rt = 1;
  goto Yphh;
 }
 sf.pos=7284104;
 Vw = Za(sizeof(YjUM));
 VcrCount = 0;
 sf.pos=7284105;
 while (((Vb != Y3QJ) && (Vb != 10)))
 {
  sf.pos=7284106;
  if ((Vb == 13))
  {
   sf.pos=7284107;
   ++(VcrCount);
  }
  else
  {
   sf.pos=7284108;
   while ((VcrCount > 0))
   {
    sf.pos=7284109;
    Ye7fa(Vw, 13);
    sf.pos=7284110;
    --(VcrCount);
   sf.pos=7284111;
   }
   sf.pos=7284112;
   Ye7fa(Vw, Vb);
  }
  sf.pos=7284113;
  Vb = YFeQ(t);
 sf.pos=7284114;
 }
 sf.pos=7284115;
 r = YbNW(Vw);
Yphh:
 topFrame = sf.prev;
 return r;
}
Tl *YCm1(Yw8L *t) {
 Zsf sf;
 Tl *r = 0;
 Tl *Vresult = NULL;
 Tc *Vline = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8702500;
  ZthrowThisNil();
 }
 sf.pos=8702501;
 Vresult = ZnewList((Tt*)&string__T, 0);
 sf.pos=8702502;
 while (1)
 {
  sf.pos=8702503;
  Vline = YaEh(t);
  sf.pos=8702504;
  if ((Vline == NULL))
  {
   rt = 2;
   goto YwED;
  }
  sf.pos=8702505;
  ZLap((Tl*)Vresult, (Tz)(void*)Vline);
YwED:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=8702506;
 }
 sf.pos=8702507;
 r = Vresult;
 topFrame = sf.prev;
 return r;
}
Ts YwHoa(Yw8L *t, Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9482300;
  ZthrowThisNil();
 }
 Vret = 0;
 sf.pos=9482301;
 if ((t->Vfd == NULL))
 {
  Tr ex;
  sf.pos=9482302;
  *Znao(&ex, YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8)), YXKl__Ytlm_I_imt, 19);
  ZthrowIobject(ex);
 }
 sf.pos=9482303;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, t->Vfd) == 1)
   Vret = 1;
  else
   Vret = 0;
  }
 sf.pos=9482304;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts YGmp(Yw8L *t) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6056700;
  ZthrowThisNil();
 }
 sf.pos=6056701;
 Vret = 0;
 sf.pos=6056702;
 if ((t->Vfd != NULL))
 {
  sf.pos=6056703;
 if (fflush(t->Vfd) == 0)
  Vret = 1;
 else
  Vret = 0;
 }
 sf.pos=6056704;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts YrF8(Yw8L *t) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1575500;
  ZthrowThisNil();
 }
 sf.pos=1575501;
 Vret = 0;
 sf.pos=1575502;
 if ((t->Vfd != NULL))
 {
  sf.pos=1575503;
 if (fflush(t->Vfd) != 0) Vret = 0;
  sf.pos=1575504;
 if (fclose(t->Vfd) != 0) Vret = 0;
  sf.pos=1575505;
  t->Vfd = NULL;
 }
 sf.pos=1575506;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5981900;
  ZthrowThisNil();
 }
 sf.pos=5981901;
 r = YwHoa(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext) {
 Zsf sf;
 Ts r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6618800;
  ZthrowThisNil();
 }
 sf.pos=6618801;
 if (((YwHoa(t, Atext) == 1) && (YwHoa(t, ((Tc*)&Yk)) == 1)))
 {
  sf.pos=6618802;
  r = 1;
  rt = 1;
  goto Y7Vd;
 }
 sf.pos=6618803;
 r = 0;
Y7Vd:
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YRt7g(Yw8L *t) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8261800;
  ZthrowThisNil();
 }
 sf.pos=8261801;
 r = YwHoa(t, ((Tc*)&Yk));
 topFrame = sf.prev;
 return r;
}
Tc *Yw8L__Yw8L_I_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZa */
 (Tc*)Yw8L__YHhZb, /* MIOModule__CFile.write - Yw8L__YHhZb */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZc */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZd */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZe */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZf */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZg */
 (Tc*)0, /* MIOModule__CFile.writeByte - YvfVa */
 (Tc*)0, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7a */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7b */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7c */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7d */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7e */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7f */
 (Tc*)Yw8L__YRt7g, /* MIOModule__CFile.print - Yw8L__YRt7g */
 (Tc*)0, /* MIOModule__CFile.format - Yw8L__YTPv */
 (Tc*)0,
 (Tc*)0,
 (Tc*)YFeQ, /* MIOModule__CFile.readByte - YFeQ */
 (Tc*)0, /* MIOModule__CFile.readChar - YAPp */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyuma */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyum */
 (Tc*)0, /* MIOModule__CFile.readAllBytes - YVfz */
 (Tc*)YaEh, /* MIOModule__CFile.readLine - YaEh */
 (Tc*)0, /* MIOModule__CFile.readLineRaw - Yn2l */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1a */
 (Tc*)YCm1, /* MIOModule__CFile.readAllLines - YCm1 */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWFa */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWF */
 (Tc*)0, /* MIOModule__CFile.writeAllLines - YZFx */
 (Tc*)YGmp, /* MIOModule__CFile.flush - YGmp */
 (Tc*)YrF8, /* MIOModule__CFile.close - YrF8 */
 (Tc*)0, /* MIOModule__CFile.Finish - YSo_ */
 (Tc*)0, /* Init - Yw8La */
};
Tc *Yw8L__YdXi_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
};
To ToYw8L[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* name */
};
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, ToYw8L};
Tr YsGz(Tc *AfileName) {
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9983800;
 {
  int fnr = open(ZgetCstring(AfileName), O_RDONLY);
  if (fnr >= 0) {
 sf.pos=9983801;
 Vfile = *Znao(&Vfile, Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 sf.pos=9983802;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "r");
  }
 }
 sf.pos=9983803;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
Tr YiBk(Tc *AfileName, Tb Atruncate) {
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8158000;
 {
  int flags = O_WRONLY|O_CREAT;
  if (Atruncate) flags |= O_TRUNC;
  int fnr = open(ZgetCstring(AfileName), flags, 0666);
  if (fnr >= 0) {
   if (!Atruncate) lseek(fnr, 0, SEEK_END);
 sf.pos=8158001;
 Vfile = *Znao(&Vfile, Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 sf.pos=8158002;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "w");
  }
 }
 sf.pos=8158003;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
Ts Yvcu(Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vret = 0;
 sf.pos=8487000;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, stdout) == 1)
   Vret = 1;
  else
   Vret = 0;
 }
 sf.pos=8487001;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts Yl0k(Tc *Atext) {
 Ts Vret;
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vret = 0;
 sf.pos=187200;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=187201;
 if ((Vlen == 0 || fwrite(ZgetCstring(Atext), (size_t)Vlen, 1, stdout) == 1) && fputc('\n', stdout) >= 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=187202;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts Ylxt() {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vret = 0;
 sf.pos=4676100;
 if (fflush(stdout) == 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=4676101;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts YJqza(YjUM *t, Tc *Atext) {
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8998700;
  ZthrowThisNil();
 }
 sf.pos=8998701;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=8998702;
 if ((t->Vs == NULL))
 {
  sf.pos=8998703;
  t->Vs = ZnewArray((Tt*)&byte__T, sizeof(Tc), (Vlen + 30));
  sf.pos=8998704;
  Zas(t->Vs, Atext, 0, 0);
  sf.pos=8998705;
  t->VsLen = Vlen;
 }
 else
 {
  sf.pos=8998706;
  if ((((t->VsLen + Vlen) + 1) >= ZArraySize(t->Vs)))
  {
   sf.pos=8998707;
   ZarrayResize(t->Vs, sizeof(Tc), (((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + Vlen) + 50)) ;
  }
  sf.pos=8998708;
  Zas(t->Vs, Atext, 0, t->VsLen);
  sf.pos=8998709;
  t->VsLen += Vlen;
 }
 sf.pos=8998710;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Ts Ye7fa(YjUM *t, Ti Abyte) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3855200;
  ZthrowThisNil();
 }
 sf.pos=3855201;
 if ((t->Vs == NULL))
 {
  sf.pos=3855202;
  t->Vs = ZnewArray((Tt*)&byte__T, sizeof(Tc), 30);
 }
 else {
 sf.pos=3855203;
 if (((t->VsLen + 2) >= ZArraySize(t->Vs)))
 {
  sf.pos=3855204;
  ZarrayResize(t->Vs, sizeof(Tc), ((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + 50)) ;
 }
 }
 sf.pos=3855205;
 (*(Tc*)ZarrayPtr(t->Vs, (t->VsLen)++)) = Abyte;
 sf.pos=3855206;
 (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
 sf.pos=3855207;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Tc *YbNW(YjUM *t) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vr = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6453100;
  ZthrowThisNil();
 }
 sf.pos=6453101;
 if ((t->Vs == NULL))
 {
  sf.pos=6453102;
  Vr = ((Tc*)&Ya);
 }
 else
 {
  sf.pos=6453103;
  Vr = ZnewString(t->Vs->ptr, t->VsLen);
 }
 sf.pos=6453104;
 r = Vr;
 topFrame = sf.prev;
 return r;
}
Ts YjUM__YHhZb(YjUM *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7200700;
  ZthrowThisNil();
 }
 sf.pos=7200701;
 r = YJqza(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Ts YjUM__YRt7(YjUM *t, Tc *Atext) {
 Zsf sf;
 Ts r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2676000;
  ZthrowThisNil();
 }
 sf.pos=2676001;
 if (((YJqza(t, Atext) == 1) && (YJqza(t, ((Tc*)&Yk)) == 1)))
 {
  sf.pos=2676002;
  r = 1;
  rt = 1;
  goto Yvkn;
 }
 sf.pos=2676003;
 r = 0;
Yvkn:
 topFrame = sf.prev;
 return r;
}
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {2, 0},
 {0, (Tt*)&array__T}, /* s */
 {0, (Tt*)&string__T}, /* x */
};
Tto YjUM__T = {390, (Tc*)&YE4c, 0, ToYjUM};
int JIOModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=745200;
   Y59X = Yd89();
   sf.pos=745201;
   Yb0q = Yvyt();
   sf.pos=745202;
   YeNQ = YsM3();
  }
  topFrame = sf.prev;
 }
 return done;
}
/* IOModule done */
/* including LOGModule bodies */
void YFf6(Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 Ygkj(7, Amsg, Apos, Aflags);
 return;
}
void Ygkj(Te Alevel, Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 YjUM *Vw = 0;
 Tc *VwholeMsg = NULL;
 Y2KX *Vtv = 0;
 Tr t0 = {NULL};
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 int rt = 0;
 if ((((((Alevel == 0) && !(YuOS(YU8T)))) || (((Alevel == 1) && (Y86c__Ye9f(YlUb) < 2)))) || (((Alevel == 2) && (Y86c__Ye9f(YlUb) < 1)))))
 {
  rt = 1;
  goto YbRZ;
 }
 ++(*ZDictGetIntP(Ytd2, (Tz)(Ti)Alevel));
 Vw = Za(sizeof(YjUM));
 if ((Apos != NULL))
 {
  YJqza(Vw, YpI_(Apos));
  YJqza(Vw, ((Tc*)&YFDa));
 }
 if ((((Aflags) & 2) >> 1))
 {
  YJqza(Vw, ((Tc*)&YJ5p));
 }
 switch (Alevel)
 {
 case 4:
  {
   YJqza(Vw, ((Tc*)&Yyq1));
    break;
  }
 case 5:
  {
   YJqza(Vw, ((Tc*)&Y27a));
    break;
  }
 case 6:
  {
   YJqza(Vw, ((Tc*)&Y3l3));
    break;
  }
 case 7:
  {
   YJqza(Vw, ((Tc*)&YmM8));
    break;
  }
 }
 YJqza(Vw, YmaW);
 YJqza(Vw, Amsg);
 if ((((Aflags) & 1)))
 {
  YwlF(*Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 }
 if (!((((Aflags) & 4) >> 2)))
 {
  YJqza(Vw, ((Tc*)&Yk));
 }
 VwholeMsg = YbNW(Vw);
 Yvcu(VwholeMsg);
 if ((((Yz2b).ptr) != NULL))
 {
  if (YiAD)
  {
   Vtv = YgaY(NULL);
   ((Ts (*)(void*, Tc*))(Yz2b.table[1]))(Yz2b.ptr, ZcS5(YYTs(Vtv), ((Tc*)&YU), (t1 = ZintFormat(((Tc*)&YwV7), Vtv->Vusec)), ((Tc*)&YG), (Tc*)1));
  }
  ((Ts (*)(void*, Tc*))(Yz2b.table[1]))(Yz2b.ptr, VwholeMsg);
 }
 if ((Alevel >= 5))
 {
  ++(Yrpn);
  Y7LJ();
 }
 else {
 if (((Y9Rj() - YvW3) > YOwl))
 {
  Y7LJ();
 }
 }
 if ((Alevel == 7))
 {
  Zexit(Ypp_a(NULL, ((Tc*)&YQAha), 205, 7), 10);
 }
YbRZ:
 return;
}
void YwlF(Tr Aout) {
 Zsf sf;
 Tl *Zf1 = NULL;
 YkxB *Vp = 0;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8489900;
 ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ((Tc*)&Ya));
 sf.pos=8489901;
 ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ((Tc*)&YDzC));
 sf.pos=8489903;
 {
  Tfl Zf1i;
  Zf1 = (sf.pos=8489904, MZ__backtrace(0, -1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vp;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8489905;
  ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ZcS3(YpI_(Vp), ((Tc*)&YFDa), (t0 = Vp->Vtext)));
  sf.pos=8489906;
  }
 }
 topFrame = sf.prev;
 return;
}
void Y7LJ() {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5655500;
 Ylxt();
 sf.pos=5655501;
 if ((((Yz2b).ptr) != NULL))
 {
  sf.pos=5655502;
  ((Ts (*)(void*))(Yz2b.table[34]))(Yz2b.ptr);
 }
 sf.pos=5655503;
 YvW3 = Y9Rj();
 topFrame = sf.prev;
 return;
}
int JLOGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 if (round == 0) {
   sf.pos=8332600;
   YU8T = YttT(NULL, ((Tc*)&YLa), ((Tc*)&YGwH), 0, ((Tc*)&YhpM));
   sf.pos=8332601;
   YlUb = YttT(NULL, ((Tc*)&Y2a), ((Tc*)&YUsn), 0, ((Tc*)&YSuP));
  }
  if (round == 0) {
   sf.pos=8332602;
   Ytd2 = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MLOGModule__ELevel__T, (Tt*)&int__T, 0), (Tz)(Ti)0, (Tz)(Ti)0), (Tz)(Ti)1, (Tz)(Ti)0), (Tz)(Ti)2, (Tz)(Ti)0), (Tz)(Ti)3, (Tz)(Ti)0), (Tz)(Ti)4, (Tz)(Ti)0), (Tz)(Ti)5, (Tz)(Ti)0), (Tz)(Ti)6, (Tz)(Ti)0), (Tz)(Ti)7, (Tz)(Ti)0);
  }
  topFrame = sf.prev;
 }
 return done;
}
/* LOGModule done */
/* including ARGModule bodies */
Ts Ytu_() {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6650100;
 r = (((Y6fX == NULL)) ? (0) : (1));
 topFrame = sf.prev;
 return r;
}
Ti Y2H3() {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4183000;
 r = ZListSize(Y1p3);
 topFrame = sf.prev;
 return r;
}
Tl *YUgp() {
 Zsf sf;
 Tl *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2522700;
 r = Y1p3;
 topFrame = sf.prev;
 return r;
}
To ToYnU5[] = {
 {0, 0},
};
Tto YnU5__T = {390, (Tc*)&Yr32, 0, ToYnU5};
void YY8i() {
 Tr t0 = {NULL};
 if ((Y6fX == NULL))
 {
  Tr ex;
  *Znao(&ex, YVNj__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YeBP)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 return;
}
void YZH8() {
 Zsf sf;
 Tc *Varg = NULL;
 Tc *Vvalue = NULL;
 Tc *Vflagname = NULL;
 Tc *Vflagname1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vk = NULL;
 Tl *Zf21 = NULL;
 Tc *Vk1 = NULL;
 Tr Vflag = {NULL};
 Y86c *Vbflag = 0;
 Y86c *Vbflag1 = 0;
 Y_SI *Vsflag = 0;
 YJQu *Viflag = 0;
 YzqH *Vsflag1 = 0;
 Tr t0 = {NULL};
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8253300;
 if ((Y6fX == NULL))
 {
  Tb VdoFlags;
  Tb Vskip;
  sf.pos=8253301;
  if ((Y7be == NULL))
  {
   sf.pos=8253302;
   Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
   sf.pos=8253303;
   YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  }
  sf.pos=8253304;
  if ((YUBd && (((ZDictSize(Y7be) > 0) || (ZDictSize(YBQy) > 0)))))
  {
   Tr ex;
   sf.pos=8253305;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y7T_)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=8253306;
  {
   Tfl Zf2i;
   Zf2 = ZDictKeys(Y7be, 0);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vk;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tr YXyJ = {NULL};
   sf.pos=8253307;
   (YXyJ = ZDictGetIobj(Y7be, (Tz)(void*)Vk), ((void (*)(void*))(YXyJ.table[17]))(YXyJ.ptr));
   sf.pos=8253308;
   }
  }
  sf.pos=8253309;
  {
   Tfl Zf21i;
   Zf21 = ZDictKeys(YBQy, 0);
   Zf21i.l = Zf21;
   Zf21i.valp = (void*)&Vk1;
   Zf21i.i = 0;
   for (; ZforListPtrCont(&Zf21i); ) {
   Tr YWyJ = {NULL};
   sf.pos=8253310;
   (YWyJ = ZDictGetIobj(YBQy, (Tz)(void*)Vk1), ((void (*)(void*))(YWyJ.table[17]))(YWyJ.ptr));
   sf.pos=8253311;
   }
  }
  sf.pos=8253312;
  Y6fX = ZnewList((Tt*)&string__T, 0);
  sf.pos=8253313;
  VdoFlags = !(YUBd);
  Vskip = 0;
  sf.pos=8253314;
  {
   Ti Vi;
   Tfr Zf2;
   ZforRangeNew(0, (ZListSize(Y1p3) - 1), 0, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vi); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vi)) {
   sf.pos=8253315;
   if (Vskip)
   {
    sf.pos=8253316;
    Vskip = 0;
    rt = 4;
    if (rt) goto YgsM;
   }
   sf.pos=8253317;
   Varg = ((Tc *)ZListGetPtr(Y1p3, Vi));
   sf.pos=8253318;
   if (((!(VdoFlags) || (ZstringGetChar(Varg, 0) != 45)) || (ZstringCmp(Varg, ((Tc*)&YT)) == 0)))
   {
    sf.pos=8253319;
    ZLap((Tl*)Y6fX, (Tz)(void*)Varg);
    sf.pos=8253320;
    if (YQpY)
    {
     sf.pos=8253321;
     VdoFlags = 0;
    }
   }
   else
   {
    sf.pos=8253322;
    if ((ZstringCmp(Varg, ((Tc*)&Y1ia)) == 0))
    {
     sf.pos=8253323;
     VdoFlags = 0;
    }
    else
    {
     Vflag.ptr = NULL;
     Vvalue = NULL;
     sf.pos=8253324;
     if ((ZstringCmp(ZstringSlice(Varg, 0, 1, 0), ((Tc*)&Y1ia)) == 0))
     {
      Ti Vidx;
      sf.pos=8253325;
      Vflagname = ZstringSlice(Varg, 2, -1, 0);
      sf.pos=8253326;
      if ((!(YhUP) && ((((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) == 0) || (ZstringCmp(Vflagname, ((Tc*)&Y3vi)) == 0)) || (ZstringCmp(Vflagname, ((Tc*)&Yll7)) == 0)))))
      {
       sf.pos=8253327;
       Yfj5((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) != 0));
      }
      sf.pos=8253328;
      Vidx = ZstringFindChar(Vflagname, 61, 0);
      sf.pos=8253329;
      if ((Vidx > 0))
      {
       sf.pos=8253330;
       Vvalue = ZstringSlice(Vflagname, (Vidx + 1), -1, 0);
       sf.pos=8253331;
       Vflagname = ZstringSlice(Vflagname, 0, (Vidx - 1), 0);
      }
      sf.pos=8253332;
      Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)Vflagname, trZero);
      sf.pos=8253333;
      if (((((Vflag).ptr) == NULL) && (ZstringCmp(ZstringSlice(Vflagname, 0, 1, 0), ((Tc*)&YhZb)) == 0)))
      {
       sf.pos=8253334;
       Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)ZstringSlice(Vflagname, 2, -1, 0), trZero);
       sf.pos=8253335;
       if ((((Vflag).ptr) != NULL))
       {
        sf.pos=8253336;
        if ((Vflag).type == 0)
        {
         sf.pos=8253337;
         Vflagname = ZstringSlice(Vflagname, 2, -1, 0);
         sf.pos=8253338;
         Vvalue = ((Tc*)&YhZb);
        }
        else
        {
         sf.pos=8253339;
         Vflag = trZero;
        }
       }
      }
     }
     else
     {
      Ti Vidx;
      sf.pos=8253340;
      Vflagname1 = ZstringSlice(Varg, 1, -1, 0);
      sf.pos=8253341;
      Vidx = ZstringFindChar(Vflagname1, 61, 0);
      sf.pos=8253342;
      if ((Vidx > 0))
      {
       sf.pos=8253343;
       Vvalue = ZstringSlice(Vflagname1, (Vidx + 1), -1, 0);
       sf.pos=8253344;
       Vflagname1 = ZstringSlice(Vflagname1, 0, (Vidx - 1), 0);
      }
      else
      {
       sf.pos=8253345;
       while ((ZstringSize(Vflagname1) > 1))
       {
        sf.pos=8253346;
        Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)ZstringSlice(Vflagname1, 0, 0, 0), trZero);
        sf.pos=8253347;
        if ((((Vflag).ptr) == NULL))
        {
         rt = 2;
         goto Yy70;
        }
        else
        {
         sf.pos=8253348;
         if ((Vflag).type == 0)
         {
          sf.pos=8253349;
          ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
          sf.pos=8253351;
          Vbflag = ((Y86c *)Znio(0, 8253350, (Vflag)));
          sf.pos=8253352;
          Vbflag->Vcurrent = !(Vbflag->Vdefault);
          sf.pos=8253353;
          Vflagname1 = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=8253354;
          Vflag = trZero;
         }
         else {
         sf.pos=8253355;
 if ((Vflag).type == 3)
         {
          rt = 2;
          goto YuBh;
         }
         else {
         sf.pos=8253356;
 if ((!(Y_kI) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[7])))))
         {
          sf.pos=8253357;
          Vvalue = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=8253358;
          Vflagname1 = ZstringSlice(Vflagname1, 0, 0, 0);
         }
         }}
YuBh:
         if (rt) goto Yy70;
        }
Yy70:
        if (rt == 2) { rt &= 1; break; }
       sf.pos=8253359;
       }
      }
      sf.pos=8253360;
      if ((ZstringSize(Vflagname1) != 1))
      {
       sf.pos=8253361;
       YSUO(ZcS(((Tc*)&YcW8), Varg));
      }
      else {
      sf.pos=8253362;
 if ((((Vflag).ptr) == NULL))
      {
       sf.pos=8253363;
       Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)Vflagname1, trZero);
      }
      }
     }
     sf.pos=8253364;
     if ((((Vflag).ptr) == NULL))
     {
      sf.pos=8253365;
      if (!(YUBd))
      {
       sf.pos=8253366;
       YSUO(ZcS(((Tc*)&Y2hB), Varg));
      }
     }
     else
     {
      sf.pos=8253367;
      if ((((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])) > 0) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[6])))))
      {
       sf.pos=8253368;
       YSUO(ZcS(((Tc*)&YcLH), Varg));
      }
      sf.pos=8253369;
      ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
      sf.pos=8253370;
      if ((Vflag).type == 0)
      {
       sf.pos=8253372;
       Vbflag1 = ((Y86c *)Znio(0, 8253371, (Vflag)));
       sf.pos=8253373;
       if ((Vvalue != NULL))
       {
        sf.pos=8253374;
        if (((ZstringCmp(Vvalue, ((Tc*)&YjK7)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YsfP)) == 0)))
        {
         sf.pos=8253375;
         Vbflag1->Vcurrent = 1;
        }
        else {
        sf.pos=8253376;
 if (((ZstringCmp(Vvalue, ((Tc*)&YhZb)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YvpX)) == 0)))
        {
         sf.pos=8253377;
         Vbflag1->Vcurrent = 0;
        }
        else
        {
         sf.pos=8253378;
         YSUO(ZcS(((Tc*)&YHSJ), Varg));
        }
        }
       }
       else
       {
        sf.pos=8253379;
        Vbflag1->Vcurrent = !(Vbflag1->Vdefault);
       }
      }
      else {
      sf.pos=8253380;
 if ((Vflag).type == 3)
      {
       sf.pos=8253381;
       if ((Vvalue != NULL))
       {
        sf.pos=8253382;
        YSUO(ZcS(((Tc*)&Y6QK), Varg));
       }
       sf.pos=8253384;
       Vsflag = ((Y_SI *)Znio(3, 8253383, (Vflag)));
       sf.pos=8253385;
       Vsflag->Vcurrent = ZnewList((Tt*)&string__T, 0);
       sf.pos=8253386;
       {
        Ti Vj;
        Tfr Zf7;
        ZforRangeNew((Vi + 1), (ZListSize(Y1p3) - 1), 0, 1, &Zf7);
        for (ZforRangeGetInt(&Zf7, &Vj); ZforRangeContInt(&Zf7); ZforRangeNextInt(&Zf7, &Vj)) {
        sf.pos=8253387;
        ZLap((Tl*)Vsflag->Vcurrent, (Tz)(void*)((Tc *)ZListGetPtr(Y1p3, Vj)));
        sf.pos=8253388;
        }
       }
       rt = 2;
       goto YxuQ;
      }
      else
      {
       sf.pos=8253389;
       if ((!((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[8]))) && (Vvalue == NULL)))
       {
        sf.pos=8253390;
        Vskip = 1;
        sf.pos=8253391;
        if ((Vi == (ZListSize(Y1p3) - 1)))
        {
         sf.pos=8253392;
         YSUO(ZcS(((Tc*)&Y_ju), Varg));
        }
        sf.pos=8253393;
        Vvalue = ((Tc *)ZListGetPtr(Y1p3, (Vi + 1)));
       }
       sf.pos=8253394;
       if ((Vflag).type == 1)
       {
        sf.pos=8253396;
        Viflag = ((YJQu *)Znio(1, 8253395, (Vflag)));
        sf.pos=8253397;
        if ((Vvalue == NULL))
        {
         sf.pos=8253398;
         Viflag->Vcurrent = Viflag->Vdefault;
         sf.pos=8253399;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)Viflag->Vdefault);
        }
        else
        {
         Ti VintVal;
         sf.pos=8253400;
         VintVal = ZstringToInt(Vvalue, 1, 0);
         sf.pos=8253401;
         Viflag->Vcurrent = VintVal;
         sf.pos=8253402;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)VintVal);
        }
       }
       else {
       sf.pos=8253403;
 if ((Vflag).type == 2)
       {
        sf.pos=8253405;
        Vsflag1 = ((YzqH *)Znio(2, 8253404, (Vflag)));
        sf.pos=8253406;
        if ((Vvalue == NULL))
        {
         sf.pos=8253407;
         Vsflag1->Vcurrent = Vsflag1->Vdefault;
         sf.pos=8253408;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vsflag1->Vdefault);
        }
        else
        {
         sf.pos=8253409;
         Vsflag1->Vcurrent = Vvalue;
         sf.pos=8253410;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vvalue);
        }
       }
       else
       {
        Tr ex;
        sf.pos=8253411;
        *Znao(&ex, YrHq__YwtA__YRHR(NULL, ((Tc*)&YjTs)), YrHq__Ytlm_I_imt, 26);
        ZthrowIobject(ex);
       }
       }
      }
      }
YxuQ:
      if (rt) goto YdgD;
     }
YdgD:
     if (rt) goto YOd6;
    }
YOd6:
    if (rt) goto YgsM;
   }
YgsM:
   if (rt == 2) { rt &= 1; break; }
   if (rt == 4) { rt &= 1; continue; }
   sf.pos=8253412;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YSUO(Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8529500;
 ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, Amsg);
 sf.pos=8529501;
 if ((Yun4 != NULL))
 {
  sf.pos=8529502;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=8529503;
 if (!(YhUP))
 {
  sf.pos=8529504;
  ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, ZcS3(((Tc*)&YkFE), YzvW, ((Tc*)&Y15F)));
 }
 sf.pos=8529505;
 Zexit(Ypp_a(NULL, ((Tc*)&Ye5Da), 456, 5), 1);
 topFrame = sf.prev;
 return;
}
void Yfj5(Tb Averbose) {
 Ti VmaxLeadLen;
 Zsf sf;
 Td *VallFlags = NULL;
 Tl *Zf1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vkey = NULL;
 Tc *VargText = NULL;
 Tc *Vlead = NULL;
 Tl *Zf11 = NULL;
 Tc *Vkey1 = NULL;
 Tr Vflag = {NULL};
 Tr Vflag1 = {NULL};
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2956000;
 if ((Yun4 != NULL))
 {
  sf.pos=2956001;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=2956002;
 Yl0k(((Tc*)&YaBy));
 sf.pos=2956003;
 VallFlags = Y7be;
 sf.pos=2956004;
 {
  Tfl Zf11i;
  Zf11 = ZDictKeys(YBQy, 0);
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vkey1;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=2956005;
  Vflag = ZDictGetIobj(YBQy, (Tz)(void*)Vkey1);
  sf.pos=2956006;
  if (((*(Tc**)(Vflag.ptr + (size_t)Vflag.table[1])) == NULL))
  {
   sf.pos=2956007;
   *ZDictGetIobjP(VallFlags, (Tz)(void*)(*(Tc**)(Vflag.ptr + (size_t)Vflag.table[2]))) = Vflag;
  }
  sf.pos=2956008;
  }
 }
 VmaxLeadLen = 0;
 sf.pos=2956009;
 {
  Ti Vdisplay;
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&bool__T, 2), ZLap((Tl*)t0, (Tz)(Ti)0), ZLap((Tl*)t0, (Tz)(Ti)1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdisplay;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=2956010;
  if (Vdisplay)
  {
   sf.pos=2956011;
   YTlu(((Tc*)&YwXF), VmaxLeadLen);
   sf.pos=2956012;
   Yl0k(((Tc*)&YEcf));
  }
  sf.pos=2956013;
  {
   Tfl Zf2i;
   Zf2 = ZstringListSort(ZDictKeys(VallFlags, 0), 1);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vkey;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tb Vopt;
   sf.pos=2956014;
   Vflag1 = ZDictGetIobj(VallFlags, (Tz)(void*)Vkey);
   sf.pos=2956015;
   VargText = ((Tc*)&Ya);
   Vopt = 0;
   sf.pos=2956016;
   if ((Vflag1).type == 1)
   {
    sf.pos=2956017;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956018;
     VargText = ((Tc*)&Yy2p);
    }
    else
    {
     sf.pos=2956019;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956020;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956021;
 if ((Vflag1).type == 2)
   {
    sf.pos=2956022;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956023;
     VargText = ((Tc*)&YanE);
    }
    else
    {
     sf.pos=2956024;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956025;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956026;
 if ((Vflag1).type == 3)
   {
    sf.pos=2956027;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956028;
     VargText = ((Tc*)&YDci);
    }
    else
    {
     sf.pos=2956029;
     VargText = ZcS((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])), ((Tc*)&YulU));
    }
    sf.pos=2956030;
    Vopt = 1;
   }
   }}
   sf.pos=2956031;
   if ((ZbyteStringSize(VargText) != 0))
   {
    sf.pos=2956032;
    if (Vopt)
    {
     sf.pos=2956033;
     VargText = ZcS3(((Tc*)&YVZ), VargText, ((Tc*)&YEa));
    }
    else
    {
     sf.pos=2956034;
     VargText = ZcS3(((Tc*)&Yq_), VargText, ((Tc*)&Y9a));
    }
   }
   sf.pos=2956035;
   Vlead = ((Tc*)&Ya);
   sf.pos=2956036;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])) != NULL))
   {
    sf.pos=2956037;
    Vlead = ZcS5(((Tc*)&YT), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])), VargText, ((Tc*)&YG), (Tc*)1);
   }
   sf.pos=2956038;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])) != NULL))
   {
    sf.pos=2956039;
    if (((ZbyteStringSize(Vlead) != 0) && (ZbyteStringSize(VargText) != 0)))
    {
     sf.pos=2956040;
     if (Vdisplay)
     {
      sf.pos=2956041;
      if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
      {
       sf.pos=2956042;
       Vlead =  ZcS(Vlead, ((Tc*)&Y_y2));
      }
      sf.pos=2956043;
      Yl0k(Vlead);
     }
     sf.pos=2956044;
     Vlead = ((Tc*)&Ya);
    }
    sf.pos=2956045;
    Vlead =  ZcS(Vlead, ZcS5(((Tc*)&Y1ia), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])), VargText, ((Tc*)&YG), (Tc*)1));
   }
   sf.pos=2956046;
   if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
   {
    sf.pos=2956047;
    Vlead =  ZcS(Vlead, ((Tc*)&Y2yA));
   }
   sf.pos=2956048;
   if (Vdisplay)
   {
    sf.pos=2956049;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])) != NULL))
    {
     sf.pos=2956050;
     YTlu(Vlead, VmaxLeadLen);
     sf.pos=2956051;
     Yl0k((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])));
    }
    else
    {
     sf.pos=2956052;
     Yl0k(Vlead);
    }
    sf.pos=2956053;
    if (Averbose)
    {
     sf.pos=2956054;
     YTlu(((Tc*)&Ya), VmaxLeadLen);
     sf.pos=2956055;
     Yl0k(ZcS(((Tc*)&Ym4c), YpI_((*(YkxB**)(Vflag1.ptr + (size_t)Vflag1.table[9])))));
    }
   }
   else
   {
    sf.pos=2956056;
    if ((VmaxLeadLen < ZstringSize(Vlead)))
    {
     sf.pos=2956057;
     VmaxLeadLen = ZstringSize(Vlead);
    }
    sf.pos=2956058;
    if ((VmaxLeadLen > 30))
    {
     sf.pos=2956059;
     VmaxLeadLen = 30;
     rt = 2;
     goto YAEw;
    }
YAEw:
    if (rt) goto Yfan;
   }
Yfan:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=2956060;
   }
  }
  sf.pos=2956061;
  }
 }
 sf.pos=2956062;
 Zexit(Ypp_a(NULL, ((Tc*)&Ye5Da), 564, 5), YMLU);
 topFrame = sf.prev;
 return;
}
void YTlu(Tc *Alead, Ti AmaxLeadLen) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8179800;
 Yvcu(Alead);
 sf.pos=8179801;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(ZstringSize(Alead), AmaxLeadLen, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=8179802;
  Yvcu(((Tc*)&YG));
  sf.pos=8179803;
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YAMW(YuMQ *t) {
 Ti Vidx;
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4300000;
  ZthrowThisNil();
 }
 sf.pos=4300001;
 Vidx = ZstringFind(t->Vtext, ((Tc*)&YMtG), 0);
 sf.pos=4300002;
 if ((Vidx < 0))
 {
  sf.pos=4300003;
  r = t->Vtext;
  rt = 1;
  goto YZtK;
 }
 sf.pos=4300004;
 r = ZcS3(ZstringSlice(t->Vtext, 0, (Vidx - 1), 0), YzvW, (t0 = ZstringSlice(t->Vtext, (Vidx + 3), -1, 0)));
YZtK:
 topFrame = sf.prev;
 return r;
}
To ToYuMQ[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* text */
};
Tto YuMQ__T = {390, (Tc*)&Y6qT, 0, ToYuMQ};
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=327300; t = Za(sizeof(Y86c));}
 sf.pos=327301;
 Y86c__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=327302;
 t->Vcurrent = Adefault;
 sf.pos=327303;
 t->Vdefault = Adefault;
 sf.pos=327304;
 t->VcanRepeat = 1;
 topFrame = sf.prev;
 return t;
}
void YEqoa(Y86c *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3891100;
  ZthrowThisNil();
 }
 sf.pos=3891101;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
Tb YHoR(Y86c *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->Vcurrent;
 return r;
}
Tb YuOS(Y86c *t) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6128400;
  ZthrowThisNil();
 }
 sf.pos=6128401;
 r = YHoR(t);
 topFrame = sf.prev;
 return r;
}
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Zsf sf;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7664400; t = Za(sizeof(Y86c));}
 sf.pos=7664401;
 if ((Y6fX != NULL))
 {
  Tr ex;
  sf.pos=7664402;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Yc_h)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=7664403;
 if (((((AshortName == NULL) || (ZbyteStringSize(AshortName) == 0))) && (((AlongName == NULL) || (ZbyteStringSize(AlongName) == 0)))))
 {
  Tr ex;
  sf.pos=7664404;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y6pY)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=7664405;
 if ((ZbyteStringSize(AshortName) != 0))
 {
  sf.pos=7664406;
  t->VshortName = AshortName;
 }
 sf.pos=7664407;
 if ((ZbyteStringSize(AlongName) != 0))
 {
  sf.pos=7664408;
  t->VlongName = AlongName;
 }
 sf.pos=7664409;
 t->Vdoc = Adoc;
 sf.pos=7664410;
 if ((Y7be == NULL))
 {
  sf.pos=7664411;
  Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  sf.pos=7664412;
  YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
 }
 sf.pos=7664413;
 if (((AlongName != NULL) && (ZbyteStringSize(AlongName) != 0)))
 {
  sf.pos=7664414;
  if (ZDictHas(YBQy, (Tz)(void*)AlongName))
  {
   sf.pos=7664415;
   Y86c__YofP(t, AlongName, ZDictGetIobj(YBQy, (Tz)(void*)AlongName), Apos);
  }
  sf.pos=7664416;
  ZDictAddTzIobj(0, YBQy, (Tz)(void*)AlongName, *Znao(&t0, t, Y86c__YuQR_I_imt, 0));
 }
 sf.pos=7664417;
 if (((AshortName != NULL) && (ZbyteStringSize(AshortName) != 0)))
 {
  sf.pos=7664418;
  if ((ZstringSize(AshortName) > 1))
  {
   Tr ex;
   sf.pos=7664419;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y9CP)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=7664420;
  if (ZDictHas(Y7be, (Tz)(void*)AshortName))
  {
   sf.pos=7664421;
   Y86c__YofP(t, AshortName, ZDictGetIobj(Y7be, (Tz)(void*)AshortName), Apos);
  }
  sf.pos=7664422;
  ZDictAddTzIobj(0, Y7be, (Tz)(void*)AshortName, *Znao(&t0, t, Y86c__YuQR_I_imt, 0));
 }
 sf.pos=7664423;
 t->Vpos = Apos;
 topFrame = sf.prev;
 return t;
}
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *Y_CE = NULL;
 void *p1;
 Tr ex;
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7569700;
  ZthrowThisNil();
 }
 sf.pos=7569701;
 VonePos = ((p1 = ((Y_CE = (*(YkxB**)(Aflag.ptr + (size_t)Aflag.table[9])), Y_CE == NULL ? NULL : YpI_(Y_CE)))) == NULL ? (((Tc*)&YbbH)) : p1);
 sf.pos=7569702;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=7569703;
 *Znao(&ex, Ve, YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Ti Y86c__Ye9f(Y86c *t) {
 Ti r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->VsetCount;
 return r;
}
Tc *Y86c__YuQR_I_imt[] = {
 (Tc*)&Y86c__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)Y86c__YcLu, /* MARGModule__CBool.NEW - Y86c__YcLu */
 (Tc*)Y86c__YofP, /* MARGModule__CBool.throwDuplicate - Y86c__YofP */
 (Tc*)0, /* MARGModule__CBool.setArgName - Y86c__Y836 */
 (Tc*)0, /* MARGModule__CBool.disableCompact - Y86c__YJbb */
 (Tc*)0, /* MARGModule__CBool.optionalArg - Y86c__YxuH */
 (Tc*)Y86c__Ye9f, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* Init - Y86ca */
};
To ToY86c[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y86c__T = {390, (Tc*)&YZ1F, 0, ToY86c};
void Y49ga(YJQu *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1635000;
  ZthrowThisNil();
 }
 sf.pos=1635001;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYJQu[] = {
 {6, 0},
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YJQu__T = {390, (Tc*)&YzBa, 0, ToYJQu};
void YJaza(YzqH *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8620600;
  ZthrowThisNil();
 }
 sf.pos=8620601;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYzqH[] = {
 {8, 0},
 {0, (Tt*)&string__T}, /* current */
 {0, (Tt*)&string__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YzqH__T = {390, (Tc*)&YDAE, 0, ToYzqH};
void YSkKa(Y_SI *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6447800;
  ZthrowThisNil();
 }
 sf.pos=6447801;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToY_SI[] = {
 {7, 0},
 {0, (Tt*)&list__T}, /* current */
 {0, (Tt*)&list__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y_SI__T = {390, (Tc*)&Ygf5, 0, ToY_SI};
int JARGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
  done = 0;
  } else if (round > 2001) {
    if (Ytu___r == 0) {
      Ytu___r = Ytu_();
      done &= Ytu___r;
    }
  }
  topFrame = sf.prev;
 }
 return done;
}
/* ARGModule done */
void YqsW(Tc *As) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5608700;
 YFf6(As, NULL, 0);
 topFrame = sf.prev;
 return;
}
Tc *Ygor(Tc *Af, Tl *Aargs) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 Tl *Zf2 = NULL;
 Tc *Vi = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7242400;
 Vres = ((Tc*)&YUR);
 sf.pos=7242401;
 if ((ZListSize(Aargs) >= 1))
 {
  Ti Vc;
  sf.pos=7242402;
  Vc = 0;
  sf.pos=7242403;
  {
   Tfl Zf2i;
   Zf2 = Aargs;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vi;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=7242404;
   if ((Vc == 0))
   {
    sf.pos=7242405;
    Vres =  ZcS(Vres, Vi);
   }
   else
   {
    sf.pos=7242406;
    Vres =  ZcS(Vres, ZcS(((Tc*)&Y6), Vi));
   }
   sf.pos=7242407;
   ++(Vc);
   sf.pos=7242408;
   }
  }
 }
 sf.pos=7242409;
 Vres =  ZcS(Vres, Af);
 sf.pos=7242410;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
void Ywpw(Tc *Af, Tl *Aargs) {
 Zsf sf;
 Tc *Vres = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5650900;
 Vres = Ygor(Af, Aargs);
 sf.pos=5650901;
 ((Ts (*)(void*, Tc*))(Yb0q.table[1]))(Yb0q.ptr, Vres);
 topFrame = sf.prev;
 return;
}
Ts YP9u(Ti *Rrows, Ti *Rcols) {
 Ti Vi;
 Zsf sf;
 Ts r = 0;
 Tc *Vs = NULL;
 Tc *Vrw = NULL;
 Tc *Vcl = NULL;
 Ta *Vdigits = NULL;
 Tc *Zf1 = NULL;
 Tc *Zf11 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1557600;
 if ((((Ts (*)(void*, Tc*))(Yb0q.table[1]))(Yb0q.ptr, ((Tc*)&YQh8)) != 1))
 {
  sf.pos=1557601;
  r = 0;
  rt = 1;
  goto Y9eX;
 }
 sf.pos=1557602;
 Vs = ((Tc*)&Ya);
 sf.pos=1557603;
 while (1)
 {
  Tc Vc;
  sf.pos=1557604;
  Vc = ((Ti (*)(void*))(Y59X.table[22]))(Y59X.ptr);
  sf.pos=1557605;
  if ((Vc == Y3QJ))
  {
   rt = 2;
   goto Yo5G;
  }
  sf.pos=1557606;
  Vs =  ZcS(Vs, ZintAsString(Vc));
  sf.pos=1557607;
  if ((Vc == 82))
  {
   rt = 2;
   goto Yo5G;
  }
Yo5G:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=1557608;
 }
 sf.pos=1557609;
 if (((ZstringGetChar(Vs, 0) != 27) || (ZstringGetChar(Vs, 1) != 91)))
 {
  sf.pos=1557610;
  r = 0;
  rt = 1;
  goto Y9eX;
 }
 sf.pos=1557611;
 Vrw = ((Tc*)&Ya);
 sf.pos=1557612;
 Vcl = ((Tc*)&Ya);
 sf.pos=1557613;
 Vi = 0;
 sf.pos=1557614;
 Vdigits = ZStringToArray(((Tc*)&Y_eV));
 sf.pos=1557615;
 {
  Ti Vc;
  Tfs iZf1;
  Zf1 = ZstringSlice(Vs, 2, -1, 0);
  ZforStringNew(Zf1, &iZf1);
  for (ZforStringGetInt(&iZf1, &Vc); ZforStringContInt(&iZf1); ZforStringNextInt(&iZf1, &Vc)) {
  Ti Vnum;
  sf.pos=1557616;
  Vnum = ZArrayFind((Ta*)Vdigits, (Tz)(Ti)Vc);
  sf.pos=1557617;
  if ((Vnum != -1))
  {
   sf.pos=1557618;
   Vrw =  ZcS(Vrw, Zint2string(Vnum));
  }
  else {
  sf.pos=1557619;
 if ((Vc == 59))
  {
   rt = 2;
   goto Yvc4;
  }
  }
  sf.pos=1557620;
  ++(Vi);
Yvc4:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=1557621;
  }
 }
 sf.pos=1557622;
 {
  Ti Vc;
  Tfs iZf11;
  Zf11 = ZstringSlice(Vs, (Vi + ZstringSize(Vrw)), -1, 0);
  ZforStringNew(Zf11, &iZf11);
  for (ZforStringGetInt(&iZf11, &Vc); ZforStringContInt(&iZf11); ZforStringNextInt(&iZf11, &Vc)) {
  Ti Vnum;
  sf.pos=1557623;
  Vnum = ZArrayFind((Ta*)Vdigits, (Tz)(Ti)Vc);
  sf.pos=1557624;
  if ((Vnum != -1))
  {
   sf.pos=1557625;
   Vcl =  ZcS(Vcl, Zint2string(Vnum));
  }
  else {
  sf.pos=1557626;
 if ((Vc == 82))
  {
   rt = 2;
   goto YyLL;
  }
  }
YyLL:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=1557627;
  }
 }
 sf.pos=1557628;
 (*Rrows) = ZstringToInt(Vrw, 1, 0);
 sf.pos=1557629;
 (*Rcols) = ZstringToInt(Vcl, 1, 0);
 sf.pos=1557630;
 r = 1;
Y9eX:
 topFrame = sf.prev;
 return r;
}
Ti YZ7l(Ys45 *Ar, Tu Acx, Ti Ats) {
 Ti Vrx;
 Tu Vc;
 Zsf sf;
 Ti r = 0;
 Tc *Zf1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7218400;
 Vrx = 0;
 sf.pos=7218401;
 Vc = 0;
 sf.pos=7218402;
 {
  Ti Vj;
  Tfs iZf1;
  Zf1 = Ar->Vtxt;
  ZforStringNew(Zf1, &iZf1);
  for (ZforStringGetInt(&iZf1, &Vj); ZforStringContInt(&iZf1); ZforStringNextInt(&iZf1, &Vj)) {
  sf.pos=7218403;
  if ((Vc >= Acx))
  {
   rt = 2;
   goto YXXh;
  }
  sf.pos=7218404;
  if ((Vj == 9))
  {
   sf.pos=7218405;
   Vrx += (((Ats - 1)) - ((Vrx % Ats)));
  }
  sf.pos=7218406;
  ++(Vrx);
  sf.pos=7218407;
  ++(Vc);
YXXh:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=7218408;
  }
 }
 sf.pos=7218409;
 r = Vrx;
 topFrame = sf.prev;
 return r;
}
Tb YjGn(Ti Ach) {
 Ti Vc;
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vc = 0;
 sf.pos=2382900;
int*c = &Vc;
 sf.pos=2382901;
 Vc = Ach;
 sf.pos=2382902;
 r = isspace(*c) || strchr(",.()+-/*=~%<>[];\"'", *c) != NULL;
 topFrame = sf.prev;
 return r;
}
Ybkz *Yfrg(Ybkz *t, Tc *Aft, Tl *Afp, Ti Aflags, Tc *Aics, Tl *Akw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8261900; t = Za(sizeof(Ybkz));}
 sf.pos=8261901;
 t->Vft = Aft;
 sf.pos=8261902;
 t->Vfpatterns = Afp;
 sf.pos=8261903;
 t->Vflags = Aflags;
 sf.pos=8261904;
 t->VicommentStyle = Aics;
 sf.pos=8261905;
 t->Vkeywords = Akw;
 topFrame = sf.prev;
 return t;
}
To ToYbkz[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* ft */
 {0, (Tt*)&list__T}, /* fpatterns */
 {0, (Tt*)&string__T}, /* icommentStyle */
 {0, (Tt*)&list__T}, /* keywords */
};
Tto Ybkz__T = {390, (Tc*)&Ygt_, 0, ToYbkz};
Tc *Yh7e(Tc *As, Ti Afrom, Ti Alen) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7912800;
 r = ZstringSlice(As, Afrom, (Afrom + Alen), 0);
 topFrame = sf.prev;
 return r;
}
void YiiI(Ys45 *t) {
 Zsf sf;
 Tc *Zf1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9013900;
  ZthrowThisNil();
 }
 sf.pos=9013901;
 t->Vrender = ((Tc*)&Ya);
 sf.pos=9013902;
 {
  Ti Vi;
  Tfs iZf1;
  Zf1 = t->Vtxt;
  ZforStringNew(Zf1, &iZf1);
  for (ZforStringGetInt(&iZf1, &Vi); ZforStringContInt(&iZf1); ZforStringNextInt(&iZf1, &Vi)) {
  sf.pos=9013903;
  if ((Vi == 9))
  {
   sf.pos=9013904;
   {
    Ti Vj;
    Tfr Zf3;
    ZforRangeNew(0, (t->Vts - 1), 0, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vj); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vj)) {
    sf.pos=9013905;
    t->Vrender =  ZcS(t->Vrender, ZintAsString(32));
    sf.pos=9013906;
    }
   }
  }
  else
  {
   sf.pos=9013907;
   t->Vrender =  ZcS(t->Vrender, ZintAsString(Vi));
  }
  sf.pos=9013908;
  }
 }
 sf.pos=9013909;
 YYmf(t);
 topFrame = sf.prev;
 return;
}
void Yz4M(Ys45 *t, Tu Apos, Ti Ach) {
 Ti Vat;
 Zsf sf;
 Tc *Vtmp = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5965100;
  ZthrowThisNil();
 }
 sf.pos=5965101;
 Vat = Apos;
 sf.pos=5965102;
 if ((t->Vtxt == NULL))
 {
  sf.pos=5965103;
  t->Vtxt = ((Tc*)&Ya);
 }
 sf.pos=5965104;
 if ((Apos > ZstringSize(t->Vtxt)))
 {
  sf.pos=5965105;
  Vat = ZstringSize(t->Vtxt);
 }
 sf.pos=5965106;
 Vtmp = ((Tc*)&Ya);
 sf.pos=5965107;
 if ((Vat != 0))
 {
  sf.pos=5965108;
  Vtmp = ZstringSlice(t->Vtxt, 0, (Vat - 1), 0);
 }
 sf.pos=5965109;
 Vtmp =  ZcS(Vtmp, ZintAsString(Ach));
 sf.pos=5965110;
 Vtmp =  ZcS(Vtmp, ZstringSlice(t->Vtxt, (Vat + 1), -1, 0));
 sf.pos=5965111;
 t->Vtxt = Vtmp;
 sf.pos=5965112;
 YiiI(t);
 topFrame = sf.prev;
 return;
}
void YdbI(Ys45 *t, Tu Apos) {
 Zsf sf;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9081000;
  ZthrowThisNil();
 }
 sf.pos=9081001;
 t->Vtxt = ZcS3(ZstringSlice(t->Vtxt, 0, Apos, 0), ((Tc*)&YG), (t0 = ZstringSlice(t->Vtxt, (Apos + 1), -1, 0)));
 sf.pos=9081002;
 YiiI(t);
 topFrame = sf.prev;
 return;
}
void YPEA(Ys45 *t, Tu Apos) {
 Zsf sf;
 Tc *Vtmp = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2094100;
  ZthrowThisNil();
 }
 sf.pos=2094101;
 Vtmp = ((Tc*)&Ya);
 sf.pos=2094102;
 if ((Apos != 0))
 {
  sf.pos=2094103;
  Vtmp = ZstringSlice(t->Vtxt, 0, (Apos - 1), 0);
 }
 sf.pos=2094104;
 t->Vtxt = ZcS3(Vtmp, ((Tc*)&YG), (t0 = ZstringSlice(t->Vtxt, Apos, -1, 0)));
 sf.pos=2094105;
 YiiI(t);
 topFrame = sf.prev;
 return;
}
void Yoz2(Ys45 *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5642100;
  ZthrowThisNil();
 }
 sf.pos=5642101;
 t->Vtxt = t->Vorig;
 sf.pos=5642102;
 YiiI(t);
 topFrame = sf.prev;
 return;
}
void YhvK(Ys45 *t, Ti Apos) {
 Zsf sf;
 Tc *Vtmp = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8745100;
  ZthrowThisNil();
 }
 sf.pos=8745101;
 if (((Apos > 0) || (Apos < ZstringSize(t->Vtxt))))
 {
  sf.pos=8745102;
  Vtmp = ((Tc*)&Ya);
  sf.pos=8745103;
  if ((Apos > 0))
  {
   sf.pos=8745104;
   Vtmp = ZstringSlice(t->Vtxt, 0, (Apos - 1), 0);
  }
  sf.pos=8745105;
  Vtmp =  ZcS(Vtmp, ZstringSlice(t->Vtxt, (Apos + 1), -1, 0));
  sf.pos=8745106;
  t->Vtxt = Vtmp;
 }
 sf.pos=8745107;
 YiiI(t);
 topFrame = sf.prev;
 return;
}
Ti YjIv(Ys45 *t, Ti Arx) {
 Ti Vcrx;
 Ti Vcx;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3362300;
  ZthrowThisNil();
 }
 sf.pos=3362301;
 Vcrx = 0;
 sf.pos=3362302;
 Vcx = 0;
 sf.pos=3362303;
 {
  Tfr Zf1;
  ZforRangeNew(0, ZstringSize(t->Vtxt), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vcx); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vcx)) {
  sf.pos=3362304;
  if ((ZstringGetChar(t->Vtxt, Vcx) == 9))
  {
   sf.pos=3362305;
   Vcrx += (((t->Vts - 1)) - ((Vcrx % t->Vts)));
  }
  sf.pos=3362306;
  ++(Vcrx);
  sf.pos=3362307;
  if ((Vcrx > Arx))
  {
   sf.pos=3362308;
   r = Vcx;
   rt = 1;
   goto YZ_A;
  }
YZ_A:
  if (rt) goto YtsF;
  sf.pos=3362309;
  }
 }
 sf.pos=3362310;
 r = Vcx;
YtsF:
 topFrame = sf.prev;
 return r;
}
void YIV3(Ys45 *t, Tc *As) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3324900;
  ZthrowThisNil();
 }
 sf.pos=3324901;
 t->Vtxt =  ZcS(t->Vtxt, As);
 sf.pos=3324902;
 YiiI(t);
 topFrame = sf.prev;
 return;
}
void YYmf(Ys45 *t) {
 Ti Vj;
 Tb Vpsep;
 Ti Vinstr;
 Zsf sf;
 Tc *Vics = NULL;
 Tl *Vkw = NULL;
 Tl *Zf3 = NULL;
 Tc *Vkeyw = NULL;
 Tc *Vk = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8707800;
  ZthrowThisNil();
 }
 sf.pos=8707801;
 if ((t->Vsyn == NULL))
 {
  sf.pos=8707802;
  t->Vhl = ZnewList((Tt*)&byte__T, 0);
  sf.pos=8707803;
  {
   Ti Vj;
   Tfr Zf2;
   ZforRangeNew(0, (ZstringSize(t->Vrender) - 1), 0, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vj); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vj)) {
   sf.pos=8707804;
   ZLap((Tl*)t->Vhl, (Tz)(Ti)HL_NORMAL);
   sf.pos=8707805;
   }
  }
  sf.pos=8707806;
  rt = 1;
  goto YfoT;
 }
 sf.pos=8707807;
 Vj = 0;
 sf.pos=8707808;
 Vics = t->Vsyn->VicommentStyle;
 sf.pos=8707809;
 t->Vhl = ZnewList((Tt*)&byte__T, 0);
 sf.pos=8707810;
 Vpsep = 1;
 sf.pos=8707811;
 Vinstr = 0;
 sf.pos=8707812;
 Vkw = t->Vsyn->Vkeywords;
 sf.pos=8707813;
 while ((Vj < ZstringSize(t->Vrender)))
 {
  Ti Vc;
  Tc Vphl;
  sf.pos=8707814;
  Vc = ZstringGetChar(t->Vrender, Vj);
  Vphl = 0;
  sf.pos=8707815;
uint8_t*phl = &Vphl;
  sf.pos=8707816;
  Vphl = ((((Vj > 0))) ? (ZListGetInt(t->Vhl, (Vj - 1))) : (HL_NORMAL));
  sf.pos=8707817;
  ZLap((Tl*)t->Vhl, (Tz)(Ti)HL_NORMAL);
  sf.pos=8707818;
  if (((ZstringSize(Vics) > 0) && (Vinstr == 0)))
  {
   sf.pos=8707819;
   if ((ZstringCmp(Yh7e(t->Vrender, Vj, (ZstringSize(Vics) - 1)), Vics) == 0))
   {
    sf.pos=8707820;
    *(Tc*)ZListGetIntP(t->Vhl, Vj) = HL_COMMENT;
    sf.pos=8707821;
    {
     Ti Vi;
     Tfr Zf4;
     ZforRangeNew((Vj + 1), (ZstringSize(t->Vrender) - 1), 0, 1, &Zf4);
     for (ZforRangeGetInt(&Zf4, &Vi); ZforRangeContInt(&Zf4); ZforRangeNextInt(&Zf4, &Vi)) {
     sf.pos=8707822;
     ZLap((Tl*)t->Vhl, (Tz)(Ti)HL_COMMENT);
     sf.pos=8707823;
     }
    }
    rt = 2;
    goto YovX;
   }
YovX:
   if (rt) goto Yel2;
  }
  sf.pos=8707824;
  if (((t->Vsyn->Vflags & HI_STRING) != 0))
  {
   sf.pos=8707825;
   if ((Vinstr != 0))
   {
    sf.pos=8707826;
    *(Tc*)ZListGetIntP(t->Vhl, Vj) = HL_STRING;
    sf.pos=8707827;
    if (((Vc == 92) && ((Vj + 1) < (ZstringSize(t->Vrender) - 1))))
    {
     sf.pos=8707828;
     ZLap((Tl*)t->Vhl, (Tz)(Ti)HL_STRING);
     sf.pos=8707829;
     Vj += 2;
     rt = 4;
     if (rt) goto YoJj;
    }
    sf.pos=8707830;
    if ((Vc == Vinstr))
    {
     sf.pos=8707831;
     Vinstr = 0;
    }
    sf.pos=8707832;
    ++(Vj);
    sf.pos=8707833;
    Vpsep = 1;
    rt = 4;
YoJj:
    if (rt) goto Ys3D;
   }
   else
   {
    sf.pos=8707834;
    if ((((Vc == 34) || (Vc == 39))))
    {
     sf.pos=8707835;
     Vinstr = Vc;
     sf.pos=8707836;
     *(Tc*)ZListGetIntP(t->Vhl, Vj) = HL_STRING;
     sf.pos=8707837;
     ++(Vj);
     rt = 4;
     if (rt) goto YlaD;
    }
YlaD:
    if (rt) goto Ys3D;
   }
Ys3D:
   if (rt) goto Yel2;
  }
  sf.pos=8707838;
  if (((t->Vsyn->Vflags & HI_NUM) != 0))
  {
   sf.pos=8707839;
   if (((isdigit(Vc) && ((Vpsep || *phl == HL_NUMBER))) || (((Vc == 46) && *phl == HL_NUMBER))))
   {
    sf.pos=8707840;
    *(Tc*)ZListGetIntP(t->Vhl, Vj) = HL_NUMBER;
    sf.pos=8707841;
    ++(Vj);
    sf.pos=8707842;
    Vpsep = 0;
    rt = 4;
    if (rt) goto YvCk;
   }
YvCk:
   if (rt) goto Yel2;
  }
  sf.pos=8707843;
  if (Vpsep)
  {
   Tb Vbroken;
   sf.pos=8707844;
   Vbroken = 0;
   sf.pos=8707845;
   {
    Tfl Zf3i;
    Zf3 = Vkw;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vkeyw;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    Ti Vlen;
    Tb Vk2;
    sf.pos=8707846;
    Vk = Vkeyw;
    sf.pos=8707847;
    Vlen = (ZstringSize(Vk) - 1);
    sf.pos=8707848;
    Vk2 = ZstringEndsWith(Vk, ((Tc*)&Y8a), 0);
    sf.pos=8707849;
    if (Vk2)
    {
     sf.pos=8707850;
     --(Vlen);
     sf.pos=8707851;
     Vk = ZstringSlice(Vk, 0, Vlen, 0);
    }
    sf.pos=8707852;
    if (((ZstringCmp(Yh7e(t->Vrender, Vj, Vlen), Vk) == 0) && ((((Vj + Vlen) >= (ZstringSize(t->Vrender) - 1)) || YjGn(ZstringGetChar(t->Vrender, ((Vj + Vlen) + 1)))))))
    {
     Tc Vhi;
     sf.pos=8707853;
     Vhi = ((Vk2) ? (HL_TYPE) : (HL_KEYWORD));
     sf.pos=8707854;
     *(Tc*)ZListGetIntP(t->Vhl, Vj) = Vhi;
     sf.pos=8707855;
     {
      Ti Vo;
      Tfr Zf5;
      ZforRangeNew((Vj + 1), (Vj + Vlen), 0, 1, &Zf5);
      for (ZforRangeGetInt(&Zf5, &Vo); ZforRangeContInt(&Zf5); ZforRangeNextInt(&Zf5, &Vo)) {
      sf.pos=8707856;
      ZLap((Tl*)t->Vhl, (Tz)(Ti)Vhi);
      sf.pos=8707857;
      }
     }
     sf.pos=8707858;
     Vj += (Vlen + 1);
     sf.pos=8707859;
     Vbroken = 1;
     rt = 2;
     goto YbN3;
    }
YbN3:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=8707860;
    }
   }
   sf.pos=8707861;
   if (Vbroken)
   {
    sf.pos=8707862;
    Vpsep = 0;
    rt = 4;
    if (rt) goto Y680;
   }
Y680:
   if (rt) goto Yel2;
  }
  sf.pos=8707863;
  Vpsep = YjGn(Vc);
  sf.pos=8707864;
  ++(Vj);
Yel2:
  if (rt == 2) { rt &= 1; break; }
  if (rt == 4) { rt &= 1; continue; }
 sf.pos=8707865;
 }
YfoT:
 topFrame = sf.prev;
 return;
}
Ys45 *Yngj(Ys45 *t, Tc *Atext, Ti Ats, Ybkz *Asyn) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3301000; t = Za(sizeof(Ys45));}
 sf.pos=3301001;
 t->Vtxt = Atext;
 sf.pos=3301002;
 t->Vts = Ats;
 sf.pos=3301003;
 t->Vorig = Atext;
 sf.pos=3301004;
 t->Vhl = ZnewList((Tt*)&byte__T, 0);
 sf.pos=3301005;
 t->Vrender = ((Tc*)&Ya);
 sf.pos=3301006;
 t->Vsyn = Asyn;
 topFrame = sf.prev;
 return t;
}
To ToYs45[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* txt */
 {0, (Tt*)&string__T}, /* orig */
 {0, (Tt*)&string__T}, /* render */
 {0, (Tt*)&list__T}, /* hl */
 {0, (Tt*)&Ybkz__T}, /* syn */
};
Tto Ys45__T = {390, (Tc*)&YSv9, 0, ToYs45};
void YouM(YQfU *t, Tc *As, Tc *Ab) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7783500;
  ZthrowThisNil();
 }
 sf.pos=7783501;
 t->Vstatusmsg = ZcS(As, Ab);
 sf.pos=7783502;
 t->Vstatime = Y9Rj();
 topFrame = sf.prev;
 return;
}
void YteW(YQfU *t) {
 Zsf sf;
 Tl *Zf1 = NULL;
 Ys45 *Vr = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1296900;
  ZthrowThisNil();
 }
 sf.pos=1296901;
 {
  Tfl Zf1i;
  Zf1 = t->Verows;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vr;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=1296902;
  Vr->Vsyn = t->Vcsyn;
  sf.pos=1296903;
  YYmf(Vr);
  sf.pos=1296904;
  }
 }
 topFrame = sf.prev;
 return;
}
void YYQw(YQfU *t) {
 Zsf sf;
 Tl *Zf1 = NULL;
 Ybkz *Ventry = 0;
 Tl *Zf2 = NULL;
 Tc *Vfp = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4711000;
  ZthrowThisNil();
 }
 sf.pos=4711001;
 t->Vcsyn = NULL;
 sf.pos=4711002;
 if ((t->Vfilename == NULL))
 {
  sf.pos=4711003;
  rt = 1;
  goto Y71_;
 }
 sf.pos=4711004;
 {
  Tfl Zf1i;
  Zf1 = Vfiletypes;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Ventry;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4711005;
  {
   Tfl Zf2i;
   Zf2 = Ventry->Vfpatterns;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vfp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4711006;
   if (ZstringEndsWith(t->Vfilename, Vfp, 0))
   {
    sf.pos=4711007;
    t->Vcsyn = Ventry;
    sf.pos=4711008;
    YteW(t);
    sf.pos=4711009;
    rt = 1;
    goto YM9M;
   }
YM9M:
   if (rt) goto Ya4F;
   sf.pos=4711010;
   }
  }
Ya4F:
  if (rt) goto Y71_;
  sf.pos=4711011;
  }
 }
Y71_:
 topFrame = sf.prev;
 return;
}
Ti YB3w(YQfU *t, Ti Ahl) {
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7471300;
  ZthrowThisNil();
 }
 sf.pos=7471301;
 switch (Ahl)
 {
 case HL_NUMBER:
  {
   sf.pos=7471302;
   r = 34;
   rt = 1;
   goto YJvt;
  }
 case HL_KEYWORD:
  {
   sf.pos=7471303;
   r = 33;
   rt = 1;
   goto YJvt;
  }
 case HL_TYPE:
  {
   sf.pos=7471304;
   r = 32;
   rt = 1;
   goto YJvt;
  }
 case HL_MATCH:
  {
   sf.pos=7471305;
   r = 31;
   rt = 1;
   goto YJvt;
  }
 case HL_STRING:
  {
   sf.pos=7471306;
   r = 35;
   rt = 1;
   goto YJvt;
  }
 case HL_COMMENT:
  {
   sf.pos=7471307;
   r = 36;
   rt = 1;
   goto YJvt;
  }
 default:
  {
   sf.pos=7471308;
   r = 37;
   rt = 1;
   goto YJvt;
  }
YJvt:
  if (rt) goto Y3ms;
 }
Y3ms:
 topFrame = sf.prev;
 return r;
}
void Yc1O(YQfU *t) {
 Ti Vscx;
 Ti Vscy;
 Ti Vscoloff;
 Ti Vsrowoff;
 Zsf sf;
 Tc *Vquery = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=666100;
  ZthrowThisNil();
 }
 sf.pos=666101;
 Vscx = t->Vcx;
 sf.pos=666102;
 Vscy = t->Vcy;
 sf.pos=666103;
 Vscoloff = t->Vcoloff;
 sf.pos=666104;
 Vsrowoff = t->Vrowoff;
 sf.pos=666105;
 Vquery = Y1GC(((Tc*)&YUFM), (&ZCB_YYfE));
 sf.pos=666106;
 if ((Vquery == NULL))
 {
  sf.pos=666107;
  t->Vcx = Vscx;
  sf.pos=666108;
  t->Vcy = Vscy;
  sf.pos=666109;
  t->Vcoloff = Vscoloff;
  sf.pos=666110;
  t->Vrowoff = Vsrowoff;
 }
 topFrame = sf.prev;
 return;
}
Tc *YoQj(YQfU *t) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 Tl *Zf1 = NULL;
 Ys45 *Vj = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8121900;
  ZthrowThisNil();
 }
 sf.pos=8121901;
 Vres = ((Tc*)&Ya);
 sf.pos=8121902;
 {
  Tfl Zf1i;
  Zf1 = t->Verows;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vj;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8121903;
  Vres =  ZcS(Vres, ZcS(Vj->Vtxt, ((Tc*)&Yk)));
  sf.pos=8121904;
  }
 }
 sf.pos=8121905;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
void YWKz(YQfU *t) {
 Zsf sf;
 volatile Tc *Vw = NULL;
 volatile Tr Vf = {NULL};
 volatile Tr Ve = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8257500;
  ZthrowThisNil();
 }
 sf.pos=8257501;
 if ((t->Vfilename != NULL))
 {
  sf.pos=8257502;
  Vw = YoQj(t);
  sf.pos=8257503;
  {
   volatile int caught = 0;
   Tn *te = (&Zenv);
   int try_index = te->tryCtxUsed;
   volatile int did_jump = 0;
   sf.pos=8257504;
   ZtryDeeper(te, &sf);
   if (setjmp(te->tryCtx[try_index].jmpBuf) != 0) {
    ++did_jump;
    topFrame = &sf;
   }
   if (did_jump == 0) /* TRY */
   {
    sf.pos=8257505;
    Vf = YiBk(t->Vfilename, 1);
    te->tryCtxUsed = try_index;
    did_jump = 1; caught = 1; /* ELSE */
    {
     sf.pos=8257506;
     if ((((((Tr)Vf)).ptr) == NULL))
     {
      sf.pos=8257507;
      YouM(t, ZcS3(((Tc*)&YU14), t->Vfilename, ((Tc*)&YiHc)), ((Tc*)&Ya));
     }
     else
     {
      sf.pos=8257508;
      ((Ts (*)(void*, Tc*))(((Tr)Vf).table[1]))(((Tr)Vf).ptr, ((Tc*)Vw));
      sf.pos=8257509;
      ((Ts (*)(void*))(((Tr)Vf).table[35]))(((Tr)Vf).ptr);
      sf.pos=8257510;
      {
       volatile Ti Vj;
       Tfr Zf6;
       ZforRangeNew(0, (t->Vn_erows - 1), 0, 1, &Zf6);
       for (ZforRangeGetInt(&Zf6, &Vj); ZforRangeContInt(&Zf6); ZforRangeNextInt(&Zf6, &Vj)) {
       sf.pos=8257511;
       ((Ys45 *)ZListGetPtr(t->Verows, ((Ti)Vj)))->Vorig = ((Ys45 *)ZListGetPtr(t->Verows, ((Ti)Vj)))->Vtxt;
       sf.pos=8257512;
       }
      }
      sf.pos=8257513;
      t->Vfmodified = 0;
      sf.pos=8257514;
      YouM(t, ZcS3(((Tc*)&YxQ_), Zint2string(ZstringSize(((Tc*)Vw))), ((Tc*)&YPwc)), ((Tc*)&Ya));
     }
    }
   }
   te->tryCtxUsed = try_index;
   if (did_jump == 1 && !caught && ((te->thrown[te->thrownUsed - 1]).type == 21)) /* CATCH */
   {
    Ve = te->thrown[--te->thrownUsed];
    caught = 1;
    sf.pos=8257515;
    YouM(t, ZcS(((Tc*)&Y7hz), ((Tc* (*)(void*, Tb))(((Tr)Ve).table[9]))(((Tr)Ve).ptr, 0)), ((Tc*)&Ya));
   }
   if ((did_jump == 1 && !caught) || did_jump > 1) Zrethrow();
  }
 }
 else
 {
  sf.pos=8257516;
  t->Vfilename = Y1GC(((Tc*)&Yjjm), NULL);
  sf.pos=8257517;
  if ((t->Vfilename == NULL))
  {
   sf.pos=8257518;
   YouM(t, ((Tc*)&Ysvx), ((Tc*)&Ya));
  }
  else
  {
   sf.pos=8257519;
   YWKz(t);
  }
 }
 sf.pos=8257520;
 YYQw(t);
 topFrame = sf.prev;
 return;
}
void YJA8(YQfU *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7710300;
  ZthrowThisNil();
 }
 sf.pos=7710301;
 t->Vrx = 0;
 sf.pos=7710302;
 if ((t->Vcy < t->Vn_erows))
 {
  sf.pos=7710303;
  t->Vrx = YZ7l(((Ys45 *)ZListGetPtr(t->Verows, t->Vcy)), t->Vcx, t->Vts);
 }
 sf.pos=7710304;
 if ((t->Vcy < t->Vrowoff))
 {
  sf.pos=7710305;
  t->Vrowoff = t->Vcy;
 }
 sf.pos=7710306;
 if ((t->Vcy >= (t->Vrowoff + t->Vrows)))
 {
  sf.pos=7710307;
  t->Vrowoff = ((t->Vcy - t->Vrows) + 1);
 }
 sf.pos=7710308;
 if ((t->Vcx < t->Vcoloff))
 {
  sf.pos=7710309;
  t->Vcoloff = t->Vcx;
 }
 sf.pos=7710310;
 if ((t->Vcx >= (t->Vcoloff + t->Vcols)))
 {
  sf.pos=7710311;
  t->Vcoloff = ((t->Vcx - t->Vcols) + 1);
 }
 topFrame = sf.prev;
 return;
}
void Yuq0(YQfU *t, Tc *As, Ti Aat) {
 Zsf sf;
 Ys45 *Vr = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3518900;
  ZthrowThisNil();
 }
 sf.pos=3518901;
 if ((((Aat >= 0) && (Aat <= t->Vn_erows))))
 {
  sf.pos=3518902;
  Vr = Yngj(NULL, As, t->Vts, t->Vcsyn);
  sf.pos=3518903;
  YiiI(Vr);
  sf.pos=3518904;
  if ((Aat == t->Vn_erows))
  {
   sf.pos=3518905;
   ZLap((Tl*)t->Verows, (Tz)(void*)Vr);
  }
  else
  {
   sf.pos=3518906;
   ZListInsert((Tl*)t->Verows, (Aat + 1), (Tz)(void*)Vr);
  }
  sf.pos=3518907;
  ++(t->Vn_erows);
  sf.pos=3518908;
  ++(t->Vfmodified);
 }
 topFrame = sf.prev;
 return;
}
void YzYj(YQfU *t) {
 Zsf sf;
 Ys45 *Vr = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1569900;
  ZthrowThisNil();
 }
 sf.pos=1569901;
 if ((((t->Vcx == 0) && (t->Vcy == 0)) && (t->Vn_erows == 0)))
 {
  sf.pos=1569902;
  Yuq0(t, ((Tc*)&Ya), t->Vcy);
 }
 else
 {
  sf.pos=1569903;
  Vr = ((Ys45 *)ZListGetPtr(t->Verows, t->Vcy));
  sf.pos=1569904;
  Yuq0(t, ZstringSlice(Vr->Vtxt, t->Vcx, -1, 0), t->Vcy);
  sf.pos=1569905;
  if ((t->Vcx > 0))
  {
   sf.pos=1569906;
   Vr->Vtxt = ZstringSlice(Vr->Vtxt, 0, (t->Vcx - 1), 0);
  }
  else
  {
   sf.pos=1569907;
   Vr->Vtxt = ((Tc*)&Ya);
  }
  sf.pos=1569908;
  YiiI(Vr);
 }
 sf.pos=1569909;
 ++(t->Vcy);
 sf.pos=1569910;
 t->Vcx = 0;
 topFrame = sf.prev;
 return;
}
void YcHr(YQfU *t, Ti Ac) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3752700;
  ZthrowThisNil();
 }
 sf.pos=3752701;
 if ((t->Vcy == t->Vn_erows))
 {
  sf.pos=3752702;
  Yuq0(t, ((Tc*)&Ya), t->Vn_erows);
  sf.pos=3752703;
  --(t->Vfmodified);
 }
 sf.pos=3752704;
 Yz4M(((Ys45 *)ZListGetPtr(t->Verows, t->Vcy)), t->Vcx, Ac);
 sf.pos=3752705;
 ++(t->Vcx);
 sf.pos=3752706;
 ++(t->Vfmodified);
 topFrame = sf.prev;
 return;
}
void YneO(YQfU *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1993700;
  ZthrowThisNil();
 }
 sf.pos=1993701;
 YdbI(((Ys45 *)ZListGetPtr(t->Verows, t->Vcy)), t->Vcx);
 topFrame = sf.prev;
 return;
}
void Y7mW(YQfU *t) {
 Zsf sf;
 Ys45 *Vr = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9286300;
  ZthrowThisNil();
 }
 sf.pos=9286301;
 if ((t->Vcy != t->Vn_erows))
 {
  sf.pos=9286302;
  Vr = ((Ys45 *)ZListGetPtr(t->Verows, t->Vcy));
  sf.pos=9286303;
  if ((t->Vcx > 0))
  {
   sf.pos=9286304;
   YhvK(Vr, (t->Vcx - 1));
   sf.pos=9286305;
   --(t->Vcx);
  }
  else {
  sf.pos=9286306;
 if ((t->Vcy > 0))
  {
   sf.pos=9286307;
   t->Vcx = ZstringSize(((Ys45 *)ZListGetPtr(t->Verows, (t->Vcy - 1)))->Vtxt);
   sf.pos=9286308;
   YIV3(((Ys45 *)ZListGetPtr(t->Verows, (t->Vcy - 1))), Vr->Vtxt);
   sf.pos=9286309;
   ZListClearItem((Tl*)t->Verows, t->Vcy);
   sf.pos=9286310;
   --(t->Vn_erows);
   sf.pos=9286311;
   --(t->Vcy);
  }
  }
 }
 topFrame = sf.prev;
 return;
}
void YaZr(YQfU *t, Tc *Afname) {
 Zsf sf;
 volatile Tr Vf = {NULL};
 volatile Tl *Vlines = NULL;
 Tl *Zf5 = NULL;
 volatile Tc *Vline = NULL;
 volatile Tr Ve = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6327800;
  ZthrowThisNil();
 }
 sf.pos=6327801;
 {
  volatile int caught = 0;
  Tn *te = (&Zenv);
  int try_index = te->tryCtxUsed;
  volatile int did_jump = 0;
  sf.pos=6327802;
  ZtryDeeper(te, &sf);
  if (setjmp(te->tryCtx[try_index].jmpBuf) != 0) {
   ++did_jump;
   topFrame = &sf;
  }
  if (did_jump == 0) /* TRY */
  {
   sf.pos=6327803;
   Vf = YsGz(((Tc*)Afname));
   te->tryCtxUsed = try_index;
   did_jump = 1; caught = 1; /* ELSE */
   {
    sf.pos=6327804;
    if ((((((Tr)Vf)).ptr) == NULL))
    {
     sf.pos=6327805;
     YouM(t, ZcS3(((Tc*)&YU14), ((Tc*)Afname), ((Tc*)&YiHc)), ((Tc*)&Ya));
    }
    else
    {
     sf.pos=6327806;
     t->Vfilename = ((Tc*)Afname);
     sf.pos=6327807;
     Vlines = ((Tl* (*)(void*))(((Tr)Vf).table[30]))(((Tr)Vf).ptr);
     sf.pos=6327808;
     {
      Tfl Zf5i;
      Zf5 = ((Tl*)Vlines);
      Zf5i.l = Zf5;
      Zf5i.valp = (void*)&Vline;
      Zf5i.i = 0;
      for (; ZforListPtrCont(&Zf5i); ) {
      sf.pos=6327809;
      Yuq0(t, ((Tc*)Vline), t->Vn_erows);
      sf.pos=6327810;
      }
     }
     sf.pos=6327811;
     t->Vfmodified = 0;
     sf.pos=6327812;
     YYQw(t);
     sf.pos=6327813;
     ((Ts (*)(void*))(((Tr)Vf).table[35]))(((Tr)Vf).ptr);
    }
   }
  }
  te->tryCtxUsed = try_index;
  if (did_jump == 1 && !caught && ((te->thrown[te->thrownUsed - 1]).type == 21)) /* CATCH */
  {
   Ve = te->thrown[--te->thrownUsed];
   caught = 1;
   sf.pos=6327814;
   YouM(t, ZcS(((Tc*)&Y7hz), ((Tc* (*)(void*, Tb))(((Tr)Ve).table[9]))(((Tr)Ve).ptr, 0)), ((Tc*)&Ya));
  }
  if ((did_jump == 1 && !caught) || did_jump > 1) Zrethrow();
 }
 topFrame = sf.prev;
 return;
}
void YbQH(YQfU *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9826600;
  ZthrowThisNil();
 }
 sf.pos=9826601;
 YEDW(t);
 sf.pos=9826602;
 YouM(t, ((Tc*)&YwGe), ((Tc*)&Ya));
 topFrame = sf.prev;
 return;
}
void Yeai(YQfU *t, Ti Ak) {
 Ti Vkey;
 Ti Vsz;
 Zsf sf;
 Td *Vmapper = NULL;
 Ys45 *Vr = 0;
 Tc *Zf5 = NULL;
 Tl *Zf4 = NULL;
 Tc *Vline = NULL;
 Tc *Vtimes = NULL;
 Tc *Vtimes1 = NULL;
 Tc *Vt = NULL;
 Tc *Zf3 = NULL;
 Ys45 *Vr2 = 0;
 Td *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1504500;
  ZthrowThisNil();
 }
 Vkey = 0;
 sf.pos=1504501;
 if ((t->Vmode == 78))
 {
  sf.pos=1504502;
  Vmapper = (t0 = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&int__T, (Tt*)&int__T, 0), (Tz)(Ti)104, (Tz)(Ti)LEFT), (Tz)(Ti)108, (Tz)(Ti)RIGHT), (Tz)(Ti)106, (Tz)(Ti)DOWN), (Tz)(Ti)107, (Tz)(Ti)UP));
  sf.pos=1504503;
  if (ZDictHas(Vmapper, (Tz)(Ti)Ak))
  {
   sf.pos=1504504;
   Vkey = ZDictGetInt(Vmapper, (Tz)(Ti)Ak);
  }
  else
  {
   sf.pos=1504505;
   Vkey = Ak;
  }
 }
 else
 {
  sf.pos=1504506;
  Vkey = Ak;
 }
 sf.pos=1504507;
 Vr = ((((t->Vcy >= t->Vn_erows))) ? (NULL) : (((Ys45 *)ZListGetPtr(t->Verows, t->Vcy))));
 sf.pos=1504508;
 switch (Vkey)
 {
 case LEFT:
  {
   sf.pos=1504509;
   if ((t->Vcx > 0))
   {
    sf.pos=1504510;
    --(t->Vcx);
   }
   else {
   sf.pos=1504511;
 if ((t->Vcy > 0))
   {
    sf.pos=1504512;
    --(t->Vcy);
    sf.pos=1504513;
    if ((t->Vcy < t->Vn_erows))
    {
     sf.pos=1504514;
     t->Vcx = ZstringSize(((Ys45 *)ZListGetPtr(t->Verows, t->Vcy))->Vtxt);
    }
   }
   }
    break;
  }
 case RIGHT:
  {
   sf.pos=1504515;
   if (((Vr != NULL) && (t->Vcx < ZstringSize(Vr->Vtxt))))
   {
    sf.pos=1504516;
    ++(t->Vcx);
   }
    break;
  }
 case UP:
  {
   sf.pos=1504517;
   if ((t->Vcy != 0))
   {
    sf.pos=1504518;
    --(t->Vcy);
   }
    break;
  }
 case DOWN:
  {
   sf.pos=1504519;
   if (((t->Vn_erows != 0) && (t->Vcy < (t->Vn_erows - 1))))
   {
    sf.pos=1504520;
    ++(t->Vcy);
   }
    break;
  }
 case 62:
  {
   sf.pos=1504521;
   if ((Vr != NULL))
   {
    sf.pos=1504522;
    YneO(t);
    sf.pos=1504523;
    ++(t->Vfmodified);
   }
    break;
  }
 case 60:
  {
   sf.pos=1504524;
   if ((Vr != NULL))
   {
    sf.pos=1504525;
    YPEA(Vr, t->Vcx);
    sf.pos=1504526;
    ++(t->Vfmodified);
   }
    break;
  }
 case 117:
  {
   sf.pos=1504527;
   if ((Vr != NULL))
   {
    sf.pos=1504528;
    if ((ZstringCmp(Vr->Vtxt, Vr->Vorig) != 0))
    {
     sf.pos=1504529;
     {
      Ti Vc;
      Tfs iZf5;
      Zf5 = Vr->Vtxt;
      ZforStringNew(Zf5, &iZf5);
      for (ZforStringGetInt(&iZf5, &Vc); ZforStringContInt(&iZf5); ZforStringNextInt(&iZf5, &Vc)) {
      sf.pos=1504530;
      if ((ZstringFindChar(Vr->Vorig, Vc, 0) == -1))
      {
       sf.pos=1504531;
       --(t->Vfmodified);
      }
      sf.pos=1504532;
      }
     }
     sf.pos=1504533;
     Yoz2(Vr);
     sf.pos=1504534;
     YouM(t, ((Tc*)&YcRO), ((Tc*)&Ya));
    }
    else
    {
     sf.pos=1504535;
     YouM(t, ((Tc*)&Y3Gy), ((Tc*)&Ya));
    }
   }
    break;
  }
 case 68:
  {
   sf.pos=1504536;
   if ((Vr != NULL))
   {
    sf.pos=1504537;
    ZListClearItem((Tl*)t->Verows, t->Vcy);
    sf.pos=1504538;
    --(t->Vn_erows);
    sf.pos=1504539;
    ++(t->Vfmodified);
   }
    break;
  }
 case 91:
  {
   sf.pos=1504540;
   if ((Vr != NULL))
   {
    sf.pos=1504541;
    t->Vcopy = Vr->Vtxt;
    sf.pos=1504542;
    YouM(t, ((Tc*)&YzlG), ((Tc*)&Ya));
   }
    break;
  }
 case 93:
  {
   sf.pos=1504543;
   if ((t->Vcopy != NULL))
   {
    sf.pos=1504544;
    {
     Tfl Zf4i;
     Zf4 = ZstringSplit(t->Vcopy, ((Tc*)&Yk), 0);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Vline;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=1504545;
     Yuq0(t, Vline, t->Vcy);
     sf.pos=1504546;
     ++(t->Vcy);
     sf.pos=1504547;
     }
    }
   }
    break;
  }
 case 123:
  {
   sf.pos=1504548;
   if ((t->Vcopy != NULL))
   {
    sf.pos=1504549;
    t->Vcopy =  ZcS(t->Vcopy, ZcS(((Tc*)&Yk), Vr->Vtxt));
    sf.pos=1504550;
    if ((ZstringSize(t->Vcopy) > 250))
    {
     sf.pos=1504551;
     YouM(t, ((Tc*)&YAc9), ((Tc*)&Ya));
     sf.pos=1504552;
     t->Vcopy = ZstringSlice(t->Vcopy, 0, 250, 0);
    }
    else
    {
     sf.pos=1504553;
     YouM(t, ((Tc*)&Y56D), ((Tc*)&Ya));
    }
   }
   else
   {
    sf.pos=1504554;
    t->Vcopy = Vr->Vtxt;
    sf.pos=1504555;
    YouM(t, ((Tc*)&YzlG), ((Tc*)&Ya));
   }
    break;
  }
 case 74:
  {
   sf.pos=1504556;
   Vtimes = Y1GC(((Tc*)&YK3W), NULL);
   sf.pos=1504557;
   if ((Vtimes == NULL))
   {
    sf.pos=1504558;
    YouM(t, ((Tc*)&Y7D8), ((Tc*)&Ya));
    rt = 2;
    goto YejS;
   }
   sf.pos=1504559;
   {
    Ti Vi;
    Tfr Zf3;
    ZforRangeNew(0, ZstringToInt(Vtimes, 0, 20), 0, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vi); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vi)) {
    sf.pos=1504560;
    Yeai(t, DOWN);
    sf.pos=1504561;
    }
   }
YejS:
   if (rt == 2) { rt &= 1; break; }
    break;
  }
 case 75:
  {
   sf.pos=1504562;
   Vtimes1 = Y1GC(((Tc*)&YMbE), NULL);
   sf.pos=1504563;
   if ((Vtimes1 == NULL))
   {
    sf.pos=1504564;
    YouM(t, ((Tc*)&YKoD), ((Tc*)&Ya));
    rt = 2;
    goto Ybun;
   }
   sf.pos=1504565;
   {
    Ti Vi;
    Tfr Zf3;
    ZforRangeNew(0, ZstringToInt(Vtimes1, 0, 20), 0, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vi); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vi)) {
    sf.pos=1504566;
    Yeai(t, UP);
    sf.pos=1504567;
    }
   }
Ybun:
   if (rt == 2) { rt &= 1; break; }
    break;
  }
 case 112:
  {
   sf.pos=1504568;
   Vt = Y1GC(ZcS3(((Tc*)&Y9At), ((((Y9Rj() % 5) == 0)) ? (((Tc*)&Ye_A)) : (((Tc*)&Y6Hv))), ((Tc*)&YNTX)), NULL);
   sf.pos=1504569;
   if ((Vt == NULL))
   {
    sf.pos=1504570;
    YouM(t, ((Tc*)&YZj2), ((Tc*)&Ya));
    rt = 2;
    goto Y8ET;
   }
   sf.pos=1504571;
   {
    Ti Vi;
    Tfr Zf3;
    ZforRangeNew(0, (ZstringSize(Vt) - 1), 0, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vi); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vi)) {
    sf.pos=1504572;
    YPEA(Vr, t->Vcx);
    sf.pos=1504573;
    }
   }
   sf.pos=1504574;
   {
    Ti Vc;
    Tfs iZf3;
    Zf3 = Vt;
    ZforStringNew(Zf3, &iZf3);
    for (ZforStringGetInt(&iZf3, &Vc); ZforStringContInt(&iZf3); ZforStringNextInt(&iZf3, &Vc)) {
    sf.pos=1504575;
    YcHr(t, Vc);
    sf.pos=1504576;
    }
   }
Y8ET:
   if (rt == 2) { rt &= 1; break; }
    break;
  }
 case 65:
  {
   sf.pos=1504577;
   if ((Vr != NULL))
   {
    sf.pos=1504578;
    t->Vcx = ZstringSize(Vr->Vtxt);
   }
    break;
  }
 case 73:
  {
   sf.pos=1504579;
   t->Vcx = 0;
    break;
  }
  if (rt) goto Y9Vw;
 }
 sf.pos=1504580;
 Vr2 = ((((t->Vcy >= t->Vn_erows))) ? (NULL) : (((Ys45 *)ZListGetPtr(t->Verows, t->Vcy))));
 sf.pos=1504581;
 Vsz = (((Vr2 != NULL)) ? (ZstringSize(Vr2->Vtxt)) : (0));
 sf.pos=1504582;
 if ((t->Vcx > Vsz))
 {
  sf.pos=1504583;
  t->Vcx = Vsz;
 }
Y9Vw:
 topFrame = sf.prev;
 return;
}
Ts YLNB(YQfU *t) {
 Zsf sf;
 Ts r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7063500;
  ZthrowThisNil();
 }
 sf.pos=7063501;
    struct winsize ws;
 sf.pos=7063502;
 if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
 {
  sf.pos=7063503;
  if ((((Ts (*)(void*, Tc*))(Yb0q.table[1]))(Yb0q.ptr, ((Tc*)&Yd1d)) != 1))
  {
   sf.pos=7063504;
   r = 0;
   rt = 1;
   goto YIbH;
  }
  sf.pos=7063505;
  r = YP9u(&(t->Vrows), &(t->Vcols));
YIbH:
  ;
  rt = 1;
  goto YbcY;
 }
 else
 {
  sf.pos=7063506;
  t->Vrows = (ws.ws_row - 2);
  sf.pos=7063507;
  t->Vcols = ws.ws_col;
  sf.pos=7063508;
  r = 1;
  rt = 1;
  goto YbcY;
 }
YbcY:
 topFrame = sf.prev;
 return r;
}
void YEDW(YQfU *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2417900;
  ZthrowThisNil();
 }
 sf.pos=2417901;
 t->Vrowoff = 0;
 sf.pos=2417902;
 t->Vcoloff = 0;
 sf.pos=2417903;
 t->Verows = ZnewList((Tt*)&Ys45__T, 0);
 sf.pos=2417904;
 t->Vmode = 'N';
 sf.pos=2417905;
 t->Vts = 2;
 sf.pos=2417906;
 t->Vstatusmsg = ((Tc*)&Ya);
 sf.pos=2417907;
 t->Vstatime = 0;
 sf.pos=2417908;
 t->Vn_erows = 0;
 sf.pos=2417909;
 t->Vfilename = NULL;
 sf.pos=2417910;
 t->Vfmodified = 0;
 sf.pos=2417911;
 t->Vrx = 0;
 sf.pos=2417912;
 t->Vexpand = 1;
 sf.pos=2417913;
 t->Vcopy = NULL;
 sf.pos=2417914;
 t->Vcx = 0;
 sf.pos=2417915;
 t->Vcy = 0;
 sf.pos=2417916;
 t->Vcsyn = NULL;
 topFrame = sf.prev;
 return;
}
YQfU *Yek3(YQfU *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1477400; t = Za(sizeof(YQfU));}
 sf.pos=1477401;
 YEDW(t);
 sf.pos=1477402;
 t->Vrows = 0;
 sf.pos=1477403;
 t->Vcols = 0;
 sf.pos=1477404;
 t->Vorig_termios = malloc(sizeof(struct termios));
 topFrame = sf.prev;
 return t;
}
To ToYQfU[] = {
 {5, 0},
 {0, (Tt*)&list__T}, /* erows */
 {0, (Tt*)&string__T}, /* copy */
 {0, (Tt*)&string__T}, /* filename */
 {0, (Tt*)&string__T}, /* statusmsg */
 {0, (Tt*)&Ybkz__T}, /* csyn */
};
Tto YQfU__T = {390, (Tc*)&YT6N, 0, ToYQfU};
void YYfE(Tc *Aquery, Ti Ak) {
 Ti Vkey;
 Ti Vcurrent;
 Zsf sf;
 Ys45 *Vr = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3376301;
 if ((Yu33 != NULL))
 {
  sf.pos=3376302;
  ((Ys45 *)ZListGetPtr(Vec->Verows, Yr0N))->Vhl = Yu33;
  sf.pos=3376303;
  Yu33 = NULL;
 }
 Vkey = 0;
 sf.pos=3376304;
int*key = &Vkey;
 sf.pos=3376305;
 Vkey = Ak;
 sf.pos=3376306;
 if ((Ak == 27))
 {
  sf.pos=3376307;
  YouM(Vec, ((Tc*)&YRuz), ((Tc*)&Ya));
  sf.pos=3376308;
  YHqw = -1;
  sf.pos=3376309;
  Ynxs = 1;
  sf.pos=3376310;
  rt = 1;
  goto YLW4;
 }
 else {
 sf.pos=3376311;
 if (*key == RIGHT || *key == DOWN)
 {
  sf.pos=3376312;
  Ynxs = 1;
 }
 else {
 sf.pos=3376313;
 if (*key == LEFT || *key == UP)
 {
  sf.pos=3376314;
  Ynxs = -1;
 }
 else {
 sf.pos=3376315;
 if (*key == '\r')
 {
  sf.pos=3376316;
  if ((YHqw == -1))
  {
   sf.pos=3376317;
   YouM(Vec, ZcS(((Tc*)&YAGa), Aquery), ((Tc*)&Ya));
   sf.pos=3376318;
   Ynxs = 1;
   sf.pos=3376319;
   rt = 1;
   goto Yco_;
  }
  else
  {
   sf.pos=3376320;
   YouM(Vec, ((Tc*)&Ytas), ((Tc*)&Ya));
   sf.pos=3376321;
   YHqw = -1;
   sf.pos=3376322;
   Ynxs = 1;
   sf.pos=3376323;
   rt = 1;
   goto Yco_;
  }
Yco_:
  if (rt) goto YLW4;
 }
 else
 {
  sf.pos=3376324;
  YHqw = -1;
  sf.pos=3376325;
  Ynxs = 1;
 }
 }}}
 sf.pos=3376326;
 if ((YHqw == -1))
 {
  sf.pos=3376327;
  Ynxs = 1;
 }
 sf.pos=3376328;
 Vcurrent = YHqw;
 sf.pos=3376329;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(0, (Vec->Vn_erows - 1), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  Ti Vmatch;
  sf.pos=3376330;
  Vcurrent += Ynxs;
  sf.pos=3376331;
  if ((Vcurrent == -1))
  {
   sf.pos=3376332;
   Vcurrent = (Vec->Vn_erows - 1);
  }
  else {
  sf.pos=3376333;
 if ((Vcurrent == Vec->Vn_erows))
  {
   sf.pos=3376334;
   Vcurrent = 0;
  }
  }
  sf.pos=3376335;
  Vr = ((Ys45 *)ZListGetPtr(Vec->Verows, Vcurrent));
  sf.pos=3376336;
  Vmatch = ZstringFind(Vr->Vrender, Aquery, 0);
  sf.pos=3376337;
  if ((Vmatch != -1))
  {
   sf.pos=3376338;
   YHqw = Vcurrent;
   sf.pos=3376339;
   Vec->Vcy = Vcurrent;
   sf.pos=3376340;
   Vec->Vcx = YjIv(Vr, Vmatch);
   sf.pos=3376341;
   Vec->Vrowoff = Vec->Vn_erows;
   sf.pos=3376342;
   Yr0N = Vcurrent;
   sf.pos=3376343;
   Yu33 = ZListCopy(Vr->Vhl);
   sf.pos=3376344;
   {
    Ti Vj;
    Tfr Zf3;
    ZforRangeNew(Vec->Vcx, (Vec->Vcx + ((ZstringSize(Aquery) - 1))), 0, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vj); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vj)) {
    sf.pos=3376345;
    if ((Vj < ZListSize(Vr->Vhl)))
    {
     sf.pos=3376346;
     *(Tc*)ZListGetIntP(Vr->Vhl, Vj) = HL_MATCH;
    }
    sf.pos=3376347;
    }
   }
   rt = 2;
   goto YjdK;
  }
YjdK:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=3376348;
  }
 }
YLW4:
 topFrame = sf.prev;
 return;
}
void YDKA() {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2541100;
  struct termios raw;
  atexit(disableRawMode);

  tcgetattr(STDIN_FILENO, Vec->Vorig_termios);

  raw = *Vec->Vorig_termios;
  raw.c_iflag &= ~(BRKINT | INPCK | ISTRIP | IXON | ICRNL);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag |= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;
  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
    YqsW(((Tc*)&Ykqx));
 topFrame = sf.prev;
 return;
}
void YdnK() {
 Zsf sf;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9433000;
 Ywpw(((Tc*)&Yla), (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YY))));
 sf.pos=9433001;
 YNEj(1, 1);
 topFrame = sf.prev;
 return;
}
void YNEj(Ti Ax, Ti Ay) {
 Zsf sf;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5606300;
 Ywpw(((Tc*)&Yja), (t0 = ZnewList((Tt*)&string__T, 2), ZLap((Tl*)t0, (Tz)(void*)Zint2string(Ay)), ZLap((Tl*)t0, (Tz)(void*)Zint2string(Ax))));
 topFrame = sf.prev;
 return;
}
Tc *YcnF(Ti Ax, Ti Ay) {
 Zsf sf;
 Tc *r = 0;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1447700;
 r = Ygor(((Tc*)&Yja), (t0 = ZnewList((Tt*)&string__T, 2), ZLap((Tl*)t0, (Tz)(void*)Zint2string(Ay)), ZLap((Tl*)t0, (Tz)(void*)Zint2string(Ax))));
 topFrame = sf.prev;
 return r;
}
void YyP1() {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1205100;
 YouM(Vec, ((Tc*)&Yeix), ((Tc*)&Ya));
 topFrame = sf.prev;
 return;
}
void YLzL() {
 Ti Vc;
 Zsf sf;
 Tc *Vfname = NULL;
 Ta *Vmovement = NULL;
 Tc *Vto = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vc = 0;
 sf.pos=4026600;
int*c = &Vc;
 sf.pos=4026601;
 Vc = Y8Q5();
 sf.pos=4026602;
 if (*c == CTRL_KEY('q'))
 {
  sf.pos=4026603;
  if (((Vec->Vfmodified > 0) && (Y1kq > 0)))
  {
   sf.pos=4026604;
   YyP1();
   sf.pos=4026605;
   --(Y1kq);
  }
  else
  {
   sf.pos=4026606;
   YdnK();
   sf.pos=4026607;
   Zexit(Ypp_a(NULL, ((Tc*)&Ya_Da), 927, 7), 0);
  }
 }
 else {
 sf.pos=4026608;
 if (*c == CTRL_KEY('o'))
 {
  sf.pos=4026609;
  Vfname = Y1GC(((Tc*)&Yq1o), NULL);
  sf.pos=4026610;
  if ((Vfname == NULL))
  {
   sf.pos=4026611;
   YouM(Vec, ((Tc*)&Y38M), ((Tc*)&Ya));
   sf.pos=4026612;
   rt = 1;
   goto YhXc;
  }
  sf.pos=4026613;
  if (((Vec->Vfmodified > 0) && (Y1kq > 0)))
  {
   sf.pos=4026614;
   YyP1();
   sf.pos=4026615;
   --(Y1kq);
  }
  else
  {
   sf.pos=4026616;
   YEDW(Vec);
   sf.pos=4026617;
   YaZr(Vec, Vfname);
  }
YhXc:
  if (rt) goto Y5hO;
 }
 else {
 sf.pos=4026618;
 if (*c == CTRL_KEY('w'))
 {
  sf.pos=4026619;
  if (((Vec->Vfmodified > 0) && (Y1kq > 0)))
  {
   sf.pos=4026620;
   YyP1();
   sf.pos=4026621;
   --(Y1kq);
  }
  else
  {
   sf.pos=4026622;
   YbQH(Vec);
  }
 }
 else
 {
  sf.pos=4026623;
  Vmovement = ZStringToArray(((Tc*)&Yp3l));
  sf.pos=4026624;
  Y1kq = 1;
  sf.pos=4026625;
  switch (Vc)
  {
  case 13:
   {
    sf.pos=4026626;
    YzYj(Vec);
     break;
   }
  case CTRL_KEY('f'):
   {
    sf.pos=4026627;
    Yc1O(Vec);
     break;
   }
  case CTRL_KEY('g'):
   {
    Ti Vpos;
    sf.pos=4026628;
    Vto = Y1GC(((Tc*)&Yq_k), NULL);
    sf.pos=4026629;
    if ((Vto == NULL))
    {
     sf.pos=4026630;
     YouM(Vec, ((Tc*)&YKlk), ((Tc*)&Ya));
    }
    sf.pos=4026631;
    Vpos = ZstringToInt(Vto, 0, 1);
    sf.pos=4026632;
    if ((Vpos <= Vec->Vn_erows))
    {
     sf.pos=4026633;
     Vec->Vcy = Vpos;
    }
    else
    {
     sf.pos=4026634;
     YouM(Vec, ZcS3(((Tc*)&Ykz0), (((Vpos > (Vec->Vn_erows + 40))) ? (((Tc*)&YSd9)) : (((Tc*)&YU30))), ((Tc*)&YW0q)), ((Tc*)&Ya));
    }
     break;
   }
  case CTRL_KEY('c'):
   {
    sf.pos=4026635;
    YouM(Vec, ((Tc*)&YNJx), ((Tc*)&Ya));
     break;
   }
  case '\x1b':
   {
    sf.pos=4026636;
    Vec->Vmode = (((Vec->Vmode == 78)) ? (73) : (78));
     break;
   }
  case HOME:
   {
    sf.pos=4026637;
    Vec->Vcx = 0;
     break;
   }
  case END:
   {
    sf.pos=4026638;
    if (((Vec->Vcy < Vec->Vn_erows)))
    {
     sf.pos=4026639;
     Vec->Vcx = ZstringSize(((Ys45 *)ZListGetPtr(Vec->Verows, Vec->Vcy))->Vtxt);
    }
     break;
   }
  case BACKSPACE:
  case CTRL_KEY('h'):
  case DEL:
   {
    sf.pos=4026640;
    Y7mW(Vec);
     break;
   }
  case CTRL_KEY('s'):
   {
    sf.pos=4026641;
    YWKz(Vec);
     break;
   }
  case PAGE_UP:
  case PAGE_DOWN:
   {
    sf.pos=4026642;
    if (*c == PAGE_UP)
    {
     sf.pos=4026643;
     Vec->Vcy = Vec->Vrowoff;
    }
    else {
    sf.pos=4026644;
 if (*c == PAGE_DOWN)
    {
     sf.pos=4026645;
     Vec->Vcy = ((Vec->Vrowoff + Vec->Vrows) - 1);
     sf.pos=4026646;
     if ((Vec->Vcy > Vec->Vrows))
     {
      sf.pos=4026647;
      Vec->Vcy = Vec->Vrows;
     }
    }
    }
    sf.pos=4026648;
    {
     Ti Vn;
     Tfr Zf4;
     ZforRangeNew(Vec->Vn_erows, 0, 0, -1, &Zf4);
     for (ZforRangeGetInt(&Zf4, &Vn); ZforRangeContInt(&Zf4); ZforRangeNextInt(&Zf4, &Vn)) {
     Ti Vres;
     sf.pos=4026649;
     Vres = *c == PAGE_UP ? UP : DOWN;
     sf.pos=4026650;
     Yeai(Vec, Vres);
     sf.pos=4026651;
     }
    }
     break;
   }
  case UP:
  case LEFT:
  case DOWN:
  case RIGHT:
   {
    sf.pos=4026652;
    Yeai(Vec, Vc);
     break;
   }
  case 9:
   {
    sf.pos=4026653;
    if (Vec->Vexpand)
    {
     sf.pos=4026654;
     {
      Ti Vi;
      Tfr Zf5;
      ZforRangeNew(0, (Vec->Vts - 1), 0, 1, &Zf5);
      for (ZforRangeGetInt(&Zf5, &Vi); ZforRangeContInt(&Zf5); ZforRangeNextInt(&Zf5, &Vi)) {
      sf.pos=4026655;
      YcHr(Vec, 32);
      sf.pos=4026656;
      }
     }
    }
     break;
   }
  case CTRL_KEY('l'):
   {
    rt = 2;
    if (rt == 2) { rt &= 1; break; }
     break;
   }
  default:
   {
    sf.pos=4026657;
    if ((Vec->Vmode == 78))
    {
     sf.pos=4026658;
     Yeai(Vec, Vc);
    }
    else
    {
     sf.pos=4026659;
     YcHr(Vec, Vc);
    }
     break;
   }
   if (rt) goto Ym3A;
  }
Ym3A:
  ;
 }
 }}
Y5hO:
 topFrame = sf.prev;
 return;
}
Tc *YZeI() {
 Zsf sf;
 Tc *r = 0;
 Tc *Vab = NULL;
 Tc *Vw = NULL;
 Tc *Zf3 = NULL;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3145800;
 Vab = ((Tc*)&Ya);
 sf.pos=3145801;
 {
  Ti Vy;
  Tfr Zf1;
  ZforRangeNew(0, (Vec->Vrows - 1), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vy); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vy)) {
  Ti Vn;
  sf.pos=3145802;
  Vn = (Vy + Vec->Vrowoff);
  sf.pos=3145803;
  if ((Vn >= Vec->Vn_erows))
  {
   sf.pos=3145804;
   if (((Vec->Vn_erows == 0) && (Vy == (Vec->Vrows / 3))))
   {
    Ti Vpadding;
    sf.pos=3145805;
    Vw = ZcS(((Tc*)&Y1ky), Vvenci_v);
    sf.pos=3145806;
    Vpadding = (((Vec->Vcols - ZstringSize(Vw))) / 2);
    sf.pos=3145807;
    if ((Vpadding != 0))
    {
     sf.pos=3145808;
     Vab =  ZcS(Vab, ((Tc*)&Yab));
     sf.pos=3145809;
     --(Vpadding);
    }
    sf.pos=3145810;
    while ((Vpadding != 0))
    {
     sf.pos=3145811;
     Vab =  ZcS(Vab, ((Tc*)&YG));
     sf.pos=3145812;
     --(Vpadding);
    sf.pos=3145813;
    }
    sf.pos=3145814;
    Vab =  ZcS(Vab, ZstringSlice(Vw, 0, Vec->Vcols, 0));
   }
   else
   {
    sf.pos=3145815;
    Vab =  ZcS(Vab, ((Tc*)&Yab));
   }
  }
  else
  {
   Ti Vsz;
   Ti Vlen;
   Ti Vj;
   Ti Vccolor;
   sf.pos=3145816;
   Vsz = (ZstringSize(((Ys45 *)ZListGetPtr(Vec->Verows, Vn))->Vrender) - 1);
   sf.pos=3145817;
   Vlen = (Vsz - Vec->Vcoloff);
   sf.pos=3145818;
   if ((Vlen < 0))
   {
    sf.pos=3145819;
    Vlen = 0;
   }
   sf.pos=3145820;
   if ((Vlen >= Vec->Vcols))
   {
    sf.pos=3145821;
    Vlen = (Vec->Vcols - 1);
   }
   sf.pos=3145822;
   Vj = 0;
   sf.pos=3145823;
   Vccolor = -1;
   sf.pos=3145824;
   {
    Ti Vc;
    Tfs iZf3;
    Zf3 = ZstringSlice(((Ys45 *)ZListGetPtr(Vec->Verows, Vn))->Vrender, Vec->Vcoloff, (Vec->Vcoloff + Vlen), 0);
    ZforStringNew(Zf3, &iZf3);
    for (ZforStringGetInt(&iZf3, &Vc); ZforStringContInt(&iZf3); ZforStringNextInt(&iZf3, &Vc)) {
    Ti Vhlval;
    Vhlval = 0;
    sf.pos=3145825;
int*hlval = &Vhlval;
    sf.pos=3145826;
    Vhlval = ZListGetInt(((Ys45 *)ZListGetPtr(Vec->Verows, Vn))->Vhl, Vj);
    sf.pos=3145827;
    if (*hlval == HL_NORMAL)
    {
     sf.pos=3145828;
     if ((Vccolor != -1))
     {
      sf.pos=3145829;
      Vab =  ZcS(Vab, Ygor(((Tc*)&YUa), (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YQsa)))));
      sf.pos=3145830;
      Vccolor = -1;
     }
     sf.pos=3145831;
     Vab =  ZcS(Vab, ZintAsString(Vc));
    }
    else
    {
     Ti Vcolor;
     sf.pos=3145832;
     Vcolor = YB3w(Vec, Vhlval);
     sf.pos=3145833;
     if ((Vcolor != Vccolor))
     {
      sf.pos=3145834;
      Vccolor = Vcolor;
      sf.pos=3145835;
      Vab =  ZcS(Vab, Ygor(((Tc*)&YUa), (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)Zint2string(Vcolor)))));
     }
     sf.pos=3145836;
     Vab =  ZcS(Vab, ZintAsString(Vc));
    }
    sf.pos=3145837;
    ++(Vj);
    sf.pos=3145838;
    }
   }
   sf.pos=3145839;
   Vab =  ZcS(Vab, Ygor(((Tc*)&YUa), (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YQsa)))));
  }
  sf.pos=3145840;
  Vab =  ZcS(Vab, ((Tc*)&Y6Sh));
  sf.pos=3145841;
  Vab =  ZcS(Vab, ((Tc*)&Yau));
  sf.pos=3145842;
  }
 }
 sf.pos=3145843;
 r = Vab;
 topFrame = sf.prev;
 return r;
}
Tc *Y4Sa() {
 Ti Vstatlen;
 Zsf sf;
 Tc *r = 0;
 Tc *Vab = NULL;
 Tc *VbarText = NULL;
 Tc *VstatText = NULL;
 Tc *Vwelcome = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 Tc *t3 = NULL;
 Tc *t4 = NULL;
 Tc *t5 = NULL;
 Tc *t6 = NULL;
 Tc *t7 = NULL;
 Tl *t8 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2570800;
 Vab = ((Tc*)&Ya);
 sf.pos=2570801;
 VbarText = ZstringSlice(ZcS8(((Tc*)&YG), (((Vec->Vfilename == NULL)) ? (((Tc*)&YsQ7)) : (ZstringSlice(Vec->Vfilename, 0, 20, 0))), (t0 = (((Vec->Vfmodified > 0)) ? (((Tc*)&YQ)) : (((Tc*)&Ya)))), ((Tc*)&Yhyt), (t2 = Zint2string(Vec->Vn_erows)), ((Tc*)&YVqY), (Tc*)1, (Tc*)1), 0, (Vec->Vcols - 1), 0);
 sf.pos=2570802;
 VstatText = ZcS12(((Tc*)&Y7), ZintAsString(Vec->Vmode), ((Tc*)&YsAp), (t0 = (((Vec->Vcsyn != NULL)) ? (Vec->Vcsyn->Vft) : (((Tc*)&YzQY)))), ((Tc*)&Y3dz), (t2 = Zint2string((Vec->Vcy + 1))), ((Tc*)&YV), (t4 = Zint2string((Vec->Vn_erows + 1))), ((Tc*)&YJ7Q), (t6 = Zint2string((Vec->Vcx + 1))), (Tc*)1, (Tc*)1);
 sf.pos=2570803;
 Vstatlen = ZstringSize(VstatText);
 sf.pos=2570804;
 Vwelcome = ((Tc*)&YZAu);
 sf.pos=2570805;
 if (((ZstringSize(VbarText) + ZstringSize(Vwelcome)) < (Vec->Vcols - Vstatlen)))
 {
  sf.pos=2570806;
  VbarText = ZcS(Vwelcome, VbarText);
 }
 sf.pos=2570807;
 Vab =  ZcS(Vab, Ygor(((Tc*)&YUa), (t8 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t8, (Tz)(void*)((Tc*)&Y2)))));
 sf.pos=2570808;
 Vab =  ZcS(Vab, VbarText);
 sf.pos=2570809;
 {
  Ti Vn;
  Tfr Zf1;
  ZforRangeNew(ZstringSize(VbarText), (Vec->Vcols - 1), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vn); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vn)) {
  sf.pos=2570810;
  if (((Vec->Vcols - Vn) == Vstatlen))
  {
   sf.pos=2570811;
   Vab =  ZcS(Vab, VstatText);
   rt = 2;
   goto YxF8;
  }
  sf.pos=2570812;
  Vab =  ZcS(Vab, ((Tc*)&YG));
YxF8:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=2570813;
  }
 }
 sf.pos=2570814;
 Vab =  ZcS(Vab, Ygor(((Tc*)&YUa), ZnewList((Tt*)&string__T, 0)));
 sf.pos=2570815;
 Vab =  ZcS(Vab, ((Tc*)&Yau));
 sf.pos=2570816;
 r = Vab;
 topFrame = sf.prev;
 return r;
}
Tc *YTEZ() {
 Ti Vmsglen;
 Zsf sf;
 Tc *r = 0;
 Tc *Vab = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8679500;
 Vab = ((Tc*)&Ya);
 sf.pos=8679501;
 Vab =  ZcS(Vab, Ygor(((Tc*)&Yma), ZnewList((Tt*)&string__T, 0)));
 sf.pos=8679502;
 Vmsglen = ZstringSize(Vec->Vstatusmsg);
 sf.pos=8679503;
 if (((Vmsglen > 0) && ((Y9Rj() - Vec->Vstatime) < 500000)))
 {
  sf.pos=8679504;
  Vab =  ZcS(Vab, Vec->Vstatusmsg);
 }
 sf.pos=8679505;
 r = Vab;
 topFrame = sf.prev;
 return r;
}
void Y9Dc() {
 Zsf sf;
 Tc *Vab = NULL;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5680000;
 YLNB(Vec);
 sf.pos=5680001;
 YJA8(Vec);
 sf.pos=5680002;
 Vab = ((Tc*)&Ya);
 sf.pos=5680003;
 Vab =  ZcS(Vab, Ygor(((Tc*)&YTa), (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YamK)))));
 sf.pos=5680004;
 Vab =  ZcS(Vab, YcnF(1, 1));
 sf.pos=5680005;
 Vab =  ZcS(Vab, YZeI());
 sf.pos=5680006;
 Vab =  ZcS(Vab, Y4Sa());
 sf.pos=5680007;
 Vab =  ZcS(Vab, YTEZ());
 sf.pos=5680008;
 Vab =  ZcS(Vab, YcnF((((Vec->Vrx - Vec->Vcoloff)) + 1), (((Vec->Vcy - Vec->Vrowoff)) + 1)));
 sf.pos=5680009;
 Vab =  ZcS(Vab, Ygor(((Tc*)&YPa), (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YamK)))));
 sf.pos=5680010;
  write(STDOUT_FILENO, ZgetCstring(Vab), ZstringSize(Vab));
 topFrame = sf.prev;
 return;
}
Tc *Y1GC(Tc *Amsg, Tcb *Afn) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vbuf = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8745500;
 Vbuf = ((Tc*)&Ya);
 sf.pos=8745501;
 while (1)
 {
  Ti Vc;
  sf.pos=8745502;
  YouM(Vec, Amsg, Vbuf);
  sf.pos=8745503;
  Y9Dc();
  Vc = 0;
  sf.pos=8745504;
int*c = &Vc;
  sf.pos=8745505;
  Vc = Y8Q5();
  sf.pos=8745506;
  if (*c == DEL || *c == CTRL_KEY('h') || *c == BACKSPACE)
  {
   sf.pos=8745507;
   if ((ZstringSize(Vbuf) > 1))
   {
    sf.pos=8745508;
    Vbuf = ZstringSlice(Vbuf, 0, (ZstringSize(Vbuf) - 2), 0);
   }
   else
   {
    sf.pos=8745509;
    Vbuf = ((Tc*)&Ya);
   }
  }
  sf.pos=8745510;
  if (*c == '\x1b')
  {
   sf.pos=8745511;
   YouM(Vec, ((Tc*)&Ya), ((Tc*)&Ya));
   sf.pos=8745512;
   if ((Afn != NULL))
   {
    sf.pos=8745513;
    ((void (*)(Tcb *, Tc*, Ti))Afn->cfunc)((Tcb*)Afn, Vbuf, Vc);
   }
   sf.pos=8745514;
   r = NULL;
   rt = 1;
   goto YBPm;
  }
  sf.pos=8745515;
  if (*c == '\r')
  {
   sf.pos=8745516;
   if ((ZstringSize(Vbuf) > 0))
   {
    sf.pos=8745517;
    YouM(Vec, ((Tc*)&Ya), ((Tc*)&Ya));
    sf.pos=8745518;
    if ((Afn != NULL))
    {
     sf.pos=8745519;
     ((void (*)(Tcb *, Tc*, Ti))Afn->cfunc)((Tcb*)Afn, Vbuf, Vc);
    }
    rt = 2;
    goto YV6_;
   }
YV6_:
   if (rt) goto YBPm;
  }
  else {
  sf.pos=8745520;
 if (!iscntrl(*c) && *c < 128)
  {
   sf.pos=8745521;
   Vbuf =  ZcS(Vbuf, ZintAsString(Vc));
  }
  }
  sf.pos=8745522;
  if ((Afn != NULL))
  {
   sf.pos=8745523;
   ((void (*)(Tcb *, Tc*, Ti))Afn->cfunc)((Tcb*)Afn, Vbuf, Vc);
  }
YBPm:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YOxB;
 sf.pos=8745524;
 }
 sf.pos=8745525;
 r = Vbuf;
YOxB:
 topFrame = sf.prev;
 return r;
}
Ti Y8Q5() {
 Ti Vnread;
 Tc Vc;
 Ti Vres;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vnread = 0;
 sf.pos=7939000;
int*nread = &Vnread;
 Vc = 0;
 sf.pos=7939001;
char*c = &Vc;
 Vres = 0;
 sf.pos=7939002;
int*res = &Vres;
 sf.pos=7939003;
 while ((*nread = read(STDIN_FILENO, c, 1)) != 1)
 {
  sf.pos=7939004;
  if (*nread == -1 && errno != EAGAIN)
  {
   sf.pos=7939005;
   YqsW(((Tc*)&Y9Ri));
  }
 sf.pos=7939006;
 }
 sf.pos=7939007;
 if (*c == '\x1b')
 {
  sf.pos=7939008;
    char seq[3];
  sf.pos=7939009;
  if (read(STDIN_FILENO, &seq[0], 1) != 1)
  {
   sf.pos=7939010;
   r = '\x1b';
   rt = 1;
   goto YNjP;
  }
  sf.pos=7939011;
  if (read(STDIN_FILENO, &seq[1], 1) != 1)
  {
   sf.pos=7939012;
   r = '\x1b';
   rt = 1;
   goto YNjP;
  }
  sf.pos=7939013;
  if (seq[0] == '[')
  {
   sf.pos=7939014;
   if (seq[1] >= '0' && seq[1] <= '9')
   {
    sf.pos=7939015;
    if (read(STDIN_FILENO, &seq[2], 1) != 1)
    {
     sf.pos=7939016;
     r = '\x1b';
     rt = 1;
     goto Yatd;
    }
    sf.pos=7939017;
    if (seq[2] == '~')
    {
     Tc Vseq1;
     sf.pos=7939018;
     Vseq1 = seq[1];
     sf.pos=7939019;
     switch (Vseq1)
     {
     case '1':
      {
       sf.pos=7939020;
       r = HOME;
       rt = 1;
       goto YSsI;
      }
     case '3':
      {
       sf.pos=7939021;
       r = DEL;
       rt = 1;
       goto YSsI;
      }
     case '4':
      {
       sf.pos=7939022;
       r = END;
       rt = 1;
       goto YSsI;
      }
     case '5':
      {
       sf.pos=7939023;
       r = PAGE_UP;
       rt = 1;
       goto YSsI;
      }
     case '6':
      {
       sf.pos=7939024;
       r = PAGE_DOWN;
       rt = 1;
       goto YSsI;
      }
     case '7':
      {
       sf.pos=7939025;
       r = HOME;
       rt = 1;
       goto YSsI;
      }
     case '8':
      {
       sf.pos=7939026;
       r = END;
       rt = 1;
       goto YSsI;
      }
YSsI:
      if (rt) goto YhvD;
     }
YhvD:
     if (rt) goto Yatd;
    }
Yatd:
    if (rt) goto Yq1Z;
   }
   else
   {
    Tc Vseq1;
    sf.pos=7939027;
    Vseq1 = seq[1];
    sf.pos=7939028;
    switch (Vseq1)
    {
    case 65:
     {
      sf.pos=7939029;
      r = UP;
      rt = 1;
      goto YOW5;
     }
    case 66:
     {
      sf.pos=7939030;
      r = DOWN;
      rt = 1;
      goto YOW5;
     }
    case 67:
     {
      sf.pos=7939031;
      r = RIGHT;
      rt = 1;
      goto YOW5;
     }
    case 68:
     {
      sf.pos=7939032;
      r = LEFT;
      rt = 1;
      goto YOW5;
     }
    case 72:
     {
      sf.pos=7939033;
      r = HOME;
      rt = 1;
      goto YOW5;
     }
    case 70:
     {
      sf.pos=7939034;
      r = END;
      rt = 1;
      goto YOW5;
     }
YOW5:
     if (rt) goto Yx4N;
    }
Yx4N:
    if (rt) goto Yq1Z;
   }
Yq1Z:
   if (rt) goto YNjP;
  }
  else {
  sf.pos=7939035;
 if (seq[0] == 'O')
  {
   Tc Vseq1;
   sf.pos=7939036;
   Vseq1 = seq[1];
   sf.pos=7939037;
   switch (Vseq1)
   {
   case 72:
    {
     sf.pos=7939038;
     r = HOME;
     rt = 1;
     goto YpcY;
    }
   case 70:
    {
     sf.pos=7939039;
     r = END;
     rt = 1;
     goto YpcY;
    }
YpcY:
    if (rt) goto YtAG;
   }
YtAG:
   if (rt) goto YNjP;
  }
  }
  sf.pos=7939040;
  r = '\x1b';
YNjP:
  ;
  rt = 1;
  goto Y0Pr;
 }
 else
 {
  sf.pos=7939041;
  r = Vc;
  rt = 1;
  goto Y0Pr;
 }
Y0Pr:
 topFrame = sf.prev;
 return r;
}
void ZcbYYfE(Tcb *cb, Tc *arg0, Ti arg1) {
YYfE(arg0, arg1);
}
/*
 * INIT IMT
 */
void ZimtInit(void) {
 {
  Ytlm *p = 0;
  ToYtlm[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtlm[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtlm[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YEro *p = 0;
  YEro__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YEro__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YEro__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYEro[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYEro[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYEro[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YKhn *p = 0;
  YKhn__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YKhn__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YKhn__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYKhn[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYKhn[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYKhn[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y1uN *p = 0;
  Y1uN__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y1uN__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y1uN__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY1uN[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY1uN[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY1uN[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YAxe *p = 0;
  YAxe__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YAxe__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YAxe__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYAxe[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYAxe[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYAxe[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YVNj *p = 0;
  YVNj__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YVNj__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YVNj__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYVNj[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYVNj[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYVNj[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yalz *p = 0;
  Yalz__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yalz__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yalz__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYalz[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYalz[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYalz[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yw3O *p = 0;
  Yw3O__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yw3O__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yw3O__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYw3O[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYw3O[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYw3O[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y2EX *p = 0;
  Y2EX__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y2EX__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y2EX__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY2EX[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY2EX[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY2EX[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YX0i *p = 0;
  YX0i__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YX0i__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YX0i__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYX0i[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYX0i[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYX0i[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YP_P *p = 0;
  YP_P__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YP_P__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YP_P__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYP_P[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYP_P[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYP_P[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YzSI *p = 0;
  YzSI__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YzSI__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YzSI__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYzSI[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYzSI[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYzSI[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YXKl *p = 0;
  YXKl__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YXKl__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YXKl__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYXKl[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYXKl[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYXKl[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YuDC *p = 0;
  YuDC__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YuDC__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YuDC__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYuDC[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYuDC[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYuDC[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YrHq *p = 0;
  YrHq__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YrHq__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YrHq__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYrHq[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYrHq[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYrHq[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YkxB *p = 0;
  ToYkxB[1].off = (int)((Tc*)&p->Vfilename - (Tc*)p);
  ToYkxB[2].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Yw8L *p = 0;
  Yw8L__Yw8L_I_imt[20] = (Tc*)((Tc*)&p->Vfd - (Tc*)p);
  Yw8L__Yw8L_I_imt[21] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYw8L[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
 }
 {
  YjUM *p = 0;
  ToYjUM[1].off = (int)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[2].off = (int)((Tc*)&p->Vx - (Tc*)p);
 }
 {
  YuMQ *p = 0;
  ToYuMQ[1].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Y86c *p = 0;
  Y86c__YuQR_I_imt[1] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  Y86c__YuQR_I_imt[2] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  Y86c__YuQR_I_imt[3] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  Y86c__YuQR_I_imt[4] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  Y86c__YuQR_I_imt[5] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  Y86c__YuQR_I_imt[6] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  Y86c__YuQR_I_imt[7] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  Y86c__YuQR_I_imt[8] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  Y86c__YuQR_I_imt[9] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  ToY86c[1].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY86c[2].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY86c[3].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY86c[4].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY86c[5].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YJQu *p = 0;
  ToYJQu[1].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYJQu[2].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYJQu[3].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYJQu[4].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYJQu[5].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYJQu[6].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YzqH *p = 0;
  ToYzqH[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYzqH[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYzqH[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYzqH[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYzqH[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYzqH[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYzqH[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYzqH[8].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Y_SI *p = 0;
  ToY_SI[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY_SI[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY_SI[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY_SI[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY_SI[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY_SI[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY_SI[7].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Ybkz *p = 0;
  ToYbkz[1].off = (int)((Tc*)&p->Vft - (Tc*)p);
  ToYbkz[2].off = (int)((Tc*)&p->Vfpatterns - (Tc*)p);
  ToYbkz[3].off = (int)((Tc*)&p->VicommentStyle - (Tc*)p);
  ToYbkz[4].off = (int)((Tc*)&p->Vkeywords - (Tc*)p);
 }
 {
  Ys45 *p = 0;
  ToYs45[1].off = (int)((Tc*)&p->Vtxt - (Tc*)p);
  ToYs45[2].off = (int)((Tc*)&p->Vorig - (Tc*)p);
  ToYs45[3].off = (int)((Tc*)&p->Vrender - (Tc*)p);
  ToYs45[4].off = (int)((Tc*)&p->Vhl - (Tc*)p);
  ToYs45[5].off = (int)((Tc*)&p->Vsyn - (Tc*)p);
 }
 {
  YQfU *p = 0;
  ToYQfU[1].off = (int)((Tc*)&p->Verows - (Tc*)p);
  ToYQfU[2].off = (int)((Tc*)&p->Vcopy - (Tc*)p);
  ToYQfU[3].off = (int)((Tc*)&p->Vfilename - (Tc*)p);
  ToYQfU[4].off = (int)((Tc*)&p->Vstatusmsg - (Tc*)p);
  ToYQfU[5].off = (int)((Tc*)&p->Vcsyn - (Tc*)p);
 }
}

/*
 * INIT GLOBALS
 */
int ZglobInit(int round) {
 int done = 1;
 Tl *t0;
 Tl *t1;
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 sf.frof = NULL;
 topFrame = &sf;
 done &= JIOModule(round);
 done &= JLOGModule(round);
 done &= JARGModule(round);
 if (round == 2001) {
   sf.pos=0;
   Vfiletypes = ZnewList((Tt*)&Ybkz__T, 1); ZLap((Tl*)Vfiletypes, (Tz)(void*)Yfrg(NULL, ((Tc*)&Ye5c), (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYv4))), HI_NUM | HI_STRING, ((Tc*)&YJ), (t1 = ZnewList((Tt*)&string__T, 31), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Y0Y5)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YrUa)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YqI4)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YHo2)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Yj1a)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YexT)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Yc7A)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Y6T9)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YMwW)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YGD1)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Yz51)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Yr1a)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Y7fW)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Y9jU)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YML6)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YZzE)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Yn3A)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Y6FU)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YjG6)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Y9a)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YIuk)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&Y8Cc)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YBs9)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YPOy)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YcbZ)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YF0o)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YaTa)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YB_5)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YyD_)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YiGa)), ZLap((Tl*)t1, (Tz)(void*)((Tc*)&YDd3)))));
   sf.pos=1;
   Vec = Yek3(NULL);
   sf.pos=3376300;
   Yu33 = NULL;
 }
 topFrame = sf.prev;
 return done;
}

/*
 * MAIN
 */
void disableRawMode() {
  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, Vec->Vorig_termios) == -1)
    YqsW(((Tc*)&Ykqx));
  free(Vec->Vorig_termios);
}

#if defined(__MINGW32__) || defined(_MSC_VER)
# define CATCH_SIG(sig, func) signal(sig, func)
  typedef struct SEH_EXCEPTION_REGISTRATION_S SEH_EXCEPTION_REGISTRATION;
  struct SEH_EXCEPTION_REGISTRATION_S
  {
    SEH_EXCEPTION_REGISTRATION *prev;
    PEXCEPTION_HANDLER handler;
  };
  static EXCEPTION_DISPOSITION exception_handler(PEXCEPTION_RECORD pRecord, SEH_EXCEPTION_REGISTRATION *pReg, PCONTEXT pContext, PEXCEPTION_RECORD pRecord2) {
   Zdeadly(11);
   return ExceptionContinueSearch;
  }
#else
# define CATCH_SIG(sig, func) catch_sig(sig, func)
void catch_sig(int sig, void *func) {
 struct sigaction act;
 act.sa_handler = func;
 sigemptyset(&act.sa_mask);
 act.sa_flags = SA_NODEFER;
 sigaction(sig, &act, NULL);
}
#endif

int Fmain(void);
int main(int argc, char **argv) {
 int r = 0;
 int round = 0;
#if defined(__MINGW32__) || defined(_MSC_VER)
 SEH_EXCEPTION_REGISTRATION seh_er;
 seh_er.handler = (PEXCEPTION_HANDLER)(exception_handler);
 asm volatile ("movl %%fs:0, %0" : "=r" (seh_er.prev));
 asm volatile ("movl %0, %%fs:0" : : "r" (&seh_er));
#else
# ifdef SIGSEGV
 CATCH_SIG(SIGSEGV, Zdeadly);
# endif
# ifdef SIGBUS
 CATCH_SIG(SIGBUS, Zdeadly);
# endif
# ifdef SIGFPE
 CATCH_SIG(SIGFPE, Zdeadly);
# endif
#endif
#if defined(__MINGW32__) || defined(_MSC_VER)
# ifdef __MINGW32__
 _fmode = _O_BINARY;
# else
 _set_fmode(_O_BINARY);
# endif
 _setmode(_fileno(stdin), _O_BINARY);
 _setmode(_fileno(stdout), _O_BINARY);
 _setmode(_fileno(stderr), _O_BINARY);
#endif
 emergencyAlloc = malloc(16384);
 ZimtInit();
 ZglobInit(round++);
 YzvW = Zstr(argv[0]);
 Y1p3 = ZnewList(&string__T, 0);
 {
  int i;
  for (i = 1; i < argc; ++i) {
   ZLa(Y1p3, -1, (Tz)(void*)Zstr(argv[i]));
  }
 }

 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 1002) ZthrowCstringInit("Early initialization not done within 1000 rounds");
 }
 YZH8();

 round = 2001;
 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 3002) ZthrowCstringInit("Initialization not done within 1000 rounds");
 }
 r = Fmain();
 beforeExit();
 if (topFrame != NULL) fprintf(stderr, "INTERNAL: topFrame not NULL\n");
 return r;
}


int Fmain(void) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 r = 0;
 sf.pos=527000;
 YDKA();
 sf.pos=527001;
 if ((YLNB(Vec) != 1))
 {
  sf.pos=527002;
  YqsW(((Tc*)&Yt7s));
 }
 sf.pos=527003;
 YouM(Vec, ((Tc*)&YmOu), ((Tc*)&Ya));
 sf.pos=527004;
 if ((Y2H3() > 0))
 {
  sf.pos=527005;
  YaZr(Vec, ((Tc *)ZListGetPtr(YUgp(), 0)));
 }
 sf.pos=527006;
 while (1)
 {
  sf.pos=527007;
  Y9Dc();
  sf.pos=527008;
  YLzL();
 sf.pos=527009;
 }
 sf.pos=527010;
 r = 0;
 topFrame = sf.prev;
 return r;
}
