#ifndef COLOR1_H
#define COLOR1_H
#include <QWidget>
#include <QColor>

namespace Ui {
class colorclass;
}

class colorclass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)
public:
    explicit colorclass(QWidget *parent = 0);
    ~colorclass();
    QColor color() const
    {
       return m_color;
    }
signals:
    void colorChanged(QColor arg);

private slots:
    void onColorChanged();

private:
    Ui::ColorSelect *ui;
    QColor m_color;
};

#endif // COLOR1_H
