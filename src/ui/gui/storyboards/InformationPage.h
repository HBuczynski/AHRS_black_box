#ifndef INFORMATIONPAGE_H
#define INFORMATIONPAGE_H

#include "../PageController.h"

#include <QWidget>
#include <memory>

#include "Buttons.h"

namespace Ui {
class InformationPage;
}

class InformationPage : public QWidget
{
    Q_OBJECT

public:
    explicit InformationPage(gui::PageController *controller, QWidget *parent = 0);
    ~InformationPage();

    void initializeExit();
    void initializeContinue();

    void setMasterConnectionEstablished();
    void setMasterConnectionFailed();
    void setSecondaryConnectionEstablished();
    void setSecondaryConnectionFailed();
    void setBITSMaster();
    void setBITSMasterFailed();
    void setBITSRedundant();
    void setBITRedundantFailed();

signals:
    void signalAHRSPage();
    void signalExitPage();
    void signalStartAcquisition(std::vector<uint8_t>);

private:
    void pageSetup();

    void initializeButtons(std::map<peripherals::SwitchCode, std::string> name, std::map<peripherals::SwitchCode, std::function<void()> > callbackFunctions);

    void firstButton();
    void secondButton();
    void thirdButton();
    void exitButton();
    void continueButton();

    gui::PageController *controller_;
    std::unique_ptr<Buttons> buttons_;
    Ui::InformationPage *ui_;
};

#endif // INFORMATIONPAGE_H
