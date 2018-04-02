#include "rename.h"
#include "ui_rename.h"
#include <QFileDialog>
#include <QFileSystemModel>
#include <QTime>
#include <QGraphicsBlurEffect>

Rename::Rename(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rename)
{
    ui->setupUi(this);
#ifdef Q_WS_WIN
    QDir path(getenv("HOMEPATH"));
    QString where = getenv("HOMEPATH");
#endif
#ifdef Q_OS_LINUX
    QDir path(getenv("HOME"));
    QString where = getenv("HOME");
#endif
    QDir::setCurrent(where);
    QString qdms = QString::fromUtf8("Crtd By A_C");
    ui->statusBar->showMessage(qdms);
    QStringList files = path.entryList(QDir::Dirs | QDir::Files);
    ui->listWidget->addItems(files);
    ui->label->setText(QDir::currentPath());
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    //NOTE Maybe (new QGraphicsOpacityEffect(this));
    effect->setBlurRadius(8);
    ui->frame->setGraphicsEffect(effect);
    ui->frame->move(680,23);
}

void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(5);
    while( QTime::currentTime() < dieTime ) QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

QString Rename::Grtolt(QString &txt)
{
    txt.replace(QString::fromUtf8("α"),"a");
    txt.replace(QString::fromUtf8("ά"),"a");
    txt.replace(QString::fromUtf8("β"),"b");
    txt.replace(QString::fromUtf8("γ"),"g");
    txt.replace(QString::fromUtf8("δ"),"d");
    txt.replace(QString::fromUtf8("ε"),"e");
    txt.replace(QString::fromUtf8("έ"),"e");
    txt.replace(QString::fromUtf8("ζ"),"z");
    txt.replace(QString::fromUtf8("η"),"i");
    txt.replace(QString::fromUtf8("ή"),"i");
    txt.replace(QString::fromUtf8("θ"),"th");
    txt.replace(QString::fromUtf8("ι"),"i");
    txt.replace(QString::fromUtf8("ί"),"i");
    txt.replace(QString::fromUtf8("κ"),"k");
    txt.replace(QString::fromUtf8("λ"),"l");
    txt.replace(QString::fromUtf8("μ"),"m");
    txt.replace(QString::fromUtf8("ν"),"n");
    txt.replace(QString::fromUtf8("ξ"),"ks");
    txt.replace(QString::fromUtf8("ο"),"o");
    txt.replace(QString::fromUtf8("ό"),"o");
    txt.replace(QString::fromUtf8("π"),"p");
    txt.replace(QString::fromUtf8("ρ"),"r");
    txt.replace(QString::fromUtf8("σ"),"s");
    txt.replace(QString::fromUtf8("τ"),"t");
    txt.replace(QString::fromUtf8("υ"),"y");
    txt.replace(QString::fromUtf8("ύ"),"y");
    txt.replace(QString::fromUtf8("φ"),"f");
    txt.replace(QString::fromUtf8("χ"),"x");
    txt.replace(QString::fromUtf8("ψ"),"ps");
    txt.replace(QString::fromUtf8("ω"),"o");
    txt.replace(QString::fromUtf8("ώ"),"o");
    txt.replace(QString::fromUtf8("ς"),"s");
    txt.replace(QString::fromUtf8("Α"),"A");
    txt.replace(QString::fromUtf8("Ά"),"A");
    txt.replace(QString::fromUtf8("Β"),"B");
    txt.replace(QString::fromUtf8("Γ"),"G");
    txt.replace(QString::fromUtf8("Δ"),"D");
    txt.replace(QString::fromUtf8("Ε"),"E");
    txt.replace(QString::fromUtf8("Έ"),"E");
    txt.replace(QString::fromUtf8("Ζ"),"Z");
    txt.replace(QString::fromUtf8("Η"),"I");
    txt.replace(QString::fromUtf8("Ή"),"I");
    txt.replace(QString::fromUtf8("Θ"),"TH");
    txt.replace(QString::fromUtf8("Ι"),"I");
    txt.replace(QString::fromUtf8("Ί"),"I");
    txt.replace(QString::fromUtf8("Κ"),"K");
    txt.replace(QString::fromUtf8("Λ"),"L");
    txt.replace(QString::fromUtf8("Μ"),"M");
    txt.replace(QString::fromUtf8("Ν"),"N");
    txt.replace(QString::fromUtf8("Ξ"),"KS");
    txt.replace(QString::fromUtf8("Ο"),"O");
    txt.replace(QString::fromUtf8("Ό"),"O");
    txt.replace(QString::fromUtf8("Π"),"P");
    txt.replace(QString::fromUtf8("Ρ"),"R");
    txt.replace(QString::fromUtf8("Σ"),"S");
    txt.replace(QString::fromUtf8("Τ"),"T");
    txt.replace(QString::fromUtf8("Υ"),"Y");
    txt.replace(QString::fromUtf8("Ύ"),"Y");
    txt.replace(QString::fromUtf8("Φ"),"F");
    txt.replace(QString::fromUtf8("Χ"),"X");
    txt.replace(QString::fromUtf8("Ψ"),"PS");
    txt.replace(QString::fromUtf8("Ω"),"O");
    txt.replace(QString::fromUtf8("Ώ"),"O");
    return txt;
}

