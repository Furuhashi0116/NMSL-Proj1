#include "systemcenter.h"
#include "ui_systemcenter.h"
#include "login.h"
#include "record.h"
#include "QElapsedTimer"
#include <QHeaderView>
#include <QMovie>

/**
 * SystemCenter UI initialize
 *
 * @author Zicun Hang
 */
SystemCenter::SystemCenter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemCenter)
{
    ui->setupUi(this);

    m_tcpsocket = new QTcpSocket;
    m_tcpsocket->connectToHost(QHostAddress::LocalHost,8848);//设置客户端的端口号
    connect(m_tcpsocket,SIGNAL(readyRead()),
            this,SLOT(readMessage()));//用于接受数据


    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setStyleSheet("QFrame{border-radius:10px;}");

    /*
     * Add anything here to function 'showString' in this page
     *
     * for slow start
     *
     */
}

/**
 * SystemCenter UI destory
 *
 * @author Zicun Hang
 */
SystemCenter::~SystemCenter()
{
    delete ui;
    qDebug() << "Destory : systemcenter" << endl;
}

/**
 * on_pushButton_clicked
 *
 * @author Zicun Hang
 */
void SystemCenter::on_pushButton_quit_clicked()
{
    this->close();
}

/**
 * slot method
 *
 * @author Zicun Hang
 * @param s1 username
 * @param s2 name
 * @param s3 position
 * @param s4 gender
 * @param s5 email
 */
