#include <QPalette>
#include "colorclass.h"
#include "ui_colorclass.h"
#include <QMessageBox>
#include <QWidget>
#include <QColor>
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QtCore>
#include <QPen>
#include <QtAlgorithms>

colorclass::colorclass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::colorclass)
{
    ui->setupUi(this);
    connect(ui->redslider,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    connect(ui->greenslider,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    connect(ui->blueslider,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    onColorChanged();

     m_mouseClick = false;
     myPenColor = QColor(0,255,0,255);// set default color
     pencil.setColor(myPenColor);

}

colorclass::~colorclass()
{
    delete ui;
}

void colorclass::onColorChanged()
{
    m_color.setRgb(ui->redslider->value(),ui->greenslider->value(),ui->blueslider->value());
    QPalette pal=ui->displaywidget->palette();
    pal.setColor(QPalette::Window,m_color);
    ui->displaywidget->setPalette(pal);
    emit colorChanged(m_color);
    QPalette p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18;
    //black , white , darkGray , gray , lightGray , red , green , blue ,
    //cyan , magenta , yellow , darkRed , darkGreen , darkBlue , darkCyan , darkMagenta , darkYellow

    p1=ui->chooseRed->palette();
    p1.setColor(QPalette::Background,Qt::red);
    ui->chooseRed->setPalette(p1);

    p2=ui->chooseBlue->palette();
    p2.setColor(QPalette::Background,Qt::blue);
    ui->chooseBlue->setPalette(p2);

    p3=ui->chooseYellow->palette();
    p3.setColor(QPalette::Background,Qt::yellow);
    ui->chooseYellow->setPalette(p3);

    p4=ui->chooseGreen->palette();
    p4.setColor(QPalette::Background,Qt::green);
    ui->chooseGreen->setPalette(p4);

    p5=ui->chooseWhite->palette();
    p5.setColor(QPalette::Background,Qt::white);
    ui->chooseWhite->setPalette(p5);

    p6=ui->chooseBlack->palette();
    p6.setColor(QPalette::Background,Qt::black);
    ui->chooseBlack->setPalette(p6);

    p7=ui->chooseMagenta->palette();
    p7.setColor(QPalette::Background,Qt::magenta);
    ui->chooseMagenta->setPalette(p7);

    p8=ui->chooseCyan->palette();
    p8.setColor(QPalette::Background,Qt::cyan);
    ui->chooseCyan->setPalette(p8);

    p9=ui->chooseDarkRed->palette();
    p9.setColor(QPalette::Background,Qt::darkRed);
    ui->chooseDarkRed->setPalette(p9);

    p10=ui->chooseDarkGreen->palette();
    p10.setColor(QPalette::Background,Qt::darkGreen);
    ui->chooseDarkGreen->setPalette(p10);

    p11=ui->chooseDarkBlue->palette();
    p11.setColor(QPalette::Background,Qt::darkBlue);
    ui->chooseDarkBlue->setPalette(p11);

    p12=ui->chooseDarkCyan->palette();
    p12.setColor(QPalette::Background,Qt::darkCyan);
    ui->chooseDarkCyan->setPalette(p12);

    p13=ui->chooseDarkMagenta->palette();
    p13.setColor(QPalette::Background,Qt::darkMagenta);
    ui->chooseDarkMagenta->setPalette(p13);

    p14=ui->chooseDarkYellow->palette();
    p14.setColor(QPalette::Background,Qt::darkYellow);
    ui->chooseDarkYellow->setPalette(p14);

    p15=ui->chooseGray->palette();
    p15.setColor(QPalette::Background,Qt::gray);
    ui->chooseGray->setPalette(p15);

    p16=ui->chooseLightGray->palette();
    p16.setColor(QPalette::Background,Qt::lightGray);
    ui->chooseLightGray->setPalette(p16);

    p17=ui->chooseDarkGray->palette();
    p17.setColor(QPalette::Background,Qt::darkGray);
    ui->chooseDarkGray->setPalette(p17);

    p18=ui->chooseOrange->palette();
    p18.setColor(QPalette::Background,QColor::fromRgb(255,140,0));   //Orange
    ui->chooseOrange->setPalette(p18);

}

void colorclass::mousePressEvent(QMouseEvent *e)
{
    m_lastPoint = e->pos();
    m_mouseClick = true;
    update();

    if((m_mouseClick && m_lastPoint.x()>530 && m_lastPoint.x()<(530+111) && m_lastPoint.y()>20 && m_lastPoint.y()<(20+101)) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","widgetDsiplay");
        myPenColor = QColor(ui->redslider->value(),ui->greenslider->value(),ui->blueslider->value());
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>30 && m_lastPoint.x()<(30+64) && m_lastPoint.y()>160 && m_lastPoint.y()<(160+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","blue");
        myPenColor=QColor(0,0,255);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>30 && m_lastPoint.x()<(30+64) && m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","red");
        myPenColor = QColor(255,0,0);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>30 && m_lastPoint.x()<(30+64) && m_lastPoint.y()>320 && m_lastPoint.y()<(320+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","yellow");
        myPenColor=QColor(0,0,255);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>110 && m_lastPoint.x()<(110+64) && m_lastPoint.y()>160 && m_lastPoint.y()<(160+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","green");
        myPenColor=QColor(0,0,255);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>110 && m_lastPoint.x()<(110+64) && m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","white");
        myPenColor=QColor(255,255,255);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>110 && m_lastPoint.x()<(110+64) && m_lastPoint.y()>320 && m_lastPoint.y()<(320+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","black");
        myPenColor=QColor(0,0,0);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>190 && m_lastPoint.x()<(190+64) && m_lastPoint.y()>160 && m_lastPoint.y()<(160+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","magenta");
        myPenColor=QColor(255,0,255);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>190 && m_lastPoint.x()<(190+64) && m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","darkGreen");
        myPenColor=QColor(0,100,0);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>190 && m_lastPoint.x()<(190+64) && m_lastPoint.y()>320 && m_lastPoint.y()<(320+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","darkRed");
        myPenColor=QColor(139,0,0);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>270 && m_lastPoint.x()<(270+64) && m_lastPoint.y()>160 && m_lastPoint.y()<(160+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","darkBlue");
        myPenColor=QColor(0,0,139);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>270 && m_lastPoint.x()<(270+64) && m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","darkCyan");
        myPenColor=QColor(0,139,139);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>270 && m_lastPoint.x()<(270+64) && m_lastPoint.y()>320 && m_lastPoint.y()<(320+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","darkMagenta");
        myPenColor=QColor(255,0,255);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>350 && m_lastPoint.x()<(350+64) && m_lastPoint.y()>160 && m_lastPoint.y()<(160+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","darkYellow");
        myPenColor=QColor(139,0,139);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>350 && m_lastPoint.x()<(350+64) && m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","orange");
        myPenColor=QColor(255,140,0);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>350 && m_lastPoint.x()<(350+64) && m_lastPoint.y()>320 && m_lastPoint.y()<(320+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","darkGray");
        myPenColor=QColor(169,169,169);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>430 && m_lastPoint.x()<(430+64) && m_lastPoint.y()>160 && m_lastPoint.y()<(160+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","gray");
        myPenColor=QColor(128,128,128);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>430 && m_lastPoint.x()<(430+64) && m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","lightGray");
        myPenColor=QColor(211,211,211);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>430 && m_lastPoint.x()<(430+64) && m_lastPoint.y()>320 && m_lastPoint.y()<(320+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","cyan");
        myPenColor=QColor(0,255,255);
        pencil.setColor(myPenColor);
        brush.setColor(myPenColor);
    }
}

void colorclass::on_ChooseThis_clicked()
{
    if(m_mouseClick)
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","chooseThis");
        myPenColor = QColor(ui->redslider->value(),ui->greenslider->value(),ui->blueslider->value());
        pencil.setColor(myPenColor);
    }
}
