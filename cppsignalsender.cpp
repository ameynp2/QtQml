#include "cppsignalsender.h"

cppSignalSender::cppSignalSender(QObject *parent) : QObject{parent},
    mTimer (new QTimer(this)),
    mValue(0)
{
    connect(mTimer, &QTimer::timeout, [=](){
        ++mValue;
        emit cppTimer(QString::number(mValue));
    });

    mTimer->start(1000);
}

void cppSignalSender::cppSlot()
{
    emit callQml("Information from C++");
}

