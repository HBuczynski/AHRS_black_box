#ifndef AHRSPAGE_H
#define AHRSPAGE_H

#include <QWidget>

#include "WidgetPFD.h"
#include "WidgetTC.h"
#include "WidgetVSI.h"

#include "Buttons.h"

namespace Ui {
class AHRSPage;
}

class AHRSPage : public QWidget
{
    Q_OBJECT

public:
    explicit AHRSPage(QWidget *parent = 0);
    ~AHRSPage();

    inline void setRoll( float roll );
    inline void setPitch( float pitch );
    inline void setAltitude( float altitude );
    inline void setPressure( float pressure );
    inline void setAirspeed( float airspeed );
    inline void setMachNo( float machNo );
    inline void setHeading( float heading );
    inline void setClimbRate( float climbRate );

    inline void setTurnRate( float turnRate );
    inline void setSlipSkid( float slipSkid );

private:
    void setup();
    void initializeButtons(std::map<peripherals::SwitchesCode, std::string> name, std::map<peripherals::SwitchesCode, std::function<void()> > callbackFunctions);

    void calibrateButton();
    void menuButton();
    void logsButton();
    void exitButton();

    Buttons *buttons_;
    WidgetTC *widgetTC_;
    WidgetVSI *widgetVSI_;
    WidgetPFD *widgetPFD_;
    Ui::AHRSPage *ui;

    utility::Logger& logger_;
};

#endif // AHRSPAGE_H