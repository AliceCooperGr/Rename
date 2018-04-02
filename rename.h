#ifndef RENAME_H
#define RENAME_H

#include <QMainWindow>

namespace Ui {
class Rename;
}

class Rename : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = 0);
    ~Rename();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    QString Grtolt(QString &txt);
    void InDir(int spcs);

    void on_pushButton_3_clicked();

private:
    Ui::Rename *ui;
};

#endif // RENAME_H
