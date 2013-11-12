#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>

ColorSelect::ColorSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSelect)
{
    ui->setupUi(this);
    connect(ui->,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    connect(ui->Yellow,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    connect(ui->Blue,SIGNAL(valueChanged(int)),SLOT(onColorChanged()));
    onColorChanged();
}

ColorSelect::~ColorSelect()
{
    delete ui;
}

void ColorSelect::onColorChanged()
{
    m_color.setRgb(ui->Red->value(),ui->Yellow->value(),ui->Blue->value());
    QPalette pal=ui->displaywidget->palette();
    pal.setColor(QPalette::Window,m_color);
    ui->displaywidget->setPalette(pal);
    emit colorChanged(m_color);

}
