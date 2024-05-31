#pragma once

class ISensorAsync
{
public:
    virtual bool initiateReading() = 0;
    virtual void onNewReading() = 0;
};

