#ifndef QGATES
#define QGATES
#include "qbool.h"

extern qbool qnot(qbool a);
extern qbool qand(qbool a, qbool b);
extern qbool qor(qbool a, qbool b);
extern qbool qnor(qbool a, qbool b);
extern qbool qxor(qbool a, qbool b);
extern qbool qxnor(qbool a, qbool b);
extern qbool qmux (qbool s, qbool a, qbool b);

#endif
