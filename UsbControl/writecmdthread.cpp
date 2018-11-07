#include "writecmdthread.h"
#include "powertestinstancegetter.h"

void WriteCmdThread::run()
{
    PowerTestInstanceGetter o_PowerTestInstanceGetter;
    PowerTest *p_PowerTest = o_PowerTestInstanceGetter.GetInstance();
    int n_Ret = p_PowerTest->StartSinglePowerTest(m_pLDHandle);
    if(n_Ret){
        p_PowerTest->WriteSendCmdResult(m_nStation, true);
    }
    else{
        p_PowerTest->WriteSendCmdResult(m_nStation, false);
    }
}

void WriteCmdThread::SetStation(int n_Station)
{
    m_nStation = n_Station;
}

void WriteCmdThread::SetLDHandle(libusb_device_handle *p_LDHandle)
{
    m_pLDHandle = p_LDHandle;
}
