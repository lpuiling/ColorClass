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

  //  ui->setupUi(this);
  // connect(ui->chooseRed,SIGNAL(hasMouseTracking()),SLOT(mousePressEvent(QMouseEvent *e)));
  // m_mouseClick= mousePressEvent(QMouseEvent *e);
     //connect(ui->chooseRed->hasMouseTracking());
    //OK=new QPushButton("OK");

   // ui->OK(button)
     m_mouseClick = false;
     myPenColor = QColor(0,255,0,255);// set default color
     pencil.setColor(myPenColor);
     //myMouse.MouseButtonPress=m_mouseClick;


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

    //if(ui->displaywidget->c)

    QPalette p1=ui->chooseRed->palette();
    p1.setColor(QPalette::Background,Qt::red);
    ui->chooseRed->setPalette(p1);

    QPalette p2=ui->chooseBlue->palette();
    p2.setColor(QPalette::Background,Qt::blue);
    ui->chooseBlue->setPalette(p2);

    QPalette p3=ui->chooseYellow->palette();
    p3.setColor(QPalette::Background,Qt::yellow);
    ui->chooseYellow->setPalette(p3);

    QPalette p4=ui->chooseGreen->palette();
    p4.setColor(QPalette::Background,Qt::green);
    ui->chooseGreen->setPalette(p4);

    QPalette p5=ui->chooseWhite->palette();
    p5.setColor(QPalette::Background,Qt::white);
    ui->chooseWhite->setPalette(p5);

    QPalette p6=ui->chooseBlack->palette();
    p6.setColor(QPalette::Background,Qt::black);
    ui->chooseBlack->setPalette(p6);

}

void colorclass::mousePressEvent(QMouseEvent *e)
{
    m_lastPoint = e->pos();
   // bool xRange=0;
   // bool yRange=0;
   // if( m_lastPoint.x()>30 && m_lastPoint.x()<94 )
        //xRange=1;
   // if( m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )
    //    yRange=1;
    m_mouseClick = true;
    update();
    if(m_mouseClick && m_lastPoint.x()>30 && m_lastPoint.x()<94 && m_lastPoint.y()>240 && m_lastPoint.y()<(240+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","red");
        myPenColor = QColor(255,0,0);
        pencil.setColor(myPenColor);
    }
    else if(m_mouseClick && m_lastPoint.x()>30 && m_lastPoint.x()<94 && m_lastPoint.y()>160 && m_lastPoint.y()<(160+64) )// && m_lastPoint.x()<= cRED.x()+64 && )//ui->chooseRed->hasMouseTracking())
    {
        QMessageBox msgBox;
        msgBox.information(this, "color","blue");
        myPenColor=QColor(0,0,255);
        pencil.setColor(myPenColor);
    }
    //pencil.color(255);

}

void colorclass::mouseReleaseEvent ( QMouseEvent * e )
{
    // m_mouseClick = false;
    // check if cursor not moved since click beginning
   if ((m_mouseClick) && (e->pos() == m_lastPoint))
    {
           // do something: for example emit Click signal
       emit mouseClickEvent();
    }
}
