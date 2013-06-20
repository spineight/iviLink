#ifndef ANDROID


#include "QMLAuthenticationDialog.hpp"

using namespace iviLink::Authentication;

Logger QMLAuthenticationDialog::mLogger =  Logger::getInstance(LOG4CPLUS_TEXT("applications.AuthenticationApplication"));

QMLAuthenticationDialog::QMLAuthenticationDialog()
        :isCursorHide(true)
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    mMachine = new AuthenticationStateMachine(PREFIX "/database/");
}

void QMLAuthenticationDialog::init()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    mMachine->startAuthentication(this);
}

QMLAuthenticationDialog::~QMLAuthenticationDialog()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    delete mMachine;
}

void QMLAuthenticationDialog::showNumPad()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    mPin.clear();
    emit sigShowNumPad();
    updateUiAvaliability();
}

void QMLAuthenticationDialog::hideNumPad()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    emit sigHideNumPad();
}

void QMLAuthenticationDialog::showRetryPopup()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    emit sigShowRetryPopup();
}

void QMLAuthenticationDialog::resetNumPad()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    mPin.clear();
    updateUiAvaliability();
}

void QMLAuthenticationDialog::lockInput()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    emit sigLockInput();
}

void QMLAuthenticationDialog::unlockInput()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    emit sigUnlockInput();
    updateUiAvaliability();
}


void QMLAuthenticationDialog::onNumberClicked(int number)
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    LOG4CPLUS_INFO(mLogger, "Clicked number: " + convertIntegerToString(number));
    mPin.pushToPIN(number);
    updateUiAvaliability();
}

void QMLAuthenticationDialog::onOKButtonClicked()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    if(mPin.isPINSet())
    {
        mMachine->sendPin(mPin.getFirstDigit(), mPin.getSecondDigit(), mPin.getThirdDigit(), mPin.getFourthDigit());
    }
    else
    {
        LOG4CPLUS_WARN(mLogger, "Shouldn't be able to click the button in this state?");
    }
}

void QMLAuthenticationDialog::onCancelButtonClicked()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    mMachine->cancelAuthentication();
}

void QMLAuthenticationDialog::onBackspaceButtonClicked()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    mPin.popFromPIN();
    updateUiAvaliability();
}

void QMLAuthenticationDialog::updateUiAvaliability()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);
    if(mPin.isPINSet())
    {
        emit sigUnlockOkButton();
    }
    else
    {
        emit sigLockOkButton();
    }
    if(mPin.isPINEmpty())
    {
        LOG4CPLUS_INFO(mLogger, "Pin is empty, locking backspace");
        emit sigLockBackspaceButton();
    }
    else
    {
        LOG4CPLUS_INFO(mLogger, "Pin  NOT empty, UNlocking backspace");
        emit sigUnlockBackspaceButton();
    }
    emit sigSetTexbox(QString::fromStdString(mPin.getEnteredDigitsAsString()));
}

void QMLAuthenticationDialog::setDeclarativeView(QDeclarativeView * declarativeView)
{
    mDeclarativeView = declarativeView;
}

void QMLAuthenticationDialog::onRightButtonClicked()
{
    LOG4CPLUS_TRACE_METHOD(mLogger, __PRETTY_FUNCTION__);

    if (isCursorHide)
    {
        isCursorHide = false;
        mDeclarativeView->setCursor(QCursor(Qt::ArrowCursor));
    }
    else
    {
        isCursorHide = true;
        mDeclarativeView->setCursor(QCursor(Qt::BlankCursor));
    }
}

#endif // ANDROID
