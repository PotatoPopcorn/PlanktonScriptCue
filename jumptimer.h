#ifndef JUMPTIMER_H
#define JUMPTIMER_H

#include "basejump.h"

class JumpTimer : public BaseJump
{
public:
    JumpTimer();

    QString getDetails();
};

#endif // JUMPTIMER_H
