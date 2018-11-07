#ifndef POWERTESTINSTANCEGETTER_H
#define POWERTESTINSTANCEGETTER_H
#include "powertest.h"

class PowerTestInstanceGetter
{
public:
    PowerTestInstanceGetter();
    ~PowerTestInstanceGetter();

public:
    PowerTest * GetInstance();

private:
    static PowerTest *m_pPowerTestInstance;
    static uint m_unPowerTestReference;
};

#endif // POWERTESTINSTANCEGETTER_H