void Rename::InDir(int spcs)
{
    int nm1,nm2,nm3,nm4,nm5;
    QString oldtx,newtx,space = "===========================================================================================";
    space.resize(0+(spcs*2));
    space.append(">");
    QDir pathnow(QDir::currentPath());
    QStringList files = pathnow.entryList(QDir::Dirs | QDir::Files);
    for (int i=0;i<files.count();i++) {
        oldtx=files[i];
        newtx=oldtx;
        QFileInfo info1(oldtx);
        if (info1.isFile()) {
            nm5 = ui->numfls->text().toInt();
            nm5++;
            ui->numfls->setText(QString::number(nm5));
            Grtolt(newtx);
            if (spcs>0) ui->textEdit->insertPlainText(space);
            ui->textEdit->insertPlainText(oldtx + " rename to "+ newtx + " ==> ");
            if (oldtx!=newtx) {
                if (QFile::rename(oldtx, newtx)) {
                    ui->textEdit->insertPlainText(" Ok\n");
                    nm1 = ui->numrnm->text().toInt();
                    nm1++;
                    ui->numrnm->setText(QString::number(nm1));
                } else {
                    ui->textEdit->insertPlainText(" Error\n");
                    nm3 = ui->numerr->text().toInt();
                    nm3++;
                    ui->numerr->setText(QString::number(nm3));
                }
            } else {
                ui->textEdit->insertPlainText(" Same name ... Skip\n");
                nm2 = ui->numskp->text().toInt();
                nm2++;
                ui->numskp->setText(QString::number(nm2));
            }
        } else {
            if ((oldtx!=".") && (oldtx!="..")) {
                if (spcs>0) ui->textEdit->insertPlainText(space);
                ui->textEdit->insertPlainText("  " + oldtx + " is Directory...");
                nm4 = ui->numdir->text().toInt();
                nm4++;
                ui->numdir->setText(QString::number(nm4));
                if (QDir::setCurrent(pathnow.absolutePath()+"/"+files[i])) {
                    ui->textEdit->insertPlainText("  Jumpin ==-\n");
                    spcs++;
                    InDir(spcs);
                    spcs--;
                    if (QDir::setCurrent(pathnow.absolutePath())) {
                        if (spcs>0) ui->textEdit->insertPlainText(space);
                        ui->textEdit->insertPlainText("  Return ");
                        Grtolt(newtx);
                        if (oldtx!=newtx) {
                            if (QFile::rename(oldtx, newtx)) { ui->textEdit->insertPlainText(" And rename to "+ newtx + "==-\n"); } else { ui->textEdit->insertPlainText(" And Can't rename to "+ newtx + "\n"); }
                        } else { ui->textEdit->insertPlainText(" and no need rename this Directory ==-\n"); }
                    } else {
                        ui->textEdit->insertPlainText("Error On Jumpin\n");
                        nm3 = ui->numerr->text().toInt();
                        nm3++;
                        ui->numerr->setText(QString::number(nm3));
                    }
                }
            }
        }
    }
}

Rename::~Rename()
{
    delete ui;
}

void Rename::on_pushButton_clicked()
{
#ifdef Q_WS_WIN
    QString path(getenv("HOMEPATH"));
#endif
#ifdef Q_OS_LINUX
    QString path(getenv("HOME"));
#endif
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     path,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    if(QDir::setCurrent(dir)) {
    ui->listWidget->clear();
    ui->textEdit->clear();
    ui->label->setText(dir);
    QDir pathnow(dir);
    QStringList files = pathnow.entryList(QDir::Dirs | QDir::Files);
    //qDebug() << QString::number(files.count());
    ui->listWidget->addItems(files);
    } else {
        ui->label->setText(QDir::currentPath());
    }
}

void Rename::on_pushButton_2_clicked()
{
    QTime myTimer;
    int spcs=0;
    ui->textEdit->insertPlainText("Start Rename @ "+myTimer.currentTime().toString()+"\n");
    myTimer.start();
    InDir(spcs);
    int timspd = myTimer.elapsed();
    ui->listWidget->clear();
    QDir path(ui->label->text());
    QDir::setCurrent(ui->label->text());
    QString qdms = QString::fromUtf8("Crtd By A_C");
    ui->statusBar->showMessage(qdms);
    QStringList files = path.entryList(QDir::Dirs | QDir::Files);
    ui->listWidget->addItems(files);
    ui->textEdit->insertPlainText("End @ "+myTimer.currentTime().toString()+" in "+QString::number(timspd)+" Milliseconds\n");
    QTextCursor c = ui->textEdit->textCursor();
    c.movePosition(QTextCursor::End);
    ui->textEdit->setTextCursor(c);
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    effect->setBlurRadius(8);
    ui->frame->setGraphicsEffect(effect);
    for (int i=680;i>540;i=i-2) {
        delay();
        ui->frame->move(i,23);
    }
    for (int c=8;c>0;c=c-1) {
        delay();
        effect->setBlurRadius(c);
        ui->frame->setGraphicsEffect(effect);
    }
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

void Rename::on_pushButton_3_clicked()
{
    QGraphicsBlurEffect *effect = new QGraphicsBlurEffect(this);
    effect->setBlurRadius(8);
    for (int c=0;c<8;c++) {
        delay();
        effect->setBlurRadius(c);
        ui->frame->setGraphicsEffect(effect);
    }
    for (int i=540;i<680;i=i+2) {
        delay();
        ui->frame->move(i,23);
    }
    ui->pushButton_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->numdir->setText("0");
    ui->numfls->setText("0");
    ui->numerr->setText("0");
    ui->numrnm->setText("0");
    ui->numskp->setText("0");
    ui->textEdit->clear();
}
