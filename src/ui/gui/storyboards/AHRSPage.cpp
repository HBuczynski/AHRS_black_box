#include "AHRSPage.h"
#include "ui_AHRSPage.h"

using namespace std;
using namespace utility;
using namespace peripherals;

AHRSPage::AHRSPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AHRSPage),
    logger_(Logger::getInstance())
{
    ui->setupUi(this);

    setup();
}

AHRSPage::~AHRSPage()
{
    if(buttons_)
    {
        delete buttons_;
    }

    if(widgetTC_)
    {
        delete widgetTC_;
    }

    if(widgetVSI_)
    {
        delete widgetVSI_;
    }

    if(widgetPFD_)
    {
        delete widgetPFD_;
    }

    delete ui;
}

void AHRSPage::setup()
{
    // SETUP avionic devices
    widgetPFD_ = new WidgetPFD();
    ui->pfdLayout->addWidget(widgetPFD_);

    widgetTC_ = new WidgetTC();
    ui->devicesLayout->addWidget(widgetTC_);

    widgetVSI_ = new WidgetVSI();
    ui->devicesLayout->addWidget(widgetVSI_);

    // SETUP top labels
    QFont upFont("Arial", 10, QFont::Bold);
    QFont downFont("Arial", 13, QFont::Bold);

    ui->upFirstAHRS->setStyleSheet("QLabel {color : white; background-color: rgb(45,45, 45)}");
    ui->upFirstAHRS->setFont(upFont);
    ui->upFirstAHRS->setText("AHRS I");
    ui->downFirstAHRS->setStyleSheet("QLabel {color : black; background-color: rgb(51,255,0)}");
    ui->downFirstAHRS->setFont(downFont);
    ui->downFirstAHRS->setText("MASTER");

    ui->upSecondAHRS->setStyleSheet("QLabel {color : white; background-color: rgb(45,45, 45)}");
    ui->upSecondAHRS->setFont(upFont);
    ui->upSecondAHRS->setText("AHRS II");
    ui->downSecondAHRS->setStyleSheet("QLabel {color : black; background-color: rgb(51,255,0)}");
    ui->downSecondAHRS->setFont(downFont);
    ui->downSecondAHRS->setText("REDUNDANT");

    ui->upGrdSpeed->setStyleSheet("QLabel {color : white; background-color: rgb(45,45, 45)}");
    ui->upGrdSpeed->setFont(upFont);
    ui->upGrdSpeed->setText("GRD SPEED");
    ui->downGrdSpeed->setStyleSheet("QLabel {color : rgb(51,255,0); background-color: rgb(75, 75, 75)}");
    ui->downGrdSpeed->setFont(downFont);
    ui->downGrdSpeed->setText("0 kts");

    ui->upAltGps->setStyleSheet("QLabel {color : white; background-color: rgb(45,45, 45)}");
    ui->upAltGps->setFont(upFont);
    ui->upAltGps->setText("ALT (GPS)");
    ui->downAltGps->setStyleSheet("QLabel {color : rgb(51,255,0); background-color: rgb(75, 75, 75)}");
    ui->downAltGps->setFont(downFont);
    ui->downAltGps->setText("0 ft");

    ui->upFltDuration->setStyleSheet("QLabel {color : white; background-color: rgb(45,45, 45)}");
    ui->upFltDuration->setFont(upFont);
    ui->upFltDuration->setText("FLIGHT DURATION");
    ui->downFltDuration->setStyleSheet("QLabel {color : rgb(51,255,0); background-color: rgb(75, 75, 75)}");
    ui->downFltDuration->setFont(downFont);
    ui->downFltDuration->setText("00:00:00");

    ui->upBoxPower->setStyleSheet("QLabel {color : white; background-color: rgb(45,45, 45)}");
    ui->upBoxPower->setFont(upFont);
    ui->upBoxPower->setText("FEEDER POWER");
    ui->downBoxPower->setStyleSheet("QLabel {color : rgb(51,255,0); background-color: rgb(75, 75, 75)}");
    ui->downBoxPower->setFont(downFont);
    ui->downBoxPower->setText("100 %");

    ui->upPowerSupply->setStyleSheet("QLabel {color : white; background-color: rgb(45,45, 45)}");
    ui->upPowerSupply->setFont(upFont);
    ui->upPowerSupply->setText("POWER");
    ui->downPowerSupply->setStyleSheet("QLabel {color : rgb(51,255,0); background-color: rgb(75, 75, 75)}");
    ui->downPowerSupply->setFont(downFont);
    ui->downPowerSupply->setText("100 %");

    map<SwitchesCode, string> buttonNames;
    buttonNames[SwitchesCode::FIRST_SWITCH] = "CALIBRATE";
    buttonNames[SwitchesCode::SECOND_SWITCH] = "LOGS";
    buttonNames[SwitchesCode::THIRD_SWITCH] = "MENU";
    buttonNames[SwitchesCode::FOURTH_SWITCH] = "EXIT";

    map<SwitchesCode, function<void()> > callbackFunctions;
    callbackFunctions[SwitchesCode::FIRST_SWITCH] = bind(&AHRSPage::calibrateButton, this);
    callbackFunctions[SwitchesCode::SECOND_SWITCH] = bind(&AHRSPage::menuButton, this);
    callbackFunctions[SwitchesCode::THIRD_SWITCH] = bind(&AHRSPage::logsButton, this);
    callbackFunctions[SwitchesCode::FOURTH_SWITCH] = bind(&AHRSPage::exitButton, this);

    initializeButtons(buttonNames, callbackFunctions);
}

void AHRSPage::initializeButtons(map<SwitchesCode, string> name, map<SwitchesCode, function<void()> > callbackFunctions)
{
    buttons_ = new Buttons();
    buttons_->initialize(name, callbackFunctions);

    ui->buttonLayout->addWidget(buttons_);
}

void AHRSPage::calibrateButton()
{

}

void AHRSPage::menuButton()
{

}

void AHRSPage::logsButton()
{

}

void AHRSPage::exitButton()
{

}

void AHRSPage::setRoll( float roll )
{
    widgetPFD_->setRoll( roll );
}

void AHRSPage::setPitch( float pitch )
{
    widgetPFD_->setPitch( pitch );
}

void AHRSPage::setAltitude( float altitude )
{
    widgetPFD_->setAltitude( altitude );
}

void AHRSPage::setPressure( float pressure )
{
    widgetPFD_->setPressure( pressure);
}

void AHRSPage::setAirspeed( float airspeed )
{
    widgetPFD_->setAirspeed( airspeed );
}

void AHRSPage::setMachNo( float machNo )
{
    widgetPFD_->setMachNo( machNo );
}

void AHRSPage::setHeading( float heading )
{
    widgetPFD_->setHeading( heading );
}

void AHRSPage::setClimbRate( float climbRate )
{
    widgetPFD_->setClimbRate( climbRate );
    widgetVSI_->setClimbRate( climbRate );
}

void AHRSPage::setTurnRate( float turnRate )
{
    widgetTC_->setTurnRate( turnRate );
}

void AHRSPage::setSlipSkid( float slipSkid )
{
    widgetTC_->setSlipSkid( slipSkid );
}