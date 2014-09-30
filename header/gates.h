#ifndef QGATES
#define QGATES
#include "qbool.h"
 qboolP qnot(qboolP in, qboolP out);
 qboolP qand(qboolP in1, qboolP in2, qboolP out);
 qboolP qor(qboolP a, qboolP b, qboolP out);
 qboolP qnor(qboolP a, qboolP b, qboolP out);
 qboolP qxor(qboolP a, qboolP b, qboolP out);
 qboolP qxnor(qboolP a, qboolP b, qboolP out);
 qboolP qmux (qboolP in1, qboolP in2, qboolP s, qboolP out);
 qboolP qdemux(qboolP in, qboolP s1, qboolP s2, qboolP out);
 qboolP qfulladder(qboolP in1, qboolP in2, qboolP carryin, qboolP sumout, qboolP carryout);
#endif