void SystemCenter::showString(QString s1, QString s2, QString s3, QString s4, QString s5, QString s6)
{
    this->show();
    ui->pushButton_switch->setEnabled(false);

    ui->tabWidget->setCurrentIndex(0);
    on_tabWidget_tabBarClicked(0);

    /*
     * slow start
     *
     */

    ui->label_2->setText(s1);
    ui->label_4->setText(s2);
    ui->label_8->setText(s3);
    ui->label_12->setText(s4);
    ui->label_14->setText(s5);

    QApplication::processEvents();

    connect(&netManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QPixmap *pixmap = new QPixmap("./" + s6);
    if (pixmap->isNull()){
        download("http://39.108.155.50/project1/users/" + s6, "./" + s6);
    }
    if(pixmap->isNull()){
        pixmap = new QPixmap(":/user.png");
    }

    QApplication::processEvents();

    getRoundPixmap(pixmap, QSize(140, 140));
    ui->label_5->setScaledContents(true);
    ui->label_5->setPixmap(*pixmap);
    delete pixmap;

    QApplication::processEvents();


    int fontId = QFontDatabase::addApplicationFont(":/font/fa-solid-900.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);

    //initialize tiny icon

    QFont font;
    font.setFamily(fontFamilies.at(0));
    font.setPointSize(15);
    ui->label->setFont(font);
    ui->label->setText(QChar(0xf007));
    ui->label->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");
    ui->label_9->setFont(font);
    ui->label_9->setText(QChar(0xf530));
    ui->label_9->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");
    ui->label_10->setFont(font);
    ui->label_10->setText(QChar(0xf182));
    ui->label_10->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");
    ui->label_13->setFont(font);
    ui->label_13->setText(QChar(0xf2b6));
    ui->label_13->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    QApplication::processEvents();
    ui->label_23->setFont(font);
    ui->label_23->setText(QChar(0xf551));
    ui->label_23->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    ui->label_24->setFont(font);
    ui->label_24->setText(QChar(0xf4d9));
    ui->label_24->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    ui->label_25->setFont(font);
    ui->label_25->setText(QChar(0xf2f2));
    ui->label_25->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    ui->label_42->setFont(font);
    ui->label_42->setText(QChar(0xf02d));
    ui->label_42->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    QApplication::processEvents();

    ui->label_43->setFont(font);
    ui->label_43->setText(QChar(0xf471));
    ui->label_43->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    ui->label_44->setFont(font);
    ui->label_44->setText(QChar(0xf155));
    ui->label_44->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    ui->label_46->setFont(font);
    ui->label_46->setText(QChar(0xf022));
    ui->label_46->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    ui->label_37->setFont(font);
    ui->label_37->setText(QChar(0xf0d1));
    ui->label_37->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    QApplication::processEvents();

    ui->label_41->setFont(font);
    ui->label_41->setText(QChar(0xf5cb));
    ui->label_41->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    ui->label_66->setFont(font);
    ui->label_66->setText(QChar(0xf02d));
    ui->label_66->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    QApplication::processEvents();

    ui->label_67->setFont(font);
    ui->label_67->setText(QChar(0xf471));
    ui->label_67->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    ui->label_68->setFont(font);
    ui->label_68->setText(QChar(0xf155));
    ui->label_68->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    ui->label_70->setFont(font);
    ui->label_70->setText(QChar(0xf022));
    ui->label_70->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    ui->label_77->setFont(font);
    ui->label_77->setText(QChar(0xf4de));
    ui->label_77->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    ui->label_102->setFont(font);
    ui->label_102->setText(QChar(0xf1de));
    ui->label_102->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    ui->label_104->setFont(font);
    ui->label_104->setText(QChar(0xf55f));
    ui->label_104->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");

    ui->label_107->setFont(font);
    ui->label_107->setText(QChar(0xf56e));
    ui->label_107->setStyleSheet("border: 0px; color: rgb(106, 106, 106);background:none;");


    //initialize search icon

    QFont icon_search;
    icon_search.setFamily(fontFamilies.at(0));
    icon_search.setPointSize(24);
    ui->icon_search->setFont(icon_search);
    ui->icon_search->setText(QChar(0xf35a));
    ui->icon_search->setStyleSheet("QPushButton{border: 0px; color: rgb(127, 127, 127);} "
                                    "QPushButton:hover{border: 0px; color: rgb(15, 128, 255);} ");

    ui->icon_search_B->setFont(icon_search);
    ui->icon_search_B->setText(QChar(0xf35a));
    ui->icon_search_B->setStyleSheet("QPushButton{border: 0px; color: rgb(127, 127, 127);} "

                                     "QPushButton:hover{border: 0px; color: rgb(15, 128, 255);} ");

    ui->icon_search_C->setFont(icon_search);
    ui->icon_search_C->setText(QChar(0xf35a));
    ui->icon_search_C->setStyleSheet("QPushButton{border: 0px; color: rgb(127, 127, 127);} "
                                    "QPushButton:hover{border: 0px; color: rgb(15, 128, 255);} ");

    ui->pushButton_font_sellSearch->setFont(icon_search);
    ui->pushButton_font_sellSearch->setText(QChar(0xf35a));

    ui->icon_search_D->setFont(icon_search);
    ui->icon_search_D->setText(QChar(0xf35a));
    ui->icon_search_D->setStyleSheet("QPushButton{border: 0px; color: rgb(127, 127, 127);} "
                                    "QPushButton:hover{border: 0px; color: rgb(15, 128, 255);} ");

    QApplication::processEvents();

    //set size of tablewidget

    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(105);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_A->setColumnWidth(0, 185);
    ui->tableWidget_A->setColumnWidth(1, 70);
    ui->tableWidget_A->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_A->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_B->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableWidget_B->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_B->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget_B->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_B_2->horizontalHeader()->setDefaultSectionSize(93);
    ui->tableWidget_B_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_B_2->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_C1->horizontalHeader()->setDefaultSectionSize(93);
    ui->tableWidget_C1->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_C1->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_C2->horizontalHeader()->setDefaultSectionSize(93);
    ui->tableWidget_C2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_C2->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_D1->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableWidget_D1->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_D1->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget_D1->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_D2->horizontalHeader()->setDefaultSectionSize(150);
    ui->tableWidget_D2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_D2->verticalHeader()->setDefaultSectionSize(50);
    ui->tableWidget_D2->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_D3->horizontalHeader()->setDefaultSectionSize(93);
    ui->tableWidget_D3->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_D3->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_D4->horizontalHeader()->setDefaultSectionSize(102);
    ui->tableWidget_D4->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_D4->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableWidget_stores->horizontalHeader()->setDefaultSectionSize(93);
    ui->tableWidget_stores->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_stores->setSelectionBehavior(QAbstractItemView::SelectRows);



    QApplication::processEvents();
    //fuzzy search

    connect(ui->warehouse_search_A, SIGNAL(returnPressed()), ui->icon_search, SIGNAL(clicked()), Qt::UniqueConnection);

    connect(ui->warehouse_search_B, SIGNAL(returnPressed()), ui->icon_search_B, SIGNAL(clicked()), Qt::UniqueConnection);

    connect(ui->warehouse_search_C, SIGNAL(returnPressed()), ui->icon_search_C, SIGNAL(clicked()), Qt::UniqueConnection);

    connect(ui->warehouse_search_D, SIGNAL(returnPressed()), ui->icon_search_D, SIGNAL(clicked()), Qt::UniqueConnection);

    connect(ui->quantity_D, SIGNAL(returnPressed()), ui->clothes_ADD, SIGNAL(clicked()), Qt::UniqueConnection);

    connect(ui->warehouse_id, SIGNAL(returnPressed()), ui->w_search_A, SIGNAL(clicked()), Qt::UniqueConnection);
    QApplication::processEvents();

    /**
     * purchase page date/time label display
     *
     * @author Yihan Dong
     */
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_deal_slot_function()));
    timer->start(1000);


    /**
     * purchase page setting
     *
     * @author Yihan Dong
     */
    ui->tableWidget_generateOrder->setRowCount(0);
    ui->tableWidget_generateOrder->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_generateOrder->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_generateOrder->setAlternatingRowColors(true);
    ui->tableWidget_generateOrder->verticalHeader()->setVisible(false);
    ui->tableWidget_generateOrder->setStyleSheet("selection-background-color::lightblue");


    /**
     * provider page tablewidget_prviderInfo setting
     *
     * @author Yihan Dong
    */
    ui->label_showPicName->setVisible(false);
    ui->tableWidget_providerInfo->verticalHeader()->setVisible(false);
    ui->tableWidget_providerInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_providerInfo->setSelectionBehavior(QAbstractItemView::SelectRows);

    /**
     * Add new staff page setting
     *
     * @author Yihan Dong
    */

    ui->label_newStaffUsernameTip->setVisible(false);
    ui->label_newStaffEmailTip->setVisible(false);
    ui->label_repeatPasswordTip->setVisible(false);
    ui->label_showNewPortraitName->setVisible(false);
    ui->lineEdit_addNewPassword->setEchoMode(QLineEdit::Password);
    ui->lineEdit_repeatPassword->setEchoMode(QLineEdit::Password);
    ui->pushButton_anpShowP->setIcon(QIcon("/new/prefix1/showPassword.jpg"));



//    //initialize furry search

    QElapsedTimer t;

    warehouseEditComplete();
    m_tcpsocket->flush();


    t.start();
    while(t.elapsed()<1000)
        QCoreApplication::processEvents();


    //initialize arriving table
    transfer();
    m_tcpsocket->flush();

//    QMovie *movie = new QMovie(":/movie.gif");
//    ui->label_title->setMovie(movie);
//    movie->start();

}




