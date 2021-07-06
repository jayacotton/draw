#include "f2c.h"

/* Common Block Declarations */


#define tktrnx_1 tktrnx_

extern int rescal_(void);
int logtrn_(integer * itype)
{

    tktrnx_1.keycon = 2;
    tktrnx_1.trpar1 = (real) (*itype);
    rescal_();
    return 0;
}				/* logtrn_ */

int logtrn(int type)
{
int i;
	i = type;
	return (logtrn_(&i));
}
