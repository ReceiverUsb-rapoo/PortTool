#include "powertestinstancegetter.h"

PowerTest *PowerTestInstanceGetter::m_pPowerTestInstance = NULL;
uint PowerTestInstanceGetter::m_unPowerTestReference = 0;

PowerTestInstanceGetter::PowerTestInstanceGetter()
{
    if(m_pPowerTestInstance == NULL){
        m_pPowerTestInstance = new PowerTest;
    }

    m_unPowerTestReference++;
}

PowerTestInstanceGetter::~PowerTestInstanceGetter()
{
    m_unPowerTestReference --;
    if(m_unPowerTestReference == 0){
        if(m_pPowerTestInstance != NULL){
            delete m_pPowerTestInstance;
            m_pPowerTestInstance = NULL;
        }
    }
}

PowerTest *PowerTestInstanceGetter::GetInstance()
{
    return m_pPowerTestInstance;
}