/**
 * shape picture to circle
 *
 * @author Zicun Hang
 * @param s1 username
 * @param s2 name
 * @param s3 position
 * @param s4 gender
 * @param s5 email
 */
void SystemCenter::getRoundPixmap(QPixmap* src,QSize size)

{

    QImage resultImage(size,QImage::Format_ARGB32_Premultiplied);
    QPixmap head_mask(":/mask.png");
    QPainter painter(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resultImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawPixmap(0, 0, head_mask);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOut);
    painter.drawPixmap(0, 0, src->scaled(size));
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.end();
    *src = QPixmap::fromImage(resultImage);
}

/**
 * slot method
 *
 * @author Zicun Hang
 * @param index tab index of tab widget
 */
void SystemCenter::on_tabWidget_tabBarClicked(int index){
    on_pushButton_A_clicked();
    if(index == 0){
        ui->pushButton_A->setVisible(true);
        ui->pushButton_B->setVisible(true);
        ui->pushButton_C->setVisible(true);
        ui->pushButton_D->setVisible(true);

        ui->pushButton_A->setText("");
        ui->pushButton_B->setText("");
        ui->pushButton_C->setText("");
        ui->pushButton_D->setText("");

    }
    if(index == 1){
        ui->pushButton_A->setVisible(true);
        ui->pushButton_B->setVisible(true);
        ui->pushButton_C->setVisible(true);
        ui->pushButton_D->setVisible(true);

        ui->pushButton_A->setText("");
        ui->pushButton_B->setText("");
        ui->pushButton_C->setText("");
        ui->pushButton_D->setText("");

    }
    if(index == 2){
        ui->pushButton_A->setVisible(true);
        ui->pushButton_B->setVisible(true);
        ui->pushButton_C->setVisible(true);
        ui->pushButton_D->setVisible(true);

        ui->pushButton_A->setText("");
        ui->pushButton_B->setText("");
        ui->pushButton_C->setText("");
        ui->pushButton_D->setText("");

    }
    if(index == 3){
        ui->pushButton_A->setVisible(true);
        ui->pushButton_B->setVisible(true);
        ui->pushButton_C->setVisible(true);
        ui->pushButton_D->setVisible(true);

        ui->pushButton_A->setText("Info");
        ui->pushButton_B->setText("Cargo");
        ui->pushButton_C->setText("Stock");
        ui->pushButton_D->setText("Replenish");
    }
    if(index == 4){
        ui->pushButton_A->setVisible(true);
        ui->pushButton_B->setVisible(true);
        ui->pushButton_C->setVisible(true);
        ui->pushButton_D->setVisible(true);

        ui->pushButton_A->setText("Record");
        ui->pushButton_B->setText("Delivery");
        ui->pushButton_C->setText("");
        ui->pushButton_D->setText("");

    }
    if(index == 5){
        ui->pushButton_A->setVisible(true);
        ui->pushButton_B->setVisible(true);
        ui->pushButton_C->setVisible(true);
        ui->pushButton_D->setVisible(true);

        ui->pushButton_A->setText("Display");
        ui->pushButton_B->setText("Append");
        ui->pushButton_C->setText("");
        ui->pushButton_D->setText("");

    }
    if(index == 6){
        ui->pushButton_A->setVisible(true);
        ui->pushButton_B->setVisible(true);
        ui->pushButton_C->setVisible(true);
        ui->pushButton_D->setVisible(true);

        ui->pushButton_A->setText("Garment");
        ui->pushButton_B->setText("Provider");
        ui->pushButton_C->setText("");
        ui->pushButton_D->setText("");

    }
}

/**
 * on_pushButton_A_clicked slot
 *
 * @author Zicun Hang
 */
void SystemCenter::on_pushButton_A_clicked()
{
    ui->pushButton_A->setChecked(true);
    ui->frame_2A->raise();
    ui->frame_pA->raise();
    ui->frame_systempage_1->raise();
    ui->frame_personnelpage_1->raise();
    ui->frame_sell_A->raise();
}

/**
 * on_pushButton_B_clicked slot
 *
 * @author Zicun Hang
 */
void SystemCenter::on_pushButton_B_clicked()
{
    ui->frame_2B->raise();
    ui->frame_pB->raise();
    ui->frame_systempage_2->raise();
    ui->frame_personnelpage_2->raise();
    ui->frame_sell_B->raise();
}

/**
 * on_pushButton_C_clicked slot
 *
 * @author Zicun Hang
 */
void SystemCenter::on_pushButton_C_clicked()
{
    ui->frame_2C->raise();

}

/**
 * on_pushButton_D_clicked slot
 *
 * @author Zicun Hang
 */
void SystemCenter::on_pushButton_D_clicked()
{
    ui->frame_2D->raise();
}


/**
 * progress bar
 *
 * @author Zicun Hang
 */
void SystemCenter::progressBar()
{
    ui->progressBar->setRange(0, 100);
    for (int i = 0; i <= 100; i++){
        for(int j = 0; j < 300000; j++){
            i = i + 1;
            i = i - 1;
        }
        ui->progressBar->setValue(i);
        QApplication::processEvents();
    }
}

/**
 * fast version progress bar
 *
 * @author Zicun Hang
 */
void SystemCenter::progressBar_fast()
{
    ui->progressBar->setRange(0, 100);
    for (int i = 0; i <= 100; i++){
        for(int j = 0; j < 300; j++){
            i = i + 1;
            i = i - 1;
        }
        ui->progressBar->setValue(i);
        QApplication::processEvents();
    }
}


/**
 * on_pushButton_2_clicked slot
 *
 * @author Zicun Hang
 */
void SystemCenter::on_pushButton_switch_clicked()
{
    QApplication::processEvents();
    Login *lg = new Login;
    connect(this, SIGNAL(stringReturn(QString)), lg, SLOT(showString(QString)));
    emit stringReturn(this->ui->label_2->text());
    this->close();
}

/**
 * download picture
 *
 * @author Zicun Hang
 * @param surl pic url
 * @param filePath local file path
 */
void SystemCenter::download(const QString &surl, const QString &filePath)
{
    QUrl url;
    url = QUrl(surl);

    QNetworkRequest request;
    request.setUrl(url);

    netManager.get(request);
    this->filepath = filePath;
}

/**
 * save picture
 *
 * @author Zicun Hang
 * @param reply NetworkReply
 */
void SystemCenter::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();

        QFile file(filepath);
        if (file.open(QIODevice::ReadWrite))
        {
            file.write(bytes);
        }
        file.close();
    }
    else
    {
        qDebug() << "Error\n";
    }
}

